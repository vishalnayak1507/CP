#include<iostream>
#include<vector>
#include<map>
using namespace std;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> one;
    map<int,int> two;
    int i = 0;
    int j = 0;
    while (j < nums.size()) {
        two[nums[j]]++;
        if (j - i + 1 == k) { 
            one.push_back(two.rbegin()->first); 
            two[nums[i]]--; 
            if (two[nums[i]] == 0) 
                two.erase(nums[i]);
            i++; 
        }
        j++; 
    }
    return one;
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
            vector<int>answer=maxSlidingWindow(arr,k);
            for (int i = 0; i < answer.size(); i++) {
            cout << answer[i] << " ";
            }
          cout << endl;
          t--;

        }
        return 0;
    }
    