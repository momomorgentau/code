//ABC_199_B
//Intersection
//37
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
    vector<int> v(1001,0);
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];

    rep(i,n)
    {

        for(int j =a[i];j<=b[i];++j)
        {
            ++v[j];
        }
    }
    int ans = 0;
    reps(i,1,1001) 
    {
        if(v[i]==n) ++ans;
    }
    cout << ans << endl;


    return 0;
}