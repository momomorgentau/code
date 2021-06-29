//078
//Easy Graph Problem
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, n) sum += a[i];
    ll now = 0;
    queue<int> q;
    rep(i, 2 * n)
    {
        int ai = a[i % n];
        while (sum < 10 * now)
        {
            now -= q.front();
            q.pop();
        }
        if (sum == now * 10)
        {
            cout << "Yes" << endl;
            return 0;
        }
        now += ai;
        q.emplace(ai);
    }
    cout << "No" << endl;
    return 0;
}