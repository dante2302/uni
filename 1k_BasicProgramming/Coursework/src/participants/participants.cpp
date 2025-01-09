#include "participants.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <ctime>

#include "../utils/utils.h"
#include "../menu/menu.h"
#include "../sorting/sorting.h"
#include "../validation/validation.h"
#include "../globals.h"

using namespace std;

void add_participants(Participant participants[], int &count, bool is_random)
{
    clear_window();

    if (count == MAX_PARTICIPANTS)
    {
        cout << "Списъкът е пълен.";
        return_to_main_menu(participants, count);
    }

    cout << "Брой на участници за добавяне: ";

    int n = get_validated_int(
        "Невалидно! Може да се добавят до " + 
        to_string(MAX_PARTICIPANTS - count) + 
        " участници" + '\n' + "Опитай пак: ",
        [count](int n)
        { return count + n <= MAX_PARTICIPANTS; }
    );

    clear_window();

    if(is_random){
        srand(time(0));

        for (int i = 0; i < n; ++i)
        {
            participants[count] = generate_random_participant(count + 1);
            count++;
        }
        return_to_main_menu(participants, count);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        Participant p;
        std::cout << "Enter details for participant " << "#" << (count + 1) << ":\n";
        p.id = count + 1;

        std::cout << "Name: ";
        std::getline(std::cin, p.name);

        std::cout << "Age: ";
        p.age = get_validated_int("Invalid. Try Again: ");

        std::cout << "Gender: ";
        std::cin >> p.gender;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();

        std::cout << "Thigh circumference: ";
        p.thigh = get_validated_int("Invalid. Try Again: ");

        std::cout << "Shoulder circumference: ";
        p.shoulder = get_validated_int("Invalid. Try Again: ");

        std::cout << "Neck circumference: ";
        p.neck = get_validated_int("Invalid. Try Again: ");

        std::cout << "Calf circumference: ";
        p.calf = get_validated_int("Invalid. Try Again: ");

        participants[count] = p;
        count++;
        clear_window();
    }
    return_to_main_menu(participants, count);
}

void print_separator_line(char separator, int width) {
    std::cout << std::setw(width) 
              << std::setfill(separator) << ""  
              << std::setfill(' ')  // reset the fill character to space
              << std::endl;
}

void display_participants(Participant participants[], int &count)
{
    clear_window();

    if (count == 0)
    {
        cout << "Няма въведени участници\n";
        return_to_main_menu(participants, count);
        return;
    }

    display_participant_field_names();

    for (int i = 0; i < count; ++i)
    {
        print_separator_line();
        display_participant_fields(participants[i]);
    }

    return_to_main_menu(participants, count);
}

void display_by_category(Category category)
{
    if (category.count == 0) {
        category.name == "Няма категория" 
        ? std::cout << "Няма участници без категория\n"
        : std::cout << "Няма участници в " << category.name << "\n";
        return;
    }
    else
    {
        std::cout << category.name << ":\n";
        display_participant_field_names();
        print_separator_line();
        for (int i = 0; i < category.count; ++i)
        {
            display_participant_fields(category.participants[i]);
            print_separator_line();
        }
    }
    std::cout << "\n";
};

void display_participant_field_names() {
    std::cout << std::setw(5)  << std::left << "ID"
              << std::setw(33) << std::left << "Име"
              << std::setw(22) << std::left << "Възраст"
              << std::setw(13) << std::left << "Пол"
              << std::setw(15) << std::left << "Бедро"
              << std::setw(14) << std::left << "Рамо"
              << std::setw(14) << std::left << "Врат"
              << std::setw(10) << std::left << "Прасец"
              << std::endl;
}

void display_participant_fields(const Participant &p) {
    std::cout << std::setw(5)  << std::left << p.id
              << std::setw(30) << std::left << (p.name.size() > 20 ? p.name.substr(0, 20) : p.name)
              << std::setw(15) << std::left << p.age
              << std::setw(10) << std::left << p.gender
              << std::setw(10) << std::left << p.thigh
              << std::setw(10) << std::left << p.shoulder
              << std::setw(10) << std::left << p.neck
              << std::setw(10) << std::left << p.calf
              << std::endl;
}

void deep_copy_participants(const Participant source[], Participant destination[], int count) {
    for (int i = 0; i < count; i++) {
        destination[i] = source[i]; // member-wise copy
    }
}

void sort_participants_by_name(Participant participants[], int &count)
{
    if (count == 0)
    {
        cout << "Няма участници за сортиране.\n";
        return_to_main_menu(participants, count);
    }
    cout << "Сортиране по име.\n";
    merge_sort<Participant>(
        participants,
        0,
        count - 1,
        [](const Participant &a, const Participant &b)
        {
            return a.name < b.name;
        }
    );
}

void sort_participants_by_age(Participant participants[], int &count)
{
    if (count == 0)
    {
        cout << "Няма участници за сортиране.\n";
        return_to_main_menu(participants, count);
    }
    cout << "Сортиране по възраст.\n";
    merge_sort<Participant>(
        participants,
        0,
        count - 1,
        [](const Participant &a, const Participant &b)
        {
            return a.age < b.age;
        }
    );
}

void search_participants_by_name(const Participant participants[], int count, const std::string& name) {

    Participant foundParticipants[MAX_PARTICIPANTS];
    int foundCount = 0;
    for (int i = 0; i < count; ++i) {
        if (participants[i].name == name) { 
            foundParticipants[foundCount++] = participants[i];
        }
    }

    if (!foundCount) {
        std::cout << "Няма намерени участници с това име.\n";
        return;
    }

    std::cout << "Участници с име " << name << ":\n";
    display_participant_field_names();
    for (int i = 0; i < foundCount; ++i) {
        print_separator_line();
        display_participant_fields(foundParticipants[i]);
    }
}

void search_participants_by_age_and_gender(const Participant participants[], int count, int age, const std::string& gender) {

    Participant foundParticipants[MAX_PARTICIPANTS];
    int foundCount = 0;
    for (int i = 0; i < count; ++i) {
        if (participants[i].age == age && participants[i].gender == gender) {
            foundParticipants[foundCount++] = participants[i];
        }
    }

    if (!foundCount) {
        std::cout << "Няма намерени участници с тези критерии.\n";
        return;
    }

    std::cout << "Участници с възраст " << age << " и пол " << gender << ":\n";

    display_participant_field_names();
    for (int i = 0; i < foundCount; ++i) {
        display_participant_fields(foundParticipants[i]);
    }
}

void sort_participants_by_P(Participant participants[], int &count)
{
    for (int i = 0; i < count; ++i) {
        participants[i].P = calculate_P(participants[i]);
    }

    merge_sort<Participant>(
        participants,
        0,
        count - 1,
        [](const Participant &a, const Participant &b)
        {
            return a.P > b.P; 
        }
    );
}

Participant generate_random_participant(int count) {
    Participant p;
    p.id = count;
    p.name = "Random_" + to_string(count);
    p.age = 14 + rand() % 12; // Age between 14 and 25
    p.gender = (rand() % 2 == 0) ? "M" : "F"; // Randomly choose between 'M' and 'F'
    
    p.calf = 40 + rand() % 81;  // calf between 40 and 120
    p.neck = 40 + rand() % 81;  // neck between 40 and 120
    p.shoulder = 40 + rand() % 81;  // shoulder between 40 and 120
    p.thigh = 40 + rand() % 81;  // thigh between 40 and 120
    
    return p;
}

void save_to_file(Participant participants[], int& count, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        std::cerr << "Грешка при отваряне\n";
        return_to_main_menu(participants, count);
    }

    ofs.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (int i = 0; i < count; ++i) {
        const Participant& p = participants[i];

        ofs.write(reinterpret_cast<const char*>(&p.id), sizeof(p.id));
        ofs.write(reinterpret_cast<const char*>(&p.age), sizeof(p.age));
        ofs.write(reinterpret_cast<const char*>(&p.thigh), sizeof(p.thigh));
        ofs.write(reinterpret_cast<const char*>(&p.shoulder), sizeof(p.shoulder));
        ofs.write(reinterpret_cast<const char*>(&p.neck), sizeof(p.neck));
        ofs.write(reinterpret_cast<const char*>(&p.calf), sizeof(p.calf));

        size_t name_length = p.name.size();
        ofs.write(reinterpret_cast<const char*>(&name_length), sizeof(name_length));
        ofs.write(p.name.c_str(), name_length);

        size_t gender_length = p.gender.size();
        ofs.write(reinterpret_cast<const char*>(&gender_length), sizeof(gender_length));
        ofs.write(p.gender.c_str(), gender_length);
    }

    ofs.close();

    std::cout << "Данните са записани успешно в " << filename << ".\n";
}

void load_from_file(Participant participants[], int& count, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        std::cerr << "Грешка при отваряне\n";
        return;
    }


    // Read the count of participants
    int count_for_read;
    if(MAX_PARTICIPANTS - count == 0) {
        std::cerr << "Няма повече място за участници.\n";
        return_to_main_menu(participants, count);
    }
    ifs.read(reinterpret_cast<char*>(&count_for_read), sizeof(count));
    if (!ifs) {
        std::cerr << "Грешка при четене на броя участници. Файлът може да е повреден.\n";
        return;
    }

    if(count_for_read < 0) {
        std::cerr << "Невалиден брой участници в записа: " << count_for_read << ".\n";
        return;
    }

    if (count_for_read > MAX_PARTICIPANTS - count) {
        std::cerr << "Невалиден брой участници в записа: " << count << ". Коригираме до " << MAX_PARTICIPANTS - count << ".\n";
        count_for_read = std::max(0, std::min(count_for_read, MAX_PARTICIPANTS - count));
    }

    for (int i = count; i < count_for_read; ++i) {
        Participant& p = participants[i];

        ifs.read(reinterpret_cast<char*>(&p.id), sizeof(p.id));
        ifs.read(reinterpret_cast<char*>(&p.age), sizeof(p.age));
        ifs.read(reinterpret_cast<char*>(&p.thigh), sizeof(p.thigh));
        ifs.read(reinterpret_cast<char*>(&p.shoulder), sizeof(p.shoulder));
        ifs.read(reinterpret_cast<char*>(&p.neck), sizeof(p.neck));
        ifs.read(reinterpret_cast<char*>(&p.calf), sizeof(p.calf));

        size_t name_length;
        ifs.read(reinterpret_cast<char*>(&name_length), sizeof(name_length));
        p.name.resize(name_length);
        ifs.read(&p.name[0], name_length);

        size_t gender_length;
        ifs.read(reinterpret_cast<char*>(&gender_length), sizeof(gender_length));
        p.gender.resize(gender_length);
        ifs.read(&p.gender[0], gender_length);
        count++;
    }

    ifs.close();

    std::cout << "Данните са заредени успешно от " << filename << ".\n";
    return_to_main_menu(participants, count);
}

void save_to_text_file(Participant participants[], int& count, const std::string& filename) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Грешка при отваряне на файла за запис\n";
        return;
    }

    // Write each participant's details in CSV format
    for (int i = 0; i < count; ++i) {
        const Participant& p = participants[i];
        
        ofs << p.id << ","
            << p.name << ","
            << p.age << ","
            << p.gender << ","
            << p.thigh << ","
            << p.shoulder << ","
            << p.neck << ","
            << p.calf << "\n";
    }

    std::cout << "Данните са записани успешно в " << filename << ".\n";
    ofs.close();
}

void load_from_text_file(Participant participants[], int& count, const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Грешка при отваряне на файла за четене\n";
        return;
    }

    std::string line;
    count = 0;

    // Read each line and parse it
    while (std::getline(ifs, line)) {
        std::istringstream ss(line);
        std::string field;

        Participant& p = participants[count];

        // Read and parse each field by separating by commas
        try {
            std::getline(ss, field, ','); p.id = std::stoi(field);
            std::getline(ss, field, ','); p.name = field;
            std::getline(ss, field, ','); p.age = std::stoi(field);
            std::getline(ss, field, ','); p.gender = field;
            std::getline(ss, field, ','); p.thigh = std::stod(field);
            std::getline(ss, field, ','); p.shoulder = std::stod(field);
            std::getline(ss, field, ','); p.neck = std::stod(field);
            std::getline(ss, field, ','); p.calf = std::stod(field);
        } catch (const std::exception& e) {
            std::cerr << "Грешка при четене на данни за участник: " << e.what() << "\n";
            continue; // Skip invalid data and continue with the next participant
        }

        ++count;

        // Check if we exceeded the max number of participants
        if (count >= MAX_PARTICIPANTS) {
            std::cerr << "Превишен максимален брой участници: " << MAX_PARTICIPANTS << ". Спираме четенето на данни.\n";
            break;
        }
    }

    ifs.close();

    // Handle the case where the number of participants read is invalid
    if (count < 0) {
        std::cerr << "Невалиден брой участници в записа: " << count << ".\n";
        return;
    }

    // If count exceeds the max number of participants, adjust it
    if (count > MAX_PARTICIPANTS) {
        std::cerr << "Невалиден брой участници в записа: " << count << ". Коригираме до " << MAX_PARTICIPANTS << ".\n";
        count = MAX_PARTICIPANTS;
    }

    // Print success message
    std::cout << "Данните са заредени успешно от " << filename << ".\n";

    // Call the function to return to the main menu (assuming it's defined elsewhere)
    return_to_main_menu(participants, count);
}

Category* categorize_participants(Participant participants[], int& count) {
    Category* results = new Category[5];

    int count_I = 0, count_II = 0, count_III = 0, count_IV = 0, count_no_category = 0;

    for (int i = 0; i < count; ++i) {
        if (participants[i].age >= 14 && participants[i].age <= 16) {
            results[0].participants[count_I++] = participants[i];
        } else if (participants[i].age >= 17 && participants[i].age <= 19) {
            results[1].participants[count_II++] = participants[i];
        } else if (participants[i].age >= 20 && participants[i].age <= 22) {
            results[2].participants[count_III++] = participants[i];
        } else if (participants[i].age >= 23 && participants[i].age <= 25) {
            results[3].participants[count_IV++] = participants[i];
        } else {
            results[4].participants[count_no_category++] = participants[i];
        }
    }

    // Set the count for each category
    results[0].count = count_I;
    results[1].count = count_II;
    results[2].count = count_III;
    results[3].count = count_IV;
    results[4].count = count_no_category;

    results[0].name = "I (14-16)";
    results[1].name = "II (17-19)";
    results[2].name = "III (20-22)";
    results[3].name = "IV (23-25)";
    results[4].name = "Няма категория";

    return results;
}

void categorize_and_display_participants(Participant participants[], int& count) {
    auto const categories = categorize_participants(participants, count);
    clear_window();
    for(int i = 0; i < 5; ++i) {
        display_by_category(categories[i]);
    }

    delete[] categories;  
    return_to_main_menu(participants, count);
}

double calculate_P(const Participant &p) {
    return p.thigh / (p.shoulder + p.neck + p.calf);
}

void assign_P(Participant participants[], int &count){
    for (int i = 0; i < count; ++i) {
        participants[i].P = calculate_P(participants[i]);
    }
}

void determine_winners_from_category(Category& category) {
    if (category.count == 0) {
        category.name == "Няма категория" 
        ? std::cout << "Няма участници без категория\n"
        : std::cout << "Няма участници в " << category.name << "\n";
        return;
    }

    Participant* participants = category.participants;
    int count = category.count;

    assign_P(participants, count);
    sort_participants_by_P(participants, count);

    print_separator_line('=');
    std::cout << "Победител в категория: " << category.name << "\n";

    double winning_P = participants[0].P;
    for (int i = 0; i < count; ++i) {
        double current_P = participants[i].P;

        // check if the current participant has the same P as the winner
        if (current_P == winning_P) {
            display_participant_field_names();
            display_participant_fields(participants[0]);
            std::cout <<  "\nP: " << current_P << "\n";
        }
        else break;
    }
    print_separator_line('=');
    std::cout << '\n';
}

void categorize_and_determine_winners(Participant participants[], int &count) {
    Category* categories = categorize_participants(participants, count);

    clear_window();
    for (int i = 0; i < 5; ++i)
        determine_winners_from_category(categories[i]);

    delete[] categories;  
    return_to_main_menu(participants, count);
}