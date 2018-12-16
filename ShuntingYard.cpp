#include <cctype>
#include <algorithm>
#include <bits/stdc++.h>
#include "ShuntingYard.h"



int ShuntingYard::getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string ShuntingYard::infixToPostfix(string s){
    stack<char> stack;
    stack.push('N');
    int l = s.length();
    string output;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= '1' && s[i] <= '9'))
            output+=s[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')
            stack.push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            while(stack.top() != 'N' && stack.top() != '(')
            {
                char c = stack.top();
                stack.pop();
                output += c;
            }
            if(stack.top() == '(')
            {
                char c = stack.top();
                stack.pop();
            }
        }
        //If an operator is scanned
        else{
            while(stack.top() != 'N' && getPriority(s[i]) <= getPriority(stack.top()))
            {
                char c = stack.top();
                stack.pop();
                output += c;
            }
            stack.push(s[i]);
        }
    }
    //Pop all the remaining elements from the stack
    while(stack.top() != 'N')
    {
        char c = stack.top();
        stack.pop();
        output += c;
    }
    return output;
}

Expression* ShuntingYard::stringToExpression(string postfix){
    stack<Expression*> stack;

    for (int i = 0; i < postfix.length(); ++i){
        if(isdigit(postfix[i])){
            stack.push(new Num(postfix[i]));
        }
    }
}

