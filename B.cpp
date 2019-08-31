#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin>>n>>k;
	vector<int> h(n+1, INT_MAX);
	for(int i=1; i<n+1; i++)
		cin>>h[i];
	vector<int> sol(n+1, INT_MAX);
	sol[1] = 0;
	for(int i=2; i<n+1; i++) {
		for(int j=1; j<=k && i-j > 0; j++) {
			sol[i] = min(sol[i],abs(h[i]-h[i-j])+sol[i-j]);
		}
	}
	cout<<sol[n]<<endl;

}