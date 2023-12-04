//
// Created by grego on 26/11/2023.
//

#include "app.h"
#include <stdio.h>
#include "models.h"

t_contact * register_contact() {

    printf("Entrez le nom de famille du contact : ");
    char* last_name = scan_string();

    printf("Entrez le prénom du contact : ");
    char* first_name = scan_string();

    t_contact* contact = create_contact(first_name, last_name);

    return contact;
}