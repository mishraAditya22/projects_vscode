#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class binaryTree{
    public:
        T data;
        binaryTree<T>* left;
        binaryTree<T>* right;
        binaryTree(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
binaryTree<int>* takeInut(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    binaryTree<int>* root = new binaryTree<int>(rootData);
    queue<binaryTree<int>* > pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0){
        binaryTree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"enter left data of "<<front->data<<endl;
        cin>>childData;
        if(childData!=-1){
            binaryTree<int>* child = new binaryTree<int>(childData);
            front->left  = child;
            pendingNodes.push(child);
        }
        int RchildData;
        cout<<"enter right data of "<<front->data<<endl;
        cin>>RchildData;
        if(RchildData!=-1){
            binaryTree<int>* child = new binaryTree<int>(RchildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

//bst searching here;
binaryTree<int>* b_search(binaryTree<int>* root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(root->data>key){
       return b_search(root->left,key);
    }
    return b_search(root->right,key);
}

template<typename C>
class node{
    public:
        C data;
        node * next;
        node(C data){
            this->data = data;
        }
};
//THIS SEGMENT WAS TO PRINT AND FORM A SORTED LINKED LIST FROM A BST..............

stack<int> setter;
int headHelper(binaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    headHelper(root->left);
    setter.push(root->data);
    headHelper(root->right);
}

node <int>* link_linked(stack<int> setter){
    node<int>* head= NULL;
    while(setter.empty()==0){
        int value = setter.top();
        node <int> * n = new node <int>(value);
        n->next = head;
        head = n;
        setter.pop();
    }
    return head;
}

void printLinked(node<int>* head){
    node <int>* tmp = head;
    while(tmp!=NULL){
        cout<<tmp->data<<" -> ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int minVal(binaryTree<int>* root){
    if(root==NULL){
        return 0;
    }
    if(root->left!=NULL){
        minVal(root->left);
        return root->data;
    }
}

void printTree(binaryTree<int>* root){
    if(root==NULL){
        return  ;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL){
        cout<<" L "<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<" R "<<root->right->data<<" ";
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    binaryTree<int>* root = takeInut();
    printTree(root);
    //binaryTree<int>* ans = b_search(root,5);
    //cout<<endl<<ans->data<<endl;
    /*headHelper(root);
    node<int>* head = link_linked(setter);
    printLinked(head);*/
    cout<<endl<<minVal(root);

    return 0;
}