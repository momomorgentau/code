//061
//Deck
//*2
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int q;
    cin >> q;
    vector<int> v1, v2;
    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1) v1.emplace_back(x);
        else if (t == 2) v2.emplace_back(x);
        else
        {
            int sz = v1.size();
            
            if (x <= sz) cout << v1[sz - x] << endl;
            else cout << v2[x - sz -1] << endl;
        }
    }
    return 0;
}