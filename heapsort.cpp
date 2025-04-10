#include "maxheap.cpp"
#include <iostream>
using namespace std;
int main() {
    int max =11;
    int a[] = {1, 3, 1, 4, 6, 13, 10, 9, 8, 15, 17};
    buildHeap(a , max);
    for(int i=max-1; i>=0; i--){
        swap(a[0] , a[i]);
        buildHeap(a, i);
    }
    for(int i=0; i<max; i++) cout<<a[i]<<endl;
    push(a , 34 , max);
    for(int i=max-1; i>=0; i--){
        swap(a[0] , a[i]);
        buildHeap(a, i);
    }
    for(int i=0; i<max; i++) cout<<a[i]<<endl;
    return 0;
}