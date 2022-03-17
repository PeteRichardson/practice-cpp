#include <gtest/gtest.h>

#include "../common/person.h"
#include <limits>

TEST(PersonTests, IsOld_Basic) {
    Person walter { "Walter", 33, 'M' };
    EXPECT_FALSE(walter.IsOld());
}

TEST(PersonTests, PersonCanBeOld) {
    Person methuselah {"Methuselah", UINT_MAX, 'M'};
    EXPECT_TRUE(methuselah.IsOld());
}

TEST(PersonTests, PersonCanBeNotOld) {
    Person newborn {"New Born", 0, 'M'};
    EXPECT_FALSE(newborn.IsOld());
}