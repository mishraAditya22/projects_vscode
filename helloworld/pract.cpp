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
node * merging(node *head, node *g){
    node * p = head;
    node * q = g;
    node *start = NULL;
    node * fh = NULL;
    if(p->data < q->data){
        fh = p;
        start = p;
        p = p->next;
        fh->next = NULL;
        
    }
    else {
        fh = q;
        start = q;
        q = q->next;
        fh->next = NULL;
        
    }
    while(q!=NULL || p!=NULL){
        if(p->data>q->data){
            fh->next = q;
            fh = q;
            q = q->next;
        }
        else if(p->data<q->data){
            fh->next = p;
            fh = p;
            p = p->next;
        }
    }
    return start;
}


void create(node * &head,int a[],int len){
    node * n = new node(a[0]);
    head = n;
    node *t = head;
    for(int i=1;i<len;i++){
        node * v = new node(a[i]);
        t->next = v;
        t = t->next;
    }
}
void insert(node *&head,int val){
    node *t = head;
    node * n = new node(val);
    n->next = head;
    head = n;
}
void display(node * head){
    node * t  = head;
    while(t!=NULL){
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}
int main()
{
    node * head = NULL;
    node * g = NULL;
    int a[] = {1,2,3,4,5};
    create(head,a,5);
    int b[] = {7,8,9,10,11};
    create(g,b,5);
    display(head);
    display(g);
    node * st = merging(head,g);
    display(st);
    return 0;
}