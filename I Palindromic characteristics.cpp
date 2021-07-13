/*
835D - Palindromic characteristics
https://codeforces.com/blog/entry/53588
*/
#include<bits/stdc++.h>
using namespace std;
int n, i, j, l, f[5005][5005], answer[5005];
string s;
bool palindrome[5005][5005];

int main() {
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for(i = 1; i <= n; ++i) {
		f[i][i] = 1;
		palindrome[i][i] = true;
		if(s[i] == s[i - 1]) {
			f[i - 1][i] = 2;
			palindrome[i - 1][i] = true;
		}
	}
	for(i = n - 2; i > 0; --i) for(j = i + 2; j <= n; ++j)
		if(s[i] == s[j] && palindrome[i + 1][j - 1]) {
			palindrome[i][j] = true;
			f[i][j] = 1;
		}
	for(j = 2; j <= n; ++j)
		if(j % 2 == 1)
			for(i = 1; i <= n; ++i) {
				l = i + j / 2;
				if(i + j <= n && palindrome[i][i + j] && palindrome[i][l])
					f[i][i + j] = max(f[i][i + j],f[i][l] + 1);
			}
		else
			for(i = 1; i <= n; ++i) {
				l = i - 1 + j / 2;
				if(i + j <= n && palindrome[i][i + j] && palindrome[i][l])
					f[i][i + j] = max(f[i][i + j],f[i][l] + 1);
			}
	for(i = 1; i <= n; ++i) for(j = 1; j <= n; ++j) ++answer[f[i][j]];
	for(i = n; i > 0; --i) answer[i] += answer[i + 1];
	for(i = 1; i <= n; ++i) cout << answer[i] << " ";

	return 0;
}