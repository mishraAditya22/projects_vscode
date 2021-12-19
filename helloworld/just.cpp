#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{
    public:
        T data;
        vector <TreeNode<T>*> children;
        TreeNode(int data){
            this->data = data;
        }
};
TreeNode<int>* Takeinput(){
    int rootData;
    cout<<"enter data"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"enter no of children"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = Takeinput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
int main()
{
    TreeNode<int> * root = Takeinput();
    printTree(root);

}