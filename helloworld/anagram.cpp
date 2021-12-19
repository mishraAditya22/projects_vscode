#include<iostream>
using namespace std;
int main()
{
    char a[] = "decimal";
    char b[] = "medical";
    int i,h[26] = {0};
    for(i=0;a[i]!='\0';i++){
        h[a[i]-97]+=1;
    }
    for(i=0;b[i]!=0;i++){
        h[b[i]-97]-=1;
        if(h[b[i]-97]<0){
            cout<<"not an anagram";
            break;
        }
        if(b[i]=='\0')
        {
            cout<<"it's a anagram ";
        }
    }
    return 0;
}