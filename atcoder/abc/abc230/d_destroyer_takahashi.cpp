//----------------------------
//ABC_230_D
//Destroy_Takahashi
//963
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
	int n, d;
	cin >> n >> d;
	priority_queue<P, vector<P>, greater<P>> pq;
	rep(i, n)
	{
		int l, r;
		cin >> l >> r;
		pq.emplace(r, l);
	}
	int ans = 0;
	while (!pq.empty())
	{
		int li, ri;
		ri = pq.top().first;
		li = pq.top().second;
		pq.pop();
		++ans;
		while (!pq.empty())
		{
			if (pq.top().second <= ri + d - 1)
			{
				pq.pop();
			}
			else
			{
				break;
			}
		}
	}
	cout << ans << endl;

	return 0;
}