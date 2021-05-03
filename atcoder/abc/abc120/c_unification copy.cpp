//ABC_120_C_Unification
//373
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
    stack<char> st;
    for(char c:s)
    {
        if(!st.empty() && st.top() != c) st.pop();
        else st.emplace(c);
    }
    int ans = s.size()-st.size();
    cout << ans << endl;
    return 0;
}