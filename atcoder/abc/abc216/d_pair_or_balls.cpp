//------------------------------
//ABC_216_D
//Pair of Balls
//1038
//------------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<queue<int>> vq(m);
    vector<int> h(n);
    vector<vector<int>> wo(n);
    rep(i, m)
    {
        int k; cin >> k;
        rep(j, k)
        {
            int a; cin >> a; --a;
            vq[i].emplace(a);
            wo[a].emplace_back(i);
        }
        h[vq[i].front()]++;
    }
    queue<int> color;
    rep(i, n)
    {
        if (h[i] == 2) color.emplace(i);
    }
    while (!color.empty())
    {
        int c = color.front();
        color.pop();
        int m1 = wo[c][0];
        int m2 = wo[c][1];
        vq[m1].pop();
        vq[m2].pop();
        int nc1 = -1;
        int nc2 = -1;
        if (!vq[m1].empty())nc1 = vq[m1].front();
        if (!vq[m2].empty()) nc2 = vq[m2].front();

        if (nc1 != -1)
        {
            h[nc1]++;
            if (h[nc1] == 2) color.emplace(nc1);
        }
        if (nc2 != -1)
        {
            h[nc2]++;
            if (h[nc2] == 2) color.emplace(nc2);
        }

    }


    rep(i, m)
    {
        if (!vq[i].empty())
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}