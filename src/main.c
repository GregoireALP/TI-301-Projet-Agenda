#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

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

    /**
    int my_cell_value = 5;
    int my_cell_level = 3;
    t_d_cell* my_cell = create_cell(my_cell_value, my_cell_level);
    display_cell(my_cell);
    */

    /********************************LISTS DEMOS****************************************/

    /**
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
    insert_cell(6, 6, my_list);
    display_list(my_list);
    */







    /**********************************************************************************/
    /*                               PARTIE 2                                         */
    /**********************************************************************************/


    /********************************CELLS DEMOS***************************************/

    /**
    // Classical search method
    t_d_cell *cell = search_cell_classic(10, my_list);
    if(cell != NULL) {
        printf("Found cell with value %d and level %d\n", cell->value, cell->level);
    } else {
        printf("Cell not found\n");
    }

    // Optimal search method
    t_d_cell *cell_2 = search_cell_optimal(10, my_list);
    if(cell_2 != NULL) {
        printf("Found cell with value %d and level %d\n", cell_2->value, cell_2->level);
    } else {
        printf("Cell not found\n");
    }
    */



    /********************************SEARCH DEMOS******************************/


    int n = 13;
    t_d_list* my_list_2 = create_list(n);

    int* levels = calloc(pow(2, n) - 1, sizeof(int));
    for(int i = 0; i < pow(2, n) - 1; i++) {

        int level = 0;
        int tmp = i + 1;
        while(tmp % 2 == 0) {
            tmp = tmp / 2;
            level++;
        }

        levels[i] = level;
    }

    for(int i = 0; i < pow(2, n) - 1; i++) {
        insert_cell(i, levels[i] + 1, my_list_2);
    }

    // MAX = 8192
    int value_to_search = 4539;

    //************CLASSIC SEARCH************//
    startTimer();
    t_d_cell* cell_to_search = search_cell_classic(value_to_search, my_list_2);
    if(cell_to_search != NULL) {
        printf("[CLASSICAL] Found cell with value %d and level %d\n", cell_to_search->value, cell_to_search->level);
    } else {
        printf("Cell not found\n");
    }
    stopTimer();
    displayTime();
    printf("\n");

    //************OPTIMAL SEARCH************//
    startTimer();
    t_d_cell* cell_to_search_2 = search_cell_optimal(value_to_search, my_list_2);
    if(cell_to_search_2 != NULL) {
        printf("[OPTIMAL] Found cell with value %d and level %d\n", cell_to_search_2->value, cell_to_search_2->level);
    } else {
        printf("Cell not found\n");
    }
    stopTimer();
    displayTime();
    printf("\n");



    /**********************************************************************************/
    /*                               APPLICATION                                      */
    /**********************************************************************************/

    t_input_list* MAIN_LIST = create_input_list(4);
    int app_state = 0;

    // read the text file in ../libs/data/noms2008nat_txt.txt in wich each line is a lastName, take 1000 lastName randomly and add them to the list
    FILE *file = fopen("../libs/data/noms2008nat_txt.txt", "r");
    char line[256];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        if (i < 1000) {
            char *lastName = malloc(sizeof(char) * 256);
            strcpy(lastName, line);
            lastName[strlen(lastName) - 1] = '\0';
            t_contact *contact = create_contact("John", lastName);
            insert_input(contact, MAIN_LIST);
            i++;
        }
    }

    fclose(file);


    while (app_state == 1) {

            scanf("");

            printf("%s\n", menu);
            printf("%d contacts dans la liste\n", get_number_of_contacts(MAIN_LIST));
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