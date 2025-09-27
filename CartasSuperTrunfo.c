#include <stdio.h>
#include <string.h>

// Definição da estrutura da Carta (struct) - Atualizada População e Super Poder
typedef struct {
    char estado;
    char cod[4];
    char nomecidade[50];
    // População agora é unsigned long int
    unsigned long int populacao; 
    float area;
    float pib;
    int pontosTuristico;
    
    // Campos calculados
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder; // Novo campo
} CartaCidade;

// 1. Função para ler os dados de UMA carta (População atualizada para %lu)
void lerCarta(CartaCidade *carta, int numero) {
    printf("\n--- Insira os dados da Carta %d ---\n", numero);
    
    printf("Digite o estado (A a H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o codigo da carta (ex: C01): ");
    scanf(" %s", carta->cod);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomecidade);

    printf("Digite o N° de habitantes da cidade: ");
    // Mudança: %lu para unsigned long int
    scanf(" %lu", &carta->populacao); 

    printf("Digite a area da cidade em KM²: ");
    scanf(" %f", &carta->area);

    printf("Digite o PIB da cidade: ");
    scanf(" %f", &carta->pib);

    printf("Numero de Pontos Turisticos: ");
    scanf(" %d", &carta->pontosTuristico);
}

// 2. Função para calcular as estatísticas básicas
void calcularEstatisticas(CartaCidade *carta) {
    // Cálculo da Densidade Populacional: População / Área
    if (carta->area > 0) {
        // Conversão explícita (unsigned long int para float)
        carta->densidadePopulacional = (float)carta->populacao / carta->area; 
    } else {
        carta->densidadePopulacional = 0.0;
    }
    
    // Cálculo do PIB per Capita: PIB / População
    if (carta->populacao > 0) {
        // Conversão explícita (unsigned long int para float)
        carta->pibPerCapita = carta->pib / (float)carta->populacao; 
    } else {
        carta->pibPerCapita = 0.0;
    }
}

// 3. NOVA FUNÇÃO: Calcula o Super Poder
void calcularSuperPoder(CartaCidade *carta) {
    float inversoDensidade;
    
    // O inverso da densidade é 1/Densidade Populacional
    if (carta->densidadePopulacional > 0) {
        inversoDensidade = 1.0f / carta->densidadePopulacional;
    } else {
        inversoDensidade = 0.0f; 
    }
    
    // Cálculo do Super Poder: Soma de todos os atributos numéricos
    // Atenção nas conversões de tipo (casting) para float!
    carta->superPoder = 
        (float)carta->populacao + 
        carta->area + 
        carta->pib + 
        (float)carta->pontosTuristico + 
        carta->pibPerCapita + 
        inversoDensidade;
}

// 4. Função para exibir os dados de UMA carta (Detalhada)
void exibirCarta(CartaCidade carta) {
    printf("--------------------------------------------------\n");
    printf("| Estado: %c | Código: %s | Super Poder: %.2f |\n", 
           carta.estado, carta.cod, carta.superPoder);
    printf("| Cidade: %-37s |\n", carta.nomecidade);
    printf("--------------------------------------------------\n");
    
    printf("| 1. População: %lu hab\n", carta.populacao);
    printf("| 2. Área: %.2f km²\n", carta.area);
    printf("| 3. PIB: %.2f\n", carta.pib);
    printf("| 4. Pontos Turísticos: %d\n", carta.pontosTuristico);
    
    printf("| ------------------------------------------------\n");
    printf("| 5. Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("| 6. PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("--------------------------------------------------\n");
}

// 5. NOVA FUNÇÃO: Compara todos os atributos
void compararCartas(CartaCidade c1, CartaCidade c2) {
    int resultado;
    
    printf("\n=============== COMPARAÇÃO DE CARTAS ===============\n");
    
    // Atributo 1: População (Maior vence)
    resultado = (c1.populacao > c2.populacao);
    printf("População: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Atributo 2: Área (Maior vence)
    resultado = (c1.area > c2.area);
    printf("Área: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Atributo 3: PIB (Maior vence)
    resultado = (c1.pib > c2.pib);
    printf("PIB: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Atributo 4: Pontos Turísticos (Maior vence)
    resultado = (c1.pontosTuristico > c2.pontosTuristico);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // ATENÇÃO! Atributo 5: Densidade Populacional (MENOR vence)
    // Se c1 é MENOR que c2, Carta 1 vence (resultado = 1)
    resultado = (c1.densidadePopulacional < c2.densidadePopulacional); 
    printf("Densidade Populacional: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Atributo 6: PIB per Capita (Maior vence)
    resultado = (c1.pibPerCapita > c2.pibPerCapita);
    printf("PIB per Capita: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);

    // Atributo 7: Super Poder (Maior vence)
    resultado = (c1.superPoder > c2.superPoder);
    printf("Super Poder: Carta %d venceu (%d)\n", resultado ? 1 : 2, resultado);
    
    printf("==================================================\n");
}


int main() {
    CartaCidade cartas[2];

    printf("----- SUPER TRUNFO CIDADES (Nível Avançado) -----\n");
    
    // ----------------------------------------------------
    // CARTA 1
    // ----------------------------------------------------
    lerCarta(&cartas[0], 1); 
    calcularEstatisticas(&cartas[0]); 
    calcularSuperPoder(&cartas[0]); 

    // ----------------------------------------------------
    // CARTA 2
    // ----------------------------------------------------
    lerCarta(&cartas[1], 2);
    calcularEstatisticas(&cartas[1]); 
    calcularSuperPoder(&cartas[1]); 

    // ----------------------------------------------------
    // EXIBIÇÃO E COMPARAÇÃO
    // ----------------------------------------------------
    printf("\n\n=============== CARTAS CADASTRADAS ==============\n");
    printf("Carta 1:\n");
    exibirCarta(cartas[0]);
    printf("\nCarta 2:\n");
    exibirCarta(cartas[1]);
    
    // Chama a função de comparação
    compararCartas(cartas[0], cartas[1]);

    return 0;
}