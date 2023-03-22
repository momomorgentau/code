//----------------------------
// ABC 293 A
// Swap Odd and Even
// 12
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	string s;
	cin >> s;
	rep(i, s.size() / 2)
	{
		swap(s[i * 2], s[i * 2 + 1]);
	}
	cout << s << endl;
	return 0;
}


