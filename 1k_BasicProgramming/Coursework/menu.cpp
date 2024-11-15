#include "menu.h"
#include "utils.h"
#include <iostream>

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

static const std::string heading_BG = "КОНКУРС ЗА КРАСОТА";
static const std::string heading_EN = "BEAUTY CONTEST";

static const std::string choice_BG = "Твоят Избор: ";
static const std::string choice_EN = "Твоят Избор: ";

static const int ART_BOUNDARY = 113;

void display_menu(bool isBg)
{
    const int terminalWidth = get_terminal_width();
    int choice;
    do
    {
        clear_window();
        print_char_whole_width('=', terminalWidth);
        isBg ? printMenu_BG(terminalWidth) : printMenu_EN(terminalWidth);
    } while (choice != 9);

    std::cout << "Program terminated. Data saved.\n";
}

void display_submenu()
{
    int choice;
    do
    {
        std::cout << "\nAdvanced Submenu\n"
                  << "1. Display Participants Sorted by Age and Name\n"
                  << "2. Search by Age and Gender\n"
                  << "3. Return to Main Menu\n";

        std::cin >> choice;

        switch (choice)
        {
        case 3:
            std::cout << "Returning to Main Menu...\n";
            break;
        }
    } while (choice != 3);
}

void printMenu_EN(int terminalWidth)
{
    std::cout << '\n';

    terminalWidth > ART_BOUNDARY
        ? center_multiline_string(ascii_art_EN, terminalWidth)
        : center_string(heading_EN, terminalWidth);

    print_char_whole_width('=', terminalWidth);

    std::cout << "\n";
    std::cout << (menu_EN);
    std::cout << "\n";
    std::cout << (choice_EN);
}

void printMenu_BG(int terminalWidth)
{
    std::cout << '\n';

    terminalWidth > ART_BOUNDARY
        ? center_multiline_string(ascii_art_BG, terminalWidth)
        : center_string(heading_BG, terminalWidth, true);

    print_char_whole_width('=', terminalWidth);

    std::cout << "\n";
    std::cout << (menu_BG);
    std::cout << "\n";
    std::cout << (choice_BG);
}