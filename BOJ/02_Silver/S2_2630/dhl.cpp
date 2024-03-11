#include <iostream>
#include <vector>
using namespace std;

int dR[4] = {1, -1, 0, 0};
int dC[4] = {0,  0,-1, 1};
int N, Cnt_blue, Cnt_white ;
vector<pair<int, int>> Blue_papers;
vector<pair<int, int>> White_papers;
vector<vector<int>> Map;
vector<vector<int>> Vst;

bool is_blue(int& l, int& r_start, int& c_start){
    for (int r = r_start; r < r_start + l; r++){
        for (int c = c_start; c < c_start + l; c++){
            if (Vst[r][c]){
                Blue_papers.clear();
                return false;
            }
            else{
                if (Map[r][c] == 1){
                    Blue_papers.push_back({r, c});
                }
                else{
                    Blue_papers.clear();
                    return false;
                }
            }
        }
    }

    for (auto blue: Blue_papers){
        Vst[blue.first][blue.second] = 1;
    }

    return true;
}

bool is_white(int& l, int& r_start, int& c_start){
    for (int r = r_start; r < r_start + l; r++){
        for (int c = c_start; c < c_start + l; c++){
            if (Vst[r][c]){
                White_papers.clear();
                return false;
            }
            else{
                if (Map[r][c] == 0){
                    White_papers.push_back({r, c});
                }
                else{
                    White_papers.clear();
                    return false;
                }
            }
        }
    }

    for (auto white: White_papers){
        Vst[white.first][white.second] = 1;
    }

    return true;
}

void search(int& l){
    // 2차원 벡터를 탐색 ...          
    for (int r = 0; r <= N - l; r += l){
        for (int c = 0; c <= N - l; c += l){
            if (is_blue(l, r, c)){
                Cnt_blue++;
            }
            if (is_white(l, r, c)){
                Cnt_white++;
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

    Map.resize(N, vector<int>(N, 0));
    Vst.resize(N, vector<int>(N, 0));

    for (int r = 0; r < N; r++){
        for (int c = 0; c < N; c++){
            cin >> Map[r][c];
        }
    }

    int len[8] = {128, 64, 32, 16, 8, 4, 2, 1}; 
    for (auto l: len){
        if (N < l) continue;
        search(l);
    }
    

    cout << Cnt_white << '\n' << Cnt_blue << '\n';

    Map.clear();
    Vst.clear();
    Blue_papers.clear();
    return 0;
}