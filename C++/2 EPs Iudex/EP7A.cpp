#include <bits/stdc++.h>

using namespace std;

int max(int a, int b);
int coinRow(int C[], int n, int arr_res[]);

int main() {
    int cases, n;
    cin >> cases;
    int val_case = 1;

    while (cases--) {
        cin >> n;

        if(n == 0){
            cout << "Caso " << val_case << ": 0=0" << endl;
            val_case++;
            continue;
        }

        int arr[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int arr_res[n + 1];
        int res = coinRow(arr, n, arr_res);

        stack<int> s;
        int i = n;
        while (i >= 1) {
            if (i == 1 || arr_res[i] != arr_res[i - 1]) {
                s.push(arr[i]);
                i -= 2;
            } else {
                i -= 1;
            }
        }

        bool first = true;
        cout << "Caso " << val_case << ": ";
        while (!s.empty()) {
            if (!first) {
                cout << "+";
            }
            first = false;
            cout << s.top();
            s.pop();
        }
        cout << "=" << res << endl;
        val_case++;
    }
    
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int coinRow(int C[], int n, int arr_res[]) {
    int F[n + 1];
    F[0] = 0;
    F[1] = C[1];
    arr_res[0] = 0;
    arr_res[1] = C[1];

    for (int i = 2; i <= n; i++) {
        F[i] = max(C[i] + F[i - 2], F[i - 1]);
        arr_res[i] = F[i];
    }
    return F[n];
}

// g++ EP7A.cpp -o EP7A.exe ; Get-Content input.txt | ./EP7A.jexe