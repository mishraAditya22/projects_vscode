#include<iostream>
using namespace std;
int r = 0;
int in=0;
int check(int x,int y){
    if(x==y){
        return r;  
    }
    else{
        return 'a';
    }
}


int fun1(int a[],int b[],int size,int x){
    
    if(r>size-1){
        return 0;
    }
    else{
        int s = check(x,a[r]);
        if(s!=97){
            b[in] = s;
            cout<<b[in]<<" ";
            in++;
        }
        r++;
        fun1(a, b, size , x);        
    }
}

int main(){
    int n,size,x;
    cin>>n;
    size = n;
    int first[n];
    for(int i=0;i<n;i++){
        cin>>first[i];
    }
    int sec[n];
    cin>>x;
    fun1(first,sec,size,x);
    
}