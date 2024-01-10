#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1, 0);
    vector<int> dat(n + 1, 0);
    for (int i = 1; i <=n; i++){
        dat[i] = 0;
        v[i] = i;
    }

    int cnt = 0;
    dat[0] = 1;
    for (int j = 1; j <= n; j++){
        int n_i = (j * k) % n;
        while (dat[n_i]){
            n_i = (n_i + 1) % n;
        }
        cout << v[n_i] << ' ';
        cnt += 1;
        dat[n_i] = 1;
    }

    return 0;
}