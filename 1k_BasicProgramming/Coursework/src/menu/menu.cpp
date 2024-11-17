#include "menu.h"

void display_menu(bool isBG)
{
    const Menu *menu = isBG ? &menu_BG : &menu_EN;

    clear_window();
    print_menu(*menu, isBG);

    int choice;
    choice = get_validated_int(
        menu->invalid_choice, 
        [](int choice){ return choice >= 1 && choice <= 9; }
    );

    std::cin.clear();

    handle_menu_choice(*menu, choice);
}

// void display_submenu()
// {
//     int choice;
//     do
//     {
//         std::cout << "\nAdvanced Submenu\n"
//                   << "1. Display Participants Sorted by Age and Name\n"
//                   << "2. Search by Age and Gender\n"
//                   << "3. Return to Main Menu\n";

//         std::cin >> choice;

//         switch (choice)
//         {
//         case 3:
//             std::cout << "Returning to Main Menu...\n";
//             break;
//         }
//     } while (choice != 3);
// }

void print_menu(const Menu &menu, bool isBG)
{
    const int terminalWidth = get_terminal_width();
    std::cout << '\n';

    print_char_whole_width('=', terminalWidth);

    terminalWidth > ART_BOUNDARY
        ? center_multiline_string(menu.ascii_art, terminalWidth)
        : center_string(menu.heading, terminalWidth, isBG);

    print_char_whole_width('=', terminalWidth);

    std::cout << "\n";
    std::cout << (menu.options);
    std::cout << "\n";
    std::cout << (menu.choice_prompt);
}

void handle_menu_choice(const Menu &menu, const int &choice)
{
    int count = 0;
    switch (choice)
    {
        case 1:
            add_participants(count);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            std::cout << menu.exit_text;
            break;
    }
}