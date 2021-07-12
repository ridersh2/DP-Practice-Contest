#include<bits/stdc++.h>
using namespace std;

int n, i, f[100001], mod = 715827613;

int main() {
	cin >> n;
	f[3] = 1;

	for(i = 4; i <= n; ++i) f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod;
	cout << f[n];

	return 0;
}