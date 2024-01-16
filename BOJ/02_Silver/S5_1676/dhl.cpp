#include <iostream>
using namespace std;

int dfs(int cnt, int num){
    if (num % 5 != 0 ){
        return cnt;
    }

    return dfs(cnt + 1, num / 5);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n; 
    cin >> n;
    
    if (n == 0) { cout << "0\n"; }
    else {
        int ans = 0;
        for (int i = 1; i <=n ; i++){
            ans += dfs(0, i);
        }
        cout << ans << '\n';
    }

    return 0;
}