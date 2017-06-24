#include <gtest/gtest.h>
#include "increment.h"

using namespace std;

TEST(increment_test, ctor) {
  vector<int> num01{1, 2, 3};
  vector<int> expected_inc{1, 2, 4};
  increment(num01);
  EXPECT_EQ (expected_inc, num01);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
