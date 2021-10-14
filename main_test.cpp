#include <gtest/gtest.h>
extern "C" {
    #include "header.h"
}

void copy_container(container* cont, container to_copy, size_t index)
{
    char* backup = cont[index].container_type;
    cont[index] = to_copy;
    cont[index].container_type = strncpy(backup, to_copy.container_type, 15);
}

void fill_containers(container* cont) {
    container tmp_cont_1 = {"Bucket", 28.5, 28.5, 26.5, 21.524625, 0.6, 20};
    container tmp_cont_2 = {"Tank", 136, 42.87, 42.87, 249.9458184, 5, 220};
    container tmp_cont_3 = {"Pot", 40, 20, 20, 16, 1.3, 15};
    container tmp_cont_4 = {"Bucket", 35, 21, 21, 15.435, 1, 13};
    container tmp_cont_5 = {"Pot", 15, 7, 7, 0.735, 0.5, 0.9};

    copy_container(cont, tmp_cont_1, 0);
    copy_container(cont, tmp_cont_2, 1);
    copy_container(cont, tmp_cont_3, 2);
    copy_container(cont, tmp_cont_4, 3);
    copy_container(cont, tmp_cont_5, 4);
}

container* allocate_container_memory(size_t size)
{
    container* temporary_pointer_1 = (container*)malloc(sizeof(container) * size);
    if (!temporary_pointer_1)
        assert(0);
    container* cont = temporary_pointer_1;

    char* temporary_pointer_2;
    for (size_t i = 0; i < size; i++) {
        temporary_pointer_2 = (char*)malloc(sizeof(char) * 15);
        if (!temporary_pointer_2)
            assert(0);
        cont[i].container_type = temporary_pointer_2;
    }

    return cont;
}

TEST(SORT, SORT_BY_VOLUME)
{
    container* cont = allocate_container_memory(5);

    fill_containers(cont);
    sort_array(cont, 5, true);
    EXPECT_STREQ(cont[0].container_type, "Pot");
    EXPECT_STREQ(cont[1].container_type, "Bucket");
    EXPECT_STREQ(cont[2].container_type, "Pot");
    EXPECT_EQ(cont[3].internal_width, 28.5);
    EXPECT_EQ(cont[4].internal_volume, 249.9458184);

    for (size_t i = 0; i < 5; i++) {
        free(cont[i].container_type);
    }
    free(cont);
}

TEST(SORT, SORT_GROUPING_1)
{
    container* cont = allocate_container_memory(5);

    fill_containers(cont);
    sort_array(cont, 5, false);
    EXPECT_STREQ(cont[0].container_type, "Bucket");
    EXPECT_STREQ(cont[1].container_type, "Bucket");

    for (size_t i = 0; i < 5; i++) {
        free(cont[i].container_type);
    }
    free(cont);
}

TEST(SORT, SORT_GROUPING_2)
{
    container* cont = allocate_container_memory(5);

    fill_containers(cont);
    sort_array(cont, 5, false);
    EXPECT_STREQ(cont[2].container_type, "Pot");
    EXPECT_STREQ(cont[3].container_type, "Pot");

    for (size_t i = 0; i < 5; i++) {
        free(cont[i].container_type);
    }
    free(cont);
}

TEST(SORT, SORT_GROUPING_3)
{
    container* cont = allocate_container_memory(5);

    fill_containers(cont);
    sort_array(cont, 5, false);
    EXPECT_STREQ(cont[4].container_type, "Tank");

    for (size_t i = 0; i < 5; i++) {
        free(cont[i].container_type);
    }
    free(cont);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}