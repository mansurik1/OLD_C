#include <gtest/gtest.h>
extern "C"
{
    #include "header.h"
}

TEST(test1, count_relevant_posts_2)
{
    struct tm current_date = { 0, 0, 0, 1, 1, 2015, 0, 0, 0 };

    social_media_post test_post_1 = { 42, 4.2, 1315, { 0, 0, 0, 1, 1, 2015, 0, 0, 0 }, 3 };
    social_media_post test_post_2 = { 42, 4.2, 1315, { 0, 0, 0, 13, 11, 2014, 0, 0, 0 }, 3 };
    social_media_post test_post_3 = { 42, 4.2, 1315, { 0, 0, 0, 10, 4, 2013, 0, 0, 0 }, 3 };
    social_media_post test_post_4 = { 42, 4.2, 1315, { 0, 0, 0, 31, 12, 2014, 0, 0, 0 }, 3 };
    social_media_post test_post_5 = { 42, 4.2, 1315, { 0, 0, 0, 6, 10, 2014, 0, 0, 0 }, 3 };
    social_media_post test_post_6 = { 42, 4.2, 1315, { 0, 0, 0, 25, 11, 2014, 0, 0, 0 }, 3 };
    social_media_post test_post_7 = { 42, 4.2, 1315, { 0, 0, 0, 10, 4, 2010, 0, 0, 0 }, 3 };
    social_media_post test_post_8 = { 42, 4.2, 1315, { 0, 0, 0, 30, 12, 2015, 0, 0, 0 }, 3 };
    social_media_post test_post_9 = { 42, 4.2, 1315, { 0, 0, 0, 6, 10, 2004, 0, 0, 0 }, 3 };

    social_media_post posts_array[9] = { test_post_1, test_post_2, test_post_3, test_post_4, test_post_5, test_post_6, test_post_7, test_post_8, test_post_9 };

    ushort counter = count_relevant_posts(&current_date, posts_array, 9);
    EXPECT_EQ(counter, 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}