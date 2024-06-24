#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t > 0) {
        long long n, m;
        cin >> n >> m;

        // Define matrices
        vector<vector<long long>> mat1(n, vector<long long>(m));
        vector<vector<long long>> mat2(n, vector<long long>(m));

        // Read matrix mat1
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cin >> mat1[i][j];
            }
        }

        // Read matrix mat2
        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < m; j++) {
                cin >> mat2[i][j];
            }
        }

        // Lambda function to compare two vectors
        auto compare_vecs = [] (const vector<long long>& v1, const vector<long long>& v2) -> bool {
            return v1 == v2;
        };

        bool compare = true;
        map<long long, vector<long long>> M;
        vector<vector<long long>> V;

        // Check rows
        for (long long i = 0; (i < n) && compare; i++) {
            vector<long long> v1, v2;

            for (long long j = 0; j < m; j++) {
                v1.push_back(mat1[i][j]);
                v2.push_back(mat2[i][j]);
            }

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            M[v1[0]] = v1;
            V.push_back(v2);
        }

        for (long long i = 0; (i < V.size()) && compare; i++) {
            compare = compare && compare_vecs(V[i], M[V[i][0]]);
        }

        M.clear();
        V.clear();

        // Check columns
        for (long long j = 0; (j < m) && compare; j++) {
            vector<long long> v1, v2;

            for (long long i = 0; i < n; i++) {
                v1.push_back(mat1[i][j]);
                v2.push_back(mat2[i][j]);
            }

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            M[v1[0]] = v1;
            V.push_back(v2);
        }

        for (long long i = 0; (i < V.size()) && compare; i++) {
            compare = compare && compare_vecs(V[i], M[V[i][0]]);
        }

        // Output result
        if (compare) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        t--;
    }

    return 0;
}
