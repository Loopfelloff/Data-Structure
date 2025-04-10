#include<iostream>
#include<list>
#include<map>
using namespace std;
class graph{
public:
map<int , list<pair<int,int>>> adjList;
public:
void addEdge(int u, int v, int weight = 1)
{
adjList[u].push_back(make_pair(v, weight));
adjList[v].push_back(make_pair(u, weight));
}
void displayGraph(){
    for(auto i : adjList)
    {
        cout<<i.first<<"->";
        for(auto j : adjList[i.first])
        {
            cout<<j.first<<"->";
        }
        cout<<endl;
    }
}
};
