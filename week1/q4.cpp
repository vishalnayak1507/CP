#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int max_sum=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=max(sum+nums[i],nums[i]);
            max_sum=max(max_sum,sum);
        }
        return max_sum;
    }
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<maxSubArray(arr)<<endl;
        t--;
    }
    return 0;
}