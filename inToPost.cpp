#include<bits/stdc++.h>
using namespace std;

int Precedence(char ch){
    if(ch=='^')
        return 3;

    if(ch=='*' || ch=='/')
        return 2;
    if(ch=='+' || ch == '-')
        return 1;
    else
    return -1;
}

string infixToPostfix(string s){
    stack<char>st;
    string res;
    for (int i = 0; i<s.length(); i++){
        if(s[i] >= 'a' && s[i]<='z' || s[i]>='A'&&s[i]<='Z' || s[i]>='0'&& s[i]<='9')
            res=res+s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                res = res+st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else{
            while(!st.empty()&& Precedence(st.top())>Precedence(s[i])){
                res= res+st.top();
                st.pop();
            }
            st.push(s[i]);
                }
    }
    while(!st.empty()){
        res=res+st.top();
        st.pop();
    }

    return res;
}
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
    string result = infixToPostfix("1+2-5");
    cout << eval_Postfix(result);

}


