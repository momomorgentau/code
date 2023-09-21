//----------------------------
// ABC 319 C
// False Hope
// 1111
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    vector<vector<int>> c(3, vector<int> (3));
	rep(i,3)rep(j,3) cin >> c[i][j];
	vector<int> p(9);
	rep(i,9) p[i] = i;
	double a = 0;
	double b = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9;
	do
	{
	    vector<vector<int>> d(3, vector<int> (3, -1));
	    bool ok = true;
		rep(i,9)
		{
		    int x = p[i] % 3;
			int y = p[i] / 3;
			{
			    vector<int> q;
			    rep(j, 3)
				{
				    if(j == x) continue;
					q.emplace_back(d[y][j]);
				}
				if(q[0] != -1 && q[0] == q[1] && q[0] != c[y][x])
				{
				    ok = false;
					break;
				}

			}
			{
			    vector<int> q;
			    rep(j, 3)
				{
				    if(j == y) continue;
					q.emplace_back(d[j][x]);
				}
				if(q[0] != -1 && q[0] == q[1] && q[0] != c[y][x])
				{
				    ok = false;
					break;
		        }
			}

			{
			    vector<int> q;
			    rep(j, 3)
				{
				    if(j == y && j == x) continue;
					q.emplace_back(d[j][j]);
				}
			
				if(q.size() == 2 && q[0] != -1 && q[0] == q[1] && q[0] != c[y][x])
				{
				    ok = false;
					break;
		        }
			}
			
			{
			    vector<int> q;
			    rep(j, 3)
				{
				    if(2-j == x &&j == y) continue;
					q.emplace_back(d[j][2-j]);
				}
				if(q.size() == 2 && q[0] != -1 && q[0] == q[1] && q[0] != c[y][x])
				{
				    ok = false;
					break;
		        }
			}

			d[y][x] = c[y][x];
		}
	    if(ok) a += 1;
	}while(next_permutation(p.begin(), p.end()));
    printf("%.9f\n", a / b);
	return 0;
}

