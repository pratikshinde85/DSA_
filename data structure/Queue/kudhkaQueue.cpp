#include <iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int  size;
    int *arr;

    Queue(int size)
    {
        this->size=size;
        arr=new int [size];
        front=0;
        rear=0;
    }

    void push(int data)
    {
        //check queue is empty or not

        if(rear==size)
        {
            //queue if full
            cout<<"Queue is Full.."<<endl;
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
    }

    void pop()
    {
        //check queue is emputy or not
        if(rear==front)
        {
            cout<<"Queue is empyty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rear)
            {
                rear=0;
                front=0;
            }
        }
    }

    int getSize()
    {
        
        return rear-front;        
    }
    int getFront()
    {
        if(rear==front)
        {
            cout<<"Empty Queue.."<<endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    void PrintQueue()
    {
        for(int i=0;i<rear;i++)
         {
         cout<<arr[i]<<" ";
         }
         cout<<endl;
    }
};
int main() {
  cout << "Hello world!" << endl;

  Queue q(10);
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);


  cout<<"Size of Queue is : "<<q.getSize()<<endl;
  cout<<"Front Element of Quueue is: "<<q.getFront()<<endl;
  //q.pop();
  
  cout<<"Size of Queue is : "<<q.getSize()<<endl;

 cout<<"Front Element of Quueue is: "<<q.getFront()<<endl;
    q.push(90);
     q.push(140);
      q.push(2340);
       q.push(430);

 cout<<"printing Whole Queue:"<<endl;
 q.PrintQueue();
 cout<<"Size of Queue is : "<<q.getSize()<<endl;
  q.pop();
   q.pop();
    q.pop();
     q.pop();
      q.pop();
       q.pop();
        q.pop();
        q.PrintQueue();
           q.pop();
              q.pop();
  return 0;
}