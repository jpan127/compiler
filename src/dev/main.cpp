#include "globals.hpp"
// Project libraries
#include "Parser.hpp"



/// Enumerate the different commands the compiler can run
enum class CompilerCommands
{
    execute,
    compile,
};

/**
 *  Calls the compiler and executes it
 *  @param command : Either a compile or an execute command
 *  @param path    : Path to file to compile
 */
void run_compiler(const CompilerCommands command, const string path);

int main(int argc, char const *argv[])
{
    const string usage =    "-------------------------------------------------------\n"
                            "./<NAME_OF_EXECUTABLE> execute|compile <PATH_TO_SOURCE>\n"
                            "-------------------------------------------------------\n";

    if (argc < 3)
    {
        cout << usage << endl;
        exit(EXIT_FAILURE);
    }

    const string command = argv[1];
    const string path    = argv[2];

    if ("compile" == command)
    {
        run_compiler(CompilerCommands::compile, path);
    }
    else if ("execute" == command)
    {
        run_compiler(CompilerCommands::execute, path);
    }
    else
    {
        cout << "Chosen command should be either 'execute' or 'compile', incorrect command: " << command << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}

void run_compiler(const CompilerCommands command, const string path)
{
    // Read 1000 lines at a time, files shouldn't be more than 1000 anyways
    const uint32_t capacity = 1000;

    // Initialize parser
    Parser::instance().init(path, capacity);

    // Parse
    Parser::instance().parse_file();

    // Close file
    Parser::instance().close();

    switch (command)
    {
        case CompilerCommands::compile: break;
        case CompilerCommands::execute: break;
        default:                        break;
    }
}
