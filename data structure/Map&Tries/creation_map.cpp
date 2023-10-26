#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<string,int>m;

    //insertion
    //method1
    pair<string,int>p=make_pair("alto",10);
    m.insert(p);
    //method2
    pair<string,int>p1("scorpio",11);
    m.insert(p1);
    //method 3
    m["vagnour"]=13;
   
    //method4
    auto p3=make_pair("tata",100);
    m.insert(p3);

    //access
    cout<<"value at alto is :"<<m.at("alto")<<endl;

    cout<<"value at tata is :"<<m["tata"]<<endl;

    //searching 
    //count
        cout<<m.count("tata")<<endl;
    //find
        if(m.find("tata")!=m.end()){
            cout<<"found"<<endl;
        }
        else{
            cout<<"not found"<<endl;
        }
    //size 
    cout<<"size of map "<<m.size()<<endl;
    cout<<"Printing the MAP:"<<endl;

    for(auto i : m){
        cout<<i.first<<" -> "<< i.second<<endl;
    }
    //imp point
    cout<<m["splinder"]<<endl;
    
    cout<<"size of map:"<<m.size()<<endl;
    cout<<"value of splender"<<m["splinder"]<<endl;
   //printing the map
    cout<<"Printing the MAP:"<<endl;

    for(auto i : m){
        cout<<i.first<<" -> "<< i.second<<endl;
    }
    return 0;
}