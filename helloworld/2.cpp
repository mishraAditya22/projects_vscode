#include<iostream>
#include <vector>
using namespace std;
static int index=0;
int c=0;
int y =0;
int c2=0;
int minu = 0;
void remove_duplicates(int* arr, int& n) {
	int k = 0;
	for (int i = 0; i < n; ++i) {
		int flag = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] == arr[i]) {
				flag = 0;
				break;
			}
		}
		if (flag)
			swap(arr[k++], arr[i]);
	}
	n = k;
}
void check2(int x[],int a[],int n,int n2){
    for(int i=0;i<n2;i++){
        for(int j=0;j<n;j++){
            if(x[i] == a[j]){
                c2++;
            }
        }
    }
}
void  check(int x,int y, int z){
    if(x==y==z){
        minu++;
        c++;
        index+=3;
        
    }
    else if(x==y-1==z-2){
        c++;
        index+=3;
    }
    else{
        index++;
    }
}
int check_triplets(int array[], int n){
    if(index>=n-2){
        return 0;
    }
    else if(index<n-2){
        check(array[index],array[index+1],array[index+2]); 
        check_triplets(array,n);
    }
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int a[n],x[n];
    for(int i=0;i<n;i++){
        int entry;
        cin>>entry;
        if(entry<=m){
            a[i] = entry;
            x[i] = entry;
        }
    }

    check_triplets(a,n);
    remove_duplicates(x, n);
    for(int i=0;i<n;i++){
        y++;
    }
    
    check2(x,a,n,y);
    cout<<minu<<" "<<c2;
    //cout<<c2<<" "<<minu;
    /*int final = c + (c2- minu*3)/3;
    cout<<final;*/
    return 0;  
}