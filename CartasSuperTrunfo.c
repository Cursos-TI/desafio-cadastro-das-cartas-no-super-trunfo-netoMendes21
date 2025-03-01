#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Teste larissa
// Desafio feito José Luiz Medeiros Mendes Neto

unsigned long int perCapita(float pib, int populacao)
{
    if (populacao <= 0)
    {
        printf("A popolução dever ser maior do que zero!!");
        return 0;
    }

    return (unsigned long int)(pib / populacao);
}

float densidadePopulacional(int populacao, float area)
{
    if (area <= 0)
    {
        printf("A área deve ser maior do que zero!!\n");
        return 0;
    }
    return (float)populacao / area;
}

float superPoder(int populacao, float area, float pib, int pontosTuristicos)
{
    float perCapitaValue = (float)perCapita(pib, populacao); // Converte explicitamente para evitar problemas no resultado
    float resultado = populacao + area + pib + perCapitaValue + densidadePopulacional(populacao, area) + pontosTuristicos;
    return resultado;
}

int carta(char *estado, char *codigo, char *nome, int *populacao, float *area, float *pib, int *pontosTuristicos)
{

    printf("Digite o Estado: ");
    scanf(" %c", estado);
    *estado = toupper(*estado);

    printf("Digite o código da cidade: ");
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

    carta(&estado, codigoDaCidade, nomeDaCidade, &populacao, &area, &PIB, &quantidadePontosTuristicos);

    printf("\n***Digite as propriedades da segunda carta***\n\n");

    carta(&estado2, codigoDaCidade2, nomeDaCidade2, &populacao2, &area2, &PIB2, &quantidadePontosTuristicos2);

    // primeiro jogador//
    printf("\n----------------------Carta 1----------------------");

    cartaPronta(estado, codigoDaCidade, nomeDaCidade, populacao, area, PIB, quantidadePontosTuristicos);

    // segundo jogador //
    printf("\n----------------------Carta 2----------------------");

    cartaPronta(estado2, codigoDaCidade2, nomeDaCidade2, populacao2, area2, PIB2, quantidadePontosTuristicos2);

    printf("\n---------------Comparação das Cartas----------------");

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    int pontuacao1 = 0, pontuacao2 = 0;

    if (populacao > populacao2)
    {
        printf("\nPopulação: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (populacao < populacao2)
    {
        printf("\nPopulação: Carta 2 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate na propriedade: População\n");
    }

    if (area > area2)
    {
        printf("\nÁrea: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (area < area2)
    {
        printf("\nÁrea: Carta 2 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate na propriedade: área\n");
    }

    if (PIB > PIB2)
    {
        printf("\nPIB: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (PIB < PIB2)
    {
        printf("\nPIB: Carta 2 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate na propriedade: PIB\n");
    }

    if (quantidadePontosTuristicos > quantidadePontosTuristicos2)
    {
        printf("\nPontos Turísticos: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (quantidadePontosTuristicos < quantidadePontosTuristicos2)
    {
        printf("\nPontos Turísticos: Carta 2 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate na propriedade: número de pontos turísticos\n");
    }

    if (densidadePopulacional(populacao, area) < densidadePopulacional(populacao2, area2))
    {
        printf("\nDensidade Populacional: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (densidadePopulacional(populacao, area) > densidadePopulacional(populacao2, area2))
    {
        printf("\nDensidade Populacional: Carta 2 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate na propriedade: densidade populacional\n");
    }

    if (perCapita(PIB, populacao) > perCapita(PIB2, populacao2))
    {
        printf("\nPIB per Capita: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (perCapita(PIB, populacao) < perCapita(PIB2, populacao2))
    {
        printf("\nPIB per Capita: Carta 1 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate na propriedade: renda per capita\n");
    }

    if (superPoder(populacao, area, PIB, quantidadePontosTuristicos) > superPoder(populacao2, area2, PIB2, quantidadePontosTuristicos2))
    {
        printf("\nSuper Poder: Carta 1 venceu (1)\n");
        pontuacao1 += 1;
    }
    else if (superPoder(populacao, area, PIB, quantidadePontosTuristicos) < superPoder(populacao2, area2, PIB2, quantidadePontosTuristicos2))
    {
        printf("\nSuper Poder: Carta 2 venceu (0)\n");
        pontuacao2 += 1;
    }
    else
    {
        printf("\nEmpate no superPoder\n");
    }

    printf("\n--------------Pontuação Final---------------\n");
    printf("Carta 1: %d pontos\n", pontuacao1);
    printf("Carta 2: %d pontos\n", pontuacao2);

    printf("----------------------Resultado----------------------\n");
    if (pontuacao1 > pontuacao2)
    {
        printf("Carta 1 venceu!\n");
    }
    else if (pontuacao1 < pontuacao2)
    {
        printf("Carta 2 venceu!\n");
    }
    else
    {
        printf("Empate geral!\n");
    }
    printf("----------------------Resultado----------------------\n\n");

    return 0;
}