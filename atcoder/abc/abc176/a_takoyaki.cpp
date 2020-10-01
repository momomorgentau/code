#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main()
{
	int n, x, t;
	cin >> n >> x >> t;
	int quo;
	quo = (n + x - 1) / x;
	cout << quo * t;

	return 0;
}