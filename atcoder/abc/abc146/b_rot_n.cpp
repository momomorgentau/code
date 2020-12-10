//76
//abc146_b_rot_n
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    rep(i,s.size())
    {
        int c = s[i] - 'A';
        int ns = (c + n) % 26;
        s[i] = 'A' + ns;
    }
    cout << s << endl;

}