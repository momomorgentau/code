#include <iostream>
using namespace std;

int main() 
{
    set<char> s;
    string s1 = "abc";
    string s2 = "bcd";

    s.emplace(s1);
    s.emplace(s2);



	return 0;
}