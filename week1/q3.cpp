#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        for(int i=0;i<n-1;i++){
            int first=i+1;
            int last=n-1;
            int a=target-numbers[i];
            while(first<=last){
                int mid=(first+last)/2;
                if(numbers[mid]==a){
                    return {i+1,mid+1};
                }
                else if(numbers[mid]>a){
                    last=mid-1;
                }
                else{
                    first=mid+1;
                }
            }
        }
        
        return {-1,-1};
        }
        int main(){
            int t;
            cin>>t;
            while(t>0){
                int n,k;
                cin>>n>>k;
                vector<int>arr(n);
                for(int i=0;i<n;i++){
                    cin>>arr[i];


                }
                vector<int>result=twoSum(arr,k);
                cout<<result[0]<<" "<<result[1]<<endl;
                t--;


            }
        }