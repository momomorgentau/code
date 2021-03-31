//ABC_197_F_
//
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n,m;
    cin >> n >> m;
    //元のグラフ
    //繋がっている頂点番号
    //辺に書かれている文字
    vector<vector<P>> g1(n);
    //2乗のグラフ
    //繋がっている頂点番号（前側）
    //繋がっている頂点番号（後ろ側）
    vector<vector<vector<P>>> g2(n, vector<vector<P>> (n));

    //グラフの構成
    rep(i,m)
    {
        int a,b;
        char c;
        cin >> a >> b >> c;
        --a;--b;
        //数字に変換
        g1[a].emplace_back(b,c-'a');
        g1[b].emplace_back(a,c-'a');
    }
    //2乗のグラフの構成
    rep(ai,n)rep(bj,n)
    {
        //前側頂点に繋がっている頂点
        for(auto eci:g1[ai])
        {
            int ei,ci;
            tie(ei,ci) = eci;
            //後ろ側頂点に繋がっている頂点
            for(auto ecj:g1[bj])
            {
                int ej,cj;
                tie(ej,cj) = ecj;
                //前側と後ろ側の文字が一致している
                if(ci == cj)
                {
                    g2[ai][bj].emplace_back(ei,ej);
                    g2[ei][ej].emplace_back(ai,bj);
                }
            }
        }
    }
    //大きな値を入れておく
    const int INF = 1e9;
    int ans = INF;
    //頂点をすでに通過済みかを監視
    vector<vector<int>> used(n,vector<int> (n));

    queue<tuple<int,int,int>> q;
    //初期状態を入れる
    q.emplace(0,n-1,0);
    while(!q.empty())
    {
        int x,y,cost;
        tie(x,y,cost) = q.front();
        q.pop();
        //偶数長
        if(x==y) ans = min(ans,2*cost);
        //奇数長
        for(auto yi :g1[x]) 
        {
            if(y == yi.first) ans = min(ans,2*cost+1);
        }

        for(auto xyi:g2[x][y])
        {
            int xi,yi;
            tie(xi,yi) = xyi;
            //通過済みかどうかを判定
            if(used[xi][yi]) continue;
            used[xi][yi] = 1;
            //距離を+1してqueueにいれる
            q.emplace(xi,yi,cost+1);
        }
    }
    //もし回文が作れなかったら-1
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}