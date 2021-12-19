#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int data){
            this ->data = data;
            this->next = NULL;
        }  
};
void create(node * &head ,  int a[],int len){
    node * n = new node(a[0]);
    head = n;
    node * tmp= head;
    for(int i=1;i<len;i++){
        node * n1 = new node(a[i]);
        tmp->next = n1;
        tmp = n1;
    }
}
void display(node* head){
    node * t = head;
    while (t!=NULL){
        cout<<t->data<<" ";
        t= t->next;
    }
}
int main()
{
    node * head = NULL;
    int ar[]= {1,2,3,4,5,6};
    create(head,ar,6);
    display(head);
    return 0;
}