#include "utils.h"
#include <sstream>
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/ioctl.h>
#endif

int get_terminal_width()
{
    int terminal_width = 80; // Default value

#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        terminal_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
#else
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1)
    {
        terminal_width = ws.ws_col;
    }
#endif

    return terminal_width;
}

void print_char_whole_width(char c, int width)
{
    for (int i = 0; i < width; i++)
    {
        std::cout << c;
    }
}

void clear_window()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

std::vector<std::string> split_string_into_lines(const std::string &str)
{
    std::vector<std::string> lines;
    std::stringstream ss(str);
    std::string line;
    while (std::getline(ss, line))
    {
        lines.push_back(line);
    }
    return lines;
}

void center_multiline_string(const std::string &str, int terminal_width)
{
    std::vector<std::string> lines = split_string_into_lines(str);

    for (const auto &line : lines)
    {
        center_string(line, terminal_width);
    }
}

void center_string(const std::string &str, int terminal_width, bool isCyrilic)
{
    int length = (isCyrilic ? count_utf8_characters(str) : str.length());
    int padding = (terminal_width - length) / 2;
    if (padding < 0)
        return;
    std::cout << std::string(padding, ' ') << str << std::endl;
}

size_t count_utf8_characters(const std::string &str)
{
    size_t count = 0;
    size_t i = 0;
    while (i < str.length())
    {
        unsigned char byte = str[i];

        // 1 byte
        if ((byte & 0x80) == 0x00)
        {
            i += 1; 
        }

        // 2 bytes
        else if ((byte & 0xE0) == 0xC0)
        {
            i += 2;
        }

        // 3 bytes 
        else if ((byte & 0xF0) == 0xE0)
        {
            i += 3;
        }

        // 4 bytes
        else if ((byte & 0xF8) == 0xF0)
        {
            i += 4;
        }

        // Invalid byte (shouldn't happen in properly encoded UTF-8)
        else
        {
            i += 1;
        }

        count++;
    }

    return count;
}