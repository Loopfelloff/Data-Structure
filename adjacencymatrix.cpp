#include <iostream>
#include<vector>
using namespace std;
void insertIntoMatrix(vector<vector<int>>& mat , int i , int j , int weight =1)
{
    mat[i][j] = weight;
    mat[j][i] = weight;
}
void displayMatrix(vector<vector<int>> mat){
    int size = mat.size();
    for(int i=0; i<size; i++) 
    {for(int j=0; j<size; j++) 
    {cout<<mat[i][j]<<"   ";
    }
    cout<<endl;
    }
}
