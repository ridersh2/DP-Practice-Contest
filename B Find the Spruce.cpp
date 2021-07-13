/*
1461B - Find the Spruce
https://codeforces.com/blog/entry/85491
*/
#include<bits/stdc++.h>
using namespace std;

int lef[505][505], rig[505][505], n, m, i, j, t, answer;
string s;
char a[505][505];

int main() {
	cin >> t;
	while(t--) {
		answer = 0;
		memset(rig,0,sizeof(rig));
		memset(lef,0,sizeof(lef));

		cin >> m >> n;
		for(j = 1; j <= m; ++j) {
			cin >> s;
			for(i = 1; i <= n; ++i) a[i][j] = s[i - 1];
		}

		for(j = 1; j <= m; ++j) for(i = 1; i <= n; ++i)
			if(a[i][j] == '*') lef[i][j] = min(lef[i - 1][j],lef[i][j - 1]) + 1;
		
		for(j = 1; j <= m; ++j) for(i = n; i > 0; --i)
			if(a[i][j] == '*') rig[i][j] = min(rig[i + 1][j],rig[i][j - 1]) + 1;

		for(j = 1; j <= m; ++j) for(i = 1; i <= n; ++i)
			answer += min(lef[i][j],rig[i][j]);

		cout << answer << "\n";
	}

	return 0;
}