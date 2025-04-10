#include <iostream>
#include "adjacencymatrix.cpp"
#include <queue>
using namespace std;
vector<int> returnNeighbour(vector<vector<int>> graph , int node , int size){
vector<int> neighbour;
for(int i=0; i<size; i++)
{
    if(graph[node][i] != 0)
    {
        neighbour.push_back(i);
    }
}
return neighbour;
}
void mark(vector<pair<int , bool>>& marked , int node , int size){
for(int i=0; i<size; i++){
    if(marked[i].first == node)
    {
        marked[i].second == true;
    }
}
}
int main() {   
    int v = 5;
    vector<pair<int , bool>> marked(v ,make_pair(0, false));
    vector<vector<bool>> visited(v, vector<bool>(v,false));
    vector<vector<int>> graph(v, vector<int>(v,0));
    insertIntoMatrix(graph,0 , 1 );
    insertIntoMatrix(graph,1 , 3 );
    insertIntoMatrix(graph,0 , 2 );
    insertIntoMatrix(graph,2 , 4 );
    queue<int> L;
    L.push(graph[0][0]);
    mark(marked , graph[0][0], v);
    return 0;
}
