#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool compare (int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    if (n == 0){
        cout << "0\n";
    }
    else{
        vector<int> board;
        for (int i = 0; i < n; i++){
            int score;
            cin >> score;
            board.push_back(score);
        }

        sort(board.begin(), board.end(), compare);
        int r = round(n * 0.15);

        int s = 0;
        for (int i = r; i < n - r; i++){
            s += board[i];
        }
        float mth = (n - 2 * r);
        cout << round(float(s / mth)) << '\n';
    }

    return 0;
}