//001
//*3
#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
#define reps(i,s,n) for(int i =s;i<n;++i)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    rep(i,1<<n)
    {
        int bit = i;
        vector<char> v(n);

        rep(j,n)
        {
            if(bit & (1<<j)) v[n-j-1] = ')';
            else v[n-j-1] = '(';
        }
        queue<char> q;
        for(char c:v)
        {
            if(!q.empty()) 
            {
                char tc;
                tc = q.front();
                if(tc == '(' && c == ')') q.pop();
                else q.emplace(c);
            }
            else q.emplace(c);
        }
        if(q.empty())
        {
            rep(i,n) cout << v[i];
            cout << endl;
        } 
    }
    return 0;
} 