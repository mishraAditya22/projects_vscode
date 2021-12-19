
// program code for circular linkd lists..........................

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next ;
    node(int data){
        this->data = data;
        next = NULL;
    }
};
void create(node *&head,int a[] , int len){
    node * n = new node(a[0]);
    head = n;
    node * t = head;
    for(int i=1;i<len;i++){
        node * v = new node(a[i]);
        t->next = v;
        t = t->next;
    }
    t->next = head;
}
void insertATmid(node * &head, int val,int pos){
    node * n = new node(val);
    node * t = head;
    for(int i=0;i<pos-1;i++){
        t = t->next;
    }
    n->next = t->next;
    t->next = n;
}
void display(node * head){
    node * tmp = head;
    do{
        cout<<tmp->data<<"  ";
        tmp = tmp->next;
    }while(tmp!=head);
    cout<<endl;
}
int main()
{
    node *head = NULL;
    int ar[] = {1,2,3,4,5};
    create(head,ar,5);
    display(head);
    insertATmid(head,6,3);
    display(head);
    return 0;
}