#include "sjetlib.h"
//////////////////////////////////////////////////////////////////////////
std::string getPasswd(char _ReplaceChar)
{
    std::cout << "Password:";
    std::vector<char> buffer;
    buffer.clear();
    std::ostringstream passwd;
    char key = 0;
    while (key != '\n')
    {
        if (_kbhit())
        {
            key = _getch();
            switch (key)
            {
            case 8: // BACKSPACE
                printf("\b \b");
                if (!buffer.empty())
                    buffer.pop_back();
                break;
            case 13: // ENTER
                key = '\n';
                break;
            default: // INPUT
                putchar(_ReplaceChar);
                buffer.push_back(key);
                break;
            }
        }
    }
    for (auto &i : buffer)
        passwd << i;
    return passwd.str();
}
////////////////////////////////////////////////////////////////////////////////