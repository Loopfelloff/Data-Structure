#include<bits/stdc++.h>
#include "graph.cpp"
vector<int> dijkstraalgorithm(map<int ,list<pair<int,int>>>& adjList , int size , int node)
{ 
 priority_queue<pair<int , int > , vector<pair<int,int>>, greater<pair<int ,int>>> pq;// the first element is the weight and the second element is the node.
 vector<int> distance(size , INT_MAX);
 pq.push(make_pair(0,node));
 distance[node] = 0;
 while(!pq.empty())
 {
    int u = pq.top().second;
    int weight = pq.top().first;
    pq.pop();
    for(auto i : adjList[u])
    {
        int v = i.first;
        if(distance[u] + i.second < distance[v]){
            distance[v] = distance[u] + i.second;
            pq.push(make_pair(distance[v] , v));
        }
    }
 }
 return distance;
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
    vector<int> distance = dijkstraalgorithm(g.adjList , 14 , 0);
    for(int i=0; i<distance.size(); i++) cout<<distance[i]<<"->"; 
    return 0;
}