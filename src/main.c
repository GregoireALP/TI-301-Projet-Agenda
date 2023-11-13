#include <stdio.h>
#include "fichier.h"

int main() {


    char *menu = "    _                        _       \n"
                 "   / \\   __ _  ___ _ __   __| | __ _ \n"
                 "  / _ \\ / _  |/ _ \\  _ \\ / _  |/ _  |\n"
                 " / ___ \\ (_| |  __/ | | | (_| | (_| |\n"
                 "/_/   \\_\\__, |\\___|_| |_|\\__,_|\\__,_|\n"
                 "        |___/";


    /**********************************************************************************/
    /*                               CELLS DEMOS                                      */
    /**********************************************************************************/

    int myCellValue = 5;
    int myCellLevel = 3;
    t_d_cell* myCell = create_cell(myCellValue, myCellLevel);
    //display_cell(myCell);


    /**********************************************************************************/
    /*                               LISTS DEMOS                                      */
    /**********************************************************************************/

    // Empty List Demo
    int myEmptyListLevel = 5;
    t_d_list* myEmptyList = create_list(myEmptyListLevel);
   //display_list(myEmptyList);

    // Insert Cell Demo
    insert_cell(3, 3, myEmptyList);
    insert_cell(5, 2, myEmptyList);
    insert_cell(4, 3, myEmptyList);
    insert_cell(7, 4, myEmptyList);
    //display_list(myEmptyList);
    printf("%s\n", menu);

    return 0;
}