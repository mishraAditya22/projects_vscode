#include<iostream>
using namespace std;
class queue{
    private:
        int *data;
        int rear;
        int size;
    public:
        queue(int size){
            this->size = size;
            rear = -1;
            data = new int[size];
        }
        void enqueue(int element){
            if(rear==size){
                cout<<"queue is full"<<endl;
            }
            else{
                rear++;
                data[rear] = element;
            }
        }
        void dequeue(){
            if(rear== -1){
                rear = rear;
                cout<<"queue is already empty"<<endl;
            }
            else{
                for(int i=1;i<=rear;i++){
                    data[i-1] = data[i];
                }
                rear--;
            }
        }
        void show(){
            cout<<rear;
        }
        void display(){
            for(int i=0;i<=rear;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        bool isEmpty(){
            return rear == -1;
        }
};
int main()
{
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    //q.dequeue();   
    q.display();
    cout<<q.isEmpty()<<endl;
    q.show();
    return 0;
}