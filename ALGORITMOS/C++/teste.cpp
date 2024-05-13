// # se lê 'diretiva'

#include <iostream>
using namespace std;
#define pi 3.14159 // "#define" declara uma constante


int main(){
    
    int vida = 2, water = 40, num1, num2; // Declarações multiplas
    
    cout << "Digite dois numeros de 0-10?""\n";
    cin >> num1;
    cin >> num2;
    // Representação de if e else
    if (vida == water){
        cout << "True";
    }
    else{
        cout << "False""\n";
    }
    if (num1 && num2 > 3){
        cout << "flavinho pauzudo""\n";
    }

    cout << "Hello World""\n"; // todo output tem q ter ";" no final
    cout << pi << "\n";
    return 0;
}

// **** VER OUTRAS BIBLIOTECAS DE C++