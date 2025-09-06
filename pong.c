
// Отрисовка только рамки поля 80x25 (ASCII).

#include <stdio.h>

/*  длина поля по Х
    длина поля по У
    длина палки игрока

*/
enum { FIELD_X = 80, FIELD_Y = 25, PLAYER_LENGHT = 4 };

static void clear_screen(void) {
    /* Очистка экрана и позиционирование курсора (ANSI) */
    printf("\033[H\033[J");
}

static void draw_field(int position_1, int position_2) {
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
                ch = (x == 0 ||  x == (FIELD_X - 1)) ? '.' : '=';
            } else if (x == 0 || x == (FIELD_X - 1)) {
                /* боковые стенки */
                ch = '|';
            } else {
                // находимся внутри поля

                // рисуем середину поля
                //ch = x == ((FIELD_X-2)/2) ? ':';
                if (x == ((FIELD_X-2)/2)){
                    ch = ':';
                }
                
                
                // отрисовываем положение игрока 1
                if (x == 2 && (y >= position_1 && y <= (position_1 + PLAYER_LENGHT))){
                    ch = '!';
                }


                // отрисовываем положение игрока 1
                if (x == 2 && (y >= position_2 && y <= (position_2 + PLAYER_LENGHT))){
                    ch = '!';
                }


            }
            putchar(ch);
            x = x + 1;
        }
        putchar('\n');
        y = y + 1;
    }
}

int main(void) {

    // начальные позиции игроков
    int player_1_pos_y = 2, player_2_pos_y = 10;

    draw_field(player_1_pos_y, player_2_pos_y);
    return 0;
}