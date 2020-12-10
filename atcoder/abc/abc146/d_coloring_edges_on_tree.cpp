//1192
//abc146_d_coloring_edges_on_tree
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int n; cin >> n;
    vector<P> m;
    vector<int> m_num(n);
    vector<vector<int>> link(n);

    rep(i,n-1)
    {
        int a,b; cin >> a>>b;
        --a,--b;
        m.emplace_back(a,b);
        m_num[a]++;
        m_num[b]++;
        link[a].emplace_back(b);
        link[b].emplace_back(a);
    }
    int mxm = 0;
    int mxe = 0;
    rep(i,n-1)
    {
        if(m_num[i] > mxm)
        {
            mxm = m_num[i];
            mxe = i;
        }
    }
    queue<int> q;
    map<P,int> tans;
    q.emplace(mxe);
    vector<int> used(n,0);
    while(!q.empty())
    {
        int te = q.front();
        int color = used[te];
        q.pop();
        int ci = 1;
        for(auto li:link[te])
        {
            P tp;
            tp.first = te;
            tp.second = li;
            if(tans[tp] != 0) continue;
            if(color == ci) ++ci;
            used[li] = ci;
            tans[tp] = ci;
            swap(tp.first,tp.second);
            tans[tp] = ci;
            q.emplace(li);
            ++ci;
        }
    }

    cout << mxm << endl;
    for(auto pi : m) cout << tans[pi] << endl;
    return 0;
}