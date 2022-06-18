#include<bits/stdc++.h>
using namespace std;
int eval_Postfix(string s){
    stack<char>stk;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            stk.push(s[i]-'0');
        }
        else {
            int op2= stk.top();
            stk.pop();
            int op1= stk.top();
            stk.pop();
            switch (s[i])
            {
            case '+':
                stk.push(op1+op2);
                break;
            case '-':
                stk.push(op1-op2);
                break;
            case '*':
                stk.push(op1*op2);
                break;
            case '/':
                stk.push(op1/op2);
                break;
            case '^':
                stk.push(pow(op1,op2));
                break;
            }
        }
    }
    return stk.top();
}
int main(){
    cout << eval_Postfix("45+");
}