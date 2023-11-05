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

    // Set all next pointers to NULL
    cell->next = (t_d_cell**) malloc(sizeof(t_d_cell*) * level);
    for(int i = 0; i < level; i++) {

        cell->next[i] = NULL;
    }

    return cell;
}

void display_cell(t_d_cell* cell) {

    // For each level in the cell
    for(int i = 0; i < cell->level; i++) {

        printf("[ %d|@ ]-->\n", cell->value);

    }
}

/**********************************************************************************/
/*                                 LIST                                           */
/**********************************************************************************/


t_d_list *create_list(int max_level) {

    t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));
    list->max_level = max_level;

    // Set all heads pointers to NULL
    list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_level);
    for(int i = 0; i < list->max_level; i++) {
        list->heads[i] = NULL;
    }

    return list;
}

void display_list(t_d_list* list) {
    
    // Pour chaque niveaux
    for(int i = 0; i < list->max_level; i++) {

        printf("[list head_%d] @-]-->", i);
        t_d_cell * tmp = list->heads[i];

        if(tmp != NULL) {
            while(tmp->next != NULL) {
                printf("[ %d|@ ]-->", tmp->value);
                tmp = tmp->next;
            }
        }

        printf("NULL\n");
    }

}

    /**********************************************************************************/
    /*                                 ACTIONS                                        */
    /**********************************************************************************/

void insert_cell(t_d_cell* cell, t_d_list* list) {

}
