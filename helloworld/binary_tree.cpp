#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class binaryTree{
    public:
        T data;
        binaryTree <T>* leftNode;
        binaryTree <T>* rightNode;
        binaryTree(T data){
            this -> data = data;
            rightNode = NULL;
            leftNode = NULL;
        }
        ~binaryTree(){
            delete leftNode;
            delete rightNode;
        }
};
binaryTree<int>* takeInput(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    binaryTree<int>* root = new binaryTree<int>(rootData);
    binaryTree<int>* leftchild = takeInput();
    binaryTree<int>* rightchild = takeInput();
    root->leftNode = leftchild;
    root->rightNode = rightchild;
    return root;
}

binaryTree<int>* inputLevelWise(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    binaryTree <int>* root = new binaryTree<int>(rootData);
    queue <binaryTree<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        binaryTree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter child data of  "<<front->data<<endl;
        int leftchildData;
        cin>>leftchildData;
        if(leftchildData!=-1){ 
            binaryTree<int>* child = new binaryTree<int>(leftchildData);
            front->leftNode = child;
            pendingNodes.push(child);
        }
        cout<<"enter child data of  "<<front->data<<endl;
        int rightchildData;
        cin>>rightchildData;
        if(rightchildData!=-1){ 
            binaryTree<int>* child = new binaryTree<int>(rightchildData);
            front->rightNode = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void  printTree(binaryTree<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" :";
    if(root->leftNode!=NULL){
        cout<<"L  "<<root->leftNode->data<<" , ";
    }
    if(root->rightNode!=NULL){
        cout<<"R  "<<root->rightNode->data<<" , ";
    }
    cout<<endl;
    printTree(root->leftNode);
    printTree(root->rightNode);
}
int main()
{
    /*binaryTree<int>* root = new binaryTree<int>(1);
    binaryTree<int>* node1 = new binaryTree<int>(2);
    binaryTree<int>* node2 = new binaryTree<int>(3);
    binaryTree<int>* node3 = new binaryTree<int>(4);
    binaryTree<int>* node4 = new binaryTree<int>(5);
    root->leftNode = node1;
    root->rightNode = node2;
    node2->leftNode = node3;
    node2->rightNode = node4;*/
    binaryTree<int>* root = takeInput();
    printTree(root);
    //delete root;
    return 0;
}