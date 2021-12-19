#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int val){
            data = val;
            next = NULL;
        }
};
void inserATtail(node*& head , int val){
    node * n = new node(val);
    if(head == NULL){
        head = n;
    }
    else{
        node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
    }
}
void dele(node *&head, int pos){
    node * y = head;
    node *a = head;
    if(pos==0){
        y = y->next;
        delete a ;
    }
    else{
        for(int i=0;i<pos-1;i++){
            y=y->next;   
        }
        node * b = y->next;
        node * c = b->next;
        delete b;
    }
}
void display(node * head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main()
{
    node * head = NULL;
    inserATtail(head,1);
    inserATtail(head,2);
    inserATtail(head,3);
    inserATtail(head,4);
    inserATtail(head,5);
    dele(head , 3);
    display(head);
    return 0;
}