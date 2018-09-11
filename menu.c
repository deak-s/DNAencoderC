



#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "conversionFunctions.h"
#include "encodingFunctions.h"
#include "menuCommands.h"

int main(){

//initalize scren

    initscr();
    curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);



    
    WINDOW *menu = newwin(6, 8*(xMax/10), yMax-12, (xMax / 10));
    box(menu, 0, 0);
    //use to be (ymax - 15, 4, "choose type of input");
    mvprintw(3, (xMax/2) - 30, " ____  _   _    _                               _           ");
    mvprintw(4, (xMax/2) - 30, "|  _ \\| \\ | |  / \\      ___ _ __   ___ ___   __| | ___ _ __ ");
    mvprintw(5, (xMax/2) - 30, "| | | |  \\| | / _ \\    / _ \\ '_ \\ / __/ _ \\ / _` |/ _ \\ '__|");
    mvprintw(6, (xMax/2) - 30, "| |_| | |\\  |/ ___ \\  |  __/ | | | (_| (_) | (_| |  __/ |   ");
    mvprintw(7, (xMax/2) - 30, "|____/|_| \\_/_/   \\_\\  \\___|_| |_|\\___\\___/ \\__,_|\\___|_|   ");
    
    mvprintw(9, (xMax / 2) - 3, "by soph");

    mvwprintw( menu, 1, 3 * (xMax / 10) - 2, "~choose type of input~");
    refresh();
    wrefresh(menu);

    keypad(menu, true);

    const char *options[2];
    options[0] = "File";
    options[1] = "Keyboard";

    int choice;
    int selected = 0;

    while(1){
        for(int i = 0; i < 2; i++){
            if(i == selected){
                wattron(menu, A_REVERSE);
            }
            
            mvwprintw(menu, i+3, (xMax-18) / 2, options[i]);
            wattroff(menu, A_REVERSE);

        }
        choice = wgetch(menu);

        switch(choice){
            case KEY_UP:
                selected--;
                if(selected == -1){
                    selected = 0; }
                break;
            case KEY_DOWN:
                selected++;
                if(selected == 2){
                    selected = 1; }
                break;
            default:
                break;
        }
        if(choice == 10){
            break;
        }
    }

    clear();
    refresh();


    if(selected == 0){
        char name[50];
        curs_set(1);
        mvprintw(yMax /2, (xMax/2) - 8, "enter file name: ");
        getstr(name);
        mvprintw(yMax /3, xMax/2, "%s", name);
        clear();
        refresh();
        encodeFile(name);

        getch();

        clear();
        refresh();

        char response;

        do{
            mvprintw(yMax /2, (xMax/2) - 10, "would you like to save results? (y/n)");
            response = getch();

            if(response == 'y'){
                break;
            }
            else if(response == 'n'){
                remove("results.txt");
                break;
            }
            clear();
            refresh();
        } while (response != 'y' || response != 'n');
    }

    if(selected == 1){


    }


    endwin();

    return 0;
}
