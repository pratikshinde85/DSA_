#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    string str="thruvantapuram ";
    unordered_map<char,int>m;

    for(int i=0;i<str.length();i++){
        m[str[i]]++;
    }
    for(auto i: m){
        cout<<i.first<<"-> "<<i.second<<endl;
    }

    return 0;
}