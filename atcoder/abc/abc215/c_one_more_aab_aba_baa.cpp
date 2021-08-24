//ABC_215
//One More aab aba baa
//178
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main()
{
    string s;
    ll k;
    cin >> s >> k;
    sort(s.begin(), s.end());
    int cnt = 0;
    do
    {
        ++cnt;
        if (cnt == k)
        {
            cout << s << endl;
            break;
        }
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}