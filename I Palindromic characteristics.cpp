/*
835D - Palindromic characteristics
https://codeforces.com/blog/entry/53588
*/
#include<bits/stdc++.h>
using namespace std;
int n, i, j, l, dp[5005][5005], answer[5005];
string s;
bool pal[5005][5005];

int main() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for(i = 1; i <= n; ++i) {
		dp[i][i] = 1;
		pal[i][i] = true;
		if(s[i] == s[i - 1]) {
			dp[i - 1][i] = 2;
			pal[i - 1][i] = true;
		}
	}
	for(i = n - 2; i > 0; --i) for(j = i + 2; j <= n; ++j)
		if(s[i] == s[j] && pal[i + 1][j - 1]) {
			pal[i][j] = true;
			dp[i][j] = 1;
		}
	for(j = 2; j <= n; ++j)
		if(j % 2 == 1)
			for(i = 1; i <= n; ++i) {
				l = i + j / 2;
				if(i + j <= n && pal[i][i + j] && pal[i][l])
					dp[i][i + j] = max(dp[i][i + j],dp[i][l] + 1);
			}
		else
			for(i = 1; i <= n; ++i) {
				l = i - 1 + j / 2;
				if(i + j <= n && pal[i][i + j] && pal[i][l])
					dp[i][i + j] = max(dp[i][i + j],dp[i][l] + 1);
			}
	for(i = 1; i <= n; ++i) for(j = 1; j <= n; ++j) ++answer[dp[i][j]];
	for(i = n; i > 0; --i) answer[i] += answer[i + 1];
	for(i = 1; i <= n; ++i) cout << answer[i] << " ";

	return 0;
}