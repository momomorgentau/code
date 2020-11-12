//559
//abc181d_hachi
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

//in contest
int solve1() 
{
    string s;
    cin >> s;
    vector<int> dn(10,0);
    bool ok = false;
    int cnt = 0;
    vector<int> s12(2);
    while (!s.empty() && !ok)
    {
        int d = s[0] - '0';
        if (!(d & 1)) 
        {
            if (dn[0] >= 1)
            {
                if (dn[0] >= 2 || dn[4] >= 1 || dn[8] >= 1) ok = true;
            }
            else if (dn[1] >= 1)
            {
                if (dn[6] >= 1) ok = true;
            }
            else if (dn[2] >= 1)
            {
                if (dn[3] >= 1 || dn[4] >= 1 || dn[7] >= 1) ok = true;
            }
            else if (dn[4] >= 1)
            {
                if (dn[8] >= 1 || dn[6] >= 1) ok = true;
            }
            else if (dn[5] >= 1)
            {
                if (dn[6] >= 1) ok = true;
            }
            else if (dn[6] >= 1)
            {
                if (dn[9] >= 1) ok = true;
            }
            else if (dn[8] >= 2) ok = true;

        }
        else 
        {
            if (dn[0] >= 1)
            {
                if (dn[2] >= 1 || dn[4] >= 1||dn[6] >= 1) ok = true;
            }
            else if (dn[1] >= 1)
            {
                if (dn[2] >= 1) ok = true;
            }
            else if (dn[2] >= 1)
            {
                if (dn[5] >= 1 || dn[8] >= 1 || dn[9] >= 1) ok = true;
            }
            else if (dn[3] >= 1)
            {
                if (dn[6] >= 1) ok = true;
            }
            else if (dn[4] >= 1)
            {
                if (dn[4] >= 2||dn[8] >= 1) ok = true;
            }
            else if (dn[6] >= 1)
            {
                if (dn[7] >= 1 || dn[8]>=1) ok = true;
            }
            
        }
        ++dn[d];
        s.erase(0, 1);
        if (cnt < 2)
        {
           s12[cnt] = d;
           ++cnt;
        }
    }
    if (cnt <= 2) 
    {
        int ts = s12[0] + 10 * s12[1];
        if (ts % 8 == 0) ok = true;
        ts = 10*s12[0] + s12[1];
        if (ts % 8 == 0) ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}
//after_contest
int solve2()
{
    string s;
    cin >> s;
    int l = s.length();
    if(l == 1)
    {
        if((s[0]-'0')%8==0) cout << "Yes"<< endl;
        else cout << "No"<< endl;
        return 0;
    }
    if(l == 2)
    {
        int s0 =s[0]-'0';
        int s1 =s[1]-'0';

        if((s0+s1*10)%8==0||(s1+s0*10)%8==0) cout << "Yes"<< endl;
        else cout << "No"<< endl;
        return 0;
    }
    vector<int> d(10);
    rep(i,l) ++d[s[i]-'0'];

    bool ans = true;
    for(int i = 0;i<1000;i+=8)
    {
        int x = i;
        vector<int> td(10,0);
        rep(j,3)
        {
            ++td[x%10];
            x/=10;
        }
        ans = true;
        rep(j,10) if(td[j] > d[j]) ans = false;
        if(ans) break;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

int main()
{
    solve2();
    return 0;
}


