//
// Created by grego on 02/11/2023.
//

#ifndef TI_301_PROJET_AGENDA_FICHIER_H
#define TI_301_PROJET_AGENDA_FICHIER_H


typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;

} t_d_cell;

typedef struct s_d_list
{

    int max_level;
    t_d_cell **heads;

} t_d_list;

t_d_list* create_list(int);
t_d_cell* create_cell(int, int);

void display_cell(t_d_cell*);
void display_list(t_d_list*);

void insert_cell(int, int, t_d_list*);
t_d_cell* search_cell_classic(int value, t_d_list* list);
t_d_cell* search_cell_optimal(int value, t_d_list* list);

#endif //TI_301_PROJET_AGENDA_FICHIER_H