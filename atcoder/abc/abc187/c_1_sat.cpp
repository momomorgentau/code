//ABC_187_C_1-SAT
//207
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;


int main() 
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n)
    {
        string si;
        cin >> si;
        reverse(si.begin(), si.end());
        s[i] = si;
    }
    sort(s.begin(), s.end());


    string ans = "satisfiable";

    rep(i, n-1)
    {
        if (s[i] +'!'== (s[i + 1]))
        {
            ans = s[i];
            reverse(ans.begin(), ans.end());
            break;
        }
    }
    cout << ans << endl;
    return 0;
}