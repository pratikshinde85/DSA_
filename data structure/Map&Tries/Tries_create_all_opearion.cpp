#include<iostream>
using namespace  std;

class TriesNode{
    public:
    char data;
    TriesNode *children[26];
    bool terminal;

    TriesNode(char d){
        this->data=d;
        for(int i=0;i<26;i++){
            children[i]=NULL; 
            }

        this->terminal=false;
    }
};
void insertionTries(TriesNode * root,string word){
        //base case
        if(word.length()==0){
            root->terminal=true;
            return;
        }

        char ch=word[0];
        int index=ch - 'a';
        TriesNode *child;

        //present case
        if(root->children[index]!=NULL){
                child=root->children[index];
        }
        else{
          //absent  
          child=new TriesNode(ch);
         root->children[index]= child;
        }
        insertionTries(child,word.substr(1));
}
bool searchInTries(TriesNode * root,string word){
    // base case
    if(word.length()==0){
        return root->terminal;
    }
        char ch=word[0];
        int index=ch - 'a';
        TriesNode *child;

        //present case
        if(root->children[index]!=NULL){
                child=root->children[index];
        }
        else {
            return false;
        }
        return searchInTries(child,word.substr(1));
}
void deleteInTries(TriesNode * root,string word){
    // base case 
        if(word.length()==0){
            root->terminal=false;
            return;
        }
        char ch=word[0];
        int index=ch - 'a';
        TriesNode *child;

        if(root->children[index]!=NULL){
                child=root->children[index];
        }
       
     deleteInTries(child,word.substr(1));

}
void check(TriesNode * root,string word){
    if(searchInTries(root,"code")){
        cout<<"present"<<endl;
    }
    else{
        cout<<"absent"<<endl;
    }
}
int main(){

    TriesNode *root=new TriesNode('-');
    insertionTries(root,"code");
    insertionTries(root,"codey");
    insertionTries(root,"codecheif");
    check(root,"code");
    deleteInTries(root,"code");
    check(root,"code");
    
    deleteInTries(root,"codecheif");
    check(root,"codecheif");
    insertionTries(root,"code");
    check(root,"code");
    insertionTries(root,"codecheif");
    check(root,"codecheif");
    return 0;
}