#ifndef MENU_H
#define MENU_H

#include <string>

// Function declarations
int get_terminal_width();
void clear_window();
void print_char_whole_width(char c, int width);
void display_menu(bool isBg = true);
void display_submenu();

#endif // MENU_H
