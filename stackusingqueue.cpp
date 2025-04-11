#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack {
    std::queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);                     // Step 1: Push to q2
        while (!q1.empty()) {           // Step 2: Move all from q1 to q2
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);              // Step 3: Swap q1 and q2
    }

    void pop() {
        if (!q1.empty()) q1.pop();
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
