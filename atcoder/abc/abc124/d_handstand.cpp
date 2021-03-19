//1138
//abc124_d_handstand
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n,k;
    string s;
    cin >> n >> k >> s;
    vector<pair<int,char>> vs;
    char c = s[0];
    int sec = 0;
    for(char si:s)
    {
        if(c==si) ++sec;
        else 
        {
            vs.emplace_back(sec,c);
            c=si;
            sec = 1;
        }
    }
    if(sec > 0) vs.emplace_back(sec,s[s.size()-1]);
    queue<pair<int,char>> q;
    int a = 0;
    int ans = 0;
    int cnt = 0;
    for(auto vi:vs)
    {
        if(vi.second == '1')
        {
            a += vi.first;
            q.emplace(vi);
        }
        else
        {
            while(cnt >= k)
            {
                int qi1;
                char qi2;
                tie(qi1,qi2) = q.front();
                q.pop();
                a -= qi1;
                if(qi2 == '0') --cnt;
            }
            a += vi.first;
            q.emplace(vi);
            ++cnt;
        }
        ans = max(ans,a);
    }
    cout << ans << endl;    
    return 0;
}

/*
110000101010001010
11----1-1010001010
1100001-1-10001010
110000101-1---1010

24111131111
2 1 1 3 1 1
 4 1 1 1 1

2+4+1+1+1
    1+1+1+1+1
        1+1+1+3+1

001111010101110101
 4 1 1 1 1
2 1 1 3 1 1

--1111-10101110101
001111-1-101110101
2+4+1+1
  4+1+1+1+1 
*/