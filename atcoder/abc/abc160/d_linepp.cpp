//diff879
//abc_160_d_line++
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;

const int inf = 1e9;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    --x; --y;
    vector<vector<int>> d(n, vector<int> (n,inf));
    rep(i,n) d[i][i] = 0;

    rep(i,n)
    {
        queue<int> q;
        q.emplace(i);
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(int j = -1;j <= 1; j+=2)
            {
                if(0 <= p+j && p+j < n && d[i][p+j] > d[i][p]+1)
                {
                    d[i][p+j] = d[i][p]+1;
                    q.emplace(p+j);
                }
            }
            if(p == x && d[i][y] > d[i][x]+1)
            {
                d[i][y] = d[i][p]+1;
                q.emplace(y);
            }
            if(p == y && d[i][x] > d[i][y]+1)
            {
                d[i][x] = d[i][p]+1;
                q.emplace(x);
            }
        }
    }

    map<int,int> ans;
    rep(i,n)rep(j,n) ++ans[d[i][j]];
    reps(i,1,n) cout << ans[i] / 2  << endl;
    return 0;
} 

