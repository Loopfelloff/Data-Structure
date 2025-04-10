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
    stack<int> st;
    string expression = "*/63*67";
    for(int i=expression.length()-1; i>=0; i--)
    {
        if(expression[i] >= '0' && expression[i] <='9') st.push( int(expression[i]) - 48 );
        else{
           
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int value = calculate(a, b, expression[i]);
            st.push(value);
        }
    }
    cout << st.top(); 
    return 0;
}
