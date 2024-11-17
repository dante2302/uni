#include "participants.h"


using namespace std;

Participant participants[MAX_PARTICIPANTS];

void add_participants(int &count)
{
    if (count == MAX_PARTICIPANTS)
    {
        cout << "List is full";
        return;
    }
    cout << "How many participants to add: ";
    int n = get_validated_int(
        "Invalid! Can add up to " + to_string(MAX_PARTICIPANTS - count) + '\n' + "Try again: ",
        [count](int n)
        { return count + n <= MAX_PARTICIPANTS; }
    );
    cout << n;
    for (int i = 0; i < n; ++i)
    {
        Participant p;
        std::cout << "Enter details for participant " << (count + 1) << ":\n";
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
    }
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

void display_participants() {
    clear_window();

    if(participants[0].id == 0)
    {
        cout << "No Participants.\n";
        cout << "Press Enter To Return...";
        cin.get();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    std::cout << std::setw(5) << std::left << "ID"
              << std::setw(15) << std::left << "Name"
              << std::setw(10) << std::left << "Age"
              << std::setw(10) << std::left << "Gender"
              << std::setw(10) << std::left << "Thigh"
              << std::setw(10) << std::left << "Shoulder"
              << std::setw(10) << std::left << "Neck"
              << std::setw(10) << std::left << "Calf"
              << std::endl;
    // Print participant data with proper formatting
    for (const auto& p : participants) {
        if(p.id == 0) return;
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
}