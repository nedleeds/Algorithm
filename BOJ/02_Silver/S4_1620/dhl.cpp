#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> Map;
unordered_map<string, string> Map_r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        string monster;
        cin >> monster;
        Map[to_string(i)] = monster;
        Map_r[monster] = to_string(i);
    }

    for (int j = 0; j < m; j++){
        string s;
        cin >> s;

        if ('0' <= s[0] && s[0] <= '9'){
            cout << Map[s] << '\n';
        }
        else{
            cout << Map_r[s] << '\n';
        }

    }    

    return 0;
} 