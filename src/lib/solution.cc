#include "solution.h"
#include <stack>
#include <iostream>
#include <algorithm>

vector<int> Graph::DFS_ALL()
{
  int root=0;
  vector<bool> visited_nodes(v_.size(),false);
  vector<int> DFS_v=DFS(root,visited_nodes);
  vector<int> DFS_v1,DFS_v2;
  if(DFS_v.size()==v_.size())
    return DFS_v;
  else
  {
    int num_of_nodes=v_.size();
    for(int i=0;i<num_of_nodes;i++)
    {
      auto it=find(DFS_v.begin(),DFS_v.end(),i);
      if(it==DFS_v.end())
      {  
        DFS_v1=DFS(i,visited_nodes);
        //DFS_v2.resize(DFS_v.size()+DFS_v1.size());
        //merge(DFS_v.begin(),DFS_v.end(),DFS_v1.begin(),DFS_v1.end(),DFS_v2.begin());
      }
    }
    for(auto it=DFS_v1.begin();it!=DFS_v1.end();it++)
      DFS_v.push_back(*it);
    return DFS_v;
  } 
}

vector<int> Graph::DFS(int root,vector<bool>& visited_nodes)
{
  vector<int> visit_dfs;
  stack<int> s;
  s.push(root);
  while(!s.empty())
  {
    int i=s.top();
    //cout<<"top ="<<i<<" ";
    s.pop();
    if(visited_nodes[i])
      continue;
    visited_nodes[i]=true;
    visit_dfs.push_back(i);
    auto it=v_.find(i);
    //set<int> neighbours;
    //neighbours=it->second;
    for(auto it1=(it->second).rbegin();it1!=(it->second).rend();it1++)
    {
      if(!visited_nodes[*it1])
      {  
        //cout<<"visit ="<< *it1 <<" ";
        s.push(*it1);
      }
    }
  }
  return visit_dfs;
}

