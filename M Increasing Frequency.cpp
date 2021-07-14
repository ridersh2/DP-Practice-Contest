/*
1082E - Increasing Frequency
https://codeforces.com/blog/entry/63544
*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, c, i, f[N], prefix_sum[N], suffx_sum[N], a[N], answer;

int main() {
	cin >> n >> c;

	for(i = 1; i <= n; ++i) {
		cin >> a[i];
		prefix_sum[i] = prefix_sum[i - 1];
		if(a[i] == c) ++prefix_sum[i];
	}

	for(i = n; i > 0; --i) {
		suffx_sum[i] = suffx_sum[i + 1];
		if(a[i] == c) ++suffx_sum[i];
	}

	for(i = 1; i <= n; ++i) {
		//Kaede's algorithm
		f[a[i]] = max(f[a[i]], prefix_sum[i - 1]) + 1;
		answer = max(answer, f[a[i]] + suffx_sum[i + 1]);
	}

	cout << answer;

	return 0;
}