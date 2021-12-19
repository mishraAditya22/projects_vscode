#include<iostream>
using namespace std;
template<class T>
class node {
    public:
        T data;
        node <T> *  next;
        node(int data){
            this->data = data ;
            next = NULL;
        }
};
template<class R>
class stack{
    private:
        int Top;
        int size;
        R * data;
    public:
        stack(size){
            this->size = size;
            data = new <R>[size];
            Top=0;
        }

};
int main()
{
    return 0;
}