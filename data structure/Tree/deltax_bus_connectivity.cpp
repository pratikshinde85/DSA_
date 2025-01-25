#include<iostream>
using namespace std;
int main(){

    int arr1[]={1,2,3,4,5};
    int arr2[]={6,7,3,8,9,10};
    int n1=5;
    int n2=6;
    int src=2;
    int des=9;
    bool flag=false;
    int count=0;
    for(int i=0;i<n1;i++){
        if(arr1[i]==src){
            count=i;
            break;
        }
    }

    int i=count+1;
    while(i<n1 && i<n2){
        if(arr1[i]==arr2[i]&& arr2[i]==des){
            flag=true;
            break;
        }
        else{
            flag=false;
        }
        i++;
    }
    if(flag){
        cout<<"Yes"<<endl;

    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}