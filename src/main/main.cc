#include <iostream>
#include "src/lib/solution.h"

int main()
{
    map<int,set<int>> vertices {{0,{1}}, 
    {1,{2,3}},
    {2,{0}},
    {3,{2,4,6}},
    {4,{}},
    {5,{6}},
    {6,{}}};
    Graph g(vertices);
    //int root=0;
    //int num_of_vertices=vertices.size();
    //vector<bool> visited_nodes(num_of_vertices,false);
    vector<int> v=g.DFS_ALL();
    cout<<"[";
    for(auto& i : v)
        cout<<" "<<i;
    cout<<" ]"<<endl;    
    return EXIT_SUCCESS;
}