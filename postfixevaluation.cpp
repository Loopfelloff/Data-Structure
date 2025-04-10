#include<iostream>
#include<stack>
using namespace std;
int calculate(int b , int a , char exp)
{
    switch(exp){
        case '+':
        return b + a;
        break;
        case '-':
        return b-a;
        break;
        case '*':
        return b*a;
        break;
        case '/':
        return b/a;
        break;
        default:
        return 0;
    }
    return 0;
}
int main(){
    // int a = int('1') - 48;
    stack<int> st;
    string expression = "63/67**";
    // string expression = "34+";
    for(int i=0; i<expression.length(); i++)
    {
        if(expression[i] >= '0' && expression[i] <='9') st.push( int(expression[i]) - 48 );
        else{
           
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int value = calculate(b , a , expression[i]);
            st.push(value);
        }
    }
    cout << st.top(); 
    return 0;
}
