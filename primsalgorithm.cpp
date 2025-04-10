#include<iostream>
#include<list>
#include<map>
#include<queue>
#include "graph.cpp"
int primsalgorithm(int size ,map<int , list<pair<int,int>>>& adjList ){
vector<bool> visited(size, false);
priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
pq.push(make_pair(0, 0));
int twt=0;
while(!pq.empty())
{
    int node = pq.top().second;
    int weight = pq.top().first;
    pq.pop();
    if(visited[node])continue;
    twt += weight;
    visited[node] = true;
    for(auto i : adjList[node]){
        if(!visited[i.first])
        {
            pq.push(make_pair(i.second , i.first));
        }
    }
}
return twt;
}
vector<int> minimumspanningTree(int size ,map<int , list<pair<int,int>>>& adjList)
{
    vector<bool> visited(size, false);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push(make_pair(0, 0));
    vector<int> mst;
    while(!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if(visited[node])continue;
        visited[node] = true;
        mst.push_back(node);
        for(auto i : adjList[node]){
            if(!visited[i.first])
            {    
                pq.push(make_pair(i.second , i.first));
            }
        }
    }
    return mst;
}
int main(){
    graph g;
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(1,0,4);
    g.addEdge(1,2,8);
    g.addEdge(8,2,2);
    g.addEdge(8,6,6);
    g.addEdge(8,7,7);
    g.addEdge(6,7,1);
    g.addEdge(6,5,2);
    g.addEdge(2,5,4);
    g.addEdge(3,5,14);
    g.addEdge(4,5,10);
    g.addEdge(4,3,9);
    g.addEdge(2,3,7);
    g.displayGraph();
    cout<<"the value of shortest spanning tree is "<<primsalgorithm(14 , g.adjList);
    vector<int> mt = minimumspanningTree(14 , g.adjList);
    for(int i : mt) cout << i << "->";
    return 0;
}