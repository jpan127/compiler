#include "globals.hpp"



void run_compiler(const string operation, const string path);

int main(int argc, char const *argv[])
{
    const string usage =    "-------------------------------------------------------\n"
                            "./<NAME_OF_EXECUTABLE> execute|compile <PATH_TO_SOURCE>\n"
                            "-------------------------------------------------------\n";

    if (argc < 3)
    {
        printf("%s", usage);
        exit(EXIT_FAILURE);
    }

    const string operation = argv[1];
    const string path      = argv[2];

    if (operation != "compile" && operation != "execute")
    {
        printf("Chosen operation should be either 'execute' or 'compile', incorrect operation: %s\n", operation);
        exit(EXIT_FAILURE);
    }

    run_compiler(operation, path);

    return 0;
}

void run_compiler(const string operation, const string path)
{
    // Read 100 lines at a time
    const uint32_t capacity = 100;

    // Create Parser
    Parser * parser = new Parser(path, capacity);

    // Parse
    parser.parse_file();

    // Close
    parser.close();

    // Compile
}
