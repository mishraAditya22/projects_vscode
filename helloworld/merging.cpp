#include<iostream>
using namespace std;
class merg
{
    private:
        int length1 = 5;
        int length2 = 5;
        int *p = new int [length1];
        int *p1 = new int [length2];
        int *p2 = new int [length1+length2];
    public:
        merg(){
            for(int i=0;i<length1;i++){
                cin>>p[i];
            }
            for(int j=0;j<length2;j++){
                cin>>p1[j];
            }
        }
        void display(){
            for(int j=0;j<length1+length2;j++){
                cout<<p2[j]<<"  ";
            }
       
        }
        // mering two arrays......
        void merging(){
            int i=0,j=0,k=0;
            while(i<length1 && j<length2){
                if(p[i]<p1[j]){
                    p2[k++] = p[i++];
                }
                else{
                    p2[k++] = p1[j++];
                }
                for(;i<length1;i++){
                    p2[k++] = p[i];
                }
                for(;j<length2;j++){
                    p2[k++] = p1[j];
                }
            }
        }
        
};
int main()
{
    merg m;
    void merging();
    m.display();

    return 0;
}