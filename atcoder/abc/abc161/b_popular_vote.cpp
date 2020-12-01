//102
//abc161_b_popular_vote
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)

using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int  sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    int cnt = 0;
    for (auto ai : a)
    {
        if (ai * m * 4 >= sum) ++cnt;
    }

    if (cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
