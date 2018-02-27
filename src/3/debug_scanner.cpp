    void JavaScanner::ignore_all_whitespaces(char &c)
    {
        const char eof = 0;
        while (isspace(c) && c != eof)
        {
            c = next_char();
cout << "4 ---> " << c << " ---> " << source->get_position() << endl;
        }
    }

    void JavaScanner::find_next_token()
    {
        // Syntactical symbols
        const char slash    = '/';
        const char asterisk = '*';
        const char new_line = '\n';
        const char eof      = 0;

        /**
         *  @note:
         *  If the scanner encounters a slash, but it is not proceeded by another slash or asterisk,
         *  then there is most likely a syntax issue.  The slash should have been preceeded by a left hand operator.
         */

        scanner_state_E state = scanner_state_E::ignoring_characters;
        char c = ' ';

        ///// @TODO : Clean this up
        while (c != eof)
        {
            // c = next_char();

            // Read all preceeding spaces
            ignore_all_whitespaces(c);

cout << "0 ---> " << c << " ---> " << source->get_position() << endl;

            // Finding the first slash
            if (c == slash)
            {
                c = next_char();

cout << "1 ----> " << c << " ---> " << source->get_position() << endl;

                // Finds a second slash, so it is a single line comment
                if (c == slash)
                {
                    // Ignore all characters of the current line
                    while (c != new_line && c != eof)
                    {
                        c = next_char();
cout << "2 -----> " << c << " ---> " << source->get_position() << endl;
                    }

                    // Read all subsequent spaces
                    c = next_char();
                    ignore_all_whitespaces(c);

                }
                // Finds an asterisk, so it is a multi line comment
                else if (c == asterisk)
                {
                    // Search for next asterisk that is proceeded by a slash
                    while (c != eof)
                    {
                        c = next_char();

cout << "3 -----> " << c << " ---> " << source->get_position() << endl;

                        // If parsing the comment and finds an asterisk
                        if (state == scanner_state_E::ignoring_characters && c == asterisk)
                        {
                            state = scanner_state_E::ending_asterisk;
                        }
                        // If just found an asterisk and finds another slash
                        else if (state == scanner_state_E::ending_asterisk && c == slash)
                        {
                            break;
                        }
                        // If just found an asterisk, and ending slash not found
                        else if (state == scanner_state_E::ending_asterisk && c != slash)
                        {
                            state = scanner_state_E::ignoring_characters;
                        }
                    }

                    // Read all subsequent spaces
                    c = next_char();
                    ignore_all_whitespaces(c);
                }
                else
                {
                    put_back();
                    break;
                }
            }
            // If the next character is not a space or a slash then it must be a token
            else if (!isspace(c))
            {
                break;
            }

            cout << "### End of loop " << c << " " << static_cast<int>(c) << endl;
        }

        cout << "### End of function " << c << endl;
    }
