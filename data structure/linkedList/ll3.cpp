#include<iostream>
using namespace std;
class Node
{
    public: 
    int data;
    Node * next;
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    ~Node()
    {

    }
};
void insertAthead(Node *&head,Node *&tail,int data)
{
            Node *newNode=new Node(data);
           // newNode->data=data;
            newNode->next=head;
            if(head==NULL)
            { 
                tail=newNode;
                //newNode=tail;
            }
            
            head=newNode;
            
}
void insertatTail(Node *&tail,Node *&head,int data)
{
    //step1
    Node *newNode=new Node(data);

    //step2
    if(tail==NULL)
    {
        //tail=newNode;
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
   
    //step3
    tail=newNode;
   // tail->next=NULL;
}
void printll(Node *&head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int lenfind(Node *head)
{
  Node *temp=head;
  int len=0;
  while(temp!=NULL)
  {
    temp=temp->next;
    len++;
  }
  return len;
}
void insertatPosition(Node *&head,Node *&tail,int data,int position)
{  //empty ahe ki nahi check

    if(head==NULL)
    {
        Node *newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return ;
    }


    if(position==0)
    {
      insertAthead(head,tail,data);
      return;
    }
    int len=lenfind(head);
    if(position>=len)
    {
      insertatTail(tail,head,data);
      return ;
    }
    //step 1 position find
    
    Node *prev=head;
    int i=1;
    while(i<position)
    {
        prev=prev->next;
        i++;
    }
    Node *curr=prev->next;


    //step 2
    Node *newNode=new Node(data);

    //step3 
    newNode->next=curr;

    //step4
    prev->next=newNode;
}


void DeleteNode(Node *&head,Node *&tail,int position)
{
    if(head==NULL)
    {
        cout<<"Empty LL...";
        return;
    }

    if(position==1)
    {
        Node *temp=head;
       
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }

    int len=lenfind(head);
    if(position==len)
    {
        //prev find
        int i=1;
        Node *prev=head;
        while(i<position-1)
        {
            prev=prev->next;
            i++;
        }
        prev->next=NULL;
        Node* temp = tail;
                //step4:
        tail = prev;
        delete temp;
        return;
    }
 if(position>1 && position<len)
 {
    int i=1;
        Node *prev=head;
        while(i<position-1)
        {
            prev=prev->next;
            i++;
        }
        
        Node *curr=prev->next;
        prev->next=curr->next;
        Node *temp=curr;
        temp->next=NULL;
        delete temp;
        return;
 }
    if(position>len)
    {
        cout<<"No Node present at this positoin.."<<endl;
    }
} 
Node* middleNode(Node* head) {
       int len=lenfind(head); 
       cout<<len<<endl;
       if(len==1)
       {
           return head;
       }
       if(len==2 ||len==3)
       {
           return head->next;
       }
       if(len %2==0)
       {   
           Node * temp=head;
           int i=1;
           int len1=len/2;
           cout<<len1<<endl;
           while(i<len1)
           {
               // cout<<"helo"<<endl;
               temp=temp->next;
               //cout<<len<<endl;
               //cout<<i;
                i++;
               
           }
          Node * middle=temp->next;
           return middle;
       }
       
       else
       {
           Node * temp=head;
           int i=1;
           while(i<len%2-1)
           {
               temp=temp->next;
                i++;
           }
            Node * middle=temp->next;
            return middle->next;
       }
       return head;
    }

int main()
{

    // Node *First=new Node(10);
    // Node *Second=new Node(20);
    // Node *third=new Node(30);
    // Node *Fourth=new Node(11);
    // Node *Fifth=new Node(300);
    // Node *six=new Node();

    // First->next=Second;
    // Second->next=third;
    // third->next=Fourth;
    // Fourth->next=Fifth;
    // Fifth->next=six;

    //insertAthead(First,400);
    Node *head=NULL;
    Node *tail=NULL;
    insertAthead(head,tail,100); 
    insertatTail(tail,head,600);
    insertAthead(head,tail,10); 
    insertAthead(head,tail,20); 
    // insertatTail(tail,head,40);
    // insertatTail(tail,head,240);
    //First->data=1;
    cout<<"Linkded LISt is : "<<endl;
    printll(head);
    cout<<endl;

    // cout<<endl<<"after the updation:"<<endl;
    // insertatPosition(head,tail,70,0);
    // printll(head);

    // cout<<endl<<"Delete the node .."<<endl;
    // DeleteNode(head,tail,7);
    // printll(head);
    Node *ans=middleNode(head);
     cout<<ans->data<<endl;

    return 0;
}