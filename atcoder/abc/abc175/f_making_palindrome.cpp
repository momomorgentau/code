//diff 2716
//abc175 making_plindrome

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pli = pair<ll, int>;

const ll inf = 1e18;

string rev(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    //-----要素の準備--------
    //文字列、逆順の文字列、一文字ずつずらしたインデックス
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> c(n);
    rep(i, n) cin >> s[i] >> c[i];
    rep(i, n) {
        s.emplace_back(rev(s[i]));
        c.emplace_back(c[i]);
    }
    vector<vector<int>> idx(n * 2);
    int cnt = 1; //0は終了条件にするため1から開始

    rep(i, n * 2) {
        int l = s[i].size();
        rep(j, l) {
            idx[i].emplace_back(cnt);
            ++cnt;
        }
    }

    //グラフの生成-----------------------------
    /*v[i][j]としたときに
    i -現在のノード
    j - 移動先のノード(idx)とそれにかかるコストのpair
    という配列を作成する*/

    vector<vector<Pii>> g(cnt);
    rep(i, n * 2) {
        int l = s[i].size();
        rep(j, l) { //j文字一致していると考える。
            int v = idx[i][j];
            rep(k, n * 2) { //kは次につける文字列（遷移先）
              //0~n-1は前、n~2n-1は後ろに接続する要素
              //前のものには後ろのものをつける。
                if (i / n == k / n) continue;
                int lt = s[k].size(); //遷移先の文字長
                //文字長と現在の文字の余りの長さを比較して短い方をとる。
                int w = min(lt, l - j);
                //回文のためにw文字一致する必要がある。
                if (s[i].substr(j, w) != s[k].substr(0, w)) continue;
                int u = 0;
                if (lt > w) { //遷移先のほうが長い
                    u = idx[k][w];
                }
                else if (l > j + w) { //元の文字列の方が長い
                    u = idx[i][j + w];
                }
                else u = 0; //一致している。
                g[v].emplace_back(u, c[k]);
            }
        }
    }


    vector<ll> d(cnt, inf);
    priority_queue<Pli, vector<Pli>, greater<Pli>> pq;

    //多始点->文字を1つだけ置いた状態を全ての文字分queueに入れておく。
    rep(i, n)
    {
        d[idx[i][0]] = c[i];
        pq.emplace(c[i], idx[i][0]);
    }
    while (!pq.empty())
    {
        ll c = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        if (d[s] < c) continue;
        for (auto a : g[s])
        {
            int gt = a.first;
            int gc = a.second;
            if (d[gt] <= d[s] + gc) continue;
            d[gt] = d[s] + gc;
            pq.emplace(d[gt], gt);
        }
    }

    ll ans = d[0];
    rep(i, n * 2)
    {
        int l = s[i].size();
        rep(j, l)
        {
            string t = s[i].substr(j);
            if (t == rev(t)) ans = min(ans, d[idx[i][j]]);
        }

    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

