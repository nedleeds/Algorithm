#include <iostream>
#include <vector>
using namespace std;

bool isVPS(){
    string s;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '('){
            ++cnt;
        }
        else {
            --cnt;
        }
        if (cnt < 0 && i < s.length() - 1) { return false; }
    }

    return cnt == 0;
}

int main()
{
    int n;
    cin >> n;

    for (int tc = 0; tc < n; tc++)
    {
        if (isVPS()){ cout << "YES\n"; }
        else{ cout << "NO\n"; }
    }
    
    return 0;
}