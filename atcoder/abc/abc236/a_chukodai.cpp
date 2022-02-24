//----------------------------
//ABC 236 A
//chukodai
//7
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
	string s;
	int a, b;
	cin >> s >> a >> b;
	--a, --b;
	swap(s[a], s[b]);
	cout << s << endl;
	return 0;
}
