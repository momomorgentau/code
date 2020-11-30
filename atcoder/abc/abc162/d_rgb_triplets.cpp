//757
//abc162_d_rgb_triplets
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int c2i(char c)
{
    if(c == 'R') return 1;
    else if(c == 'G') return 2;
    else if(c == 'B') return 4;
}

char i2c(int s)
{
    if(s == 1) return 'R';
    else if(s == 2) return 'G';
    else if(s == 4) return 'B';
}

int main()
{   
    int n;
    string s;
    cin >> n >> s;
    vector<int> rs(n);
    vector<int> gs(n);
    vector<int> bs(n);

    int r = 0, g = 0, b = 0;
    rep(i,n)
    {
        char c = s[n-i-1];
        if(c == 'R') ++r;
        else if(c == 'G') ++g;
        else if(c == 'B') ++b;
        rs[n-i-1] = r;
        gs[n-i-1] = g;
        bs[n-i-1] = b;
    }
    ll ans = 0;

    rep(i,n)
    {
        char c1 = s[i];
        reps(j,i+1,n)
        {
            char c2 = s[j];
            if(c2 == c1) continue;
            char c3 = i2c(7 - c2i(c1)-c2i(c2));
            int add;
            if(c3 == 'R') add = rs[j];
            else if(c3 == 'G') add =  gs[j];
            else if(c3 == 'B') add =  bs[j];

            int ni = j+j-i;
            if(ni < n && s[ni] == c3) --add;
            ans += add;
            
        }
    }
    cout << ans << endl;

    return 0;
}