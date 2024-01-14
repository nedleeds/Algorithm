#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++ ){
        q.push(i);
    }

    int cnt = 1;
    int idx = 1;
    cout << "<";
    while (!q.empty()){
        int f = q.front();
        q.pop();

        if (cnt % k == 0){
            cout << f;
            idx++;
            if (idx <= n){ cout << ", "; }
            else{ cout << ">\n"; }
        }
        else{
            q.push(f);
        }
        cnt++;
    }

    return 0;
}