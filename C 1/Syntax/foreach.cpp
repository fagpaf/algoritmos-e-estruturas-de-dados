#include <bits/stdc++.h>

using namespace std;

int main() {
        
    // int myNumbers[5] = {10, 20, 30, 40, 50};
    // for (int i : myNumbers) {
    //     cout << i << "\n";
    // }

    string food = "Pizza";
    string &meal = food;

    cout << food << "\n";  // Outputs Pizza
    cout << meal << "\n";  // Outputs Pizza

    string* ptr = &food;
    *ptr = "Hamburguer";

    cout << *ptr << "\n";

    cout << food << "\n";

    return 0;
}