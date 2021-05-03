//ABC_114_D_756
//1337
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
    map<int,int> mp;
    for(int i=2;i<=n;++i)
    {
        int tmp = i;
        int pn = 2;
        while(tmp>1)
        {
            if(tmp%pn == 0) 
            {
                ++mp[pn];
                tmp/=pn;
            }
            else ++pn;
        }
    }
    vector<int> able;
    for(auto [key,num]:mp) cout << key<<" "<<num << endl;

    int h75=0,h25=0,h15=0,h5=0,h3=0;
    for(auto [key,num]:mp) 
    {
        if(num>=74) ++h75;
        if(num>=24) ++h25;
        if(num>=14) ++h15;
        if(num>=4) ++h5;
        if(num>=2) ++h3;
    }
    int ans =0;
    //75*1
    ans += h75;
    //25*3
    ans += h25*(h25-1)/2;
    ans += h25*(h3-h25);
    //15*5
    ans += h15*(h15-1)/2;
    ans += h15*(h5-h15);
    //5*5*3
    ans += h5*(h5-1)*(h5-2) / 6;
    ans += h5*(h5-1)/2 * (h3-h5);
    cout << ans << endl; 
    return 0;
}