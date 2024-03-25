#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int ans = 0;
    for (int i = 0; i < m; i++){
        if (s[i] == 'O') continue;
        
        int k = 0; // IOI 수
        while (s[i + 1] == 'O' && s[i + 2] == 'I'){
            k++;
            if (k == n){
                ans++;
                k--; // 연속된 IOI(n) 일 때를 고려하여 하나 뺌
            }
            i += 2; // next index
        } 
    }

    cout << ans << '\n';

    return 0;
}