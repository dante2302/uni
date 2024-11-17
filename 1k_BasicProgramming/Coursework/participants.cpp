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
}

void displayParticipants() {
    std::cout << setw(5) << "ID" << setw(15) << "Name" << setw(5) << "Age" << setw(5) << "Gender"
         << setw(10) << "Thigh" << setw(10) << "Shoulder" << setw(10) << "Neck" << setw(10) << "Calf" << endl;

    for (const auto& p : participants) {
        std::cout << setw(5) << p.id << setw(15) << p.name << setw(5) << p.age << setw(5) << p.gender
             << setw(10) << p.thigh << setw(10) << p.shoulder
             << setw(10) << p.neck << setw(10) << p.calf << endl;
    }
}
