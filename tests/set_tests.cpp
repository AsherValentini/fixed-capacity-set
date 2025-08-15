#include <gtest/gtest.h>
#include "set.hpp"


TEST(SET, COUNT) {

    set<int, 5> mySet;
    mySet.insert(2);

    ASSERT_TRUE(mySet.count(2));

}


