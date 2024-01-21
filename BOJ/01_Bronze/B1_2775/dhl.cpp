#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> APT(15, vector<int>(15, 0));

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int tc;
    cin >> tc;

    for (int c = 1; c <= 14; c++){
        APT[0][c] = c;
    }

    for (int r = 1; r <= 14; r++){
        for (int c = 1; c <= 14; c++){
            for (int d = 1; d <=c; d++){
                APT[r][c] += APT[r-1][d];
            }
        }
    }

    while (tc--){
        int row, col;
        cin >> row >> col;
        cout << APT[row][col] <<'\n';
    }

    return 0;
}