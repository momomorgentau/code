//160
//abc124_c_coloring_colorfully
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    string s;
    cin >> s;
    int ans1 = 0;
    int ans2 = 0;
    rep(i,s.size())
    {
        if(i%2 == 0) {if(s[i] =='0') ++ans1;}
        else {if(s[i] == '1') ++ans1;}
    }
    rep(i,s.size())
    {
        if(i%2 == 1) {if(s[i]=='0') ++ans2;}
        else {if(s[i] == '1') ++ans2;}
    }
    cout << min(ans1,ans2) << endl;
    return 0;
}


