//1074
//abc140_d_face_produces_unhappiness
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

int main() 
{    
    int n, k;
    string s;
    cin >> n >> k >> s;
    char init = s[0];
    bool ic = true;
    int sk = 0;
    int ans = -1;
    rep(i,n)
    {
        char si = s[i];
        if(si == init)
        {
            if(ic) ++ans;
            else 
            {
                ic = true;
            }
        }
        else
        {
            if(sk < k)
            {
                if(i != n-1 && s[i] != s[i+1]) ++sk;
                ++ans;
                ic = true;
            }
            else
            {
                if(!ic) ++ans;
                else ic = false;
            }   
        }
    }
    cout << ans << endl;
    return 0;
}
/*
lrlrrl -> 1

101001
010120 ->

lllrll

rlrr -> 1
llrl -> 1

lrlrrl
llrlll
rrllll

13 3
LRRLRLRRLRLLR

lrrrrrrrrrllr
lllllllll

9 2
RRRLRLRLL
llllllrll
rrrll
rrrrrrrll



１操作で最大＋２？
＋２のとき
rl---ll
*/