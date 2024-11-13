#include <bits/stdc++.h>

using namespace std;

std::tuple<int, int> create_tuple(int x, int y) {
    return std::make_tuple(x, y);
}

int main() {
    // Chama a função para criar uma tupla
    auto result = create_tuple(5, 10);

    // Imprime os valores da tupla
    std::cout << "Primeiro elemento: " << std::get<0>(result) << std::endl;
    std::cout << "Segundo elemento: " << std::get<1>(result) << std::endl;

    return 0;
}
// g++ teste.cpp -o teste.exe ; Get-Content input.txt | ./teste.exe