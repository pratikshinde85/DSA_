#include <iostream>
using namespace std;
class Node {
    public :
        int data;
        Node * prev;
        Node * next;


        Node()
        {
            this->data=0;
            this->next=NULL;
            this->prev=NULL;
        }

        Node(int data)
        {
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
};

void print(Node *&head){
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int getLength(Node *&head){
    Node * temp=head;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}

void insetAtHead(Node *&head,Node *&tail,int data){
    //ll is empty
    if(head==NULL)
    {
        Node * newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //ll is not empty
    //step1
     Node * newNode=new Node(data);
     //step2
     newNode->next=head;

     //step3
      head->prev=newNode;

      //step4

      head=newNode;


}

void insetAtTail(Node *&head,Node *&tail,int data){
    //ll is empty
    if(head==NULL)
    {
        Node * newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    //LL is not empty

   // step1
    Node * newNode=new Node(data);

    //step 2

    tail->next=newNode;
    //step 3

    newNode->prev=tail;

    //step4
    tail=newNode;

}


void insertAtPosition(Node* & head,Node * & tail,int data,int position){
    //if position is 1

    if(position==1){
    insetAtHead(head,tail,data);
        return;
    }

    //if postion is last measn tail
    int len=getLength(head);
    if(position==len) {
        insetAtTail(head,tail,data);
        return;
    }
    //insertion at middle

    //step1
    Node * newNode=new Node(data);
    //step2
    //prevnode and curr node find

    int i=1;
    Node * prevNode=head;
    while(i<position-1)
    {
        prevNode=prevNode->next;
        i++;
    }
    Node * currNode=prevNode->next;

    //step 3;
    prevNode->next=newNode;
    newNode->prev=prevNode;

    //step4

    newNode->next=currNode;
    currNode->prev=newNode;



}
int main() {
Node *first=new Node(10);
Node *second=new Node(30);
Node *third=new Node(50);

first->next=second;
second->prev=first;


second->next=third;
third->prev=second;

print(first);

cout<<endl;

insetAtHead(first,third,70);
print(first);

cout<<endl;
insetAtTail(first,third,90);

print(first);

cout<<endl;
insertAtPosition(first,third,100,5);
print(first);

cout<<endl;
insertAtPosition(first,third,300,1);
print(first);

cout<<endl;
 return 0;
}