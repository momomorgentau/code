//ABC_120_B_K-th_Common_Divisor
//97
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> ans;
    for(int i=1;i<=min(a,b);++i)
    {
        if(a%i==0 && b%i==0) ans.emplace_back(i);
    }
    cout << ans[ans.size()-k] << endl; 
    return 0;
}