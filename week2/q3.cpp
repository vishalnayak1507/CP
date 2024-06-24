#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> a(n), b(n);
        vector<long long> sm(n);
        map<int, int> mp;
        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b.begin(), b.end());
        sm[0] = b[0];
        for (i = 1; i < n; ++i)
            sm[i] = sm[i - 1] + b[i];
        mp[b[n - 1]] = n - 1;
        for (i = n - 2; i >= 0; --i)
        {
            if (sm[i] >= b[i + 1])
                mp[b[i]] = mp[b[i + 1]];
            else
                mp[b[i]] = i;
        }
        for (i = 0; i < n; ++i)
            cout << mp[a[i]] << " ";
        cout << endl;
    }
    return 0;
}
