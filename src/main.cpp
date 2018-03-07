#include "globals.hpp"
// Project libraries
#include "Parser.hpp"



/**
 *  Calls the compiler and executes it
 *  @param operation : Either a compile or an execute operation @TODO : Should change to enum
 *  @param path      : Path to file to compile
 */
void run_compiler(const string operation, const string path);

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

    const string operation = argv[1];
    const string path      = argv[2];

    if (operation != "compile" && operation != "execute")
    {
        cout << "Chosen operation should be either 'execute' or 'compile', incorrect operation: " << operation << endl;
        exit(EXIT_FAILURE);
    }

    run_compiler(operation, path);

    return 0;
}

void run_compiler(const string operation, const string path)
{
    // Read 100 lines at a time
    const uint32_t capacity = 100;

    // Initialize parser
    Parser::instance().init(path, capacity);

    // Parse
    Parser::instance().parse_file();

    // Close file
    Parser::instance().close();

    // Compile
}
