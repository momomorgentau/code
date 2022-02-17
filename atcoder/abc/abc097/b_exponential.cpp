//----------------------------
//ABC_097_b
//Exponential
//247
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
	int x;
	cin >> x;
	int ans = 1;
	reps(b, 2, x + 1)
	{
		reps(p, 2, 100)
		{
			int now = pow(b,p);
			if (now > x)
			{
				break;
			}
		    ans = max(now, ans);
		}
	}
	cout << ans << endl;
	return 0;

}