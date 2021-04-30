//ABC_199_D
//RGB_Coloring_2
//1804
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> g(20);
vector<int> prm;
vector<int> used(20,-1);
//探索順序をもとめる
//探索順序をprmにいれる
void dfs1(int s)
{
    //一度訪れた頂点をメモ
    used[s] = 1;
    //通った頂点を順番に入れて行く
    prm.emplace_back(s);
    for(auto e:g[s])
    {
        //通った頂点には行かない
        if(used[e]!=-1)continue;
        dfs1(e);
    } 
}
//頂点の色を管理
vector<int> color(20,-1);
//塗り方を全探索
//lは今まで塗った頂点数
int dfs2(int l)
{
    int res = 0;
    //もし、全部塗れてたら+1をかえす
    if(l == prm.size()) return 1;
    //次の頂点
    //prmには頂点が順番で入ってる
    int s = prm[l];
    //使用可能な色
    vector<int> c(3);
    for(auto e: g[s])
    {
        if(color[e]==-1) continue;
        //隣り合う頂点で使われてたら+1
        ++c[color[e]];
    }
    rep(i,3)
    {
        //0のものだけ使える
        if(c[i]!=0)continue;
        //色をつけて次の頂点へ
        //グローバルのカラーに書き込む
        color[s] = i;
        res += dfs2(l+1);
        //戻るときには色を消す
        color[s] = -1;
    }
    return res;
}

int main()
{
    int n,m;
    cin >> n >> m;
    rep(i,m)
    {
        int a,b;
        cin>> a>>b;
        --a,--b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    ll ans = 1;
    rep(i,n)
    {
        //通った頂点は1となっている。
        //連結しているので飛ばす。
        if(used[i] == 1) continue;
        //配列をからにしておく
        prm.clear();
        //頂点iから順番をprmに追加していく
        dfs1(i);
        //色情報をリセット、全部の色を消す。
        rep(j,n) color[j] = -1;
        //頂点数0から探索開始
        ans *= dfs2(0);
    }
    cout << ans << endl;

    return 0;
}