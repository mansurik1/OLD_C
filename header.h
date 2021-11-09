#ifndef HEADER_H
#define HEADER_H

#define uint unsigned int
#define ushort unsigned short

#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    uint ID;
    double average_rating;
    uint number_of_votes;
    struct tm last_vote;
    ushort last_vote_rating;
} social_media_post;

unsigned int count_relevant_posts(struct tm*, social_media_post*, uint);
ushort calculate_dates_difference(struct tm*, struct tm*);

#endif
