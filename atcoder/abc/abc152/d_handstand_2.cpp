//1045
//abc152_d_handstand_2
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;
int main()
{

	int n;
	cin >> n;
	vector<vector<int>> c(10, vector<int>(10, 0));
	rep(i, n)
	{
		int x = i + 1;
		int dr = x % 10;
		int dl = dr;
		while (x > 0)
		{
			dl = x % 10;
			x /= 10;
		}
		++c[dr][dl];
	}
	ll ans = 0;
	reps(i, 1, 10)reps(j, 1, 10)
	{
		ans += (ll)c[i][j] * c[j][i];
	}
	cout << ans << endl;

	return 0;
}
