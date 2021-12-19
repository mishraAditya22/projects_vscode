#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node * next;
        node(int data){
            this->data = data;
            next = NULL;
        }
};
void insertAthead(node * & head, int val){
    node * n = new node(val);
    n->next = head ;
    head = n;
}
void insertAttail(node * & head , int val){
    node * n = new node(val);
    if(head == NULL){
        head = n;
    }
    else{
        node * tmp = head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = n;
    }
}
void insertATmid(node * &head, int val ,  int pos){
    node * n = new node(val);
    node * pre_node = head;
    for(int i=0;i<pos-1;i++){
        pre_node = pre_node->next;
    }
    node *  next_node = pre_node->next;
    pre_node->next = n;
    n->next = next_node;
}
void dele(node *head ,int pos ){
    node* tmp = head;
    if(pos==0){
        node * a = tmp->next;
        node * b = a->next;
        tmp->next = b;
        delete a;
    }
    else{
        for(int  i=0;i<pos-1;i++){
        tmp = tmp->next;
        }
        node * a = tmp->next;
        node * b = a->next;
        tmp->next = b;
        delete a;
    }
}
void imsearch(node *&head , int key){
    node * tmp = NULL;
    while(head!=NULL){
        if(head->data == key){
            tmp->next = head->next;
            tmp->next = head;
            head = tmp;
        }
        else{
            tmp = head;
            head = head->next;

        }
    }
}
void display(node * head){
    node * tmp = head;
    /*while(tmp!=NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }*/
    //displaying using recursion .
    if(tmp!=0){
        cout<<tmp->data<<" ";
        display(tmp->next);
    }
}
// func for adding linked lists data;
int sum(node * head){
    node * tmp = head;
    if(tmp!=NULL){
        return tmp->data+ sum(tmp->next);
    }
    else{
        return 0;
    }
}
void sg(node * head){
    node * tmp = head;
    cout<<endl<<tmp->next->next->data;
}
int main()
{
    node * head = NULL;
    insertAthead(head,1);
    insertAthead(head,2);
    insertAttail(head , 3);
    insertATmid(head , 8 ,2);
    insertATmid(head,6,3);
    //dele(head,2);
    //dele(head,0);
   /* display(head);
    cout<<sum(head);*/
    display(head);
    sg(head);
    return 0;
}