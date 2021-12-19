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
void insertAthead( node * &head , int no){
            node * n = new node(no);
            n->next = head;
            head = n;
}
void insertAttail(node* &head, int val){
    node * n = new node(val);
    node * temp = head;
    while(temp->next!=NULL){
        temp  = temp->next;
    }
    temp->next =  n;
}
void display( node* head){
    node * temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}     
int main()
{
    node *head = NULL;
    insertAthead(head,5);
    insertAthead(head , 4);
    insertAthead(head,3);
    insertAttail(head,2);
    display(head);
    return 0;
}