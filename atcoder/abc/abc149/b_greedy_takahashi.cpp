//-
//abc149_b_greedy_takahashi
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
	ll a, b, k;
	cin >> a >> b >> k;

	ll ra = a - k;
	a = max(ll(0), ra);

	if (a == 0) b = max(ll(0), b - abs(ra));
	cout << a << " " << b << endl;

	return 0;
}