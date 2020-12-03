//456
//abc157_c_guess_the_number

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;



void solve1()
{
    int n,m;
    cin >> n >> m;
    vector<int> d(n,-1);
    int ans;
    rep(i,m)
    {
        int s,c;
        cin >> s >> c;
        --s;
        if(d[s] != -1 && d[s] != c)
        {
            cout << -1 << endl;
            return;
        }
        d[s] = c;
    }

    if(d[0] == 0 && n != 1)
    {
            cout << -1 << endl;
            return;

    }

    rep(i,n)
    {
        if(d[i] == -1)
        {
            if(i == 0 && n != 1) d[i] = 1;
            else d[i] = 0;
        }
    }
    rep(i,n) cout << d[i];
    cout << endl;
}

void solve2()
{
    int n,m;
    cin >> n >> m;
    vector<int> s(m);
    vector<int> c(m);
    rep(i,m) cin >> s[i] >> c[i];
    int ans = -1;
    int st = pow(10,n-1);
    int gt = st * 10;
    if(st == 1) st = 0;

    reps(i,st,gt)
    {
        bool ok = true;
        
        rep(j,m)
        {
            int x = i;
            rep(i,n-s[j])
            {
                x /= 10;
            }
           
            if(x%10 != c[j]) ok = false;
        }
        if(ok) 
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve1();
    //solve2();

    
    return 0;
} 

