#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
int main()
{
	int d, t, s;
	cin >> d >> t >> s;

	string ans;
	if (s * t >= d) ans = "Yes";
	else ans = "No";

	cout << ans << endl;
	return 0;
}