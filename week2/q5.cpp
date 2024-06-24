#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        map<int, vector<int>> POSITION; 
        
        
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            POSITION[x].push_back(i);  
        }
        
       
        for (int j=k;j>0;j--) {
            int a, b;
            cin >> a >> b;
            
            
            if (POSITION.count(a) && POSITION.count(b)) {
                
                if (POSITION[a][0] < POSITION[b][POSITION[b].size() - 1])
                    cout << "YES\n";
                else
                    cout << "NO\n";
            } else {
                
                cout << "NO\n";
            }
        }
    }
    return 0;
}
