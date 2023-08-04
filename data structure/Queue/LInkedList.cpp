#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;

    Node(){
        this->data=data;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }



};
void InsertAtLast(Node *head,Node *tail,int data)
    {
            Node * newNode=new Node(data);
            tail->next=newNode;
            tail=newNode; 

    }

void PrintLinkedList(Node * head)
{
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}
int main(){

    Node * head=new Node(10);
    Node * tail=head;
    //head->next=tail;
    head->next=NULL;

    InsertAtLast(head,tail,30);
    //InsertAtLast(head,tail,50);
    PrintLinkedList(head);

   
    return 0;

}