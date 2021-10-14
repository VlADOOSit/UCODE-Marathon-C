#include "../inc/header.h"

void print_string(WINDOW* win) {

    char text1[] = "Wake up , Neo..";
    char text2[] = "The Matrix has you..";
    char text3[] = "Follow the white rabbit";
    char text4[] = "Knock, knock, Neo";


    for (int i = 0; i < 15; i++) {
        mvwaddch(win, 2, 2 + i, text1[i]);
        refresh();
        usleep(200000);
    }
    wclear(win);
    usleep(100000);
    

    for (int i = 0; i < 20; i++) {
        mvwaddch(win, 2, 2 + i, text2[i]);
        refresh();
        usleep(200000);
    }
    wclear(win);
    usleep(100000);
    for (int i = 0; i < 23; i++) {
        mvwaddch(win, 2, 2 + i, text3[i]);
        refresh();
        usleep(200000);
    }
    wclear(win);
    usleep(100000);
    for (int i = 0; i < 17; i++) {
        mvwaddch(win, 2, 2 + i, text4[i]);
        refresh();
        usleep(200000);
    }
}
