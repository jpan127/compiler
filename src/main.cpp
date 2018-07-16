#include <chrono>

#include "antlr4-runtime.h"
#include "CmmLexer.h"
#include "CmmParser.h"

#include "common.hpp"
#include "logger.hpp"
#include "Pass1Visitor.hpp"
#include "Pass2Visitor.hpp"
#include "JasminEmitter.hpp"



static constexpr bool debug = true;

static const char * pass1_msg =
    "\n"
    "------------------------------------------------\n"
    "|                   P A S S  1                 |\n"
    "------------------------------------------------\n";

static const char * pass2_msg =
    "\n"
    "------------------------------------------------\n"
    "|                   P A S S  2                 |\n"
    "------------------------------------------------\n";

static const char * unknown_exception_msg =
    "\n"
    "------------------------------------------------\n"
    "|               Unknown Exception              |\n"
    "------------------------------------------------\n";

int main(int argc, const char *args[])
{
    /// Create logger
    SpeedLoggerPtr logger = logger_create(debug);

    const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    {
        try
        {
            /// Make sure argument exists
            if (argc < 2)
            {
                THROW_EXCEPTION(MissingArgument, "Missing argument : path to sample program");
            }

            /// Input Stream
            std::ifstream ins(args[1]);
            logger->debug("{}", args[1]);

            /// ANLTR Input Stream
            antlr4::ANTLRInputStream input(ins);

            /// Lexer
            CmmLexer lexer(&input);

            /// Tokenizer
            antlr4::CommonTokenStream tokens(&lexer);

            /// Parser
            CmmParser parser(&tokens);

            /// Parse Tree
            antlr4::tree::ParseTree *tree = parser.compilationUnit();

            /// Get file name and strip rest of string
            std::string program_name = args[1];
            program_name = program_name.substr(0, program_name.find_last_of("."));
            program_name = program_name.substr(program_name.find_last_of("/") + 1);

            /// Output Stream
            std::ofstream j_file(program_name + ".j");
            if (j_file.fail())
            {
                THROW_EXCEPTION(FileOpenError, "Failed to open file :" + program_name + ".j");
            }

            backend::JasminEmitter j_emitter(j_file);

            /// First Pass
            logger->debug("{}", pass1_msg);
            backend::Pass1Visitor pass1(
                program_name,
                j_file,
                j_emitter,
                logger
            );
            pass1.visit(tree);

            /// Second Pass
            logger->debug("{}", pass2_msg);
            backend::Pass2Visitor pass2(
                program_name,
                j_file,
                j_emitter,
                logger
            );
            pass2.visit(tree);

            /// Sanity clean up
            if (j_file.is_open())
            {
                j_file.flush();
                j_file.close();
            }

            delete tree;
        }
        catch (const CustomException & e)
        {
            e.print_and_exit();
        }
        catch (const std::exception & e)
        {
            cerr << e.what() << endl;
        }
        catch (...)
        {
            logger->error("{}", unknown_exception_msg);
        }
    }
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    const auto elapsed_time_us  = std::chrono::duration_cast <std::chrono::microseconds> (end - start);
    const auto elapsed_time_sec = (elapsed_time_us.count() / 1000000.0);

    logger->info("Compilation Time : {} seconds", elapsed_time_sec);

    return 0;
}
