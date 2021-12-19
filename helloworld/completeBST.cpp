#include<iostream>
#include<vector>
using namespace std;
class PriorityQueue{
    vector<int> pq;
    public:
        PriorityQueue(){
            //empty ........
        }
        bool isEmpty(){
            return pq.size()==0;
        }
        int getSize(){
            return pq.size();
        }
        int getMin(){
            if(isEmpty()){
                return 0;
            }
            return pq[0];
        }
        void insert(int data){
            pq.push_back(data);
            int childIndex  = pq.size()-1;
            while(childIndex>0){
                int ParentIndex = (childIndex-1)/2;
                if(pq[childIndex]<pq[ParentIndex]){
                    int tmp = pq[childIndex];
                    pq[childIndex] = pq[ParentIndex];
                    pq[ParentIndex] = tmp;
                }
                else{
                    break;
                }
                childIndex = ParentIndex;
            }
        } 
        int removeMin(){
            int ans = pq[0];
            pq[0] = pq[pq.size()-1];
            pq.pop_back();
            int parentIndex = 0;
            int leftChildIndex = 2*parentIndex+1 , rightChildIndex = 2*parentIndex+2 ;
            while(leftChildIndex<pq.size()){
                int minIndex = parentIndex;
                if(pq[minIndex]>pq[leftChildIndex]){
                    minIndex = leftChildIndex;
                }
                if(rightChildIndex <pq.size() && pq[rightChildIndex]<pq[minIndex]){
                    minIndex = rightChildIndex;
                }
                if(minIndex==parentIndex){
                    break;
                }
                int tmp = pq[minIndex];
                pq[minIndex] = pq[parentIndex];
                pq[parentIndex] = tmp;
                parentIndex = minIndex;
                leftChildIndex = 2*parentIndex+1;

            }
            return ans;
        }
};
int main()
{
    PriorityQueue p;
    p.insert(10);
    p.insert(1);
    p.insert(15);
    p.insert(18);
    p.insert(9);
    p.insert(121);
    p.insert(100);
    cout<<p.removeMin()<<" "<<p.getSize()<<" "<<p.getMin();
    return 0;
}