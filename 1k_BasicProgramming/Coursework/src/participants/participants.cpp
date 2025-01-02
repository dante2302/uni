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
#include "../sorting/sorting.h"


using namespace std;

Participant participants[MAX_PARTICIPANTS];

void add_participants(int &count)
{
    clear_window();

    if (count == MAX_PARTICIPANTS)
    {
        cout << "Списъкът е пълен.";
        return_to_main_menu();
    }

    cout << "Брой на участници за добавяне: ";

    int n = get_validated_int(
        "Невалидно!Може да се добавят до " + 
        to_string(MAX_PARTICIPANTS - count) + 
        " участници" + '\n' + "Опитай пак: ",
        [count](int n)
        { return count + n <= MAX_PARTICIPANTS; }
    );

    clear_window();

    srand(time(0));
    for (int i = 0; i < n; ++i)
    {
        // Participant p;
        // std::cout << "Enter details for participant " << "#" << (count + 1) << ":\n";
        // p.id = count + 1;

        // std::cout << "Name: ";
        // std::getline(std::cin, p.name);

        // std::cout << "Age: ";
        // p.age = get_validated_int("Invalid. Try Again: ");

        // std::cout << "Gender: ";
        // std::cin >> p.gender;

        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // cin.clear();

        // std::cout << "Thigh circumference: ";
        // p.thigh = get_validated_int("Invalid. Try Again: ");

        // std::cout << "Shoulder circumference: ";
        // p.shoulder = get_validated_int("Invalid. Try Again: ");

        // std::cout << "Neck circumference: ";
        // p.neck = get_validated_int("Invalid. Try Again: ");

        // std::cout << "Calf circumference: ";
        // p.calf = get_validated_int("Invalid. Try Again: ");

        // participants[count] = p;
        // count++;
        // clear_window();
        participants[count] = generate_random_participant(count + 1);
        count++;
    }
    return_to_main_menu();
}


void print_separator_line() {
    std::cout << std::setw(5) << std::setfill('-') << ""  // ID
              << std::setw(15) << ""  // Name
              << std::setw(10) << ""  // Age
              << std::setw(10) << ""  // Gender
              << std::setw(10) << ""  // Thigh
              << std::setw(10) << ""  // Shoulder
              << std::setw(10) << ""  // Neck
              << std::setw(10) << ""  // Calf
              << std::setfill(' ')  // Reset the fill character to space
              << std::endl;
}

void display_participants()
{
    clear_window();

    if (participants[0].id == 0)
    {
        cout << "Няма въведени участници\n";
        return_to_main_menu();
        return;
    }

    std::cout << std::setw(5) << std::left << "ID"
              << std::setw(15) << std::left << "Име"
              << std::setw(10) << std::left << "Възраст"
              << std::setw(10) << std::left << "Пол"
              << std::setw(10) << std::left << "Бедро"
              << std::setw(10) << std::left << "Рамо"
              << std::setw(10) << std::left << "Врат"
              << std::setw(10) << std::left << "Прасец"
              << std::endl;

    for (const auto &p : participants)
    {
        if (p.id == 0)
            return_to_main_menu();
        print_separator_line();
        std::cout << std::setw(5) << std::left << p.id
                  << std::setw(15) << std::left << p.name
                  << std::setw(10) << std::left << p.age
                  << std::setw(10) << std::left << p.gender
                  << std::setw(10) << std::left << p.thigh
                  << std::setw(10) << std::left << p.shoulder
                  << std::setw(10) << std::left << p.neck
                  << std::setw(10) << std::left << p.calf
                  << std::endl;
    }

    return_to_main_menu();
}

void sort_participants(const int &count)
{
    if(count == 0)
    {
        cout << "Няма участници за сортиране.\n";
        return_to_main_menu();
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

    return_to_main_menu();
}

void printParticipants(const Participant arr[], int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "Име: " << arr[i].name << ", Възраст: " << arr[i].age << '\n';
    }
}

Participant generate_random_participant(int count)
{
    Participant p;
    p.id = count;
    p.name = to_string(rand() % 10 * 10);
    p.age = rand() % 101;
    p.gender = "m";
    p.calf = rand() % 101;
    p.neck = rand() % 101;
    p.shoulder = rand() % 101;
    p.thigh = rand() % 101;

    return p;
}
void save_to_file(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Неуспешен опит за отваряне на файл за запис.\n";
        return;
    }

    int activeCount = 0;
    for (int i = 0; i < MAX_PARTICIPANTS; i++) {
        if (participants[i].id != 0) {
            activeCount++;
        }
    }

    file.write(reinterpret_cast<const char*>(&activeCount), sizeof(activeCount));

    for (int i = 0; i < MAX_PARTICIPANTS; i++) {
        if (participants[i].id != 0) {
            file.write(reinterpret_cast<const char*>(&participants[i]), sizeof(Participant));
        }
    }

    std::cout << "Данните са записани в " << filename << ".\n";
}

void load_from_file(int& count, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Неуспешен опит за отваряне на файл за четене.\n";
        return;
    }

    // Debug: File opened
    std::cout << "Файлът е отворен успешно: " << filename << "\n";

    // Read the count of participants
    file.read(reinterpret_cast<char*>(&count), sizeof(count));
    if (!file) {
        std::cerr << "Грешка при четене на броя участници. Файлът може да е повреден.\n";
        return;
    }

    // Debug: Validate the count
    std::cout << "Брой участници в записа: " << count << "\n";

    if (count < 0 || count > MAX_PARTICIPANTS) {
        std::cerr << "Невалиден брой участници в записа: " << count << ". Коригираме до " << MAX_PARTICIPANTS << ".\n";
        count = std::max(0, std::min(count, MAX_PARTICIPANTS));
    }

    // Clear the participants array
    std::fill(std::begin(participants), std::end(participants), Participant{});

    // Read participant data
    file.read(reinterpret_cast<char*>(participants), sizeof(Participant) * count);
    if (!file) {
        std::cerr << "Грешка при четене на данните за участниците. Файлът може да е повреден.\n";
        count = 0;  // Reset count if data is incomplete
        return;
    }

    // Debug: Validate participants
    for (int i = 0; i < count; ++i) {
        std::cout << "Участник " << i + 1 << ": ID=" << participants[i].id
                  << ", Име=" << participants[i].name
                  << ", Възраст=" << participants[i].age << "\n";
    }

    std::cout << "Данните са заредени успешно от " << filename << ".\n";
}