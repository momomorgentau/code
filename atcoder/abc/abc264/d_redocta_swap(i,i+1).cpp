//----------------------------
//ABC 264 D
//"redocta".swap(i,i+1)
//414
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
	map<string, int> mp;
	cin >> s;
	queue<string> q;
	q.emplace("atcoder");
	mp["atcoder"] = 0;

	while (!q.empty())
	{
		string t = q.front();
		q.pop();
		rep(i, 6)
		{
			string tmp = t;
			swap(tmp[i], tmp[i + 1]);
			if (tmp == "atcoder" || mp[tmp] != 0) continue;
			mp[tmp] = mp[t] + 1;
			q.emplace(tmp);
		}
	}
	cout << mp[s] << endl;
	return 0;
}
