/*
375B - Maximum Submatrix 2
https://codeforces.com/blog/entry/10084
*/
#include<bits/stdc++.h>
using namespace std;

int i, j, n, m, o, dp[5001][5001], c;
string s;
priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio(0);

	cin >> m >> n;
	for(j = 1; j <= m; ++j) {
		cin >> s;
		for(i = 1; i <= n; ++i)
			if(s[i - 1] == '1') dp[i][j] = dp[i - 1][j] + 1;
	}
	for(i = 1; i <= n; ++i) {
		for(j = 1; j <= m; ++j)
			if(dp[i][j]) pq.push(dp[i][j]);
		c = 1;
		while(!pq.empty()) {
			o = max(o,pq.top() * c);
			++c;
			pq.pop();
		}
	}
	cout << o;

	return 0;
}