//----------------------------
//ABC_230_A
//AtCoder Quiz3
//5
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
	int n; cin >> n;
	string ans = "AGC0";
	if (n >= 42) ++n;
	if (n <= 9) ans += '0';
	ans += to_string(n);
	cout << ans << endl;
	return 0;
}