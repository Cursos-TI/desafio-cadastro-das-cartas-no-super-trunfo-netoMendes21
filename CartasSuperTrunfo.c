#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Teste larissa

int main()
{
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    char estado;
    char codigoDaCidade[3];
    char nomeDaCidade[50];
    int populacao, quantidadePontosTuristicos;
    float area, PIB;

    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    printf("Digite o seu Estado: \n");
    scanf(" %c", &estado);

    printf("Digite a o código da sua cidade: \n");
    scanf("%s", codigoDaCidade);

    printf("Digite o nome da Cidade: \n");
    scanf(" %[^\n]", nomeDaCidade);

    printf("Digite a população da cidade: \n");
    scanf("%d", &populacao);

    printf("Digite a Área da sua cidade: \n");
    scanf("%f", &area);

    printf("Digite o PIB da cidade: \n");
    scanf("%f", &PIB);
    PIB *= 1000000000;

    printf("Digite a quantidade de pontos turísticos da cidade: \n");
    scanf("%d", &quantidadePontosTuristicos);

    int perCapita = PIB / populacao;
    float densidadePopulacional = (float) populacao / area;

    printf("\nEstado: %c", estado);
    printf("\nCódigo da Carta: %c%s", estado, codigoDaCidade);
    printf("\nNome da Cidade: %s", nomeDaCidade);
    printf("\nPopulação: %d", populacao);
    printf("\nÁrea: %.2f km²", area);
    printf("\nDensidade Populacional: %.2f pessoas/km²", densidadePopulacional);
    printf("\nPIB: %.2f bilhões de reais", PIB / 1000000000);
    printf("\nPIB per Capita: %d reais", perCapita);
    printf("\nNúmero de Pontos Turísticos: %d\n", quantidadePontosTuristicos);

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
