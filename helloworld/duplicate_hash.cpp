#include<iostream>
using namespace std;
int main()
{
    char a[] = "finding";
    int i, h[26] = {0};
    for(i=0;a[i]!='\0';i++){
        h[a[i]-97]+=1;
    }
    for(i=0;i<26;i++){
        if(h[i]>1){
            char c = i+97;
            cout<<"duplicate found here"<<"  "<<c;
            cout<<endl;

        }
    }
    char s[] = "aditya";
    cout<<s;
    return 0;
}