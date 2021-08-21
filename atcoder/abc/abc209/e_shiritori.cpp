//ABC_209_E
//Shiritori
//2153
//ABC_209_E
//Shiritori
//2153

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int s2i(string s)
{
    int res = 0;
    for (auto c : s)
    {
        res *= 52;
        int now = c - 'a';
        if (now < 0) now += 58;
        res += now;
    }
    return res;
}

const int M = 52 * 52 * 52;
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    vector<vector<int>> g(M);
    //同じ辺を張らないように管理する
    map<P, int> mp;
    //その頂点から出ている辺の本数
    vector<int> deg(M, 0);
    rep(i, n)
    {
        int a = s2i(s[i].substr(0, 3));
        int b = s2i(s[i].substr(s[i].size() - 3));
        if (mp[make_pair(a, b)]) continue;
        ++mp[make_pair(a, b)];
        //通常はa->bに遷移可能
        //逆辺なのでb->aの辺を貼る
        g[b].emplace_back(a);
        ++deg[a];
    }
    queue<int> q;
    vector<int> ans(M, -1);
    rep(i, M)
    {
        if (deg[i] == 0)
        {
            q.emplace(i);
            ans[i] = 0;
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (ans[v] == 0)
        {
            for (auto nv : g[v])
            {
                //もう既に勝ちが決定していたら計算しない
                if (ans[nv] == 1) continue;
                ans[nv] = 1;
                q.emplace(nv);
            }
        }
        else
        {
            for (auto nv : g[v])
            {
                //勝ちが決まっている頂点には計算しない
                if (ans[nv] == 1)continue;
                --deg[nv];
                if (deg[nv] == 0)
                {
                    ans[nv] = 0;
                    q.emplace(nv);
                }
            }
        }
    }

    for (auto si : s)
    {
        int num = s2i(si.substr(si.size() - 3));
        if (ans[num] == 0) cout << "Takahashi" << endl;
        else if (ans[num] == 1) cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }

    return 0;
}