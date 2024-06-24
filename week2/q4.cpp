#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
using namespace std;


int minimumDistance(pair<int, int> c1, pair<int, int> c2) {
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        
       
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            points[i] = {a[i], a[2*n - i - 1]};
        }
        
       
        int pathLength = 0;
        for (int i = 0; i < n - 1; i++) {
            pathLength += minimumDistance(points[i], points[i + 1]);
        }
        
        cout << pathLength << endl;
        for (int i = 0; i < n; i++) {
            cout << points[i].first << " " << points[i].second << endl;
        }
    }
    return 0;
}
