#include<iostream>
using namespace std;
bool binarySearch(int arr[],int target){

    int s=0;
   // int e=sizeof(arr)/sizeof(arr[0])-1;
    int e=4;
    int mid=s+(e-s)/2;
    while(s<=e){

        if(arr[mid]==target){
            return true;
        }
        else if(target>arr[mid]){
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return false;
}
int main()
{
    cout<<"HEllo Pratik how ARE YOU .."<<endl;

    int arr[]={10,20,30,40,50};
    int target=10;
    int ans=binarySearch(arr,target);
    cout<<ans<<endl;
    return 0;
}
