//466
//abc171c_one_quadrillion_and_one_dalmatians
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using ll = long long;
using namespace std;

const int c = 26;

char i2c(int n) { return 'a' + n; }

int main() 
{
    ll n;
    cin >> n;
    
    string ans;
    while (n > 0) 
    {
        int r = n % c;
        if (r == 0) r = c-1;
        else --r;
        ans += i2c(r);
        --n;
        n /= c;
        
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}
