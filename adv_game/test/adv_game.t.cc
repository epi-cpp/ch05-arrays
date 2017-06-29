#include <gtest/gtest.h>
#include "adv_game.h"

using namespace std;

TEST(adv_game_test, winnable) {
  vector<int> game{3, 3, 1, 0, 2, 0, 1};
  bool expected = true;
  auto actual = adv_game(game);
  EXPECT_EQ (expected, actual);
}

TEST(adv_game_test, unwinnable) {
  vector<int> game{3, 2, 0, 0, 2, 0, 1};
  bool expected = false;
  auto actual = adv_game(game);
  EXPECT_EQ (expected, actual);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
