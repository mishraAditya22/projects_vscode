#include<iostream>
#include<string.h>
using namespace std;
class node{
    public:
        char data;
        node* next;
        node(int data){
            this->data = data;
            next = NULL;
        }
};
class stack{
    private:
        node * head;
    public:
        stack()
        {
            head = NULL;
        }
        void push(int element){
            node * n = new node(element);
            n->next = head;
            head = n;
        }
        char pop(){
            node * t =  head;
            head = head->next;
            return t->data;
            delete t;
        }
        bool isEmpty(){
            return head == NULL;
        }
        void display(){
            node * t = head;
            while(t!=NULL){
                cout<<t->data<<" ";
                t = t->next;
            }
            cout<<endl;
        }
};
void check(char * c){
    stack s;
    int size = strlen(c);
    for(int i=0;i<size;i++){
        if(c[i]=='(' || c[i] == '{' || c[i] == '['){
            s.push(c[i]);
        }
        else if(c[i]==')' || c[i] == '}' || c[i] == ']'){
            s.pop();
        }
    }
    int ans = s.isEmpty();
    //cout<<ans;
    if(ans==0){
        cout<<"un-balanced eqn"<<endl;
    }
    else if(ans==1){
        cout<<"balanced eqn"<<endl;
    }
    //cout<<s.isEmpty();
}

int main()
{
    char input[100];
    cin.getline(input,100);
    check(input);
    return 0;
}