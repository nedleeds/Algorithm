#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    long long v;
    long long a, b, ans;
    cin >> a >> b >> v;

    if ((v - b) % (a - b) == 0){
        ans = (v - b) / (a - b);
    }
    else {
        ans = (v - b) / (a - b) + 1;
    }
    
    cout << ans << '\n';

    return 0;
}
