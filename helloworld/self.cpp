#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next;
        node (int val){
            data = val;
            next = NULL;
        }
};
void display(node * head){
    while(head!=NULL){
        cout<<head->data<<"->>";
        head = head->next;
    }
}
int main()
{
    node* head = NULL;
    node * n = new node(1);
    node * n2 = new node(2);
    node * n3 = new node(3);
    head = n;
    n->next = n2;
    n2->next=n3;
    display(head);
    return 0;
}