//----------------------------
// ABC 295 A
// Probably English
// 15
//----------------------------
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
	vector<string> s = { "and", "not", "that", "the" ,"you" };
	rep(i, n)
	{
		string w; cin >> w;
		for (const auto& t : s)
		{
			if (t == w)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}