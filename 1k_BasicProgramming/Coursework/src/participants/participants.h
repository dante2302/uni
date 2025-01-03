#ifndef PARTICIPANTS_H
#define PARTICIPANTS_H

#include <string>
#include "../globals.h"

struct Participant {
    int id;
    std::string name;
    int age;
    std::string gender;
    double thigh;
    double shoulder;
    double neck;
    double calf;
    double P;
};

struct Category {
    Participant participants[MAX_PARTICIPANTS];
    int count;
    std::string name;
};

// Basic assignment
void add_participants(Participant participants[], int& count);
void print_separator_line(char separator='-', int width=100);
void display_participants(Participant participants[], int& count);
void display_participant_fields(const Participant &p);
void display_participant_field_names();
void search_participants_by_name(const Participant participants[], int count, const std::string& name);
Participant generate_random_participant(int count);
void save_to_file(Participant participants[], int& count, const std::string& filename);
void load_from_file(Participant participants[], int& count, const std::string& filename);
void load_from_text_file(Participant participants[], int& count, const std::string& filename);
void save_to_text_file(Participant participants[], int& count, const std::string& filename);

// Additional 1
void deep_copy_participants(const Participant source[], Participant destination[], int count);
void search_participants_by_age_and_gender(const Participant participants[], int count, int age, const std::string& gender);
void sort_participants_by_age(Participant participants[], int& count);
void sort_participants_by_name(Participant participants[], int &count);

// Additional 2
Category* categorize_participants(Participant participants[], int& count);
void categorize_and_display_participants(Participant participants[], int& count);
void display_by_category(Category category);
double calculate_P(const Participant &p);
void assign_P(Participant participants[], int &count);
void determine_winners_from_category(Category& category);
void categorize_and_determine_winners(Participant participants[], int &count);
#endif