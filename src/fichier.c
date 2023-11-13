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

    for(int i = 0; i < level; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}

void display_cell(t_d_cell* cell) {

    for(int i = 0; i < cell->level; i++) {
        printf("[ %d|@ ]-->\n", cell->value);
    }

    return;
}

/**********************************************************************************/
/*                                 LIST                                           */
/**********************************************************************************/


t_d_list *create_list(int max_level) {

        t_d_list *list = (t_d_list*) malloc(sizeof(t_d_list));

        list->max_level = max_level;
        list->heads = (t_d_cell**) malloc(sizeof(t_d_cell*) * max_level);

        for(int i = 0; i < max_level; i++) {

            list->heads[i] = NULL;

        }

        return list;
}

void display_list(t_d_list* list) {

    for(int i = 0; i < list->max_level; i++) {

        printf("[head_%d -@]-->", i);
        t_d_cell *tmp = list->heads[i];

        while(tmp != NULL) {

            printf("[ %d|@ ]-->", tmp->value);
            tmp = tmp->next[i];

        }

        printf("NULL\n");

    }

}

    /**********************************************************************************/
    /*                                 ACTIONS                                        */
    /**********************************************************************************/


void insert_cell(int value , int level, t_d_list* list) {

    t_d_cell *cell = create_cell(value, level);

    // For each level of the list
    for(int i = 0; i < level; i++) {

        // If the list is empty
        if(list->heads[i] == NULL) {

            // Insert the cell at the beginning of the list
            list->heads[i] = cell;

        } else {

            // If the cell have to be insert at the beginning of the list
            if(list->heads[i]->value > value) {

                // Insert the cell at the beginning of the list
                cell->next[i] = list->heads[i];
                list->heads[i] = cell;

            } else {

                // If the cell have to be insert in the middle of the list
                t_d_cell *tmp = list->heads[i];

                while(tmp->next[i] != NULL && tmp->next[i]->value < value) {

                    tmp = tmp->next[i];

                }

                // Insert the cell in the middle of the list
                cell->next[i] = tmp->next[i];
                tmp->next[i] = cell;

            }

        }

    }

    return;
}
