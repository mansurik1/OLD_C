#include "header.h"
#include <unistd.h>

#define TARGET_RATING 4.0
#define MAX_DELAY 90

ushort calculate_dates_difference(struct tm* date1, struct tm* date2)
{
    time_t time1 = mktime(date1), time2 = mktime(date2);
    ushort result = (ushort)(difftime(time2, time1) / 60.0 / 60.0 / 24.0);
    return result;
}

unsigned int subcount(struct tm* current_date, social_media_post* posts_array, uint array_size)
{
    uint relevant_count = 0;
    for (uint i = 0; i < array_size; ++i)
    {
        if (posts_array[i].average_rating >= TARGET_RATING && calculate_dates_difference(&posts_array[i].last_vote, current_date) <= MAX_DELAY) {
            relevant_count++;
        }
    }
    return relevant_count;
}

unsigned int count_relevant_posts(struct tm* current_date, social_media_post* posts_array, uint array_size)
{
    size_t count_processors = sysconf(_SC_NPROCESSORS_ONLN);
    pid_t pids[count_processors];
    uint common_count = 0;

    uint jobs = array_size / count_processors;

    for (uint i = 0; jobs > 0 && i < count_processors; ++i)
    {
        pids[i] = fork();
        if (pids[i] == 0)
        {
            common_count += subcount(current_date, posts_array + i * jobs, jobs);
            exit(EXIT_SUCCESS);
        }
    }

    if (jobs > 0)
    {
        int stat;
        for (size_t i = 0; i < count_processors; ++i) {
            if (waitpid(pids[i], &stat, 0) != pids[i]) {
                return 0;
            }
        }
    }

    common_count += subcount(current_date, posts_array + jobs, array_size - jobs * count_processors);

    return common_count;
}
