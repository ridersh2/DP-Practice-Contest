/*
	a very basic dp digit, you can use recursion instead of 3 'for'

	idea is kinda as same as knapsack
	number_of_way[i][j] : number of way to make number with lenght of i with sum of its digit is j
	of course it wont contain number start with 0

	you need 3 'for' to check every length, every number that will be and every sum
	i = 2, l = 1, j = 3 mean number of way to make a number length of 2 and 2-nd number is 1
	with sum total its digit is 3

	O(n * m * 10)
*/
#include<bits/stdc++.h>
using namespace std;

int n, m, mod = 1e9 + 7, i, j, l, number_of_way[101][901];

int main() {
	cin >> n >> m;

	//first number cannot be 0
	for(l = 1; l <= 9; ++l) number_of_way[1][l] = 1;

	for(i = 2; i <= n; ++i)
		for(l = 0; l <= 9; ++l)
			for(j = l; j <= m; ++j)
				number_of_way[i][j] = (number_of_way[i][j] + number_of_way[i - 1][j - l]) % mod;

	cout << number_of_way[n][m];

	return 0;
}