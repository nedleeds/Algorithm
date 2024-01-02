#include <iostream>
#include <vector>
using namespace std;

int N, M;
int DAT[100];
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

        DAT[i] = 1;
        dfs(depth + 1, i, s + V[i]);
        DAT[i] = 0;
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