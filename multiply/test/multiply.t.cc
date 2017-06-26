#include <gtest/gtest.h>
#include "multiply.h"

using namespace std;

TEST(multiply_test, ctor) {
  vector<int> num01{1, 2};
  vector<int> num02{1, 2};
  vector<int> expected_prod{1, 4, 4};
  auto actual_prod = multiply(num01, num02);
  EXPECT_EQ (expected_prod, actual_prod);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
