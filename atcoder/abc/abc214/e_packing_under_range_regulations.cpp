//ABC_214_
//Packing Under Range Regulations
//1835
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<P> LR(n);
        rep(i, n) cin >> LR[i].first >> LR[i].second;
        sort(LR.begin(), LR.end());

        const int INF = 1e9 + 7;
        LR.emplace_back(INF, INF);

        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 1;
        bool ok = true;
        for (auto const& [l, r] : LR)
        {
            while (idx < l && !pq.empty())
            {
                if (pq.top() < idx)
                {
                    ok = false;
                    break;
                }
                pq.pop();
                ++idx;
            }



            if (!ok)
            {
                cout << "No" << endl;
                break;
            }

            idx = l;
            pq.emplace(r);
        }
        if (ok) cout << "Yes" << endl;

    }

    return 0;
}