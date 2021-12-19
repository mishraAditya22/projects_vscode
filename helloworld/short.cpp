#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        int n,m;
        cin>>n>>m;
        int cities[n],travellers[m];
        for(int i=0;i<n;i++){
            cin>>cities[i];
        }
        for(int j=0;j<m;j++){
            cin>>travellers[j];
        }
        //1== left to right dir..
        //2 = right to left dir..
        //0== no train
        //-1 == if not possible..
        
        for(int i=1;i<=m;i++){
            int pos1=0,pos2=0;
            int destination = travellers[i];
            //destinatin to left side......
            for(int a=destination;a>=1;a--){
                if(cities[a]==1){
                    pos1=a;
                    break;
                }
            }
            //destination to right side ..........
            for(int b =destination;b<=n;b++){
                if(cities[b]==2){
                    pos2=b;
                    break;
                }
            }
            cout<<endl<<pos1<<"  "<<pos2<<endl;
            int step1 = destination-pos1;
            int step2 = pos2-destination;
            if(step1>=step2){
                cout<<step2<<endl;
            }
            else if (step1<step2){
                cout<<step1;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}