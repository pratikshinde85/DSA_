#include<iostream>
using namespace std;
void MissingElment(int arr[],int size){

    for(int i=0;i<size;i++){

        int index=abs(arr[i]);
        if(arr[index-1]>0){
            arr[index-1] *=-1;
        }
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        if(arr[i]>0){
            cout<<i+1<<" ";
        }
    }

    // int i=0;
    // while(i<size){
    //     int index=abs(arr[i]);
    //     if(arr[index-1]>0){
    //          swap(arr[index-1],arr[i]);
    //          arr[index-1]*=-1;
    //     }
    //     else{
    //         i++;
    //     }
    // }
    // for(int i=0;i<size;i++){
    //     cout<<arr[i]<<" ";
    //  }
    // cout<<endl;
    //  for(int i=0;i<size;i++){
    //     if(arr[i]>0){
    //         cout<<i+1<<" ";
    //     }
    // }
}
int main(){
    int arr[]={0,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]) +1 ;
    cout<<size<<endl;
    MissingElment(arr,size);
    return 0;
}