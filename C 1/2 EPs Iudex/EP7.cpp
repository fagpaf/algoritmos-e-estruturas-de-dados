#include <bits/stdc++.h>

using namespace std;

int max(int a, int b);
int coinRow(int C[], int n, int arr_res[]);

int main() {
    int cases, n;
    cin >> cases;

    while (cases--){
        cin >> n;
        int arr[n + 1];
        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        int arr_res[n];
        int res = coinRow(arr, n, arr_res);

        stack<int> s;
        if(arr_res[n] != arr_res[n -1]){
            int var = n;
            for (int i = 0; i < n/2; i++){
                if(var == 2 && (arr_res[1] > arr_res[2])){
                    var = 1;
                }
                s.push(arr[var]);
                var = var -2;
            }

            for (int i = 0; i < n/2 ; i++){
                cout << s.top() << "+";
            }
        }

    }
    
    return 0;
}
// g++ EP7.cpp -o EP7.exe ; Get-Content input.txt | ./EP7.exe

int max(int a, int b){
    if(a > b){
        return a;
    }
    
    else{
        return b;
    }
}

int coinRow(int C[], int n, int arr_res[]){
    int F[n];
    F[0] = 0;
    F[1] = C[1];
    for (int i = 2; i <= n; i++){
        F[i] = max(C[i] + F[i - 2], F[i - 1]);
        arr_res[i] = F[i];
    }
    return F[n];
}