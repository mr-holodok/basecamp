//
// Created by mukola on 24.02.20.
//

#include <gtest/gtest.h>
#include <algorithm>
#include "BucketSorter.h"


TEST(test_suite_1, test_1) {
    BucketSorter b = BucketSorter(10);
    std::vector<float> vec{4.5, 5.5, 1.5, 6.5, 1.2, 7.1, 8.9, 9.9, 1.3};
    for (auto &elem : vec)
        b.add(elem);
    // sorting step
    b.sort();
    std::sort(vec.begin(), vec.end());
    // comparing step
    std::vector<float> *bucket_vec = b.get_values();
    EXPECT_EQ(vec, *bucket_vec);
    EXPECT_EQ(b.get_max_collisions(), 3);
    delete bucket_vec;
}

TEST(test_suite_1, test_2) {
    BucketSorter b = BucketSorter(101);
    std::vector<float> vec{100.0, 15.12, 10.1, 0.16, 17.2, 21.22, 87.15, 16.43, 56.7};
    for (auto &elem : vec)
        b.add(elem);
    // sorting step
    b.sort();
    std::sort(vec.begin(), vec.end());
    // comparing step
    std::vector<float> *bucket_vec = b.get_values();
    EXPECT_EQ(vec, *bucket_vec);
    EXPECT_EQ(b.get_max_collisions(), 1);
    delete bucket_vec;
}

TEST(test_suite_1, test_3) {
    BucketSorter b = BucketSorter(10);
    std::vector<float> vec{100.0, 15.12, 10.1, 0.16, 17.2, 21.22, 87.15, 16.43, 56.7};
    EXPECT_THROW(b.add(vec[0]), std::invalid_argument);
}

TEST(test_suite_1, test_4) {
    BucketSorter b = BucketSorter(101);
    std::vector<float> vec{100.0, 15.12, 10.1, 0.16, 17.2, 21.22, 87.15, 16.43, 56.7};
    for (auto &elem : vec)
        b.add(elem);
    // sorting step
    b.sort();

    for (auto &elem : vec)
        EXPECT_TRUE(b.check(elem));
    for (auto &elem : {1.0, 4.0, 5.55, 6.66, 7.77, 8.88, 9.1})
        EXPECT_FALSE(b.check(elem));
}