#ifndef PROJECT_HEADER_H
#define PROJECT_HEADER_H

#include <stdbool.h>
/*
    Задание полей структуры и создание
    псевдонима пользовательского типа
*/
typedef struct container
{
    char* container_type;

    double internal_length;
    double internal_width;
    double internal_height;
    double internal_volume;

    double internal_weight;
    double load_weight;
} container;

enum ERROR_LIST
{
    MEMORY_ALLOCATION_ERROR = 1,
    MEMORY_REALLOCATION_ERROR = 2,
};

unsigned int finalize_user_input();
int user_input();

void add_record(container*, size_t *);
void sort_array(container*, size_t, bool);
void print_array(container*, size_t);

#endif