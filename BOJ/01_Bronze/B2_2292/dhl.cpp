#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    long long n, ans;
    cin >> n;
    
    if (n == 1){
        ans = 0;
    }
    else{
        int k = 2;
        while (3 * (k-2) * (k-1) + 1){
            if (n <= 3 * (k-2) * (k-1) + 1){ break; }
            k++;
        }
        ans = k - 2;
    }

    cout << ans + 1 << '\n';

    return 0;
}