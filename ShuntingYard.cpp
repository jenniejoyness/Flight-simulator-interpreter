#include <cctype>
#include <algorithm>
#include <bits/stdc++.h>
#include "ShuntingYard.h"
#include "Num.cpp"
#include "Minus.cpp"
#include "Plus.cpp"
#include "Mult.cpp"
#include "Div.cpp"



int ShuntingYard::getPriority(string C)
{
    if (C == "-" || C == "+")
        return 1;
    else if (C == "*" || C == "/")
        return 2;
    else if (C == "^")
        return 3;
    return 0;
}

vector<string> ShuntingYard::infixToPostfix(vector<string> s){
    stack<string> stack;
    stack.push("N");
    int l = s.size();
    vector<string>  output;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if(!isOperator(s[i]) && s[i]!= "(" && s[i]!= ")")
            output.push_back((s[i]));

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == "(")
            stack.push("(");

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ")")
        {
            while(stack.top() != "N" && stack.top() != "(")
            {
                string c = stack.top();
                stack.pop();
                output.push_back((c));
            }
            if(stack.top() == "(")
            {
                string c = stack.top();
                stack.pop();
            }
        }
        //If an operator is scanned
        else{
            while(stack.top() != "N" && getPriority(s[i]) <= getPriority(stack.top()))
            {
                string c = stack.top();
                stack.pop();
                output.push_back((c));
            }
            stack.push(s[i]);
        }
    }
    //Pop all the remaining elements from the stack
    while(stack.top() != "N")
    {
        string c = stack.top();
        stack.pop();
        output.push_back((c));
    }
    return output;
}

Expression* ShuntingYard::stringToExpression(vector<string> postfix){
    stack<Expression*> stack;

    for (int i = 0; i < postfix.size(); ++i){
        if(!isOperator(postfix[i])){
            stack.push(new Num(stod(postfix[i])));
        }
        else {
            Expression* right = stack.top();
            stack.pop();
            Expression* left = stack.top();
            stack.pop();
            switch (postfix[i][0]){
                case '+':
                  stack.push(new Plus(left,right)) ;
                  break;
                case '-':
                    stack.push(new Minus(left,right)) ;
                    break;
                case '/':
                    stack.push(new Div(left,right)) ;
                    break;
                case '*':
                    stack.push(new Mult(left,right)) ;
                    break;
            }

        }
    }
    Expression* result = stack.top();
    return result;
}

bool ShuntingYard::isOperator(string s){
    if (s == "+" || s == "-" || s == "/" || s == "*"){
        return true;
    }
    return false;
}