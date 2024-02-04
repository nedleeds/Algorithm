#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct POS{int r, c;} Pos;
vector<POS> V;

bool compare(POS a, POS b){
    if (a.c < b.c) return true;
    if (a.c == b.c){
        if (a.r < b.r){ return true; }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> Pos.r >> Pos.c;
        V.push_back(Pos);
    }

    sort(V.begin(), V.end(), compare);

    for (auto p: V){
        cout << p.r << ' ' << p.c << '\n';
    }

    return 0;
}