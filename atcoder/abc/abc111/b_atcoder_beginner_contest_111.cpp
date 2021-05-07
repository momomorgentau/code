//ABC_111_B
//AtCoder_Beginner_Contest_111
//58
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
	vector<int> v = { 111,222,333,444,555,666,777,888,999 };
	for (auto vi : v)
	{
		if (vi < n) continue;
		cout << vi << endl;
		return 0;
	}
	return 0;
}