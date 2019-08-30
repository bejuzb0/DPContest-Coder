#include <bits/stdc++.h>
using namespace std;
int greatest(int a, int b, int c) {
	if(a > b) {
		if(a > c) {
			return 0;
		}
		else return 2;
	}
	else {
		if(b > c)
			return 1;
		else return 2;
	}
}

int choose(vector<int> a, int leave) {
	int m = INT_MIN;
	int index = -1;
	for(int i=0; i<3; i++) {
		if(a[i] > m && i != leave) {
			m = a[i];
			index = i;
		}
	}
	return index;
}

int main() {
	int n;
	cin>>n;
	vector<vector<int> > v;
	int a,b,c;

	vector<int> temp(3);
	for(int i=0; i<n; i++) {
		cin>>temp[0]>>temp[1]>>temp[2];
		v.push_back(temp);
	}

	vector<int> sol(v.size());
	int leave = greatest(v[0][0], v[0][1], v[0][2]);
	sol[0] = v[0][leave];
	for(int i=1; i<n; i++) {
		leave = choose(v[1], leave);
		sol[i] = sol[i-1] + v[i][leave];
	}
	cout<<sol[n-1]<<endl;
}