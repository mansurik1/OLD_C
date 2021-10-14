#include <stdlib.h>
#include "header.h"

int main()
{
    //  Создание указателя на массив структур и
    //  переменной для хранения размера массива
    size_t number_of_records = 0;
    size_t container_array_size = 10;

    container* container_array = NULL;
    container* temporary_pointer = (container*)malloc(sizeof(container) * container_array_size);
    if (!temporary_pointer)
        return MEMORY_ALLOCATION_ERROR;
    else
        container_array = temporary_pointer;

    //  Получение пользовательского ввода
    int userChoice = user_input();

    while (userChoice != 51) {
       if (userChoice == 49)
       {
           add_record(container_array, &number_of_records);
           finalize_user_input();

           if ((double)container_array_size / (double)number_of_records < 1.5) {
               container_array_size = (int)((double)container_array_size * 1.5);
               temporary_pointer = realloc(container_array, container_array_size * sizeof(container));
               if (!temporary_pointer) {
                   free(container_array);
                   return MEMORY_REALLOCATION_ERROR;
               }
               else
                   container_array = temporary_pointer;
           }
       }
       else
           if (userChoice == 50)
           {
               print_array(container_array, number_of_records);
           }

        userChoice = user_input();
    }

    for (size_t i = 0; i < number_of_records; i++) {
        free(container_array[i].container_type);
    }

    free(container_array);

    return 0;
}
