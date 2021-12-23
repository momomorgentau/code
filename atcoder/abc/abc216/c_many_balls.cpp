//------------------------------
//ABC_216_C
//Many Balls
//145
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
    ll n;
    cin >> n;
    string ans = "";
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans += 'A';
            --n;
        }
        else
        {
            ans += 'B';
            n /= 2;
        }

    }
    reverse(ans.begin(), ans.end());
    for (const auto& c : ans) cout << c;
    cout << endl;
    return 0;
}