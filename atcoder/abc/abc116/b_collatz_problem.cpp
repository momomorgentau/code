//ABC_116_B_Collatz_Problems
//128
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int s;
    cin >> s;
    map<int,bool> mp;
    mp[s] = true;
    int a = s;
    int ans = 1;
    while(1)
    {
        if(a&1) a = 3*a+1;
        else a = a / 2;
        if(mp[a]) break;
        else
        {
            mp[a] = true;
            ++ans;
        }
    }
    cout << ans+1 << endl;
    return 0;
}