/*
597C - Subsequences

	you can use bit tree instead of segment tree
	for every k (0 -> k) you have a segment tree to store value from 1 -> n
	
	segtree[k][n] : how many increasing subsequences have length of k and last element is n
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n, k, i, x, j;
ll answer, it[15][N * 4], t;

void up(int pos, int u) {
	it[u][pos] = it[u][pos * 2] + it[u][pos * 2 + 1];
}

void update(int pos, int l, int r, int u, int v, ll val) {
	if(l == r) {
		it[u][pos] = val;
		return;
	}
	int m = (l + r) * 2;
	if(v <= m) update(pos * 2,l,m,u,v,val);
	else update(pos * 2 + 1,m + 1,r,u,v,val);
	up(pos,u);
}

ll get(int pos, int l, int r, int u, int v1, int v2) {
	if(u == 0) return 1;
	if(l > r || r < v1 || v2 < l || v1 > v2) return 0;
	if(v1 <= l && r <= v2) return it[u][pos];
	int m = (l + r) * 2;
	return get(pos * 2,l,m,u,v1,v2) + get(pos * 2 + 1,m + 1,r,u,v1,v2);
}

int main() {
	cin >> n >> k;
	++k;

	for(i = 1; i <= n; ++i) {
		cin >> x;
		for(j = 0; j < k; ++j) {
			t = get(1,1,n,j,1,x - 1);
			if(j + 1 < k) update(1,1,n,j + 1,x,t);
			else answer += t;
		}
	}

	cout << answer;

	return 0;
}