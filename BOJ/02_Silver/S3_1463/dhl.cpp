#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    arr[1] = 0;

    for (int i = 2; i <= n; i++){
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) { 
            arr[i] = min(arr[i], arr[i / 2] + 1) ; 
        }
        if (i % 3 == 0) { 
            arr[i] = min(arr[i], arr[i / 3] + 1) ; 
        }
    }

    cout << arr[n] << '\n';

    return 0;
}

/*

3으로 나눠 떨어지면 3으로 나눈다. 
2로 나눠 떨어지면 2로 나눈다.
1을 뺀다.

arr[i] : i 를 1로 만드는 최소 연산 수.
arr[1] : 1 을 1로 만드는 최소 연산 수. : 0
arr[2] : 2 를 1로 만드는 최소 연산 수. : 2 -> 1 : 1번
arr[3] : 3 을 1로 만드는 최소 연산 수. : 3 -> 1 : 1번
arr[4] : 4 를 1로 만드는 최소 연산 수. : 4 -> (3 or 2) -> 1 : 2번 : min(arr[3], arr[2]) + 1
arr[5] : 5 를 1로 만드는 최소 연산 수. : 5 -> arr[4] + 1

*/
