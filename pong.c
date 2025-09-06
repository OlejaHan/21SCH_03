
// Отрисовка только рамки поля 80x25 (ASCII).

#include <stdio.h>

enum { FIELD_X = 80, FIELD_Y = 25 };

static void clear_screen(void) {
    /* Очистка экрана и позиционирование курсора (ANSI) */
    printf("\033[H\033[J");
}

static void draw_field(void) {
    clear_screen();


    // проходимся по высоте поля
    int y = 0;
    while (y < FIELD_Y) {

        // проходимся про длине поля
        int x = 0;
        while (x < FIELD_X) {

            char ch = ' ';
            // если мы в позиции верхней или нижней границы
            if (y == 0 || y == (FIELD_Y - 1)) {
                /* верх/низ рамки/угол рамки */
                ch = (x == 0 ||  x == (FIELD_X - 1)) ? (int) 35 : '=';
            } else if (x == 0 || x == (FIELD_X - 1)) {
                /* боковые стенки */
                ch = (int) 35;
            } else {
                // находимся внутри поля
                if (x == 39)
                {
                    /* середина поля */
                    ch = (int) 58;
                }
                
                //ch = (int) 60;
            }
            putchar(ch);
            x = x + 1;
        }
        putchar('\n');
        y = y + 1;
    }
}

int main(void) {
    draw_field();
    return 0;
}