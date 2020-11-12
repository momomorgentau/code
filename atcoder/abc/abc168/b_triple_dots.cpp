//6
//abc168_b_triple_dots
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using ll = long long;

int main()
{
	int k;
	string s;
	cin >> k >> s;
	string ans = s;
	if (s.length() > k) ans = s.substr(0,k) + "...";
	
	cout << ans << endl;
	return 0;
}