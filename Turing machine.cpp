#include <iostream>
#include <string>
#include <cctype>
#include <exception>
#include <bits/stdc++.h>

using namespace std;

bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='(')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
           return false;

        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            break;

        }
}
 // Check Empty Stack
    return (s.empty());

}

bool Character(string exp)
{
    for(int i = 0 ; i < exp.length() ; i++)
        if(exp[i]!='(' && exp[i]!=')' && !isdigit(exp[i]))
            return false;

    return true;

}
class ExpressionError: public invalid_argument
{
public:
    const char *mMsg ;
    ExpressionError() : invalid_argument(mMsg) {}
    virtual const char *what() const noexcept {return mMsg;}
};

class NotBalancedParentheses: public ExpressionError
{
public:
    NotBalancedParentheses(){}
    virtual const char *what() const noexcept {return "parentheses not balanced";}
};

class InvalidCharacter: public ExpressionError
{
public:
    InvalidCharacter(){}
    virtual const char *what() const noexcept {return "invalid character";}
};

int main()
{
    string expr;
    cin >> expr;
    try
    {
       if(areParanthesisBalanced(expr)&& Character(expr))
       {
           cout<<"accepted"<<endl;
       }
       else
        if(!areParanthesisBalanced(expr)&& !Character(expr))
        {
             cout << "parentheses not balanced" << endl << "invalid character" << endl;
        }
        else
         if(!areParanthesisBalanced(expr)&& Character(expr))
        {
            //throw NotBalancedParentheses();
            throw InvalidCharacter();
        }
        else
         if(areParanthesisBalanced(expr)&& !Character(expr))
        {
            //throw InvalidCharacter();
            throw NotBalancedParentheses();
        }

    }
    catch(exception &err)
    {
        cout << err.what() << endl;
    }


    return 0;
}



