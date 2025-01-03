#include "./menu/menu.h"
#include "./participants/participants.h"
#include "./utils/utils.h"
#include "globals.h"
#include <iostream>
#include <string>


int main()
{
    system("chcp 65001");
    Participant participants[MAX_PARTICIPANTS];
    int count = 0;

    // Load on startup
    clear_window();
    load_from_file(participants, count, exit_filename);
    display_menu(participants, count);
    return 0;
}