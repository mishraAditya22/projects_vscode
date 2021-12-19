#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void maxCost(int  no[], char  label[], int n, int d, int M_cost){
    int i=1,tmp=0,b=i-1;
    while(n>0){
        if(label[b]=='L' and i%d==0){
            if(tmp==0){
                if(no[b]>M_cost){
                    M_cost = no[i];
                }
            }
            else{
                tmp += no[b];
                if(M_cost<tmp){
                    M_cost = tmp;
                    
                }
                tmp = 0;
            }
            n--;
        }   
        if(label[b] == 'L' and i%d!=0){
            tmp += no[b];

        }
        if(label[b] =='I' ){
            tmp+=no[b];
        } 
    }
}
int main()
{
    int n,d;
    cin>>n>>d;
    int  no[n];
    for(int i =0;i<n;i++){
        cin>>no[i];
    }
    char label[n];
    for(int j=0;j<n;j++){
        cin>>label[j];
    }
    return 0;
}