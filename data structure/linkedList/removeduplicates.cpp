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
Node * removeDuplicates(Node * &head)
{
    Node * curr=head;
    while(curr!=NULL)
    {
        if(head==NULL)
        {
            return head;
        }
        if(curr->next!=NULL && curr->data==curr->next->data)
        {
            //Node * temp=curr->next;
            curr->next=curr->next->next;
           // temp->next=NULL;
            // temp;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}

void sort(Node * &head)
{   
    int one=0,zero=0,two=0;
    Node * temp=head;

    // if(head==NULL)
    // {
    //     return head;
    // }
   // cout<<"hello";
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero++;
        }
        if(temp->data==1)
        {
            one++; 
        }
        if(temp->data==2)
        {
            two++;
           
        }
        temp=temp->next;
    }

    temp=head;
    while(temp!=NULL)
    {
        while(zero--)
        {
            temp->data=0;
            temp=temp->next;
        }
        while(one--)
        {
            temp->data=1;
            temp=temp->next;
        }
        while(two--)
        {
            temp->data=2;
            temp=temp->next;
        }
    }
}
Node* sort2(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty " << endl;
                return NULL;
        }
        if(head -> next == NULL) {
                //sngle node in LL
                return head;
        }

        //create dummy nodes
        Node* zeroHead = new Node(-101);
        Node* zeroTail = zeroHead; 

        Node* oneHead = new Node(-101);
        Node* oneTail = oneHead; 

        Node* twoHead = new Node(-101);
        Node* twoTail = twoHead; 

        //traverse the original LL
        Node* curr = head;
        while(curr != NULL) {

                if(curr -> data == 0) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        zeroTail -> next = temp;
                        zeroTail = temp;

                }
                else if(curr -> data == 1) {
                        //take out the one wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        oneTail -> next = temp;
                        oneTail = temp;

                }
                else if(curr -> data == 2) {
                        //take out the zero wali node
                        Node* temp = curr;
                        curr = curr -> next;
                        temp -> next = NULL;

                        //append the zero node in zeroHead LL
                        twoTail -> next = temp;
                        twoTail = temp;

                }
        }

        //ab yha pr, zero , one, two, teeno LL readyv h 

        // join them 
        //remove dummmy nodes

        //modify one wali list
        Node* temp = oneHead;
        oneHead = oneHead -> next;
        temp -> next = NULL;
        delete temp;

        //modify two wali list
        temp = twoHead;
        twoHead = twoHead -> next;
        temp -> next = NULL;
        delete temp;

        //join list
        if(oneHead != NULL) {
                // one wali list is non empty
                //zero wali list ko one wali list se attach krdia 
                zeroTail -> next = oneHead;
                
                if(twoHead != NULL)
                        oneTail -> next = twoHead;
        }
        else{
                //one wali list is empty
                if(twoHead != NULL)
                        zeroTail -> next = twoHead;
        }

        //remove zerohead dummy Node
        temp = zeroHead;
        zeroHead = zeroHead -> next;
        temp -> next = NULL;
        delete temp;
        
        //return head of the modified linked list
        return zeroHead;

}
void print(Node * &head)
{
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
     Node *head=new Node(1);
    Node *Second=new Node(2);
    Node *third=new Node(2);
    Node *Fourth=new Node(1);
    Node *Fifth=new Node(0);
    Node *six=new Node(0);

    head->next=Second;
    Second->next=third;
    third->next=Fourth;
    Fourth->next=Fifth;
    Fifth->next=six;

    print(head);
    // head=removeDuplicates(head);
    // print(head);
    sort(head);

    print(head);

    sort2(head);
    print(head);
    return 0;
}