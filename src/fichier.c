//
// Created by grego on 02/11/2023.
//

#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************************/
/*                                 CELL                                           */
/**********************************************************************************/

t_d_cell *create_cell(int value, int level) {

    t_d_cell *cell = (t_d_cell*) malloc(sizeof(t_d_cell));
    cell->value = value;
    cell->level = level;
    cell->next = (t_d_cell**) malloc(sizeof(t_d_cell*) * level);

    return cell;
}

void display_cell(t_d_cell* cell) {
    for(int i = 0; i < cell->level; i++) {
        printf("[ %d|@ ]->\n", cell->value);
    }
}

/**********************************************************************************/
/*                                 LIST                                           */
/**********************************************************************************/


t_d_list *create_list(int max_level) {

    t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));
    list->max_level = max_level;
    list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_level);

}

void display_list(t_d_list* list) {

    for(int i = 0; i < list->max_level; i++) {
        printf("[list head_%d @-]--> \n", i);
    }

}