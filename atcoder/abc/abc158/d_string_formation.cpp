//610
//abc158_d_string_formation
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    string s;
    int q;
    cin >> s >> q;
    bool rev = false;
    rep(i,q)
    {
        int t;
        cin >> t;
        if(t == 1) rev = !rev;
        else
        {
            int f;
            string c;

            cin >> f >> c;
            --f;
            if(rev^f) s += c;
            else s.insert(0,c);
        }
    }
    
    if(rev) reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}
