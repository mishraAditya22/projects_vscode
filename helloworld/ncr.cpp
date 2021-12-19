//program for combination formula .
#include<iostream>
using namespace std;
int a,b,c1;
int recursion(int n){
    if(n>1){
        return n*recursion(n-1);
    }
    else {
        return 1;
    }
}
int output(int no,int co){
    int result;
    
    a = recursion(no);
    b = recursion(co);
    c1 = recursion(no-co);
    result = a/(b*c1);
    return result;
}
int main()
{
    int n,c;
    cout<<"enter the value of n and c respectively :  "<<endl;
    cin>>n>>c;
    cout<<"cobination formula result is :   ";
    cout<<output(n,c);
    return 0;
}