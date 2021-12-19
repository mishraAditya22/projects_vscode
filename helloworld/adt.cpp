#include<iostream>
using namespace std;
class array
{
    private:
        int length;
        int size;
        int * ar = new int [length];
    public:
        // this set function is used to store data members with their values..
        void set(int a, int b){
            length = a;
            size = b;
            int c[length];
            for(int i=0;i<length;++i){
                cin>>c[i];
                ar[i] = c[i];
            }
        }
        // this append func is made to append digits/elements at the last of array if size is still left...
        void append(int x){
            if(length<size){
                ar[length++] = x;
            }
            
        }
        void insert(int index, int h){
            for(int i=length;i>index;i--){
                ar[i] = ar[i-1];
            }
            ar[index] = h;
            length++;
        }
        void delete_ele(int y){
            int f = ar[y];
            for(int i=y;i<length-1;i++){
                ar[i]=ar[i+1];
            }
            length--;
        }
        int  display(){
            for(int j=0;j<length;++j){
                cout<<ar[j]<<"  ";
            }
            cout<<endl;
        }
        void show(){
            cout<<length<<" is the length and  "<<size <<" is size  "<<endl;
        }
        

};
int main ()
{
    array am;
    am.set(5,8);
    am.display();
    am.show();
    //int t=6;
    am.append(6);
    am.display();
    am.show();
    am.insert(3,9);
    am.display();
    am.show();
    am.delete_ele(3);
    am.display();
    am.show();
    return 0;
}