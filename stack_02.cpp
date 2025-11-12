#include <iostream> 
#include <cctype> 
using namespace std; 

struct Node  { 
    char data; 
    Node* next; 
}; 

class Stack{ 
    Node* top; 
public: 
    Stack() { 
        top = NULL; 
    } 

    //Push a character onto the stack 
    void push(char x){ 
        Node* t=new Node; 
        t->data =x; 
        t->next=top; 
        top =t; 
    } 

    //Pop a character from stack 
    char pop(){ 
        if(top == NULL) return '\0'; 
        char x =top->data; 
        Node* t = top; 
        top = top->next; 
        delete t; 
        return x; 
    } 

    // Peek at the top of the stack 
    char peek(){ 
        if(top!=NULL) return top->data; 
        else return '\0'; 
    } 

    //Check if stack is empty 
    bool isEmpty(){ 
        return top ==NULL; 
    } 
}; 

// Function to check precedence of operators 
int precedence(char op){ 
    if(op=='+'|| op=='-') return 1; 
    if(op=='*'|| op=='/') return 2; 
    return 0; 
} 

//Function to convert infix expression to postfix 
string infixToPostfix(string infix){ 
    Stack s; 
    string postfix =""; 

    //Loop through each character 
    for (char ch: infix){ 
        if (isalnum(ch)){ 
            postfix += ch; 
        } 
        else if (ch =='('){ 
            s.push(ch); 
        } 
        else if (ch==')'){ 
            while (!s.isEmpty() && s.peek() !='(') 
                postfix += s.pop(); 
            s.pop(); 
        } 
        else{ 
            while(!s.isEmpty() && precedence(ch)<=precedence(s.peek())) 
                postfix +=s.pop(); 
            s.push(ch); 
        } 
    } 

    //Pop remaining operators from stack 
    while (!s.isEmpty()) 
        postfix +=s.pop(); 

    return postfix; 
} 

//Function to convert infix to prefix 
string infixToPrefix(string infix) { 
    string rev =""; 

    //Step 1,2: Reverse and swap brackets 
    for (int i=infix.length()-1;i>=0;i--){ 
        if(infix[i]=='(') 
            rev +=')'; 
        else if(infix[i]==')') 
            rev +='('; 
        else 
            rev += infix[i]; 
    } 

    //step 3: Get postfix of modified expression 
    string postfix = infixToPostfix(rev); 

    //Step 4: Reverse postfix to get prefix 
    string prefix =""; 
    for (int i=postfix.length()-1;i>=0;i--){ 
        prefix +=postfix[i]; 
    } 
    return prefix; 
} 

//Main function 
int main() { 
    string infix; 
    // Get infix input from user 
    cout<<"Enter infix:"; 
    cin>>infix; 

    //Call functions and show output 
    cout<<"Postfix:"<<infixToPostfix(infix)<< endl; 
    cout<<"Prefix:"<<infixToPrefix(infix)<< endl; 
    return 0;
}
