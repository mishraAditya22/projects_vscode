#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data = data;
            next = NULL;
        }
};
class queue{
    private:
        node * head ;
    public:
        queue(){
            head = NULL;
        }
        void enqueue(int element){
            node * n = new node(element);
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
        void dequeue(){
            node * t = head;
            head = head->next ;
            delete t;
        }
        void display(){
            node * t = head;
            while(t!=NULL){
                cout<<t->data<<"  ";
                t = t->next;
            }
            cout<<endl;
        }
};
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.display();
    return 0;
}
