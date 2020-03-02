#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;

class Graph {
public:
  Graph(map<int,set<int>>& vertices):v_(vertices){}
  map<int,set<int>> v_;
  vector<int> DFS(int root,vector<bool>& visited_nodes);
  vector<int> DFS_ALL();
};

#endif