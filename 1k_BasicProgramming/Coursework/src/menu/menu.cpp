#include <string>
#include <iostream>
#include <limits>
#include <ios>
#include "../utils/utils.h"
#include "../validation/validation.h"
#include "../participants/participants.h"
#include "../globals.h"
#include "menu.h"

void display_menu(Participant participants[], int& count)
{
    clear_window();
    print_menu(main_menu);

    int choice;
    choice = get_validated_int(
        main_menu.invalid_choice, 
        [](int choice){ return choice >= 1 && choice <= 11; }
    );

    std::cin.clear();

    handle_menu_choice(main_menu, choice, participants, count);
}

void display_submenu(Participant participants[], int& count)
{
    clear_window();
    print_menu(additional_submenu);

    int choice;
    choice = get_validated_int(
        main_menu.invalid_choice, 
        [](int choice){ return choice >= 1 && choice <= 3; }
    );

    std::cin.clear();

    handle_submenu_choice(main_menu, choice, participants, count);
}

void print_menu(const Menu &menu)
{
    const int terminalWidth = get_terminal_width();
    std::cout << '\n';

    print_char_whole_width('=', terminalWidth);
    bool has_ascii = menu.ascii_art.length() > 0;
    if(has_ascii || menu.heading.length() > 0)
    {
        terminalWidth > ART_BOUNDARY && has_ascii
            ? center_multiline_string(menu.ascii_art, terminalWidth)
            : center_string(menu.heading, terminalWidth, true);

        print_char_whole_width('=', terminalWidth);
    }
    else{
        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << (menu.options);
    std::cout << "\n";
    std::cout << (menu.choice_prompt);
}

void handle_menu_choice(const Menu &menu, const int &choice, Participant participants[], int& count)
{
    switch (choice)
    {
        case 1:
            add_participants(participants, count);
            break;

        case 2:
            display_participants(participants, count);
            break;

        case 3:
        {
            clear_window();
            Participant tempParticipants[MAX_PARTICIPANTS];
            deep_copy_participants(participants, tempParticipants, count);
            sort_participants_by_age(tempParticipants, count);
            if(count > 0)
            {
                const int winning_age = tempParticipants[0].age;
                for (int i = 0; i < count; ++i)
                {
                    double current_age = participants[i].age;

                    if (current_age == winning_age)
                    {
                        display_participant_field_names();
                        display_participant_fields(participants[0]);
                    }
                    else
                        break;
                }
            }
            else
            {
                std::cout << "Няма въведени участници\n";
            }
            delete[] tempParticipants;
            return_to_main_menu(participants, count);
            break;
        }

        case 4:
        {
            clear_window();
            std::cout << "Въведете име на участника: ";
            std::string name;
            getline(std::cin, name);
            std::cout << "\n";
            search_participants_by_name(participants, count, name);
            return_to_main_menu(participants, count);
            break;
        }

        case 5:
            clear_window();
            sort_participants_by_age(participants, count);    
            return_to_main_menu(participants, count);
            break;

        case 6:
        {
            clear_window();
            print_menu(file_type_menu);
            int file_type_choice_save;
            file_type_choice_save = get_validated_int(
                file_type_menu.invalid_choice, 
                [](int choice){ return choice >= 1 && choice <= 2; }
            );
            clear_window();
            std::string filename_save; 
            std::cout << "Въведете име на файла: ";
            std::getline(std::cin, filename_save);
            switch (file_type_choice_save)
            {
                case 1:
                    save_to_text_file(participants, count, filename_save);
                    return_to_main_menu(participants, count);
                    break;
                case 2:
                    save_to_file(participants, count, filename_save);
                    return_to_main_menu(participants, count);
                    break;
            }
            break;
        }

        case 7:
        {
            clear_window();
            print_menu(file_type_menu);
            int file_type_choice;
            file_type_choice = get_validated_int(
                file_type_menu.invalid_choice, 
                [](int choice){ return choice >= 1 && choice <= 2; }
            );
            clear_window();
            std::string filename; 
            std::cout << "Въведете име на файла: ";
            std::getline(std::cin, filename);
            switch (file_type_choice)
            {
                case 1:
                    load_from_text_file(participants, count, filename);
                    break;
                case 2:
                    load_from_file(participants, count, filename);
                    break;
            }
            break;
        }
        case 8:
            display_submenu(participants, count);
            break;
        case 9:
            categorize_and_display_participants(participants, count);
            break;
        case 10:
            categorize_and_determine_winners(participants, count);
            break;
        case 11:
            save_to_file(participants, count, exit_filename);
            exit(0);
    }
}

void handle_submenu_choice(const Menu &menu, const int &choice, Participant participants[], int& count)
{
    switch (choice)
    {
        case 1:
        {
            clear_window();
            Participant tempParticipants[MAX_PARTICIPANTS];
            deep_copy_participants(participants, tempParticipants, count);
            sort_participants_by_name(tempParticipants, count);
            sort_participants_by_age(tempParticipants, count);
            display_participants(tempParticipants, count);
            delete[] tempParticipants;
            break;
        }

        case 2:
        {
            clear_window();
            std::cout << "Въведете възраст: ";
            int age = get_validated_int("Невалидна възраст ", [](int age){ return age > 0; });
            std::cout << "Потвърдете(Натиснете Enter)...\n";
            clear_window();
            std::string gender = 
                get_validated_int("Въведете пол(M[0] F[1]): ", 
                    [](int gender){ return gender == 0 || gender == 1;}
                ) == 0 ? "M" : "F";
            clear_window();
            search_participants_by_age_and_gender(participants, count,age, gender);
            return_to_main_menu(participants, count);
            break;
        }

        case 3:
            display_menu(participants, count);
            break;
    }
}

void return_to_main_menu(Participant participants[], int& count)
{
    std::cout << '\n';
    std::cout << "Натисни Enter...";
    std::string placeholder;
    getline(std::cin, placeholder);
    display_menu(participants, count);
}