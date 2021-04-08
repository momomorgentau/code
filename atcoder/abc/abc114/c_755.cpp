//ABC_114_C_755
//1045
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;

    auto judge = [](ll a)
    {
        int bit = 0;
        while(a > 0)
        {
            int d = a%10;
            if(d == 3) bit |= 1<<0;
            else if(d == 5) bit |= 1<<1;
            else bit |= 1<<2;
            a /= 10;
        }
        if(bit == 7) return true;
        else return false;
    };

    queue<ll> q;
    q.emplace(0);
    int ans = 0;
    while(!q.empty())
    {
        ll qi = q.front();
        q.pop();
        if(qi > n) continue;
        if(judge(qi)) ++ans;
        q.emplace(qi*10+3);
        q.emplace(qi*10+5);
        q.emplace(qi*10+7);
    }
    cout << ans << endl;

    return 0;
}