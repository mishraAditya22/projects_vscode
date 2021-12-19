#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data =  data;
            next = NULL;
        }
};
void insert(node *&head,int val){
    node * n = new node(val);
    if(head==NULL){
        head = n;
    }
    else{
        node *t = head;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = n;
    }
}
void reverse(node*head){
    node * p = head;
    node *q = NULL;
    node * r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
void display(node *head){
    node * t = head;
    while(t!=NULL){
        cout<<t->data<<"  ";
        t = t->next;
    }
}
int main()
{
    node * head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    reverse(head);
    display(head);
    return 0;
}