//ABC_214_C
//Distribution
//319
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using T = tuple<int, int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int>S(n);
    vector<P> T(n);
    rep(i, n) cin >> S[i];
    rep(i, n) cin >> T[i].first;
    rep(i, n) T[i].second = i;
    vector<ll> ANS(n);
    rep(i, n) ANS[i] = T[i].first;
    sort(T.begin(), T.end());

    for (auto const& [val, i] : T)
    {
        int idx = i;
        while (1)
        {

            int nx = (idx + 1) % n;
            if (ANS[nx] <= S[idx] + ANS[idx]) break;
            ANS[nx] = S[idx] + ANS[idx];
            idx = nx;
        }
    }
    for (auto const& a : ANS) cout << a << endl;
    return 0;
}