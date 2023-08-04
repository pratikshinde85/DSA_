#include <iostream>
#include<stack>
using namespace std;

int main() {
  cout << "Hello world!" << endl;
  string str="pratik";
  //using stack;
  stack<char>st;

  for(int i=0;i<str.length();i++)
  {
      st.push(str[i]);
  }

  while(!st.empty())
  {
      cout<<st.top()<<" ";
      st.pop();
  }

  cout<<endl<<"using normal for loop: "<<endl;

  for(int i=str.length()-1;i>=0;i--)
  {
      cout<<str[i]<<" ";
  }
  return 0;
}