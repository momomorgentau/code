//diff 5
//abc173b_judge_status_summary

#include<bits/stdc++.h>
#define rep(i,n) for(int i =0;i<n;++i)
using namespace std;
int main()
{
    int n;
    cin >> n;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    int c4 = 0;

    rep(i, n)
    {
        string s;
        cin >> s;
        if (s == "AC") ++c1;
        else if (s == "WA") ++c2;
        else if (s == "TLE") ++c3;
        else ++c4;
    }

    cout << "AC x " << c1 << endl;
    cout << "WA x " << c2 << endl;
    cout << "TLE x " << c3 << endl;
    cout << "RE x " << c4 << endl;
    return 0;
}