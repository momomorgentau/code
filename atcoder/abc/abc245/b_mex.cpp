//----------------------------
//ABC 245 B
//Mex
//40
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
	cin >> n;
	vector<int> used(2005);
	rep(i, n)
	{
		int a; cin >> a;
		used[a] = 1;
	}
	rep(i, 2005)
	{
		if (used[i] != 1)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
