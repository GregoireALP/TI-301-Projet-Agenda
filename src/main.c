#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "fichier.h"
#include "timer.h"

char *menu = "    _                        _       \n"
             "   / \\   __ _  ___ _ __   __| | __ _ \n"
             "  / _ \\ / _  |/ _ \\  _ \\ / _  |/ _  |\n"
             " / ___ \\ (_| |  __/ | | | (_| | (_| |\n"
             "/_/   \\_\\__, |\\___|_| |_|\\__,_|\\__,_|\n"
             "        |___/";

int main() {

    /**********************************************************************************/
    /*                               PARTIE 1                                         */
    /**********************************************************************************/


    /********************************CELLS DEMOS****************************************/

    int my_cell_value = 5;
    int my_cell_level = 3;
    t_d_cell* my_cell = create_cell(my_cell_value, my_cell_level);
    //display_cell(my_cell);


    /********************************LISTS DEMOS****************************************/

    // Empty List Demo
    int my_empty_list_level = 5;
    t_d_list* my_empty_list = create_list(my_empty_list_level);
   //display_list(my_empty_list);

    // Insert Cell Demo
    int my_list_level = 6;
    t_d_list* my_list = create_list(my_list_level);
    insert_cell(3, 3, my_list);
    insert_cell(5, 2, my_list);
    insert_cell(4, 3, my_list);
    insert_cell(7, 4, my_list);
    //display_list(my_list);


    /**********************************************************************************/
    /*                               PARTIE 2                                         */
    /**********************************************************************************/

    /********************************CELLS DEMOS***************************************/

    // Classical search method
    t_d_cell *cell = search_cell_classic(7, my_list);
    //printf("Found cell with value %d and level %d\n", cell->value, cell->level);

    // Optimal search method
    t_d_cell *cell_2 = search_cell_optimal(7, my_list);
    //printf("Found cell with value %d and level %d\n", cell_2->value, cell_2->level);



    /********************************CLASSIC SEARCH DEMOS******************************/

    t_d_list * my_classical_test_list = create_list(1);
    int* values_for_1000 = (int*)malloc(1000*sizeof(int));
    int* values_for_10000 = (int*)malloc(10000*sizeof(int));
    int* values_for_100000 = (int*)malloc(10000*sizeof(int));

    for(int i = 0; i < 1000; i++) {
        insert_cell(i, 1, my_classical_test_list);
    }

    startTimer();

    t_d_cell * my_classical_test_cell = search_cell_classic(999, my_classical_test_list);

    stopTimer();
    displayTime();


    return 0;
}