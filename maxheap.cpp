// btw if a[left] > a[largest] is used it is for max heap , if a[left] < a[largest] is used it is basically for minheap
#include <iostream>
using namespace std;
void heapifyArr(int a[],int index, int size)
{
    int left = 2*index + 1;
    int right = 2*index +2;
    int largest = index;
    if(left < size && a[left] > a[largest]) {
        largest = left;
    }
    if(right < size && a[right] > a[largest]) {
        largest = right;
    }
    if(largest != index) {
       swap(a[index] , a[largest]);
        heapifyArr(a , largest , size);
    }
}
void buildHeap(int arr[] , int size){
    int n = size/2 - 1;
    for(int i = n; i>=0; i--)
    {
        heapifyArr(arr ,  i , size);
    }
}

void push(int arr[] , int val , int& size)
{
arr[size] = val;
size++;
buildHeap(arr , size);
}