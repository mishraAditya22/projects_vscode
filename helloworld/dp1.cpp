#include<iostream>
#include<unordered_map>
using namespace std;
//brute force soln....................
int min_steps(int n,int steps){
    if(n<=1){
        return steps;
    }
    int a = min_steps(n-1,steps+1);
    int b= INT8_MAX,c=INT8_MAX;
    if(n%2==0){
        b = min_steps(n/2,steps+1);
    }
    if(n%3==0){
        c = min_steps(n/3,steps+1);
    }
    return min(a,min(b,c));
}

//memoiziation soln...............
int min_steps1(int n,int steps, unordered_map<int,int>* forCheck){
    if(n<=1){
        return steps;
    }
    if(forCheck->count(n)>0){

    }

}
void min_steps1(int n, int steps){
    unordered_map<int,int> forCheck;
}
int main()
{
    int n;
    cin>>n;
    cout<<min_steps( n, 0);
    return 0;
}