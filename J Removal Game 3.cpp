#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int st, len, j, n, k, en;
//st: start, en: end, len: length
ll a[305], f[155][305][305];

int main() {
	cin >> n >> k;
	for(st = 1; st <= n; ++st) cin >> a[st];

	for(j = 1; j <= k; ++j) for(len = j * 2; len <= n; ++len)
		for(st = 1; st <= n - len + 1; ++st) {

			en = st + len - 1;

			//take first 2 numbers
			f[j][st][en] = max(f[j][st][en], f[j - 1][st + 2][en] + abs(a[st] - a[st + 1]));

			//take last 2 numbers
			f[j][st][en] = max(f[j][st][en], f[j - 1][st][en - 2] + abs(a[en] - a[en - 1]));

			//take both first and last number
			f[j][st][en] = max(f[j][st][en], f[j - 1][st + 1][en - 1] + abs(a[st] - a[en]));

			//delete a number
			f[j][st][en] = max(f[j][st][en], max(f[j][st + 1][en], f[j][st][en - 1]));
		}
	cout << f[k][1][n];

	return 0;
}