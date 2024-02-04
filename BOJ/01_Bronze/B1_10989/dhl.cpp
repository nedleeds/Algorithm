#include <iostream>
using namespace std;

short DAT[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        short x;
        cin >> x;
        DAT[x] += 1;
    }

    for (int j = 1; j <= 10000; j++ && DAT[j]){
        while (DAT[j]--){
            cout << j << '\n'; 
        }
    }

    return 0;
}

/*
short -> 2byte
10000000 -> 20mb c
20mb >>> 8MB !!
*/