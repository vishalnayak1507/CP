#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_wins(int N, int D, std::vector<int>& powers) {
    std::sort(powers.rbegin(), powers.rend()); // Sort in descending order

    int wins=0;
    int groups=0;
    for(int i=0;i<N;i++){
        groups=groups+D/powers[i]+1;
        if(groups>N){
            break;
        }
        wins++;
    }
    
    return wins;
}

int main() {
    int N, D;
    std::cin >> N >> D;
    
    std::vector<int> powers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> powers[i];
    }
    
    int result = max_wins(N, D, powers);
    std::cout << result << std::endl;
    
    return 0;
}
