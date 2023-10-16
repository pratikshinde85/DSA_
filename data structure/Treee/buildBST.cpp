#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
};

Node * buildBST(Node *&root ,int data){
        if(root==NULL){
            root=new Node(data);
            return root;
        }

        if(root->data>data){
            //left
            root->left=buildBST(root->left,data);
        }
        else{
             root->right=buildBST(root->right,data);
        }

        return root;
  
}

void takeInput(Node * &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=buildBST(root,data);
        cin>>data;
    }
}
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
bool searchingNode(Node * root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(root->data > target){
        //left search
        return searchingNode(root->left,target);
    }
    else{
      return searchingNode(root->right,target);
    }
    
}
int main(){
    Node * root=NULL;
    cout<<"Enter the data"<<endl;
    takeInput(root);
    LevelTraversal(root);
    bool ans=searchingNode(root,10);
    cout<<"Node found or not ? "<<ans<<endl;
    return 0;
}
//  10 20 5 11 17 2 4 8 6 25 15 -1