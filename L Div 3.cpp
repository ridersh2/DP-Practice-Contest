/*
	f[i][j] is how many number that contain i digits and have sum modulo to 3 is j

	from here you can dp like problem E (sum modulo to 3 instead of just sum)
	note that you the digit in f must not be x

	after that we will put k number x to f[n - k][sum_k] (sum_k is sum of k number x modulo to 3)
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, x, i, j, l, t, sum_k;
ll f[100005][5], answer, mod = 1e9 + 7;

ll power(ll x, ll y) {
	if(y == 0) return 1;
	if(y % 2 == 0) return power((x * x) % mod,y / 2);
	return (x * power(x,y - 1)) % mod;
}

ll nCk(int n, int k) {
	ll numerator, denominator, j;

	numerator = 1;
	for(j = n - k + 1; j <= n; ++j) numerator = (numerator * j) % mod;

	denominator = 1;
	for(j = 2; j <= k; ++j) denominator = (denominator * j) % mod;

	return (numerator * power(denominator,mod - 2)) % mod;
}

int main() {
	cin >> n >> k >> x;
	f[0][0] = 1;
	
	for(i = 1; i < n - k; ++i) for(j = 0; j < 10; ++j)
		if(j != x)
			for(l = 0; l < 3; ++l) {
				t = (l + j) % 3;
				f[i][t] = (f[i][t] + f[i - 1][l]) % mod;
			}

	//first number cannot be 0
	for(j = 1; j < 10; ++j) for(l = 0; l < 3; ++l)
		if(j != x) {
			t = (j + l) % 3;
			f[n - k][t] = (f[n - k][t] + f[n - k - 1][l]) % mod;
		}

	if(x == 0) {
		//you cannot put 0 to first number (sum_k here is 0 already)
		answer = (f[n - k][0] * nCk(n - 1,k)) % mod;
	} else {
		sum_k = (3 - ((k * x) % 3)) % 3;
		//put k number x to f[n - k][sum_k] (here the f[n - k][sum_k] first number is not 0)
		answer = (f[n - k][sum_k] * nCk(n,k)) % mod;
		//put k number x to f[n - k][sum_k] but 0 is the first number so we call f[n - k - 1][sum_k]
		//also we have to put one number x to the first because the first number form f is 0
		answer = (answer + (f[n - k - 1][sum_k] * nCk(n - 1,k - 1)) % mod) % mod;
	}

	cout << answer;

	return 0;
}