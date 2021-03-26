//ABC_115_D_Christmas
//1088
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll n,x;
vector<ll> a,p; 
int l0[] = {0,1,2,3,3};
ll dfs(int n, ll x)
{
    if(n==1) return l0[x-1];
    if(x==1) return 0;
    else if(x <= a[n-1]+1) return dfs(n-1,x-1);
    else if(x == a[n-1]+2) return p[n-1]+1;
    else if(x <= 2*a[n-1]+2) return dfs(n-1,x-a[n-1]-2)+p[n-1]+1;
    else return 2*p[n-1]+1;
}

int main()
{
    cin >> n >> x;
    a.emplace_back(1);
    p.emplace_back(1);

    rep(i,n)
    {
        a.emplace_back(2*a[i]+3);
        p.emplace_back(2*p[i]+1);
    }
    cout << dfs(n,x) << endl;
    return 0;
}
/*
7 3 5 3 7 3 5 3 9 3 5 3 7 3 5 3 11
*/