#include<iostream>
using namespace std;
class Deque{
    public :
    int size;
    int front;
    int rear;
    int *arr;

    Deque(int size)
    {
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void pushRear(int data)
    {
        //Full check
        if((rear==size-1 && front==0 )&&(rear==front-1))
        {
            cout<<"Q is Full..."<<endl;
        }
        //single element
        else if(front==-1&& rear==-1)
        {
            rear=0;
            front=0;
            arr[rear]=data;
        }
        //circular nature
        else if(rear==size-1 && front!=0)
        {
            rear=0;
            arr[rear]=data;
        }
        //normal case
        else{
            rear++;
            arr[rear]=data;
        }
    }

    void pushFront(int data)
    {
        //Full check
        if((rear==size-1 && front==0 )&&(rear==front-1))
        {
            cout<<"Q is Full..."<<endl;
        }
        //single element
       else if(front==rear && front==-1)
        {
            rear=0;
            front=0;
            arr[rear]=data;
        }
        //circular nature
        else if(front==0 && rear!=size-1)
        {
            front=size-1;
            arr[front]=data;
        }
        else{
            front--;
            arr[front]=data;
        }
    }

    void popFront()
    {
       //check empty or not 
        if(rear==-1 && front==-1)
        {
            cout<<"Q is Empty..."<<endl;
        }
        //single element
        else if(rear==front && front==0)
        {
            arr[rear]=-1;
            rear=-1;
            front=-1;
        }
        //circular nature
        else if(front==size-1)
        {
            arr[front]=-1;
            front=0;
        }
        //normal case
        else
        {
            arr[front]=-1;
            front++;
        }
    }

    void popRear(){
          if(front == -1) {
                        cout << "Q is empty , cannot pop" << endl;
                        return;
                }
                else if (front == rear) {
                        arr[front] = -1;
                        front = -1;
                        rear = -1;  
                }
                else if(rear == size-1) {
                        arr[rear] = -1;
                        rear = 0;
                }
                else {
                        arr[rear] = -1;
                        rear--;
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
int main()
{
    Deque dq(10);
  dq.print();

  dq.pushRear(10);
  dq.pushRear(20);
  dq.pushRear(30);
  dq.pushRear(40);
  dq.pushRear(50);
  dq.pushRear(60);
  dq.pushRear(70);
  dq.pushRear(80);

  dq.print();

  dq.popRear();
  dq.print();

  dq.popRear();
  dq.print();

  dq.popFront();
  dq.print();

    dq.popFront();
  dq.print();

    dq.popFront();
  dq.print();

  dq.pushFront(101);
  dq.print();

  dq.pushFront(102);
  dq.print();

  dq.pushFront(103);
  dq.print();

    dq.pushFront(104);
  dq.print();

  dq.popFront();
  dq.print();

  dq.popFront();
  dq.print();

  dq.pushRear(201);
  dq.print();

    dq.pushRear(202);
  dq.print();

    dq.pushRear(203);
  dq.print();
    dq.pushRear(204);
  dq.print();

    dq.pushRear(205);
  dq.print();

    return 0;

}