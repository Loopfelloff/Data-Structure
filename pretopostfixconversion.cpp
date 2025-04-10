#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
    stack<string> s;
    string exp = "/*A+BC-+DEF";
    for(int i=exp.length()-1; i>=0; i--)
    {
    if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) {
        string a = string(1, exp[i]);
        s.push(a);
    }
    else{
        string a = s.top();
        s.pop();
        string b = s.top();
        s.pop();
        string expression = string(1,exp[i]) + b + a;
        s.push(expression);
    }
    }
    string str = s.top();
    reverse(str.begin() , str.end());
    cout<<str<<endl;
    return 0;
}
