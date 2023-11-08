//----------------------------
// ABC 326 D 
// ABC Puzzle
// 1371
//----------------------------

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;

int n;
string r,c;
string ans = "No";

void dfs(string s, int i)
{

    if(i == n)
	{
	    rep(k,n)
		{
		    int ca = 0;
			int cb = 0;
			int cc = 0;
			bool first = true;
		    rep(j, n)
			{
			    if(s[j*n+k] == 'A') ca++;
			    if(s[j*n+k] == 'B') cb++;
			    if(s[j*n+k] == 'C') cc++;

				if(first && s[j*n+k] != '.')
				{
				    first = false;
					if(c[k] != s[j*n+k])
					{
					    return;
					}
				}
			}

			if(ca != 1 || cb != 1 || cc != 1 )
			{
			     return;   
			}
		}
		ans = s;
	    return;
	}
    char p = r[i];
	rep(j, n - 2)
	{
	    for(int x = j+1; x < n -1; x++)
		{
		    for(int y = x+1; y < n; y++)
			{
			    string now0 = "";
			    string now1 = "";
				rep(k, n) now0 += ".";
				rep(k, n) now1 += ".";
				now0[j] = p;
				now1[j] = p;
				
				char c1, c2;
				if(p == 'A')
				{
				   c1 = 'B';
				   c2 = 'C';
				}
				else if(p == 'B')
				{
				   c1 = 'C';
				   c2 = 'A';
			    }
				else
				{
				    c1 = 'A';
					c2 = 'B';
				}

				now0[x] = c1;
				now1[x] = c2;

				now0[y] = c2;
				now1[y] = c1;

				dfs(s+now0, i+1);
				dfs(s+now1, i+1);
			    
			}
		}
	}
    
}

int main()
{
    cin >> n >> r >> c;

    dfs("", 0);
	if(ans == "No") cout << "No" << endl;
	else
	{
	    cout << "Yes" << endl;
	    rep(i,n)
		{
		    rep(j,n) cout << ans[i*n+j];
			cout << endl;
		}
	}
    return 0;
}

