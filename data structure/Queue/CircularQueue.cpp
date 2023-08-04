#include <iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int size;
    int *arr;


  Queue(int size)
  {
      this->size=size;
      arr=new int[size];
      front=-1;
      rear=-1;
  }  

  void push(int data){

      //full case
        if(front==0&& rear==size-1)
        {
            cout<<"Q is full.."<<endl;
        }
      //single element handle
        else if(front==-1 && rear==-1)
        {
            front=0;
            rear=0;
            arr[rear]=data;
        }
      //circular nature 
       else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=data;
        }
      //noramal case
      else
      {
          rear++;
          arr[rear]=data;
      }
  }
  void pop(){

      //empty check
        if( front==-1)
        {
            cout<<"Q id Empty.."<<endl;
        }
      //single element 
       else if(front==rear)
        {
            arr[front]=-1;
            front=-1;
            
            rear=-1;
        }
      //circular nature
        else if(front==size-1)
        {
             //arr[front]=-1;
            front=0;
           
        }
      //normal case
        else
        {
            arr[front]=-1;
            front++;
        }
  }
  void print()
  {
      for(int i=0;i<size;i++)
      {
          cout<<arr[i]<<" ";
      }
      cout<<endl;
  }
};
int main() {
  cout << "Hello world!" << endl;
  Queue q(10);

  //insertion
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(180);
  q.pop();
  q.pop();
  q.pop();
 // q.pop();
  q.pop();
  q.push(10);
  //q.pop();
 q.push(20);
 q.push(20);
 q.push(20);
 q.push(20);
 q.push(20);
 q.print();
  return 0;
}