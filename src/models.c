//
// Created by grego on 13/11/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "models.h"

/**********************************************************************************/
/*                                 UTILS                                          */
/**********************************************************************************/

/**
 * @return
 */
char* scan_string() {

        int max_size = 100;

        char* string = (char*) malloc(sizeof(char) * max_size);
        scanf("%s", string);

        return string;
}

/**
 * @param contact
 * @return
 */

char* get_name_formatted(t_contact* contact) {
    // Allocate memory for the new string
    char* name = (char*) malloc(sizeof(char) * (strlen(contact->last_name) + strlen(contact->first_name) + 2)); // +2 for the underscore and the null character

    // Copy the last name to the new string and convert to lowercase
    for(int i = 0; i < strlen(contact->last_name); i++) {
        name[i] = tolower(contact->last_name[i]);
    }
    name[strlen(contact->last_name)] = '\0'; // Ensure null-termination

    // Append the underscore
    strncat(name, "_", 1);

    // Append the first name and convert to lowercase
    for(int i = 0; i < strlen(contact->first_name); i++) {
        name[strlen(contact->last_name) + 1 + i] = tolower(contact->first_name[i]);
    }

    // Ensure the string is null-terminated
    name[strlen(contact->last_name) + strlen(contact->first_name) + 1] = '\0';

    return name;
}

int is_name_before(char* str1, char* str2) {

    // Check if str1 is before str2 alphabetically
    // Return 1 if true, 0 if false

    int i = 0;
    int j = 0;

    while(str1[i] != '\0' && str2[j] != '\0') {

        if(str1[i] < str2[j]) {
            return 1;
        } else if(str1[i] > str2[j]) {
            return 0;
        }

        i++;
        j++;
    }

    if(str1[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

t_input * find_contact(char* last_name, t_input_list* list) {

    // Find the contact in the list
    // Return the input if found, NULL otherwise

    for(int i = 0; i < list->max_level; i++) {

        t_input* tmp = list->heads[i];

        while(tmp != NULL) {

            if(strcmp(tmp->contact->last_name, last_name) == 0) {
                return tmp;
            }

            tmp = tmp->next;
        }

    }

    return NULL;

}

/**********************************************************************************/
/*                                 CONTACTS                                       */
/**********************************************************************************/

/**
 * @param first_name
 * @param last_name
 * @return
 */
t_contact* create_contact(char* first_name, char* last_name) {

    t_contact* contact = (t_contact*) malloc(sizeof(t_contact));

    contact->last_name = last_name;
    contact->first_name = first_name;

    return contact;

}


/**********************************************************************************/
/*                                 APPOINTMENTS                                   */
/**********************************************************************************/

/**
 * @param object
 * @param date_hour 0 <= date_hour <= 23
 * @param date_minute 0 <= date_minute <= 59
 * @param date_day 1 <= date_day <= 31
 * @param date_month 1 <= date_month <= 12
 * @param date_year 0 <= date_hour
 * @return
 */

t_appointment* create_appointment(char* object, int date_hour, int date_minute, int date_day, int date_month, int date_year) {

    t_appointment* appointment = (t_appointment*) malloc(sizeof(t_appointment));

    appointment->object = object;
    appointment->date_hour = date_hour;
    appointment->date_minute = date_minute;
    appointment->date_day = date_day;
    appointment->date_month = date_month;
    appointment->date_year = date_year;
    appointment->next = NULL;

    return appointment;
}

/**********************************************************************************/
/*                                     INPUTS                                     */
/**********************************************************************************/

/**
 * @param contact
 * @return
 */
t_input* create_input(t_contact* contact, int level) {

    t_input* input = (t_input*) malloc(sizeof(t_input));

    input->contact = contact;
    input->appointments = NULL;
    input->next = NULL;
    input->level = level;

    return input;
}

/**
 * @param level
 * @return
 */
t_input_list* create_input_list(int level) {

    t_input_list * input_list = (t_input_list*) malloc(sizeof(t_input_list));

    input_list->heads = (t_input **) malloc(sizeof(t_input*) * level);
    input_list->max_level = level;

    for(int i = 0; i < level; i++) {
        input_list->heads[i] = NULL;
    }

    return input_list;
}


/**
 * @param appointment
 * @param input
 */
void insert_appointment(t_appointment* appointment, t_input* input) {

    appointment->next = input->appointments;
    input->appointments = appointment;

    return;

}

void insert_input(t_contact * contact, t_input_list* list) {

    // Check if the contact is already in the list
    char* name = get_name_formatted(contact);

    for(int i = 0; i < list->max_level; i++) {

        t_input* tmp = list->heads[i];

        while(tmp != NULL) {

            if(strcmp(get_name_formatted(tmp->contact), name) == 0) {
                printf("Contact already in the list\n");
                return;
            }

            tmp = tmp->next;
        }

    }

    // Insert contact in the list by alphabetical order on level 0 only
    t_input* input = create_input(contact, 0);

    if(list->heads[0] == NULL) {
        list->heads[0] = input;
        return;
    }

    if(is_name_before(name, get_name_formatted(list->heads[0]->contact))) {
        input->next = list->heads[0];
        list->heads[0] = input;
        return;
    }

    t_input* tmp = list->heads[0];

    while(tmp->next != NULL && is_name_before(get_name_formatted(tmp->next->contact), name)) {
        tmp = tmp->next;
    }

    input->next = tmp->next;
    tmp->next = input;

    return;


}

void display_input_list(t_input_list* list) {

    for(int i = 0; i < list->max_level; i++) {

        printf("[list head_%d @-]-->", i);
        t_input *tmp = list->heads[i];


        while(tmp != NULL) {

            printf("[ %s|@ ]-->", tmp->contact->last_name);
            tmp = tmp->next;
        }

        printf("NULL\n");

    }

}
