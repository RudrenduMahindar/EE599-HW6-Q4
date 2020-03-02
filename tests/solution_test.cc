#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(DFSTest, ReturnVisitedVector) {
  map<int,set<int>> vertices {{0,{1}}, 
    {1,{2,3}},
    {2,{0}},
    {3,{2,4,6}},
    {4,{}},
    {5,{6}},
    {6,{}}};
  Graph g(vertices);
  vector<int> actual=g.DFS_ALL();
  vector<int> expected={0, 1, 2, 3, 4, 6, 5};
  EXPECT_EQ(expected, actual);
}
