#include <iostream>
#include <vector>
using namespace std;

int dR[4] = {1, -1, 0, 0};
int dC[4] = {0,  0,-1, 1};
int N;

void search(int& cnt, int& l, vector<vector<int>>& vst){
    // 2차원 벡터를 탐색 ...          
    for (int r = 0; r <= N - l; r++){
        for (int c = 0; c <= N - l; c++){
            for (int y = r; y < l; y++){
                for (int x = r; x < l; x++){
                    
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    cin >> N;

    vector<vector<int>> map(n, vector<int>(n, 0));
    vector<vector<int>> vst(n, vector<int>(n, 0));

    for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
            cin >> map[r][c];
        }
    }

    int len[8] = {128, 64, 32, 16, 8, 4, 2, 1}; 
    int cnt = 0;
    for (auto l: len){
        if (N < l) continue;
        search(cnt, l, vst);
    }
    
    map.clear();
    vst.clear();
    return 0;
}