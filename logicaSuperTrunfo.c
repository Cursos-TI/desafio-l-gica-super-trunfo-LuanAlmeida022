#include <stdio.h>

// Função para obter o nome do atributo pelo código
const char* nomeAtributo(int codigo) {
    switch (codigo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade populacional";
        case 5: return "PIB per capita";
        case 6: return "SuperPoder";
        default: return "Atributo desconhecido";
    }
}

// Função para escolher atributo com exclusão do atributo já escolhido, usando switch
int escolherAtributo(int exclui) {
    int opcao;
    while (1) {
        printf("Escolha um atributo para comparar:\n");
        for (int i = 1; i <= 6; i++) {
            if (i == exclui) continue; // pula o atributo já escolhido
            switch (i) {
                case 1: printf("1. População\n"); break;
                case 2: printf("2. Área\n"); break;
                case 3: printf("3. PIB\n"); break;
                case 4: printf("4. Densidade populacional\n"); break;
                case 5: printf("5. PIB per capita\n"); break;
                case 6: printf("6. SuperPoder\n"); break;
            }
        }
        printf("Digite o número do atributo desejado: ");
        scanf("%d", &opcao);

        // Validação usando switch
        int valido = 0;
        switch (opcao) {
            case 1: case 2: case 3: case 4: case 5: case 6:
                if (opcao == exclui) {
                    printf("Você já escolheu esse atributo. Escolha outro.\n");
                } else {
                    valido = 1; // opção válida e não excluída
                }
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
        if (valido) break; // sai do loop se opção válida
    }
    return opcao;
}

int main() {

    // Variáveis das cartas
    char estado1[50], estado2[50];
    char codigo1[50], codigo2[50];
    char cidade1[50], cidade2[50];
    long long int pib1, pib2;
    unsigned long int populacao1, populacao2;
    float area1, area2, densidade1, densidade2, cap1, cap2, superpoder1, superpoder2;
    int turistico1, turistico2, opcao1, escolha2, opcao2;

    // Coleta de dados da carta 1
    printf("Digite o estado da carta 1: \n");
    scanf("%s", estado1);

    printf("Digite o código da carta 1: \n");
    scanf("%s", codigo1);

    printf("Digite a cidade da carta 1: \n");
    scanf("%s", cidade1);

    printf("Digite a população da carta 1: \n");
    scanf("%lu", &populacao1);

    printf("Digite a área da carta 1: \n");
    scanf("%f", &area1);

    printf("Digite o PIB da carta 1: \n");
    scanf("%lld", &pib1);

    printf("Digite o número de pontos turísticos da carta 1: \n");
    scanf("%d", &turistico1);

    // Calculo da Densidade Populacional e do PIB per Capita carta 1
    densidade1 = (float)populacao1 / area1;
    cap1 = (float)pib1 / populacao1;

    // Coleta de dados da carta 2
    printf("Digite o estado da carta 2: \n");
    scanf("%s", estado2);

    printf("Digite o código da carta 2: \n");
    scanf("%s", codigo2);

    printf("Digite a cidade da carta 2: \n");
    scanf("%s", cidade2);

    printf("Digite a população da carta 2: \n");
    scanf("%lu", &populacao2);

    printf("Digite a área da carta 2: \n");
    scanf("%f", &area2);

    printf("Digite o PIB da carta 2: \n");
    scanf("%lld", &pib2);

    printf("Digite o número de pontos turísticos da carta 2: \n");
    scanf("%d", &turistico2);

    // Calculo da Densidade Populacional e do PIB per Capita carta 2
    densidade2 = (float)populacao2 / area2;
    cap2 = (float)pib2 / populacao2;

    // Cálculo do Super Poder 
    superpoder1 = (float)populacao1 + area1 + (float)pib1 + (float)turistico1 + cap1 + (1.0f / densidade1);
    superpoder2 = (float)populacao2 + area2 + (float)pib2 + (float)turistico2 + cap2 + (1.0f / densidade2);

    // Informações das cartas listadas
    printf("\n***Carta 1*** \n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área em km²: %.2f\n", area1);
    printf("PIB: R$ %lld\n", pib1);
    printf("Número de pontos turísticos: %d\n", turistico1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", cap1);
    printf("Super Poder: %.2f\n", superpoder1);

    printf("\n***Carta 2*** \n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área em km²: %.2f\n", area2);
    printf("PIB: R$ %lld\n", pib2);
    printf("Número de pontos turísticos: %d\n", turistico2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", cap2);
    printf("Super Poder: %.2f\n", superpoder2);

    // Escolha dos atributos usando a função que evita repetir o mesmo atributo
    opcao1 = escolherAtributo(0);  // Nenhum atributo excluído na primeira escolha

    printf("Deseja comparar também um segundo atributo? (0 = Não, 1 = Sim): \n");
    scanf("%d", &escolha2);

    if (escolha2 == 1) {
        opcao2 = escolherAtributo(opcao1);  // Excluir o primeiro atributo na segunda escolha
    } else {
        opcao2 = 0;
    }

    // Definição dos valores dos atributos escolhidos para cada carta
    double valoratributo1A =
        (opcao1 == 1) ? populacao1 :
        (opcao1 == 2) ? area1 :
        (opcao1 == 3) ? pib1 :
        (opcao1 == 4) ? densidade1 :
        (opcao1 == 5) ? cap1 :
        superpoder1;

    double valoratributo2A =
        (opcao1 == 1) ? populacao2 :
        (opcao1 == 2) ? area2 :
        (opcao1 == 3) ? pib2 :
        (opcao1 == 4) ? densidade2 :
        (opcao1 == 5) ? cap2 :
        superpoder2;

    int maiorA = (opcao1 == 4) ? 0 : 1;  // Densidade: menor vence

    double valoratributo1B = 0, valoratributo2B = 0;
    int maiorB = 1;

    if (opcao2 != 0) {
        valoratributo1B =
            (opcao2 == 1) ? populacao1 :
            (opcao2 == 2) ? area1 :
            (opcao2 == 3) ? pib1 :
            (opcao2 == 4) ? densidade1 :
            (opcao2 == 5) ? cap1 :
            superpoder1;

        valoratributo2B =
            (opcao2 == 1) ? populacao2 :
            (opcao2 == 2) ? area2 :
            (opcao2 == 3) ? pib2 :
            (opcao2 == 4) ? densidade2 :
            (opcao2 == 5) ? cap2 :
            superpoder2;

        maiorB = (opcao2 == 4) ? 0 : 1;  // Densidade: menor vence
    }

    // Comparações dos atributos
    int resultado1 = (valoratributo1A == valoratributo2A) ? 0 :
        ((maiorA ? valoratributo1A > valoratributo2A : valoratributo1A < valoratributo2A) ? 1 : 2);

    int resultado2 = (opcao2 == 0) ? resultado1 :
        ((valoratributo1B == valoratributo2B) ? 0 :
            ((maiorB ? valoratributo1B > valoratributo2B : valoratributo1B < valoratributo2B) ? 1 : 2));

    // Exibição clara do nome das cidades e atributos usados na comparação
    printf("\n*** Detalhes da Comparação ***\n");
    printf("Cidade Carta 1: %s\n", cidade1);
    printf("Cidade Carta 2: %s\n", cidade2);
    printf("Atributos usados na comparação:\n");
    printf("  1º Atributo: %s\n", nomeAtributo(opcao1));
    if (opcao2 != 0) {
        printf("  2º Atributo: %s\n", nomeAtributo(opcao2));
    } else {
        printf("  2º Atributo: Nenhum\n");
    }

    // Resultado final detalhado
    printf("\n*** Resultado ***\n");
    if (opcao2 == 0) {
        if (resultado1 == 0)
            printf("Empate!\n");
        else if (resultado1 == 1)
            printf("Carta 1 venceu!\n");
        else
            printf("Carta 2 venceu!\n");
    }
    else {
        if (resultado1 == resultado2) {
            if (resultado1 == 0)
                printf("Empate geral!\n");
            else if (resultado1 == 1)
                printf("Carta 1 venceu nos dois atributos!\n");
            else
                printf("Carta 2 venceu nos dois atributos!\n");
        }
        else if (resultado1 == 0 || resultado2 == 0) {
            printf("Empate em um atributo, vitória no outro: %s\n",
                (resultado1 == 1 || resultado2 == 1) ? "Carta 1" : "Carta 2");
        }
        else {
            printf("Cada carta venceu um atributo! Empate geral!\n");
        }
    }

    // Soma dos atributos para decidir o vencedor
    double somaCarta1 = valoratributo1A + valoratributo1B;
    double somaCarta2 = valoratributo2A + valoratributo2B;

    printf("\n*** Resultado por soma dos atributos ***\n");
    if (somaCarta1 == somaCarta2) {
        printf("Empate na soma dos atributos!\n");
    }
    else if (somaCarta1 > somaCarta2) {
        printf("Carta 1 venceu pela soma dos atributos!\n");
    }
    else {
        printf("Carta 2 venceu pela soma dos atributos!\n");
    }

    
    return 0;
}