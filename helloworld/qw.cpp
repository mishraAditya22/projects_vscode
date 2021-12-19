#include<iostream>
using namespace std;
class node{
    public:
        long long data;
        char *phone_name;
        node * next;
        node(){
            long long n;
            cout<<"enter phone no :  "<<endl;
            cin>>n;
            data = n;
            next = NULL;
            char *b = new char[15];
            cout<<"enter only first name of person"<<endl;
            cin>>b;
            phone_name = b;
        }
};
void insert(node *& head){
    node * n = new node();
    n->next = head;
    head = n;
}
void dele(node * head){
    char c[15];
    cout<<"enter name of contact to delete it "<<endl;
    cin>>c;
    char * s = c;
    node * tmp = head;
    while(tmp->phone_name!=s){
        tmp = tmp->next;
    }
    node * a = tmp->next;
    tmp->next = a->next;
    delete a;
}
void searchByno(node * head){
    node * t = head;
    cout<<"enter no you want to delete "<<endl;
    long long m;
    cin>>m;
    while(t->data!=m){
        t = t->next;
    }
    node * a = t->next;
    cout<<"deleted no contact-name is   ->  "<<a->phone_name<<endl;
    t->next = a->next;
    delete a;
}
void display(node * head){
    node * t =head;
    while(t!=NULL){
        cout<<t->data<<" -> "<<t->phone_name<<endl;
        t =t->next;
    }
    cout<<endl;
}
int main()
{
    node * head = NULL;
    insert(head);
    insert(head);
    insert(head);
    display(head);
    //dele(head);
    //display(head);
    searchByno(head);
    return 0;
}