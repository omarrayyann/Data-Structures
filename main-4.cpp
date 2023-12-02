/**
 * @file lab5.cpp
 * @author
 * @description This program convert an Infix expression to PostFix and then evaluate it
 * @date
 */

#include<iostream>
#include<string>
#include<exception>
#include<math.h>
#include<ctype.h>

using namespace std;

bool isOperator(char); //Function which checks if the input char is an operator
bool isleq(char, char); //Function which compare two operators  and return True if first operator has less or equal predence than the right operator
int convertOpToInt (char); //Function which converts operators into int so their precdence can be compared
string infix2postfix(string);   //Function which converts an infix notaiton into a postfix notation (lab4)
float evaluate(string postfix);     //Function which will evaluate a PostfixExpression and return the result
bool isBalanced(string expression); // Funciton which will check for balanced parentheses
bool isValidExpression(string expression); // Funciton which will check for balanced parentheses
//==============CStack Class===============
//declare the CStack class here
template<typename T>
class CStack{
private:
    int capacity;
    T* array;
    int index;
public:
    CStack(int capacity = 100){
        this->index = -1;
        this->capacity = capacity;
        array = new T[capacity];
    }
    ~CStack(){
        delete []array;
    }
    void push(T elem){
        if(size()==capacity){
            throw runtime_error("Stack is Full");
        }
        array[++index] = elem;
    }
    void pop(){
        if(!empty()){
            index--;
        }
        else{
            throw runtime_error("Stack is Empty");
        }
    }
    T top(){
        if(!empty()){
            return array[index];
        }
        else{
            throw runtime_error("Stack is Empty");
        }
    }
    int size(){
        return index+1;
    }
    bool empty(){
        return (index<0);
    }
    void display(){
        if(index==-1){
            cout << "Stack empty!" << endl;
        }
        else{
        cout << "top";
        for(int i = index; i>=0; i--){
            cout << " -> " << array[i];
        }
        cout << endl;
        }}
};

//=============Main funciton ==============
int main()
{

    while(true)
    {
        string infix;                          //Infix expression
        cout<<"Enter an Infix Expression: ";
        cin>>infix;
        
        try
        {
            if(infix=="exit")
                break;

            else if(!isValidExpression(infix))
            {
                cout<<"Expression is not Valid"<<endl;
                continue;
            }
            else if(!isBalanced(infix))
            {
                cout<<"Expression is not Balanced"<<endl;
                continue;
            }

            string postfix = infix2postfix(infix);    //Postfix Expression
            cout<<"The postfix form is: "<<postfix<<endl;
            float ans=evaluate(postfix);            //evaluate the postfix Expresion
            cout<<infix<<"="<<ans<<endl;        //print the final answer
        }
        catch(exception &e)
        {
            cout<<"Exception: "<<e.what()<<endl;
        }
    }

    return EXIT_SUCCESS;
}
//=====================================================================

bool isOperator(char ch)
{
    if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return true;
    else
        return false;

}

//Function which converts operators into int so their precdence can be compared
int convertOpToInt (char ch)
{
    if (ch=='+' || ch=='-') return 1;
    if (ch=='*' || ch=='/') return 2;
    if (ch=='^') return 3;
    return 0;
}
//Helper Function which compare two operators and return True if first operator
//has less or equal predence than the right operator
bool isleq(char opA, char opB)
{
    return (convertOpToInt(opA)<=convertOpToInt(opB));
}

//Function which will check for balanced parentheses
bool isBalanced(string expression)
{
    
    // since we're looking for only () brackets, I thought the stack implemetation would be redundent as we aonly have one type of brackets
    int openBrackets = 0;
    
    for(int i=0; i<expression.length(); i++){
        if(expression[i] == '('){
            openBrackets+=1;
        }
        else if(expression[i] == ')'){
            if(openBrackets>0){
                openBrackets-=1;
            }
            else{
                return false;
            }
        }
    }
        
    if(openBrackets==0){
        return true;
    }
    else{
        return false;
    }
   
    
}

// checks if expression is valid
bool isValidExpression(string expression){
    return expression.find_first_not_of("0123456789*^+-()") == std::string::npos;
}

// Function which converts an Infix Notaiton to a Postfix notation
string infix2postfix(string infix)
{
    
    CStack<char> stack = CStack<char>(int(infix.length()*2));
    string postfix = "";
    
    stack.push('(');
    infix += ')';
    
    for(int i=0; i<infix.length(); i++){
        
        char currentCharacter = infix[i];

        // if operand is found
        if (currentCharacter >= '0' && currentCharacter <= '9'){
            postfix += currentCharacter;}
        
        // if ( is found
        else if (currentCharacter == '('){
            stack.push('(');}
        
        // if an operator is found
        else if (isOperator(currentCharacter)){
            while(!stack.empty() && isOperator(stack.top()) && isleq(currentCharacter, stack.top())){
                postfix += stack.top();
                stack.pop();
            }
            stack.push(currentCharacter);
        }
        
        // if ) is found
        else if (currentCharacter == ')'){
            while(!stack.empty() && stack.top()!='('){
                postfix += stack.top();
                stack.pop();
            }
            if(stack.top() == '('){
                stack.pop();
            }
        }
        
    }
        
    return postfix;
}
//Function which will evaluate a PostfixExpression and return the result
float evaluate(string postfix)
{
    CStack<int> stack = CStack<int>(postfix.length()*2);
    
    for(int i=0; i<postfix.length(); i++){
        
        char currentCharacter = postfix[i];
                
        int answer = 0;

        if(isOperator(currentCharacter)){
            
            int first = stack.top();
            stack.pop();
            int second = stack.top();
            stack.pop();
            
            if (currentCharacter == '^'){
                answer = pow(second, first);
            }
            else if(currentCharacter=='*'){
                answer = first*second;
            }
            else if(currentCharacter=='/'){
                answer = first/second;
            }
            else if(currentCharacter=='-'){
                answer = second-first;
            }
            else if(currentCharacter=='+'){
                answer = first+second;
            }
            
            stack.push(answer);
            
        }
        else{
            stack.push(currentCharacter-'0');
        }
        
    }

    return stack.top();
}
