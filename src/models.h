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

typedef struct s_appointment
{
    char* object;
    int date_hour;
    int date_minute;
    int date_day;
    int date_month;
    int date_year;
    struct s_appointment *next;

} t_appointment;

typedef struct s_input
{
    t_contact* contact;
    t_appointment* appointments;

    struct s_input *next;
    int level;

} t_input;

typedef struct s_input_list
{
    int max_level;
    t_input **heads;

} t_input_list;


t_appointment* create_appointment(char*, int, int, int, int, int); // FAIT
void insert_appointment(t_appointment*, t_input *); // FAIT
int is_name_before(char*, char*);
t_input * find_contact(char*, t_input_list*);

t_contact* create_contact(char*, char*); // FAIT

t_input* create_input(t_contact*, int); // FAIT

t_input_list* create_input_list(int); // FAIT
void insert_input(t_contact *, t_input_list*);
void display_input_list(t_input_list*);

char* scan_string(); // FAIT
char* get_name_formatted(t_contact*); // FAIT



#endif //TI_301_PROJET_AGENDA_MODELS_H
