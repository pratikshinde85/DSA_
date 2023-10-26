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
Node * BuildTree(){
        int data;
        cout<<"Enter the data"<<endl;
        cin>>data;
        if(data==-1){
            return NULL;
        }
        Node * root=new Node(data);

        cout<<"Enter the data for the left: "<<data<<endl;
        root->left=BuildTree();

        cout<<"Enter the data for the right: "<<data<<endl;
        root->right=BuildTree();

        return root;


}
void LevelTraversal(Node * root){
        if(root==NULL){
            return;
        }
        queue<Node *>q;
        q.push(root);

        while(!q.empty()){

                Node * temp=q.front();
                q.pop();

                cout<<temp->data<<" ";

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
        }
}
void topViewTraversal(Node * root){
    if(root==NULL){
        return;
    }
    queue<pair<int,Node *>>q;
    map<int,int>topNode;
    q.push(make_pair(0,root));

    while(!q.empty()){
        
            auto temp=q.front();
            int hd=temp.first;
            Node * val=temp.second;

            q.pop();

            if(topNode.find(hd)==topNode.end()){
                topNode[hd]=val->data;
            }

            if(val->left){
                q.push(make_pair(hd-1,val->left));
            }
            if(val->right){
                q.push(make_pair(hd+1,val->right));
            }
            
    }
        //ans will store in the map
        for(auto i: topNode){
            cout<<i.second<<" ";
        }
    

}
void bottomViewTraversal(Node * root){
    if(root==NULL){
        return;
    }
    queue<pair<int,Node *>>q;
    map<int,int>topNode;
    q.push(make_pair(0,root));

    while(!q.empty()){
        
            auto temp=q.front();
            int hd=temp.first;
            Node * val=temp.second;

            q.pop();

            if(topNode.find(hd)==topNode.end()){
                topNode[hd]=val->data;
            }
            if(topNode.find(hd)!=topNode.end()){
                topNode[hd]=val->data;
            }
            if(val->left){
                q.push(make_pair(hd-1,val->left));
            }
            if(val->right){
                q.push(make_pair(hd+1,val->right));
            }
            
    }
        //ans will store in the map
        for(auto i: topNode){
            cout<<i.second<<" ";
        }
    

}
void printLeafNode(Node * root){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        cout<<root->data;
    }
    printLeafNode(root->left);

    printLeafNode(root->right);
}
int main(){
    Node * root=BuildTree();
    LevelTraversal(root);
    cout<<"\n Printing the TopView Traversal"<<endl;
    topViewTraversal(root);
    cout<<"\n Printing the bottomView Traversal"<<endl;
    bottomViewTraversal(root);
    cout<<endl;
    printLeafNode(root);
    return 0;
}