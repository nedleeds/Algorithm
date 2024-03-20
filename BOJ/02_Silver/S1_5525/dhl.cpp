#include <iostream>
#include <vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

int N, M;
vector<char> V;

int main()
{
    fastio;
    freopen("input.txt", "r", stdin);

    cin >> N >> M;

    if (M < 2){
        cout << 0 << '\n';
        return 0;
    }

    int cnt = 0;
    V.resize(M, 0);
    for (int i = 0; i < M; i++){
        cin >> V[i];
        if (i >= 2){
            if (V[i - 2] == 'I' && V[i - 1] == 'O' && V[i] == 'I'){
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';

    return 0;
}