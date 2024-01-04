#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool DAT[100]; // int 배열과 메모리 차이는 없다고 측정됨
int Max = -2134567890;
vector<int> V;

void dfs(int depth, int idx, int s){
    if (depth == 3){
        if (s > Max){ Max = s; }
        return ;
    }

    for (int i = 0 ; i < N; i++){
        if (DAT[i])       continue;
        if (s + V[i] > M) continue; 

        DAT[i] = true;
        dfs(depth + 1, i, s + V[i]);
        DAT[i] = false;
    }
}

int main()
{
    cin >> N >> M;
    V = vector<int>(N);
    
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        V[i] = x;
    }

    dfs(0, 0, 0);
    cout << Max << endl;
    return 0;
}