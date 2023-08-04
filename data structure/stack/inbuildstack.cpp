#include<iostream>
#include<stack>
using namespace std;

void printStack( stack<int>s)
{
    while(!s.empty())
    {

        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main()
{
    stack<int>s;
    //inssertiob

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    printStack(s);
    cout<<"after removal"<<endl;

    s.pop();
    printStack(s);
    cout<<"Size of stack: "<<s.size()<<endl;

    if(s.empty())
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}