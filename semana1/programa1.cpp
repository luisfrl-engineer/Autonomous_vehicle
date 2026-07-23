#include <iostream>
#include <iomanip>

float calcular_media(int leituras[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += leituras[i];
    }
    return (float)soma / tamanho;
}

int main() {
    int leituras[5] = {22, 25, 22, 24, 26};
    float media = calcular_media(leituras, 5);
    std::cout << std::fixed << std::setprecision(2); // coloca duas casas decimais na saída. 
    std::cout << "Media das leituras: " << media << std::endl;  // std::cout indica que vou imprimir na console. 
    std::cout << std::defaultfloat;  // volta para o formato padrão de saída.
    std::cout << "Media das leituras: " << media << std::endl;

    return 0;
}