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
    char * c = new char[15];
    cout<<"enter name of contact to delete it "<<endl;
    cin>>c;
    node * tmp = head, *tmp1=NULL;
    while(tmp->phone_name!=c){
        tmp1=tmp;
        tmp = tmp->next;
    }
    tmp1->next = tmp->next;
    delete tmp;
    tmp = tmp1->next;
    delete c;
}
void searchByno(node * head){
    node * t = head, *q=NULL;
    cout<<"enter no you want to delete "<<endl;
    long long m;
    cin>>m;
    while(t->data!=m){
        q = t;
        t = t->next;
    }
    q->next = t->next;
    cout<<"deleted no contact-name is   ->  "<<t->phone_name<<endl;
    delete t;
    t = q->next;
}
void modify(node * head){
    node * t = head, *q=NULL;
    cout<<"enter no you want to modify "<<endl;
    long long m;
    cin>>m;
    while(t->data!=m){
        q = t;
        t = t->next;
    }
    node * a = q->next;
    cout<<"enter new name "<<endl;
    char * nm = new char[15];
    cin>>nm;
    a->phone_name = nm;
}
void sort(node * head){
       
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
    char ch;
    do{
        int operaton;
        cout<<"1 -- to add  to contacts  "<<endl;
        cout<<"2 -- to delete   contact by writing name of person  "<<endl;
        cout<<"3 -- to delete   contact by writing number of person  "<<endl;
        cout<<"4 -- to display all contacts in order of recently added first "<<endl;
        cout<<"5 -- to modify   contacts  "<<endl;
        cout<<"enter operation no you want to perform "<<endl;
        cin>>operaton;
        if(operaton==1){
            insert(head);
        }
        else if (operaton==2){
            dele(head);
        }
        else if (operaton==3){
            searchByno(head);
        }
        else if (operaton==4){
            display(head);
        }
        else if (operaton==5){
            modify(head);
        }
        cout<<"enter 'y' to continue on operation or 'n' to end operations further "<<endl;
        cin>>ch;
    }while(ch=='y');
    //end of loop here...........
    return 0;
}