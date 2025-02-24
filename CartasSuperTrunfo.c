#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
// Teste larissa


// função para calcular o Pib per Capita
unsigned long int perCapita(float pib, int populacao)
{
    if (populacao == 0)
        return -1;
    return (unsigned long int)pib / populacao;
}

//função para calcular a densidade populacional
float densidadePopulacional(int populacao, float area)
{
    if (area == 0)
        return -1;
    return (float)populacao / area;
}

// função para calcular o superPoder
long long int superPoder(int populacao, float area, float pib, int pontosTuristicos)
{
    long double resuldado = populacao + area + pib + perCapita(pib, populacao) + densidadePopulacional(populacao, area) + pontosTuristicos;
    return resuldado;
}

// função para criar a carta com todos os atributos//
int carta(char *estado, char *codigo, char *nome, int *populacao, float *area, float *pib, int *pontosTuristicos)
{
    printf("Digite o Estado: ");
    scanf(" %c", estado);

    printf("Digite o código da cidade: ");
    scanf("%s", codigo);

    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", nome);

    printf("Digite a população da cidade: ");
    scanf("%d", populacao);

    printf("Digite a Área da cidade: ");
    scanf("%f", area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", pib);
    *pib *= 1000000000;

    printf("Digite a quantidade de pontos turísticos da cidade: ");
    scanf("%d", pontosTuristicos);

    return 0;
}

//Função para retornar a carta com todas informações necessárias com o formato pedido do desafio //
int cartaPronta(char estado, char *codigo, char *nome, int populacao, float area, float pib, int pontosTuristicos)
{
    printf("\nEstado: %c",toupper(estado));
    printf("\nCódigo da Carta: %c%02d", toupper(estado), atoi(codigo));
    printf("\nNome da Cidade: %s", nome);
    printf("\nPopulação: %d", populacao);
    printf("\nÁrea: %.2f km²", area);
    printf("\nDensidade Populacional: %.2f pessoas/km²", densidadePopulacional(populacao, area));
    printf("\nPIB: %.2f bilhões de reais", pib / 1000000000);
    printf("\nPIB per Capita: %lu reais", perCapita(pib, populacao));
    printf("\nNúmero de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("\nSeu SuperPoder é de: %lld\n", superPoder(populacao, area, pib, pontosTuristicos));

    return 0;
}

int main()
{
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    char estado, estado2;
    char codigoDaCidade[3], codigoDaCidade2[3];
    char nomeDaCidade[50], nomeDaCidade2[50];
    int populacao, quantidadePontosTuristicos, populacao2, quantidadePontosTuristicos2;
    float area, PIB, area2, PIB2;
    int opcao;

    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    printf("Bem-Vindo ao Jogo Super-Trunfo!\n\n");
    printf("Crie a carta do primeiro jogador:\n");
     
    // CRIAÇÃO DA CARTA DO PRIMEIRO JOGADOR//
    printf("Digite os dados da primera carta: \n\n");
    carta(&estado, codigoDaCidade, nomeDaCidade, &populacao, &area, &PIB, &quantidadePontosTuristicos);
    
    //RETORNO DA PRMEIRA CARTA//
    printf("\nEssa é a carta do primeiro jogador:\n");
    cartaPronta(estado, codigoDaCidade, nomeDaCidade, populacao, area, PIB, quantidadePontosTuristicos);
    
    printf("\nAgora crie a carta do segundo jogador\n");

    //CRIAÇÃO DA CARTA DO SEGUNDO JOGADOR//
    printf("Digite os dados da segunda carta: \n\n");
    carta(&estado2, codigoDaCidade2, nomeDaCidade2, &populacao2, &area2, &PIB2, &quantidadePontosTuristicos2);

    // RETORNO DA CARTA DO SEGUNDO JOGADOR //
    printf("\nEssa é a carta do segundo jogador:\n");
    cartaPronta(estado2, codigoDaCidade2, nomeDaCidade2, populacao2, area2, PIB2, quantidadePontosTuristicos2);

    printf("Que comece a batalha!\n");

    // Escolha de
    printf("Escolha com qual dos atributos você quer competir:\n");
    printf("1.");
    
    scanf("%d", opcao);

    switch (opcao)
    {
    case 1 :
        printf("Começar o jogo:");

        break;
    
    default:
        break;
    }
    


    
   

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    int pontuacao1, pontuacao2;
    if (populacao > populacao2)
    {
        printf("\nCarta 1 ganhou na proprieda: população\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou na propriedade: população\n");
        pontuacao2 += 1;
    }
    if (area > area2)
    {
        printf("\nCarta 1 ganhou na propriedade: área\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou na propriedade: área\n");
        pontuacao2 += 1;
    }
    if (densidadePopulacional(populacao, area) < densidadePopulacional(populacao2, area2))
    {
        printf("\nCarta 1 ganhou na propriedade: densidade populacional\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou na propriedade: densidade populacional\n");
        pontuacao2 += 1;
    }
    if (PIB > PIB2)
    {
        printf("\nCarta 1 ganhou na propriedade: PIB\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou na propriedade: PIB\n");
        pontuacao2 += 1;
    }
    if (perCapita(PIB, populacao) > perCapita(PIB2, populacao2))
    {
        printf("\nCarta 1 ganhou na propriedade: renda per capita\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou na propriedade: renda per capita\n");
        pontuacao2 += 1;
    }
    if (quantidadePontosTuristicos > quantidadePontosTuristicos2)
    {
        printf("\nCarta 1 ganhou na propriedade: números de pontos turísticos\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou na propriedade: números de pontos turísticos\n");
        pontuacao2 += 1;
    }
    if (superPoder(populacao, area, PIB, quantidadePontosTuristicos) > superPoder(populacao2, area2, PIB2, quantidadePontosTuristicos2))
    {
        printf("\nCarta 1 ganhou com o seu superPoder maior\n");
        pontuacao1 += 1;
    }
    else
    {
        printf("\nCarta 2 ganhou com o seu superPoder maior\n");
        pontuacao2 += 1;
    }
    if (pontuacao1 > pontuacao2)
    {
        printf("Carta1 venceu!\n");
    }
    else
    {
        printf("\nCarta2 venceu!\n");
    }

    printf("\nPontuação da Carta1 é: %d", pontuacao1);
    printf("\nPontuação da Carta2 é: %d\n", pontuacao2);

    return 0;
}
