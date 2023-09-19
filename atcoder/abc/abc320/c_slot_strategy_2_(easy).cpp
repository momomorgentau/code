//----------------------------
// ABC 320 C 
// Slot Strategy 2(Easy)
// 851
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int m;
	cin >> m;
	vector<string> s(3);
	rep(i,3) cin >> s[i];
	rep(i,3) s[i] += s[i] + s[i];
	const int INF = 1e9;
	int ans = INF;
	vector<int> prm = {0,1,2};
	rep(p, 10)
	{
	     
	    do
		{
			int idx = 0;
			rep(i, m*3)
			{
			    if(s[prm[idx]][i] - '0' == p)
				{
				    idx++;
					if(idx == 3)
					{
					    ans = min(ans, i);
					    break;
					}
				}
			}
		}while(next_permutation(prm.begin(), prm.end()));
	}
	if(ans == INF) ans = -1;
	cout << ans << endl;
    return 0;
}

