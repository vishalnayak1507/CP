#include<iostream>
#include <bitset>
#include <cmath>
using namespace std;

int thala(int m){
    if(m==0){
        return 1;
    }
    
    int b=32 - __builtin_clz(m) - __builtin_popcount(m);
    if(b==0){
        return 1;
    }
    else{
    return (pow(2,b));
    }
}
int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        cout <<thala(n)<<endl;
        t--;
    }
    return 0;
}