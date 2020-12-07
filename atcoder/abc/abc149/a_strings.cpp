//-
//abc149_a_strings
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	string s, t;
	cin >> s >> t;
	string ans = t + s;
	cout << ans << endl;
	return 0;
}