#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>

using namespace std;

int shortestsubarray(vector<int>& nums, int k) {
    int min_length = INT_MAX;
    int n = nums.size();
    vector<long long> two(n + 1, 0);
    deque<int> one;
    for (int i = 0; i < n; ++i) {
        two[i + 1] = two[i] + nums[i];
    }
    for (int i = 0; i <= n; ++i) {  
        while (!one.empty() && two[i] - two[one.front()] >= k) {
            min_length = min(i - one.front(), min_length);
            one.pop_front();
        }

        
        while (!one.empty() && two[i] <= two[one.back()]) {
            one.pop_back();
        }

        one.push_back(i);
    }

   
    if (min_length == INT_MAX) {
        return -1;
    } else {
        return min_length;
    }
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << shortestsubarray(arr, k) << endl;
        t--;
    }
    return 0;
}
