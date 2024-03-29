//----------------------------
//ABC 242 D
//ABC Transform
//1286
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
	const int MOD = 3;
	string s;
	int q;
	cin >> s >> q;

	auto popcount = [](ll k)
	{
		int res = 0;
		while (k > 0)
		{
			if (k & 1) ++res;
			k >>= 1;
		}
		return res;
	};

	while (q--)
	{
		ll t, k;
		cin >> t >> k;
		--k;
		//一つの文字がどれだけの要素を持つか
		ll sz = pow(2, min(t, (ll)63));
		//どこ由来か求める
		ll src = k / sz;
		//その要素において何番目か
		ll nk = k % sz;

		ll p = popcount(nk);
		char ans = (((t - p) + p * 2 + (ll)(s[src] - 'A')) % MOD) + 'A';
		printf("%c\n", ans);
	}

}
