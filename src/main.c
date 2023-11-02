#include <stdio.h>
#include "fichier.h"

int main() {

    int value = 10;
    int level = 3;

    t_d_cell *cell = create_cell(value, level);
    display_cell(cell);

    t_d_list *list = create_list(4);
    display_list(list);

    return 0;
}