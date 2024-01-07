#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long, int> COUNT_MAP;
int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N; 

    for (int i = 0; i < N; i++){
        int v; 
        cin >> v;
        if (COUNT_MAP.count(v) > 0){
            COUNT_MAP[v]++;
        }
        else{
            COUNT_MAP[v] = 1;
        }
    }

    cin >> M;

    for (int j = 0; j < M; j++){
        int k;
        cin >> k;
        cout << COUNT_MAP[k] << " ";
    }
    
    return 0;
}