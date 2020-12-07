//11
//abc148_a_round_one
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int a,b;
    cin >> a >> b;
    set<int> s;
    rep(i,3) s.insert(i+1);
    s.erase(a);
    s.erase(b);

    int ans = *s.begin();
    cout << ans << endl;

    return 0;
}