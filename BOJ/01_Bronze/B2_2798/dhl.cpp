#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector V;

int dfs(int target, int depth){
    if (depth == target){
        
    }

    // for (int j = 0; j < breadth; j++)
    // {
    //     dfs()
    // }
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

    for (int i = 0; i < N; i++){
        dfs(3, 0);
    }
}