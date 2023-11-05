//
// Created by grego on 02/11/2023.
//

#ifndef TI_301_PROJET_AGENDA_FICHIER_H
#define TI_301_PROJET_AGENDA_FICHIER_H

#endif //TI_301_PROJET_AGENDA_FICHIER_H


typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;

} t_d_cell;

typedef struct s_d_list
{

    int max_level;
    struct s_d_cell **heads;

} t_d_list;

t_d_list* create_list(int);
t_d_cell* create_cell(int, int);

void display_cell(t_d_cell*);
void display_list(t_d_list*);

void insert_cell(t_d_cell*, t_d_list*);
