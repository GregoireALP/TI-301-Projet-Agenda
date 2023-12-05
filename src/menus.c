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

    if(tmp == NULL) {
        printf("Aucun contact dans la liste.\n");
        return;
    }

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
        printf("Le contact n'existe pas, voulez vous le creer (0 = NON ; 1 = OUI)\n");
        int choice;
        scanf("%d", &choice);
        if((int) choice  == 1) {
            menu_add_contact(input_list);
        } else {
            return;
        }
    }

    printf("Entrer l'objet du rendez-vous : ");
    char* object = scan_string();

    printf("Entrer l'heure du rendez-vous : ");
    int hour;
    scanf("%d", &hour);

    if(hour < 0 || hour > 23) {
        printf("L'heure doit être comprise entre 0 et 23.\n");
        return;
    }

    printf("Entrer les minutes du rendez-vous : ");
    int minute;
    scanf("%d", &minute);

    if(minute < 0 || minute > 59) {
        printf("Les minutes doivent être comprises entre 0 et 59.\n");
        return;
    }

    printf("Entrer le jour du rendez-vous : ");
    int day;
    scanf("%d", &day);

    if(day < 1 || day > 31) {
        printf("Le jour doit être compris entre 1 et 31.\n");
        return;
    }

    printf("Entrer le mois du rendez-vous : ");
    int month;
    scanf("%d", &month);

    if(month < 1 || month > 12) {
        printf("Le mois doit être compris entre 1 et 12.\n");
        return;
    }

    printf("Entrer l'annee du rendez-vous : ");
    int year;
    scanf("%d", &year);

    if(year < 0) {
        printf("L'année doit être supérieure à 0.\n");
        return;
    }

    t_appointment* appointment = create_appointment(object, hour, minute, day, month, year);

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

int get_number_of_contacts(t_input_list* input_list) {

        int number_of_contacts = 0;

        for(int i = 0; i < input_list->max_level; i++) {

            t_input* tmp = input_list->heads[i];

            while(tmp != NULL) {
                number_of_contacts++;
                tmp = tmp->next;
            }
        }

        return number_of_contacts;
}