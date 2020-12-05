//28
//abc_153_b_common_raccoon_vs_monster
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	int h, n;
	cin >> h >> n;
	int sum = 0;
	rep(i, n)
	{
		int a; cin >> a;
		sum += a;
	}
	if (h <= sum) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
