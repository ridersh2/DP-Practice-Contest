/*
	f[i][j] : minimum price to block i positions in first j rows

	lets say x is your current position you can only take those y position

	..  ..  ..  y.  .y
	..  y.  .y  ..  ..
	y.  ..  ..  ..  ..
	x.  x.  x.  x.  x.

	so f[i][j][x] = min(f[i - 1][j - 1][x], f[i - 1][l][both 1 and 2]) for every l <= j - 2
	which lead to O(n^3)

	instead of another `for` for l we can use another array to store the minimum of array f
	min_f[i][j] : minimum of every f[i][j][1] and f[i][j][2] from 1 to i

	=> f[i][j][x] = a[j][x] + min(f[i - 1][j - 1][x], min_f[i - 1][j - 2])
	=> min_f[i][j] = min({min_f[i][j - 1], f[i][j][1], f[i][j][2]})

	O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;

int n, k, i, j, a[2001][3], f[2001][2001][3], min_f[2001][2001];

int main() {
	cin >> n >> k;
	for(i = 1; i <= n; ++i) cin >> a[i][1] >> a[i][2];

	//initially min_f = inf
	memset(min_f,60,sizeof(min_f));

	for(i = 1; i <= k; ++i) for(j = i; j <= n; ++j)
		if(j > 1) {
			f[i][j][1] = a[j][1] + min(f[i - 1][j - 1][1], min_f[i - 1][j - 2]);
			f[i][j][2] = a[j][2] + min(f[i - 1][j - 1][2], min_f[i - 1][j - 2]);
			min_f[i][j] = min(min_f[i][j - 1], min(f[i][j][1], f[i][j][2]));
		} else { //only happen one time at i = 1 and j = 1
			f[i][j][1] = a[j][1];
			f[i][j][2] = a[j][2];
			min_f[i][j] = min(a[j][1],a[j][2]);
		}

	if(k == 0) cout << 0;
	else cout << min_f[k][n];

	return 0;
}