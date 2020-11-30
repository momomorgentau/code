//662
//agc_34_a_kenken_race

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{
    int n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >>d >>s;
    --a; --b; --c; --d;
    if(c < d)
    {
        bool r = true;
        reps(i,a,c)
        {

            if(i+1 < n && s[i] == '#' && s[i+1] == '#')
            {
                r = false;
            }
        }
        reps(i,b,d)
        {

            if(i+1 < n && s[i] == '#' && s[i+1] == '#')
            {
                r = false;
            }
        }
        if(r) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }
    else
    {
        bool u = false;
        bool r = true;
        reps(i,b-1,d)
        {
            if(i+2<n && s[i] == '.' && s[i+1] == '.' && s[i+2] == '.')
            {
                u = true;
            }

        }
        reps(i,a,c)
        {

            if(i+1<n && s[i] == '#' && s[i+1] == '#')
            {
                r = false;
            }
        }
        if(u && r) cout << "Yes" <<endl;
        else cout << "No" << endl;
    }

    return 0;
} 