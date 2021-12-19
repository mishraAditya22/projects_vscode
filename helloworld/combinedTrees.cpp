#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T1>
class TreeNode{
    public:
        T1 data;
        vector <TreeNode<T1>*> children;
        TreeNode(T1 data){
            this->data = data;
        }
        
};
//input method 1 for genric trees..................
TreeNode <int>* takeInput1(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int no;
        cout<<"enter no of child"<<endl;
        cin>>no;
        for(int i=0;i<no;i++){
            int childData ;
            cout<<"enter data"<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
//input method 2 for genric trees...........
TreeNode<int>* takeInput2(){
    cout<<"enter data"<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>* root  = new TreeNode<int>(rootData);
    int no;
    cout<<"enter no of child "<<endl;
    cin>>no;
    for(int i=0;i<no;i++){
        TreeNode<int>* child = takeInput2();
        root->children.push_back(child);
    }
    return root;
}
//print tree...........
void printTree(TreeNode<int>* root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" .";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

template<typename T2>
class binaryTreeNode{
    public:
        T2 data;
        binaryTreeNode * left ;
        binaryTreeNode * right;
        binaryTreeNode(T2 data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~binaryTreeNode(){
            delete left;
            delete right;
        }
};

//input method 1 for binary trees.............
binaryTreeNode<int>* TakeInput1(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    queue<binaryTreeNode<int>*> pendingNodess;
    pendingNodess.push(root);
    while(pendingNodess.size()!=0){
        binaryTreeNode<int>* front = pendingNodess.front();
        pendingNodess.pop();
        cout<<"enter left Data of "<<front->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(leftData);
            front->left = child;
            pendingNodess.push(child);
        }
        cout<<"enter right data of "<<front->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            binaryTreeNode<int>* child = new binaryTreeNode<int>(rightData);
            front->right= child;
            pendingNodess.push(child);
        }
    }
    return root;
}

//input for binary tree method 2............
binaryTreeNode<int>* TakeInput2(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return 0;
    }
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    binaryTreeNode<int>*leftNode = TakeInput2();
    binaryTreeNode<int>* rightNode = TakeInput2();
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

//print binary trees.....

void PrintTree(binaryTreeNode <int>* root){
    if(root!=NULL){
        cout<<root->data;
    }
    if(root->left!=NULL){
        cout<<" L-> "<<root->left->data<<" .";
    }
    if(root->right!=NULL){
        cout<<" R-> "<<root->right->data<<" .";
    }
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}
int main()
{
    //genric_tree root by method 1..............
    TreeNode<int>* root1_m1 = takeInput1();
    printTree(root1_m1);
    //Genric_tree root by method 2...............
    TreeNode<int>* root1_m2 = takeInput2();
    printTree(root1_m2);
    //binary trees root by method 1..........
    binaryTreeNode<int>* root2_m1 = TakeInput1();
    PrintTree(root2_m1);
    //binary trees root 2 by method 2...........
    binaryTreeNode<int>* root2_m2 = TakeInput2();
    PrintTree(root2_m2);
    return 0;
}