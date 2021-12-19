#include<iostream>
using namespace std;
template<typename T>
class BinaryTree{
    public:
        T data;
        BinaryTree<T>* left;
        BinaryTree<T>* right;
        BinaryTree(T data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~BinaryTree(){
            delete left;
            delete right;
        }
};
template <typename C>
class BST{
    private:
        BinaryTree <C>* root;
    public:
        root= NULL;
    private:
        BinaryTree<int> * input(int data , BinaryTree<int>* root){
            if(root==NULL){
                BinaryTree<int>* newNode = new BinaryTree<int>(data);
                return newNode;
            }
            if(root->data>data){
                root->left = input(data , root->left);
            }
            else if(root->data<data){
                root->right =input(data,root->right);
            }
            return root;
        }
    public:
        void input(int data){
            this->root = input(data,this->root);
        }
    private:
        BinaryTree<int>* deleteData(int data,BinaryTree<int>* root){
            if(root== NULL){
                return NULL;
            }
            if(root->data >data){
                root->left = deleteData(data,root->left);
            }
            else if(root->data<data){
                root->right = deleteData(data,root->right);
            }
            else{
                if(root->left==NULL and root->right ==NULL){
                    return NULL;
                }
                else if(root->left==NULL){
                    BinaryTree<int>* tmp = root;
                    root->right= NULL;
                    delete root;
                    return tmp;
                }
                else if(root->right ==NULL){
                    BinaryTree<int>* tmp  = root;
                    root->left = NULL;
                    delete root;
                    return tmp;
                }
                else{
                    BinaryTree<int>* minNode = root->right;
                    while(minNode!=NULL){
                        minNode = minNode->left;
                    }
                    int minData= minNode->data;
                    root->data = minData;
                    root->right = deleteData(minData,root->right);
                    return root;
                }
            }
        }
};