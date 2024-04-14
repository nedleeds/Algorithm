#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dR[4] = {-1, 1, 0, 0};
int dC[4] = {0, 0, -1, 1};
int M, N;

struct Tomato {int r, c, day;};
vector<vector<int>> Box;
vector<vector<int>> Vst;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    cin >> M >> N;
    Box.resize(N, vector<int>(M, 0));
    Vst.resize(N, vector<int>(M,-1));

    int day = -1;
    queue<Tomato> ripe;
    for (int r = 0; r < N; r++){
        for (int c = 0; c < M; c++){
            cin >> Box[r][c];
            
            if (Box[r][c] == 1){
                day = 0;
                ripe.push({r, c, day});
                Vst[r][c] = day;
            }
        }
    }

    while (!ripe.empty()){
        Tomato now = ripe.front();
        ripe.pop();
        day = now.day;

        for (int i = 0; i < 4; i++){
            int r_new = now.r + dR[i];
            int c_new = now.c + dC[i];
            if (r_new < 0 || r_new >= N) continue;
            if (c_new < 0 || c_new >= M) continue;
            if (Box[r_new][c_new] == -1) continue;
            if (Vst[r_new][c_new] != -1) continue;

            ripe.push({r_new, c_new, now.day + 1});
            Vst[r_new][c_new] = now.day + 1;
        }
    }

    for (int r = 0; r < N; r++){
        for (int c = 0; c < M; c++){
            if (Vst[r][c] == -1 && Box[r][c] != -1){
                day = -1;
            }
        }
    }

    cout << day << '\n';

    return 0;
}