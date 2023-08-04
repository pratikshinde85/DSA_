#include <iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
  //cout << "Hello world!" << endl;
  vector<int>input;

  input.push_back(1);
  input.push_back(4);
  input.push_back(2);

  stack<int>st;
  st.push(-1);
  vector<int>ans(input.size());

  for(int i=input.size()-1;i>=0;i--)
  {
      int curr=input[i];

      while(st.top()>=curr)
      {
          st.pop();
      }

      //chota element mil jayenga

      ans[i]=st.top();
     st.push(curr);
  }


cout<<"Printing the ANS :"<<endl;

for(auto val :ans)
{
    cout<<val<<" ";
}
cout<<endl;
  return 0;
}