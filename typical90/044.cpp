//044
//Shift_and_Swapping
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;


int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int shift = 0;
	auto rem = [&](int a) {return ((a % n) + n) % n; };
	while (q--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		--x, --y;
		if (t == 1)
		{
			swap(a[rem(x+shift)], a[rem(y + shift)]);
		}
		else if (t == 2) --shift;
		else cout << a[rem(x + shift)] << endl;
	}


	return 0;
}