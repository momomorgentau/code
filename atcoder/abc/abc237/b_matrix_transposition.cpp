//----------------------------
//ABC_237_B
//Matrix Transposition
//48
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
	int h, w;
	cin >> h >> w;
	vector<vector<int>> b(w, vector<int>(h));
	rep(i, h)rep(j, w)
	{
		int ai; cin >> ai;
		b[j][i] = ai;
	}
	for (const auto& bv : b)
	{
		for (const auto& bi : bv)
		{
			cout << bi << " ";
		}
		cout << endl;
	}
	return 0;
}