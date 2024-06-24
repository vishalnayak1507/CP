#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

#define ll long long int
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if(n%2!=0){
            cout<<"YES\n";
        }
        else{
        for (ll i = 1; i < n - 1; i++) {
            arr[i + 1] -= (arr[i] - arr[i - 1]);
            arr[i] = arr[i - 1];
        }
        if (arr[n - 1] >= arr[n - 2]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        }
    }
    return 0;
}
