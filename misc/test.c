#include <stdio.h>
#include <curses.h>

int main(int argc, char *argv[])
{
    system("clear");
    printf("Test program: %s\n", argv[0]);
    getch();
    //endwin();
    return 0;
}
