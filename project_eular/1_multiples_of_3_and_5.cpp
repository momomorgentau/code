//5%
//project_eular 1

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)

using namespace std;

int main() 
{
    int n = 1000;
    int ans = 0;
    reps(i,1 ,n)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
