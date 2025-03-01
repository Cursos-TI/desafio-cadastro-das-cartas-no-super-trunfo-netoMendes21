#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Teste larissa
// Desafio feito José Luiz Medeiros Mendes Neto

// função que calcula o PIB Per Capita
unsigned long int perCapita(float pib, int populacao)
{
    if (populacao <= 0)
    {
        printf("A popolução dever ser maior do que zero!!");
        return 0;
    }

    return (unsigned long int)(pib / populacao);
}

// Função que calcula a densidade populacional
float densidadePopulacional(int populacao, float area)
{
    if (area <= 0)
    {
        printf("A área deve ser maior do que zero!!\n");
        return 0;
    }
    return (float)populacao / area;
}

// Função que calcula o super poder da cada carta
float superPoder(int populacao, float area, float pib, int pontosTuristicos)
{
    float perCapitaValue = (float)perCapita(pib, populacao); // Converte explicitamente para evitar problemas no resultado
    float resultado = populacao + area + pib + perCapitaValue + (1 / densidadePopulacional(populacao, area)) + pontosTuristicos;
    return resultado;
}

// Função para requisição de dados para as cartas
int carta(char *estado, char *codigo, char *nome, int *populacao, float *area, float *pib, int *pontosTuristicos)
{

    printf("Digite o Estado entre A e H: ");
    scanf(" %c", estado);
    *estado = toupper(*estado);

    printf("Digite o código da cidade entre 1 e 4: ");
    scanf("%s", codigo);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome);

    printf("Digite a população da cidade: ");
    scanf("%d", populacao);

    printf("Digite a Área da cidade: ");
    scanf("%f", area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &(*pib));
    *pib *= 1000000000;

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", pontosTuristicos);

    return 0;
}

// Função que retorna a carta com todos os valores que foram requeridos formatada como pedido
int cartaPronta(char estado, char *codigo, char *nome, int populacao, float area, float pib, int pontosTuristicos)
{
    printf("\nEstado: %c", estado);
    printf("\nCódigo da Carta: %c%02d", estado, atoi(codigo));
    printf("\nNome da Cidade: %s", nome);
    printf("\nPopulação: %d", populacao);
    printf("\nÁrea: %.2f km²", area);
    printf("\nDensidade Populacional: %.2f pessoas/km²", densidadePopulacional(populacao, area));
    printf("\nPIB: %.2f bilhões de reais", pib / 1000000000);
    printf("\nPIB per Capita: %lu reais", perCapita(pib, populacao));
    printf("\nNúmero de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("\nSeu SuperPoder é de: %.2f\n", superPoder(populacao, area, pib, pontosTuristicos));

    return 0;
}

int main()
{
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    char estado, estado2;
    char codigoDaCidade[2], codigoDaCidade2[2];
    char nomeDaCidade[50], nomeDaCidade2[50];
    int populacao = 0, quantidadePontosTuristicos = 0, populacao2 = 0, quantidadePontosTuristicos2 = 0;
    float area = 0, PIB = 0, area2 = 0, PIB2 = 0;

    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("***Digite os dados da primera carta***\n\n");

    // chamada da função para inserção de dados para criar a Carta 1
    carta(&estado, codigoDaCidade, nomeDaCidade, &populacao, &area, &PIB, &quantidadePontosTuristicos);

    printf("\n***Digite as propriedades da segunda carta***\n\n");

    // chamada da função para inserção de dados para criar a Carta 2
    carta(&estado2, codigoDaCidade2, nomeDaCidade2, &populacao2, &area2, &PIB2, &quantidadePontosTuristicos2);

    // primeiro jogador//
    printf("\n----------------------Carta 1----------------------");

    // função que retorna a Carta 1 com todos seus atributos
    cartaPronta(estado, codigoDaCidade, nomeDaCidade, populacao, area, PIB, quantidadePontosTuristicos);

    // segundo jogador //
    printf("\n----------------------Carta 2----------------------");

    // função que retorna a Carta 2 com todos seus atributos
    cartaPronta(estado2, codigoDaCidade2, nomeDaCidade2, populacao2, area2, PIB2, quantidadePontosTuristicos2);

    printf("\n---------------Comparação das Cartas----------------");

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    // variáveis para comparação entre atributos de cada carta
    int compararPopulacao = populacao > populacao2;
    int compararArea = area > area2;
    int compararPIB = PIB > PIB2;
    int compararQuantidadePontosTuristicos = quantidadePontosTuristicos > quantidadePontosTuristicos2;
    int compararDensidadePopulacional = densidadePopulacional(populacao, area) < densidadePopulacional(populacao2, area2);
    int compararPerCapita = perCapita(PIB, populacao) > perCapita(PIB2, populacao2);
    int compararSuperPoder = superPoder(populacao, area, PIB, quantidadePontosTuristicos) > superPoder(populacao2, area2, PIB2, quantidadePontosTuristicos2);

    printf("\nPopulação: Carta %d venceu!\n", compararPopulacao);

    printf("\nÁrea: Carta %d venceu!\n", compararArea);

    printf("\nPIB: Carta %d venceu!\n", compararPIB);

    printf("\nPontos Turísticos: Carta %d venceu!\n", compararQuantidadePontosTuristicos);

    printf("\nDensidade Populacional: Carta %d venceu!\n", compararDensidadePopulacional);

    printf("\nPIB per Capita: Carta %d venceu!\n", compararPerCapita);

    printf("\nSuper Poder: Carta %d venceu!\n", compararSuperPoder);

    return 0;
}