#include <bits/stdc++.h>
using namespace std;

int UtilFn(vector<int> arr, int t, vector<int> &output) {
	if(output[t] == -1) {
		output[t] = 0;
		for(int i=0; i<arr.size(); i++) {
			if(t - arr[i] > 0)
				output[t] += UtilFn(arr, t-arr[i], output);
			else break;
		}
	}
	return output[t];

}

int waystoform(vector<int> arr, int t) {
	vector<int> output(t+1);
	for(int i=0; i<t+1; i++)
		output[i] = -1;
	output[0] = 1;
	return UtilFn(arr, t, output);
}
int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	int t;
	cin>>t;
	cout<<waystoform(arr,t);
}