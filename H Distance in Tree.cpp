/*
161D - Distance in Tree
https://codeforces.com/blog/entry/4097
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[50001][501], o;
int i, n, k, x, y;
vector<int> adj[50001];

void dfs(int x, int tr) {
	int j, y, l;
	dp[x][0] = 1;
	for(j = 0; j < adj[x].size(); ++j) {
		y = adj[x][j];
		if(y != tr) {
			dfs(y,x);
			for(l = 1; l <= k; ++l) o += dp[x][l - 1] * dp[y][k - l];
			for(l = 1; l <= k; ++l) dp[x][l] += dp[y][l - 1];
		}
	}
}

int main() {
	cin >> n >> k;
	for(i = 1; i < n; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cout << o;

	return 0;
}