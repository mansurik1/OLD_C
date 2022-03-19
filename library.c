#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//  Процедура вывода пользовательского интерфейса
void print_user_interface(bool mode)
{
    if (mode) {
        printf("Структура данных \"Типоразмеры грузовой тары\"\n\n");
        printf("Введите номер необходимого действия:\n");
        printf("1 – Добавить запись\n");
        printf("2 – Вывести отсортированные записи\n");
        printf("3 – Завершить выполнение программы\n");
    }
    else {
        printf("\nВведено некорректное значение.\n");
        printf("Повторите ввод:\n");
    }

    printf("–> ");
}

void print_fields(container* array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("Запись №%zu\n", i + 1);
        printf("Вид тары –> %s\n", array[i].container_type);
        printf("Длина внутренней поверхности тары –>\t%lf\n", array[i].internal_length);
        printf("Ширина внутренней поверхности тары –>\t%lf\n", array[i].internal_width);
        printf("Высота внутренней поверхности тары –>\t%lf\n", array[i].internal_height);
        printf("Объём внутренней поверхности тары –>\t%lf\n", array[i].internal_volume);
        printf("Собственная масса тары –>\t\t%lf\n", array[i].internal_weight);
        printf("Максимальная масса нагрузки тары –>\t%lf\n\n", array[i].load_weight);
    }
}

//  Проверка введённого символа по значению
bool input_condition(int input)
{
    // 49, 50 и 51 – ASCII коды символов '1', '2' и '3' соответственно
    return input == 49 || input == 50 || input == 51;
}

//  Функция подсчёта количества введённых знаков
unsigned int finalize_user_input()
{
    unsigned int counter = 1;
    //  Пока не найден перенос строки, суммировать количество символов
    while (getchar() != '\n') {
        counter++;
    }

    return counter;
}

//  Функция пользовательского ввода
int user_input()
{
    print_user_interface(1);
    int user_choice = getchar();

    //  Проверка введённой строки на длину и значение
    while (finalize_user_input() > 1 || !input_condition(user_choice)) {
        print_user_interface(0);
        user_choice = getchar();
    }

    return user_choice;
}

double double_input()
{
    char tmp_string[15] = "\0";
    double tmp_double = 0.0;

    scanf("%s", tmp_string);
    tmp_double = strtof(tmp_string, NULL);
    while (tmp_double == 0.0)
    {
        print_user_interface(0);
        scanf("%s", tmp_string);
        tmp_double = strtof(tmp_string, NULL);
    }

    return tmp_double;
}

void swap(container* a, container* b)
{
    container c = *a;
    *a = *b;
    *b = c;
}

void sort_array(container* current_array, size_t size, bool sort_mode)
{
   if (sort_mode) {
       bool flag;
       for (size_t i = 0; i < size - 1; i++) {
           flag = false;
           for (size_t j = 0; j < size - i - 1; j++) {
               if (current_array[j].internal_volume > current_array[j + 1].internal_volume) {
                   swap(&current_array[j], &current_array[j + 1]);
                   flag = true;
               }
           }
           if (!flag) break;
       }
   }
   else {
       if (size > 2) {
           for (size_t i = 0; i < size - 2; ++i) {
               for (size_t j = i + 2; j < size; ++j) {
                   if (strcmp(current_array[i].container_type, current_array[j].container_type) == 0) {
                       swap(&current_array[i + 1], &current_array[j]);
                       i++;
                   }
               }
           }
       }
   }
}

void add_record(container* current_array, size_t *size)
{
    *size += 1;
    printf("\nЗапись №%zu\n", *size);

    printf("Введите вид тары –> ");
    current_array[*size - 1].container_type = (char*)malloc(15 * sizeof(char));
    scanf("%s", current_array[*size - 1].container_type);

    printf("Введите длину внутренней поверхности тары –> ");
    current_array[*size - 1].internal_length = double_input();

    printf("Введите ширину внутренней поверхности тары –> ");
    current_array[*size - 1].internal_width = double_input();

    printf("Введите высоту внутренней поверхности тары –> ");
    current_array[*size - 1].internal_height = double_input();

    printf("Введите собственную массу тары –> ");
    current_array[*size - 1].internal_weight = double_input();

    printf("Введите максимальную массу нагрузки тары –> ");
    current_array[*size - 1].load_weight = double_input();

    current_array[*size - 1].internal_volume = current_array[*size - 1].internal_length * current_array[*size - 1].internal_width * current_array[*size - 1].internal_height;
    printf("\n");
}

void print_array(container* current_array, size_t size)
{
    if (size > 0) {
        printf("\nЗаписи, отсортированные по возрасатнию объёма:\n");
        sort_array(current_array, size, 1);
        print_fields(current_array, size);

        printf("Записи, сгрупированные по виду тары:\n");
        sort_array(current_array, size, 0);
        print_fields(current_array, size);
    }
    else {
        printf("Нет записей для отображения\n\n");
    }
}