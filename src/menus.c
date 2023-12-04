//
// Created by grego on 04/12/2023.
//

#include "menus.h"
#include "models.h"
#include <stdio.h>

void menu_display_contact(t_contact* contact) {

    printf("Nom : %s\n", contact->last_name);
    printf("Prénom : %s\n", contact->first_name);

    return;
}

void menu_add_contact(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    printf("Entrer le prénom du contact : ");
    char* first_name = scan_string();

    t_contact* contact = create_contact(first_name, last_name);

    insert_input(contact, input_list);

    return;
}


void menu_find_contact(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n");
    } else {
        menu_display_contact(input->contact);
    }

    return;
}

void menu_display_all_contacts(t_input_list* input_list) {

    // Display contact on level 0
    t_input* tmp = input_list->heads[0];

    while(tmp != NULL) {
        menu_display_contact(tmp->contact);
        tmp = tmp->next;
    }

    return;
}

void menu_add_appointment(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n");
        return;
    }

    printf("Entrer l'objet du rendez-vous : ");
    char* object = scan_string();

    printf("Entrer l'heure du rendez-vous : ");
    char* hour = scan_string();

    printf("Entrer les minutes du rendez-vous : ");
    char* minute = scan_string();

    printf("Entrer le jour du rendez-vous : ");
    char* day = scan_string();

    printf("Entrer le mois du rendez-vous : ");
    char* month = scan_string();

    printf("Entrer l'année du rendez-vous : ");
    char* year = scan_string();

    t_appointment* appointment = create_appointment(object, (int) hour, (int) minute, (int) day, (int) month, (int) year);

    insert_appointment(appointment, input);

    return;
}

void menu_display_appointment(t_input_list* input_list) {

    printf("Entrer le nom de famille du contact : ");
    char* last_name = scan_string();

    t_input* input = find_contact(last_name, input_list);

    if(input == NULL) {
        printf("Le contact n'existe pas.\n");
        return;
    }

    t_appointment* tmp = input->appointments;

    while(tmp != NULL) {
        printf("Objet : %s\n", tmp->object);
        printf("Heure : %d:%d\n", tmp->date_hour, tmp->date_minute);
        printf("Date : %d/%d/%d\n", tmp->date_day, tmp->date_month, tmp->date_year);
        tmp = tmp->next;
    }

    return;
}