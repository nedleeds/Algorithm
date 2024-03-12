#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int ans[2] = {0,};
vector<vector<int>> Map;

void devide_conquer(int y, int x, int len){
    for (int r = y; r < y + len; r++){
        for (int c = x; c < x + len; c++){
            if (Map[r][c] != Map[y][x]){
                devide_conquer(y, x, len / 2);
                devide_conquer(y, x + len / 2, len / 2);
                devide_conquer(y + len / 2, x, len / 2);
                devide_conquer(y + len / 2, x + len / 2, len / 2);
                return;
            }
        }
    }
    ans[Map[y][x]]++;
}

int main(){
    fastio;
    freopen("input.txt", "r", stdin);

    int n; 
    cin >> n;

    Map.resize(n, vector<int>(n));
    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            cin >> Map[r][c];
        }
    }

    devide_conquer(0, 0, n);

    cout << ans[0] << '\n' << ans[1] << '\n';

    return 0;
}