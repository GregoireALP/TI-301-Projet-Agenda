#include <stdio.h>
#include "fichier.h"

int main() {

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

    return 0;
}