#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
    // Primeira carta

    char estado01;
    char cod01[4];
    char nomecidade01[50];
    int populacao01;
    float area01;
    float pib01;
    int pontosTuristico01;

    // Segunda carta 

    char estado02;
    char cod02[4];
    char nomecidade02[50];
    int populacao02;
    float area02;
    float pib02;
    int pontosTuristico02;


    printf("Insira os dados da primeira carta:\n");
    printf("Digite o estado (A a H):");
    scanf(" %c", &estado01);

    printf("Digite o codigo da carta:");
    scanf(" %s", &cod01);

    printf("Digite o nome da cidade:");
    scanf(" %[^\n]a", &nomecidade01);

    // %[^\n] significa > ler até encontrar um \n, utilizei para considerar nomes compostos.

    printf("Digite o N° de habitantes da cidade:");
    scanf(" %d", &populacao01);

    printf("Digite a area da cidade em KM²:");
    scanf(" %f", &area01);

    printf("Digite o PIB da cidade:");
    scanf(" %f", &pib01);

    printf("Numero de Pontos Turisticos:");
    scanf(" %d", &pontosTuristico01);

    // CARTA 2 

    printf("Insira os dados da segunda carta:\n");
    printf("Digite o estado (A a H):");
    scanf(" %c", &estado02);

    printf("Digite o codigo da carta:");
    scanf(" %s", &cod02);

    printf("Digite o nome da cidade:");
    scanf(" %[^\n]", &nomecidade02);

    printf("Digite o N° de habitantes da cidade:");
    scanf(" %d", &populacao02);

    printf("Digite a area da cidade em KM²:");
    scanf(" %f", &area02);

    printf("Digite o PIB da cidade:");
    scanf(" %f", &pib02);

    printf("Numero de Pontos Turisticos:");
    scanf(" %d", &pontosTuristico02);


    // Exibir


    printf("\n Carta 01\n");
    printf("Estado: %c\n", estado01);
    printf("Código: %s\n", cod01);
    printf("Nome Cidade: %s\n", nomecidade01);
    
    printf("População: %d\n", populacao01);
    printf("Área: %.2f km²\n", area01);
    printf("PIB: %.2f\n", pib01);
    printf("Numero de Pontos turisticos: %d\n", pontosTuristico01);

    printf("\n Carta 02\n");
    printf("Estado: %c\n", estado02);
    printf("Código: %s\n", cod02);
    printf("Nome Cidade: %s\n", nomecidade02);
    printf("População: %d\n", populacao02);
    printf("Área: %.2f km²\n", area02);
    printf("PIB: %.2f\n", pib02);
    printf("Numero de Pontos turisticos: %d\n", pontosTuristico02);

    return 0;

} 
