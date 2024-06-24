#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int XOR(vector<int>& arr, int m) {
    unordered_map<int, int> one;
    int sum = 0;
    int result= 0;

    one[0] = 1;

    for (int num : arr) {
        sum ^= num;
        if (one.find(sum ^ m) != one.end()) {
            result+= one[sum ^ m];
        }

        one[sum]++;
    }
    return result;
}

int main() {
        int t;
        cin>>t;        
        while(t>0){
            int n;
            cin>>n;
            int m;
            cin>>m;
            vector<int>arr(n);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            cout<<XOR(arr,m)<<endl;
             t--;
        }

    return 0;
}
