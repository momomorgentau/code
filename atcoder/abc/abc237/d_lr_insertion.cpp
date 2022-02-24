//----------------------------
//ABC_237_D
//LR inserion
//544
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
	int n;
	string s;
	cin >> n >> s;
	vector<string> l, r;
	int c = 0;
	for (const auto& d : s)
	{
		if (d == 'L')
		{
			r.emplace_back(to_string(c));
		}
		else
		{
			l.emplace_back(to_string(c));			
		}
		++c;
	}
	for (const auto& li : l)
	{
		cout << li << " ";
	}
	cout << c << " ";
	reverse(r.begin(), r.end());
	for (const auto& ri : r)
	{
		cout << ri << " ";
	}
	return 0;
}