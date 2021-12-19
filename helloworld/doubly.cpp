#include<iostream>
using namespace std;
class node{
    public:
        node * prev;
        int data;
        node * next;
        node(int data){
            prev = NULL;
            this->data = data;
            next = NULL;
        }
};
void insert(node *& head, int val){
    node * t = head;
    node * n = new node(val);
    if(head == NULL){
        head = n;
        t = n;
    }
    else {
        while(t->next!=NULL){
            t =t->next;
        }
        t->next=n;
        n->prev = t;
    }
}
void display(node * head){
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
    insert(head,3);
    insert(head,20);
    display(head);
    return 0;
}