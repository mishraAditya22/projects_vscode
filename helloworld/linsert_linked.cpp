#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node * next;
        node(int val){
            data = val;
            next = NULL;
        }
};
void inserATtail(node *&head,int val){
    node *tail = head;
    node * n = new node(val);
    if(head == NULL){
        head = n;
        tail = n;
    }
    
    else{
        //node *n1 = new node(va);
        node *tmp = head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = n;
    }
    
}
void insertAThead(node *&head, int val){
    node * n = new node(val);
    n->next=head;
    head = n;
}
void insertATmid(node *&head , int val,int position){
    node * n = new node(val);
    node *tmp = head;
    for(int i=0;i<position-1;i++){
        tmp = tmp->next;
    }
    node * nextnode = tmp->next;
    tmp->next = n;
    n->next = nextnode;
}
void display(node * head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    node *head = NULL;
    /*inserATtail(head,1);
    inserATtail(head,2);
    inserATtail(head,3);
    inserATtail(head,4);
    inserATtail(head,5);
    inserATtail(head,6);
    display(head);*/
    //takig enries using for loop.
    for(int i=0;i<6;i++){
        int a;
        cin>>a;
        inserATtail(head,a);
    }
    insertAThead(head,7);
    insertATmid(head , 8,1);
    display(head);
    return 0;
}