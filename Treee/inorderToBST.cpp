#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;

        Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

void LevelTraversal(Node * root){
        if(root==NULL){
            return;
        }
        queue<Node *>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){

                Node * temp=q.front();
                q.pop();
                if(temp==NULL){
                    cout<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    cout<<temp->data<<" ";

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                }
              
        }
}
Node * ConstructToBST(vector<int>&ans,int s,int e){
    if(s>e){
        return NULL;
    }

    int mid=(s+e)/2;

    int element=ans[mid];
    Node * root=new Node(element);
    root->left=ConstructToBST(ans,s,mid-1);

    root->right=ConstructToBST(ans,mid+1,e);
    return root;
}
void ConstructToDLL(Node * root,Node *&head){
    if(root==NULL){
        return;
    }

    //right solve karna hai
    ConstructToDLL(root->right,head);
    //root ko add karo
    root->right=head;

    if(head!=NULL){
        head->left=root;
    }

    //head update
    head=root;

    //left call
    ConstructToDLL(root->left,head);
}
void printDLL(Node * head){
    Node * temp=head;
    cout<<endl;
    while(head!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}
int main(){

    vector<int>inorder{300,400,450,500,550,600,700};
    int s=0;
    int e=inorder.size()-1;
    Node * root=ConstructToBST(inorder,s,e);
    LevelTraversal(root);
    Node * head=NULL;
    ConstructToDLL(root,head);
    printDLL(head);
    return 0;
}





