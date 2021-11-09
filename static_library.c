#include "header.h"

#define TARGET_RATING 4.0
#define MAX_DELAY 90

ushort calculate_dates_difference(struct tm* date1, struct tm* date2)
{
    time_t time1 = mktime(date1), time2 = mktime(date2);
    ushort result = (ushort)(difftime(time2, time1) / 60.0 / 60.0 / 24.0);
    return result;
}

unsigned int count_relevant_posts(struct tm* current_date, social_media_post* posts_array, uint array_size)
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