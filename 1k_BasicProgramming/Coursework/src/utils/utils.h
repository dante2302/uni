#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

int get_terminal_width();

void print_char_whole_width(char c, int width);

void clear_window();

std::vector<std::string> split_string_into_lines(const std::string &str);

void center_multiline_string(const std::string &str, int terminal_width);

void center_string(const std::string &str, int terminal_width, bool isCyrilic = false);

size_t count_utf8_characters(const std::string &str);

#endif