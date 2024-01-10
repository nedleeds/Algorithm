#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Pos{ int x, y; }P;

bool compare(Pos a, Pos b){
    if (a.x < b.x) { return true; }
    if (a.x == b.x){ 
        if (a.y < b.y) { 
            return true; 
        } 
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    freopen("input.txt", "r", stdin);
    
    int n;
    cin >> n;

    vector<Pos> v;
    while(n--){        
        cin >> P.x >> P.y;
        v.push_back(P);
    }

    sort(v.begin(), v.end(), compare);

    for (auto pos: v){
        cout << pos.x << ' ' << pos.y << '\n';
    }

    return 0;
}