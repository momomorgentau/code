//ABC_201_
//Do_you_know_the_second_highest_mountain?
//32
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, string>> v(n);
	rep(i, n)
	{
		int t;
		string s;
		cin >> s >> t;
		v[i] = make_pair(t,s);
	}
	sort(v.rbegin(), v.rend());
	cout << v[1].second << endl;
	return 0;
}