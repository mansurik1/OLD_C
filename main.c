#include "header.h"

int main()
{
    const char msg[] = "Неверный ввод!";

    printf("Введите текущую дату в формате ДД ММ ГГГГ: ");
    struct tm current_date;
    memset(&current_date, 0, sizeof(struct tm));

    short scanf_res;
    scanf_res = scanf("%d%*c%d%*c%d%*c", &current_date.tm_mday, &current_date.tm_mon, &current_date.tm_year);
    if (scanf_res != 3)
    {
        printf("%s", msg);
        return 1;
    }

    printf("Введите количество записей: ");
    uint num_of_recs = 0;
    scanf_res = scanf("%d", &num_of_recs);

    if (scanf_res != 1)
    {
        printf("%s", msg);
        return 1;
    }

    social_media_post* posts_array = (social_media_post*)calloc(num_of_recs, sizeof(social_media_post));

    for (uint i = 0; i < num_of_recs; ++i)
    {
        printf("\nВвод записи %d из %d:\n", i + 1, num_of_recs);

        printf("Введите ID записи: ");
        scanf_res = scanf("%d", &posts_array[i].ID);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }

        printf("Введите среднюю оценку записи: ");
        scanf_res = scanf("%lf", &posts_array[i].average_rating);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }

        printf("Введите количество оценок записи: ");
        scanf_res = scanf("%d", &posts_array[i].number_of_votes);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }

        printf("Введите дату последней оценки записи в формате ДД ММ ГГГГ: ");
        scanf_res = scanf("%d", &posts_array[i].last_vote.tm_mday);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }
        scanf_res = scanf("%d", &posts_array[i].last_vote.tm_mon);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }
        scanf_res = scanf("%d", &posts_array[i].last_vote.tm_year);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }

        printf("Введите последнюю оценку записи: ");
        scanf_res = scanf("%hu", &posts_array[i].last_vote_rating);
        if (scanf_res != 1)
        {
            printf("%s", msg);
            free(posts_array);
            return 1;
        }
    }

    printf("\nКоличество записей, удовлетворяющих критерию: %d", count_relevant_posts(&current_date, posts_array, num_of_recs));

    return 0;
}
