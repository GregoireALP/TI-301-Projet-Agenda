//
// Created by grego on 04/12/2023.
//

#ifndef TI_301_PROJET_AGENDA_MENUS_H
#define TI_301_PROJET_AGENDA_MENUS_H

#include "models.h"

void menu_add_contact(t_input_list* input_list);

void menu_find_contact(t_input_list* input_list);

void menu_add_appointment(t_input_list* input_list);

void menu_display_contact(t_contact* contact);

void menu_display_appointment(t_input_list* input_list);

void menu_display_all_contacts(t_input_list* input_list);

int get_number_of_contacts(t_input_list* input_list);


#endif //TI_301_PROJET_AGENDA_MENUS_H
