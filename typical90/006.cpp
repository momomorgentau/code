//006
//*4
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

string A = {"abcdefghijklmnopqrstuvwxyz"};
int main()
{
    int n;
    int k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> v(26,vector<int> (s.size()));
    for(auto a:A)
    {
        int m = s.size();
        rep(j,s.size())
        {
            int idx = s.size()-1-j;
            char c = s[idx];
            if(a == c) m = idx;
            v[a-'a'][idx] = m;
        }
    }

    string ans;
    int ni = 0;
    while(k>0)
    {
        rep(j,26)
        {
            int rem = s.size()-v[j][ni]-1;
            if(rem<k-1) continue;
            k--;
            ans += j + 'a';
            ni = v[j][ni]+1;
            break;
        }
    }
    cout << ans << endl;
}