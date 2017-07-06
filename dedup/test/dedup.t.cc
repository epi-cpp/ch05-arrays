#include <gtest/gtest.h>
#include "dedup.h"

using namespace std;

TEST(adv_game_test, winnable) {
  vector<int> dup{0, 0, 1, 1, 2, 3, 3};
  vector<int> ddup{0, 1, 2, 3};
  dedup(dup);
  EXPECT_EQ (ddup, dup);
}

TEST(adv_game_test, unwinnable) {
  vector<int> dup{0, 0, 0, 1, 2, 2, 3};
  vector<int> ddup{0, 1, 2, 3};
  dedup(dup);
  EXPECT_EQ (ddup, dup);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
