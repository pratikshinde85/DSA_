#include<iostream>
#include<queue>
using namespace std;
class Node {
    public:
    int data;
    Node * left;
    Node *right;
    Node(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
};
Node * buildTree(){
        int data;
        cout<<"Enter the Data"<<endl;
        cin>>data;
        if(data==-1){
            return NULL;
        }
        //step 1
        Node * root= new Node(data);
        cout<<"Enter left child of "<<data<<" "<<endl;

       //step2
        root->left=buildTree();
        cout<<"Enter right child of"<<data<<" "<<endl;

        //step 3
        root->right=buildTree();


       return root;


}

void LevelWiseTraversal(Node *root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp=q.front();
       // q.push(NULL);
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                    q.push(NULL);
            }
               
        }
        else{
                cout<<temp->data<<" ";
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
        }
        
    }
}
void Inorder(Node * root){

    if(root==NULL){
        return ;
    }
    Inorder(root->left);

    cout<<root->data<<" ";

    Inorder(root->right);
}
void preOrder(Node * root){

    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    preOrder(root->left);

    preOrder(root->right);
}
void postOrder(Node * root){

    if(root==NULL){
        return;
    }
    postOrder(root->left);
    
    postOrder(root->right);
    cout<<root->data<<" ";

}

  int Height(Node * root){
      if(root==NULL){
        return  0;
      }

      int op1=Height(root->left);
      int op2=Height(root->right);

      int ans=max(op1,op2)+1;

      return ans;
  }
int main(){

    Node * root=NULL;
    root= buildTree();

    LevelWiseTraversal(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    
    int ans=Height(root);
    cout<<"Height of Tree"<<endl;
    cout<<ans-1<<endl;
    return 0;
}