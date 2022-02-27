//----------------------------
//ABC 235 C
//The Kth Time Query
//249
//----------------------------
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    rep(i, n)
    {
        int a; cin >> a;
        mp[a].emplace_back(i + 1);
    }
    while (q--)
    {
        int x, k;
        cin >> x >> k;
        if (mp[x].size() < k)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mp[x][k - 1] << endl;

        }
    }

    return 0;
}