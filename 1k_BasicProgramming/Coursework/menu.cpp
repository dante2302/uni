#include "menu.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h> 
#else
#include <unistd.h>   
#include <sys/ioctl.h> 
#endif

const std::string menu_EN =
    "| Main Menu\n"
    "| 1. Add Participants\n"
    "| 2. Display Participants\n"
    "| 3. Search by Name\n"
    "| 4. Find Youngest\n"
    "| 5. Sort by Age\n"
    "| 6. Categorize Participants\n"
    "| 7. Determine Winners\n"
    "| 8. Advanced Options\n"
    "| 9. Exit\n";

const std::string menu_BG = 
    "| Меню\n"
    "| 1. Добавяне на Участник\n"
    "| 2. Показване на всички участници\n"
    "| 3. Показване най-младия участник\n"
    "| 4. Търсене на участник по име\n"
    "| 5. Подреди участници по възраст(възходящ ред)\n"
    "| 6. Допълнителни опции \n"
    "| 7. Категоризиране на участници \n"
    "| 8. Определи победители \n"
    "| 9. Изход \n";

static const std::string ascii_art_EN =
    "  ____                _                ____               _              _   \n"
    " | __ )   ___   __ _ | |_  _   _      / ___| ___   _ __  | |_  ___  ___ | |_ \n"
    " |  _ \\  / _ \\ / _` || __|| | | |    | |    / _ \\ | '_ \\ | __|/ _ \\/ __|| __|\n"
    " | |_) ||  __/| (_| || |_ | |_| |    | |___| (_) || | | || |_|  __/\\__ \\| |_ \n"
    " |____/  \\___| \\__,_| \\__| \\__, |     \\____|\\___/ |_| |_| \\__|\\___||___/ \\__|\n\n";

static const std::string ascii_art_BG =
    "  _  __ ___   _   _  _  ____   __ ____    ____     _____    _        _  __ ____    _     ____  ___  _____   _    \n"
    " | |/ // _ \\ | | | || |/ /\\ \\ / /|  _ \\  / ___|   |___ /   / \\      | |/ /|  _ \\  / \\   / ___|/ _ \\|_   _| / \\   \n"
    " | ' /| | | || |_| || ' /  \\ V / | |_) || |         |_ \\  / _ \\     | ' / | |_) |/ _ \\ | |   | | | | | |  / _ \\  \n"
    " | . \\| |_| ||  _  || . \\   | |  |  __/ | |___     ___) |/ ___ \\    | . \\ |  __// ___ \\| |___| |_| | | | / ___ \\ \n"
    " |_|__\\\\___/ |_| |_||_|__\\  |_|  |_|     \\____|   |____//_/   \\_\\   |_|__\\|_|  /_/   \\_\\\\____|\\___/  |_|/_/   \\_\\\n\n";

static const std::string choice_BG = "Твоят Избор: ";
static const std::string choice_EN = "Твоят Избор: ";

void display_menu(bool isBg) {
    const int terminalWidth = get_terminal_width();
    int choice;
    do {
        clear_window();

        print_char_whole_width('=', terminalWidth);
        std::cout << (isBg ? ascii_art_BG : ascii_art_EN);
        print_char_whole_width('=', terminalWidth);

        std::cout << "\n";
        std::cout << (isBg ? menu_BG : menu_EN);
        std::cout << "\n";
        std::cout << (isBg ?  choice_BG : choice_EN);
        std::cin >> choice;

    } while (choice != 9);

    std::cout << "Program terminated. Data saved.\n";
}

void display_submenu() {
    int choice;
    do {
        std::cout << "\nAdvanced Submenu\n"
                  << "1. Display Participants Sorted by Age and Name\n"
                  << "2. Search by Age and Gender\n"
                  << "3. Return to Main Menu\n";

        std::cin >> choice;

        switch (choice) {
            case 3:
                std::cout << "Returning to Main Menu...\n";
                break;
        }
    } while (choice != 3);
}

int get_terminal_width() {
    int terminal_width = 80;  // Default value

#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        terminal_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;  
    }
#else
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1) {
        terminal_width = ws.ws_col;  
    }
#endif

    return terminal_width;
}

void print_char_whole_width(char c, int width) {
    for (int i = 0; i < width; i++) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void clear_window()
{
    #ifdef _WIN32
        system("cls");
    #else

        system("clear");
    #endif
}