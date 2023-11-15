//
// Created by grego on 13/11/2023.
//

#ifndef TI_301_PROJET_AGENDA_MODELS_H
#define TI_301_PROJET_AGENDA_MODELS_H

typedef struct s_contact
{
    char* first_name;
    char* last_name;

} t_contact;

typedef struct s_apointement
{
    char* object;
    int date_hour;
    int date_minute;
    int date_day;
    int date_month;
    int date_year;

} t_apointement;



#endif //TI_301_PROJET_AGENDA_MODELS_H
