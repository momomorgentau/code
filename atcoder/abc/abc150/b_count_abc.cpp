//-
//abc150_b_count_abc

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	rep(i, s.size() - 2)
	{
		string ts = s.substr(i, 3);
		if (ts == "ABC") ++ans;
	}
	cout << ans << endl;
	return 0;
}