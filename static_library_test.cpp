#include <gtest/gtest.h>
extern "C"
{
    #include "header.h"
}

TEST(test1, calculate_far_dates_diff)
{
    struct tm date_1, date_2;
    memset(&date_1, 0, sizeof(struct tm));
    memset(&date_2, 0, sizeof(struct tm));

    date_1.tm_year = 2000;
    date_1.tm_mon = 1;
    date_1.tm_mday = 1;

    date_2.tm_year = 2021;
    date_2.tm_mon = 6;
    date_2.tm_mday = 6;

    ushort days = calculate_dates_difference(&date_1, &date_2);
    EXPECT_EQ(days, 7825);
}

TEST(test2, calculate_close_dates_diff)
{
    struct tm date_1, date_2;
    memset(&date_1, 0, sizeof(struct tm));
    memset(&date_2, 0, sizeof(struct tm));

    date_1.tm_year = 2021;
    date_1.tm_mon = 6;
    date_1.tm_mday = 3;

    date_2.tm_year = 2021;
    date_2.tm_mon = 6;
    date_2.tm_mday = 6;

    ushort days = calculate_dates_difference(&date_1, &date_2);
    EXPECT_EQ(days, 3);
}

//TEST(test3, count_relevant_posts_1)
//{
//    struct tm current_date = { 0, 0, 0, 1, 1, 2015, 0, 0, 0 };
//
//}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}