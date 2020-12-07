//719
//abc149_d_prediction_and_restriction
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n,k,r,s,p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    int ans = 0;

    map<char,int> mp;
    mp['r'] = p;
    mp['s'] = r;
    mp['p'] = s;

    queue<int> q;
    rep(i,n)
    {
        if(!q.empty())
        {
            int h = q.front();
            if(i == h)
            {
                q.pop();
                continue;
            }
        }
        char c = t[i];
        ans += mp[c];
        int ni = i + k;
        if(ni >= n) continue; 
        char cn = t[ni];
        if(c != cn) continue;
        q.emplace(ni);       
    }
    cout << ans << endl;
    return 0;
}