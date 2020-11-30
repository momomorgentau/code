//21
//abc162_a_lucky7
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
using P = pair<int,int>;

int main()
{   
    string s;
    cin >> s;
    string ans = "No";
    rep(i,3) if(s[i] - '0' == 7) ans = "Yes";
    cout << ans << endl;
    return 0;
}   
