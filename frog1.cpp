#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> h(n+1, 0);
    for(int i=1; i<n+1; i++)
        cin>>h[i];
    vector<long long> sol(n+1,-1);
    sol[0] = INT_MAX;
    sol[1] = 0;
    for(int i=2; i<n+1; i++) {
        sol[i] = min(abs(h[i]-h[i-1])+ sol[i-1], abs(h[i]-h[i-2])+sol[i-2]);
    }
    cout<<sol[n]<<endl;
}