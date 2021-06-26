//072
//Loop_Railway_Plan
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int ans = -1;
int h, w;
string g;

int main()
{
    cin >> h >> w;
    rep(i, h)
    {
        string t;
        cin >> t;
        g += t;
    }
    rep(i, h*w)
    {
        if (g[i] == '#') continue;
        queue<T> q;
        q.emplace(i, 1 << i, i);
        
        while(!q.empty())
        {
            int now, bit, s;
            tie(now, bit, s) = q.front();
            q.pop();

            if (now == s)
            {
                int d = 0;
                rep(i, (h * w))
                {
                    if (bit & (1 << i)) ++d;
                }
                if (d == 2) continue;
                else if (d > 2)
                {
                    ans = max(ans, d);
                    continue;
                }
            }


            if (now != 0 && (now - 1) % w < now % w && g[now - 1] == '.'
                && (!(bit & (1 << (now - 1))) || now - 1 == s))
            {
                q.emplace(now - 1, bit | (1 << (now - 1)), s);
            }
            if ((now + 1) % w > now % w && g[now + 1] == '.'
                && (!(bit & (1 << (now + 1))) || now + 1 == s))
            {
                q.emplace(now + 1, bit | (1 << (now + 1)), s);
            }
            if ((now - w) >= 0 && g[now - w] == '.'
                && (!(bit & (1 << (now - w))) || now - w == s))
            {
                q.emplace(now - w, bit | (1 << (now - w)), s);
            }
            if ((now + w) < h * w && g[now + w] == '.'
                && (!(bit & (1 << (now + w))) || now + w == s))
            {
                q.emplace(now + w, bit | (1 << (now + w)), s);
            }


        }
    }
    cout << ans << endl;
    return 0;
}
/*
BFS
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int ans = -1;
int h, w;
string g;

int main()
{
    cin >> h >> w;
    rep(i, h)
    {
        string t;
        cin >> t;
        g += t;
    }
    rep(i, h*w)
    {
        if (g[i] == '#') continue;
        queue<T> q;
        q.emplace(i, 1 << i, i);
        
        while(!q.empty())
        {
            int now, bit, s;
            tie(now, bit, s) = q.front();
            q.pop();

            if (now == s)
            {
                int d = 0;
                rep(i, (h * w))
                {
                    if (bit & (1 << i)) ++d;
                }
                if (d == 2) continue;
                else if (d > 2)
                {
                    ans = max(ans, d);
                    continue;
                }
            }


            if (now != 0 && (now - 1) % w < now % w && g[now - 1] == '.'
                && (!(bit & (1 << (now - 1))) || now - 1 == s))
            {
                q.emplace(now - 1, bit | (1 << (now - 1)), s);
            }
            if ((now + 1) % w > now % w && g[now + 1] == '.'
                && (!(bit & (1 << (now + 1))) || now + 1 == s))
            {
                q.emplace(now + 1, bit | (1 << (now + 1)), s);
            }
            if ((now - w) >= 0 && g[now - w] == '.'
                && (!(bit & (1 << (now - w))) || now - w == s))
            {
                q.emplace(now - w, bit | (1 << (now - w)), s);
            }
            if ((now + w) < h * w && g[now + w] == '.'
                && (!(bit & (1 << (now + w))) || now + w == s))
            {
                q.emplace(now + w, bit | (1 << (now + w)), s);
            }


        }
    }
    cout << ans << endl;
    return 0;
}
*/