#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class binaryTree{
    public:
        int data;
        binaryTree<T>* left;
        binaryTree<T>* right;
        binaryTree(int data){
            this ->data = data;
            left = NULL;
            right = NULL;
        }
};
binaryTree<int>* takeInput(){
    cout<<"enter data"<<endl;
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return 0;
    }
    binaryTree<int>* root=  new binaryTree<int>(rootData);
    binaryTree<int>* leftNode = takeInput();
    binaryTree<int>* rightNode = takeInput();
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

binaryTree<int>* TakeInput(){
    cout<<"enter data"<<endl;
    int rootData;
    cin>>rootData;
    binaryTree<int>* root = new binaryTree<int>(rootData);
    queue <binaryTree<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        binaryTree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter left data of "<<front->data<<endl;
        int LchildData;
        cin>>LchildData;
        if(LchildData!=-1){
            binaryTree<int>* child = new binaryTree<int>(LchildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"enter right data of "<<front->data<<endl;
        int RchildData;
        cin>>RchildData;
        if(RchildData!=-1){
            binaryTree<int>* child = new binaryTree<int>(RchildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int height(binaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->right),height(root->left));
}

int diameter(binaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = height(root->left);
    int option3 = height(root->right);
    return  max(option1,max(option2,option3));
}

bool balaned(binaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    int a=0 , b=0;
    a = height(root->left);
    b = height(root->right);
    if((a-b)>1){
        return false;
    }
    return (balaned(root->left)&&balaned(root->right));
}

int leafcount(binaryTree<int>* root){
    static int leaf_count=0;
    if(root==NULL){
        return 0;
    }
    
    leafcount(root->left);
    leafcount(root->right);
    if(root->right==NULL&&root->left==NULL){
        leaf_count++;
    }
    return leaf_count;
}

int sum(binaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    return root->data+ sum(root->right)+sum(root->left);
}

int sum_leaf_node(binaryTree<int>* root){
    static int sy  =0;
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        sy+= root->data ;
    }
    sum_leaf_node(root->left) ;
    sum_leaf_node(root->right);
    return sy;
}

void printBtree(binaryTree<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL){
        cout<<"L -> "<<root->left->data<<" ,";
    }
    if(root->right!=NULL){
        cout<<"R -> "<<root->right->data<<" ,";
    }
    cout<<endl;
    printBtree(root->left);
    printBtree(root->right);
}
int main()
{
    binaryTree<int>* root = TakeInput();
    printBtree(root);
    cout<<endl;
    //cout<<height(root)<<endl<<diameter(root)<<endl<<balaned(root);
    cout<<sum_leaf_node(root);

    return 0;
}