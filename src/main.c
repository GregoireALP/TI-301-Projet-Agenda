#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "fichier.h"
#include "models.h"
#include "timer.h"
#include "menus.h"
#include "app.h"

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

    for(int i = 1; i > 0; i--) {
        insert_cell(i, 1, my_classical_test_list);
    }

    // startTimer();

    t_d_cell * my_classical_test_cell = search_cell_classic(99999, my_classical_test_list);

    // stopTimer();
    // printf("%d", my_classical_test_cell->value);

    //displayTime();





    /**********************************************************************************/
    /*                               APPLICATION                                      */
    /**********************************************************************************/

    t_input_list* MAIN_LIST = create_input_list(4);
    int app_state = 1;

    while (app_state == 1) {

            scanf("");

            printf("%s\n", menu);
            printf("1. Ajouter un contact\n");
            printf("2. Chercher un contact\n");
            printf("3. Afficher les contacts\n");
            printf("4. Ajouter un rendez-vous\n");
            printf("5. Affichez les rendez vous\n");
            printf("6. Quitter\n");

            int choice = 0;
            scanf("%d", &choice);

            switch (choice) {

                case 1: {
                    menu_add_contact(MAIN_LIST);
                    break;
                }

                case 2: {
                    menu_find_contact(MAIN_LIST);
                    break;
                }

                case 3: {
                    menu_display_all_contacts(MAIN_LIST);
                    break;
                }

                case 4 : {
                    menu_add_appointment(MAIN_LIST);
                    break;
                }

                case 5: {
                    menu_display_appointment(MAIN_LIST);
                    break;
                }

                case 6: {
                    app_state = 0;
                    break;
                }

                default: {

                    printf("Choix invalide\n");
                    break;
                }
            }
    }

    return 0;
}