//----------------------------
// ABC 327 D 
// Good Tuple Problem
// 709
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int N = 2e5;
vector<set<int>> g(N+10);

vector<int> c(N+10, -1);

bool ng = false;
void dfs(int a)
{
    
    for(const auto& e: g[a])
	{
	    if(c[e] != -1)
		{
		    if(c[e] == c[a])
			{
			    ng = true;
			}
		}
		else
		{
		    c[e] = c[a] ^ 1;
	    	dfs(e);
		}
	}
}

int main()
{
    int n,m;
	cin >> n >> m;
	vector<int> a(m),b(m);
	rep(i, m) cin >> a[i];
	rep(i, m) cin >> b[i];
	rep(i, m)
	{
	    int ai = a[i];
		int bi = b[i];
		--ai, --bi;
	    g[ai].insert(bi);
	    g[bi].insert(ai);
	}

	rep(i,n)
	{
	    if(c[i] != -1) continue;
		c[i] = 0;
		dfs(i);
	}

	if(!ng) cout << "Yes" << endl;
	else cout << "No" << endl;
    
    return 0;
}


