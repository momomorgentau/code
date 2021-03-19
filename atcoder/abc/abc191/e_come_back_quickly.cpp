//ABC_191_E_Come_Back_Quickly
//1323
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<P>> edge(n);
    rep(i, m)
    {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        --ai; --bi;
        edge[ai].emplace_back(bi,ci);
    }
    const int inf = 1e9;


    rep(i, n) {
        vector<int> d(n, inf);
        priority_queue<P, vector<P>, greater<P>> pq;

        //多始点->文字を1つだけ置いた状態を全ての文字分queueに入れておく。
        /*
        rep(i, n)
        {
            pq.emplace(0,i);
        }
        */

        for (auto a : edge[i])
        {
            int bi, ci;
            tie(bi, ci) = a;
            d[bi] = min(d[bi],ci);
            pq.emplace(d[bi], bi);
        }

        while (!pq.empty())
        {
            ll c = pq.top().first;
            int s = pq.top().second;
            pq.pop();
            //cout << c <<endl;
            if (d[s] < c) continue;
            for (auto a : edge[s])
            {
                int gt = a.first;
                int gc = a.second;
                if (d[gt] <= d[s] + gc) continue;
                d[gt] = d[s] + gc;
                pq.emplace(d[gt], gt);
            }
        }
        if (d[i] == inf) cout << -1 << endl;
        else cout << d[i] << endl;
    }
    return 0;
}