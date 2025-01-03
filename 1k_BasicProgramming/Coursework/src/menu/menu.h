#ifndef MENU_H
#define MENU_H

#include <string>
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

static const Menu main_menu =
    {
        "| Меню\n"
        "| 1. Добавяне на Участник\n"
        "| 2. Показване на всички Участници\n"
        "| 3. Показване на най-младия Участник\n"
        "| 4. Търсене на Участник по Име\n"
        "| 5. Подреджане на Участници по Възраст(възходящ ред)\n"
        "| 6. Извеждане във файл\n"
        "| 7. Въвеждане от файл\n"
        "| 8. Допълнителни Опции \n"
        "| 9. Категоризиране на Участници \n"
        "| 10. Определи победители \n"
        "| 11. Изход \n",

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

static const Menu additional_submenu = {
    "| 1. Извеждане на участниците в подреден ред по години и име, без да се променя основния масив.\n"
    "| 2. Търсене и извеждане на участниците по въведена възраст и пол\n"
    "| 3. Връщане към главното меню\n",
    "ДОПЪЛНИТЕЛНИ ОПЦИИ",
};
static const Menu file_type_menu = { 
    "1. Текстов\n"
    "2. Двойчен\n",
    "ТИП ФАЙЛ: \n"
};

static const int ART_BOUNDARY = 113;

void display_menu(Participant participants[], int& count);
void print_menu(const Menu &menu);
void handle_menu_choice(const Menu &menu, const int &choice, Participant participants[], int& count);
void handle_submenu_choice(const Menu &menu, const int &choice, Participant participants[], int& count);
void return_to_main_menu(Participant participants[], int& count);
// void display_submenu();

#endif 