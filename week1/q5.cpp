#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>one;
        for(int i=0;i<n;i++){
            one[i]=nums[i];
        }
        for(int i=0;i<n;i++){
            int a=target-nums[i];
            for(auto entry:one){
                if(entry.second==a && entry.first!=i){
                    return {i,entry.first};
                    break;
                }
            }
        }
        return {-1,-1};
    }
    int main(){
        int t;
        cin>>t;
        
        while(t>0){
            int n;
            cin>>n;
            int k;
            cin>>k;
            vector<int>arr(n);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            vector<int> result = twoSum(arr, k);
            cout << result[0] << " " << result[1] << endl;
             t--;
        }
    }

