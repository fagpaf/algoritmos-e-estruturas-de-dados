#include <stdio.h>

int main(){
    
    // Simples
    int num;
    printf("Escolha um numero de 0-9 e lhe darei o dobro dele:\n");
    
    scanf("%d", &num); // O "&" é um operador de referência, que armazena o endereço de memória da variável

    num *= 2;
    printf("%d\n", num);
    //------------------------------------------------------------

    // Múltiplos
    int number;
    char carac;
    printf("Escolha um numero e uma letra: \n");

    scanf("%d %c", &number, &carac);

    printf("Seu numero e: %d\n", number);
    printf("Sua letra e: %c\n", carac);
    //------------------------------------------------------------

    // Strings como input
    char str[20];
    printf("Escreva seu nome: \n");

    scanf("%s", str); 
    /*Ao tratar strings em "scanf()", temos q especificar o tamanho do array usamos 20 pq é grande o suficiente para o primeiro nome de uma pessoa, e você não tem para utilizar o operador de referência (&).
    
    A função "scanf()" tem algumas limitações: considera o espaço como um caractere de terminação, o que significa que ele só pode exibir um palavra única*/
    
    printf("Ola %s\n", str);
    //------------------------------------------------------------

    // Função "fgets()"
    
    /*Ao utilizar essa função vc terá como input toda a linha de texto recebida do usuário
    e deve incluir os seguintes argumentos: o nome da variável string, sizeof(string_nome), e stdin
    */ 

    // tá bugado por causa do scanf() acima
    char nome[30];
    printf("Escreva seu primeiro e ultimo nome: \n");

    fgets(nome, sizeof(nome), stdin); // "sizeof" é o tamanho máximo do buffer, "stdin" indica entrada padrão
    
    printf("Esse é seu nome? %s\n", nome);
    //------------------------------------------------------------
    
    // %[^'\n']

    /*O formato %[^'\n'] é usado em uma chamada scanf em linguagem C para ler uma sequência de caracteres
    até encontrar uma quebra de linha ('\n').
    */  
    //scanf(" %[^\n]%*c %[^\n]%*c %[^\n]%*c %[^\n]%*c", linha1, linha2, linha3, linha4);
    return 0;
}