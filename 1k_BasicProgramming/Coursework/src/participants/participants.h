#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

static const int MAX_PARTICIPANTS = 30;

#include <string>

struct Participant {
    int id;
    std::string name;
    int age;
    std::string gender;
    double thigh;
    double shoulder;
    double neck;
    double calf;
};

// Basic assignment
void add_participants(int& count);
void display_participants();
void sort_participants(const int &count);
// void print_participants(const std::vector<Participant>& participants);
// void find_youngest();
// void search_by_name(const std::vector<Participant>& participants, const std::string& name);
// void sort_by_age();
// void save_to_file(const std::vector<Participant>& participants, const std::string& filename);
// void load_from_file(std::vector<Participant>& participants, const std::string& filename);

#endif