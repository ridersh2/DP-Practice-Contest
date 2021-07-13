/*
	f[i][j] : the minimum dollars after first i days past, you have j tickets left

	every f[i][j] will have 2 cases:
	
	- buy item by using ticket on ith day: f[i][j] may take the value from f[i - 1][j + 1]

	- buy item by using dollars on ith day will have 2 more cases:
		+ item > 100$: f[i][j] may take the value from f[I - 1][j - 1] + cost[i]
		(you will have a ticket after buying this item)
		
		+ item <= 100$: f[i][j] may take the value from f[i - 1][j] + cost[i]
		(you wont have a ticket after buying this item)

	of course take minimum of 2 cases

	O(n^2)
*/
#include<bits/stdc++.h>
using namespace std;

int n, i, j, f[5005][5005], cost[5005];

int main() {
	cin >> n;
	for(i = 1; i <= n; ++i) cin >> cost[i];

	for(i = 0; i <= n; ++i) for(j = 0; j <= n; ++j) f[i][j] = 1e9;
	f[0][0] = 0;

	for(i = 1; i <= n; ++i) for(j = 0; j <= n; ++j) {
		f[i][j] = f[i - 1][j + 1];
		
		//j must greater than 0 to take from f[i - 1][j - 1]
		if (cost[i] > 100 && j > 0)
			f[i][j] = min(f[i][j],f[i - 1][j - 1] + cost[i]);
		else
			f[i][j] = min(f[i][j],f[i - 1][j] + cost[i]);
	}

	//of course you have to use all the ticket left after n-th day
	cout << f[n][0];

	return 0;
}