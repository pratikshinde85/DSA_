#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st,int target)
{
    if(st.empty())
    {
        st.push(target);
        return;
    }

    //i  case mai solve jkarubga kbaki recursion sambhal lenga
    int temp=st.top();
    st.pop();


    //recursive call
    insertAtBottom(st,target);

    //backtracking
    st.push(temp);
}

void insert(stack<int>&st)
{
    if(st.empty())
    {
        //cout<<"stack is empty.."<<endl;
        return ;
    }
    int target=st.top();
    st.pop();

    insert(st);
    insertAtBottom(st,target);
   
}

void printStack(stack<int>&st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main() {
  cout << "Hello world!" << endl;

  stack<int>st;
  st.push(10);
  st.push(70);
  st.push(80);
  st.push(90);
  //printStack(st);
 // insertAtBottom(st,100);
  //insertAtBottom(st,1000);
  insert(st);
  printStack(st);
  return 0;
}