#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> Heard(500001);
vector<string> NeverHeardSeen;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string name;
        cin >> name;
        Heard[name] = 1;
    }

    for (int j = 0; j < m; j++){
        string name;
        cin >> name;
        if (Heard[name]){
            NeverHeardSeen.push_back(name);
        }
    }

    sort(NeverHeardSeen.begin(), NeverHeardSeen.end());

    cout << NeverHeardSeen.size() << '\n';
    for (auto s: NeverHeardSeen){
        cout << s << '\n';
    }

    return 0;
}