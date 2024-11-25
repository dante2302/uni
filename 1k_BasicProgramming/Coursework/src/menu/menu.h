#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <limits>
#include <ios>
#include "../utils/utils.h"
#include "../validation/validation.h"
#include "../participants/participants.h"


struct Menu
{
    std::string options;
    std::string heading;
    std::string ascii_art;
    std::string choice_prompt;
    std::string invalid_choice;
    std::string exit_text;
};

static const Menu menu_EN =
    {
        "| Main Menu\n"
        "| 1. Add Participants\n"
        "| 2. Display Participants\n"
        "| 3. Search by Name\n"
        "| 4. Find Youngest\n"
        "| 5. Sort by Age\n"
        "| 6. Categorize Participants\n"
        "| 7. Determine Winners\n"
        "| 8. Advanced Options\n"
        "| 9. Exit\n",

        "BEAUTY CONTEST",

        "  ____                _                ____               _              _   \n"
        " | __ )   ___   __ _ | |_  _   _      / ___| ___   _ __  | |_  ___  ___ | |_ \n"
        " |  _ \\  / _ \\ / _` || __|| | | |    | |    / _ \\ | '_ \\ | __|/ _ \\/ __|| __|\n"
        " | |_) ||  __/| (_| || |_ | |_| |    | |___| (_) || | | || |_|  __/\\__ \\| |_ \n"
        " |____/  \\___| \\__,_| \\__| \\__, |     \\____|\\___/ |_| |_| \\__|\\___||___/ \\__|\n"
        "                           |___/                                              \n",

        "Your choice: ",

        "Invalid choice. Please try again: ",
        
        "Program terminated. Data saved.\n"
        };

static const Menu menu_BG =
    {
        "| Меню\n"
        "| 1. Добавяне на Участник\n"
        "| 2. Показване на всички Участници\n"
        "| 3. Показване на най-младия Участник\n"
        "| 4. Търсене на Участник по Име\n"
        "| 5. Подреджане на Участници по Възраст(възходящ ред)\n"
        "| 6. Допълнителни Опции \n"
        "| 7. Категоризиране на Участници \n"
        "| 8. Определи победители \n"
        "| 9. Изход \n",

        "КОНКУРС ЗА КРАСОТА",

        "  _  __ ___   _   _  _  ____   __ ____    ____     _____    _        _  __ ____    _     ____  ___  _____   _    \n"
        " | |/ // _ \\ | | | || |/ /\\ \\ / /|  _ \\  / ___|   |___ /   / \\      | |/ /|  _ \\  / \\   / ___|/ _ \\|_   _| / \\   \n"
        " | ' /| | | || |_| || ' /  \\ V / | |_) || |         |_ \\  / _ \\     | ' / | |_) |/ _ \\ | |   | | | | | |  / _ \\  \n"
        " | . \\| |_| ||  _  || . \\   | |  |  __/ | |___     ___) |/ ___ \\    | . \\ |  __// ___ \\| |___| |_| | | | / ___ \\ \n"
        " |_|__\\\\___/ |_| |_||_|__\\  |_|  |_|     \\____|   |____//_/   \\_\\   |_|__\\|_|  /_/   \\_\\\\____|\\___/  |_|/_/   \\_\\\n\n",

        "Твоят Избор: ",

        "Невалиден избор. Опитай пак: ",

        "Програмата е прекратена. Данните са запазени.\n"

        };

static const int ART_BOUNDARY = 113;

void display_menu(const bool isBG = true);
void print_menu(const Menu &menu, const bool isBG = true);
void handle_menu_choice(const Menu &menu, const int &choice);
void return_to_main_menu();
// void display_submenu();

#endif 