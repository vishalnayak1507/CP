#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findMin(vector<int>& nums){
    
    int first=0;
    int last=nums.size()-1;
    while(first<=last){
        int mid=(first+last)/2;
        if(nums[first]<=nums[mid] && nums[mid]<=nums[last]){
            return nums[first];
        }
        else if((nums[mid]<nums[mid+1])&& (nums[mid]<nums[mid-1])){
            return  nums[mid];
        }
        else if((nums[mid]>=nums[first]) &&(nums[mid]>nums[last])){
                first=mid+1;
            }
        else if((nums[mid]<=nums[first]) &&(nums[mid]<nums[last])){
                last=mid-1;
            }
    }

    return nums[0];


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
    cout<<findMin(arr)<<endl;
    t--;
    }
    return 0;
}