//ABC_119_A_Still_TBD
//52
#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define reps(i,s,n) for(int i=s;i<n;++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    string s;
    cin >> s;
    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));
    int d = stoi(s.substr(8,2));
    bool heisei = false;
    if(y < 2019) heisei = true;
    else if(y > 2019) heisei = false;
    else
    {
            if(m < 4) heisei = true;
            else if(m > 4) heisei = false;
            else
            {
                    if(d <= 30) heisei = true;
                    else heisei = false;        
            }
    }
    if(heisei) cout << "Heisei" << endl;
    else cout << "TBD" << endl;

    return 0;
}