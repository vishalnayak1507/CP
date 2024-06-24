#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Handling edge case when n = 0
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        
        vector<int> wk;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            wk.push_back(a);
        }
        
        sort(wk.begin(), wk.end());
        wk.erase(unique(wk.begin(), wk.end()), wk.end());
        
        int idx = 0;
        int j = 0;
        int su = 1;
        
        for (int i = 0; i < wk.size(); i++) {
            while (j < wk.size() && wk[j] < wk[i] + n) j++;
            j--;
            su = j - i + 1;
            idx = max(idx, su);
        }
        
        cout << idx << endl;
    }
    return 0;
}
