#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTree{
    public:
        T data;
        BinaryTree <T>* left;
        BinaryTree<T>* right;
        BinaryTree(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

BinaryTree <int>* input2(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    BinaryTree<int> * root = new BinaryTree<int>(rootData);
    queue <BinaryTree<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"enter left data of "<<front->data<<endl;
        cin>>childData;
        if(childData!=-1){
            BinaryTree<int>* child = new BinaryTree<int>(childData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"enter right data "<<front->data<<endl;;
        int childData1;
        cin>>childData1;
        if(childData1!=-1){
            BinaryTree<int>* child = new BinaryTree<int>(childData1);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

BinaryTree <int>*  input1(){
    int rootData;
    cout<<"enter data "<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTree<int>* root = new BinaryTree<int>(rootData);
    BinaryTree<int>* leftnode  =  input1();
    BinaryTree<int>* rightnode = input1();
    root->left = leftnode;
    root->right = rightnode;
    return root;
}
//doesn't work for root->right
BinaryTree<int>* insertDuplicate(BinaryTree <int>* root){
    if(root==NULL){
        return 0;  
    }
    else{
        BinaryTree<int>* tmp = root->left;
        BinaryTree<int>* duplicateNode = new BinaryTree<int>(root->data);
        root->left = duplicateNode;
        duplicateNode->left = tmp;
        insertDuplicate(root->left->left);
        insertDuplicate(root->right);
    }
    return root;
}
//another method by gfg
//still error
void insertDuplicate1(BinaryTree <int>* root){
    BinaryTree<int>* oldLeft;
     
    if (root == NULL) {
        return ;
    }
     
    /* do the subtrees */
    insertDuplicate1(root->left);
    insertDuplicate1(root->right);
     
    /* duplicate this node to its left */
    oldLeft = root->left;
    root->left = new BinaryTree<int>(root->data);
    root->left->left = oldLeft;
    
}


void print(BinaryTree<int> * root){
    if(root!=NULL){
        cout<<root->data;
    }
    if(root->left!=NULL){
        cout<<"L-> "<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R-> "<<root->right->data<<" ";
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

int main()
{
    BinaryTree<int>* root = input2();
    BinaryTree<int>* rootNew = insertDuplicate(root);
    print(rootNew);
    return 0;
}