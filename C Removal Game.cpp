/*
	lets f[i][j] mean the different of first player score and second player score (score1 - score2)
	if they only play on interval [i,j]

	first player want to maximize it and second player want to minimize it

	if they only take one element f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1])

	now if they want take several consecutive numbers
	f[i][j] = max(sum[i,l] - f[l + 1][j],sum[l,j] - f[i][l - 1]) for every j (take maximum)
	and i != j != l (sum[x,y] mean sum from ax to ay)

	you will have another 'for' to check the l
	to calculate the sum[x,y] we can use prefix sum

	O(n^3)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, j, l;
ll f[205][205], a[205], prefix_sum[205], sum;

int main() {

	cin >> n;
	for(i = 1; i <= n; ++i) {
		cin >> a[i];
		prefix_sum[i] = prefix_sum[i - 1] + a[i];
	}

	for(i = n; i > 0; --i) for(j = i; j <= n; ++j) {
		//take the whole interval as the initial
		f[i][j] = prefix_sum[j] - prefix_sum[i - 1];

		//if l = i mean only take first element
		//if l = j mean only take last element
		for(l = i; l <= j; ++l) {

			if(l != j) {
				sum = prefix_sum[l] - prefix_sum[i - 1];
				f[i][j] = max(f[i][j],sum - f[l + 1][j]);
			}

			if(l != i) {
				sum = prefix_sum[j] - prefix_sum[l - 1];
				f[i][j] = max(f[i][j],sum - f[i][l - 1]);
			}

		}
	}

	//prefix_sum[n] = score1 + score2
	//f[1][n] = score1 - score2
	//==> (prefix_sum[n] + f[1][n]) / 2 = score1
	cout << (prefix_sum[n] + f[1][n]) / 2;

	return 0;
}