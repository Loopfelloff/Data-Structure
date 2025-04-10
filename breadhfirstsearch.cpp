// HERE IN THIS EXAMPLE I JUST SHOWED BFS HOWEVER TO DO DFS JUST REPLACE EVERY stack WITH stack AND stack.top() WITH stack.top()
#include<iostream>
#include "graph.cpp"
// #include <stack>
#include <vector>
#include <stack>
using namespace std;
vector<int> findNeighbour(map<int ,list<pair<int,int>>>& adjList , int node ,map<int , bool>& mark )
{
vector<int> neighbour;
for(auto i : adjList[node]){
    if(!mark[i.first])
    {
    neighbour.push_back(i.first);
    }
}
return neighbour;
}
vector<int> breadthFirstSearch(map<int , bool>& mark , stack<int>& L , map<int , list<pair<int,int>>>& adjList){
vector<int> list;
list.push_back(L.top());
while(!L.empty())
{
    int u = L.top();    
   
    vector<int> neighbour = findNeighbour(adjList , u  , mark);
    if(neighbour.size() >0)
    {
            list.push_back(neighbour[0]);
            L.push(neighbour[0]);
            mark[neighbour[0]] = true;
}
else{
    L.pop();
}
    
}
return list;
}
int main(){
    stack<int> L;
    map<int , bool> mark;
    graph g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.displayGraph();
    L.push(1);
    mark[1] = true;
    vector<int> list = breadthFirstSearch(mark , L , g.adjList);
    for(int i=0; i<list.size(); i++) cout<<list[i]<<" ";
    return 0;
}