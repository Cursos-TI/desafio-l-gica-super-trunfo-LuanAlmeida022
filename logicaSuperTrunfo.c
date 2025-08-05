#include <stdio.h>

int main(){

    // Variáveis das cartas

    char estado1 [50], estado2[50];
    char codigo1[50], codigo2[50];
    char cidade1 [50], cidade2[50];
    long long int pib1, pib2;
    unsigned long int populacao1, populacao2;
    float area1, area2, densidade1, densidade2, cap1, cap2;
    int turistico1, turistico2;
    float superpoder1, superpoder2;

    //Coleta de dados da carta 1
   
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
    
  //Calculo da Densidade Populacional e do  PIB per Capita carta 1
    densidade1= (float) populacao1 / area1;
    cap1= (float)pib1 / populacao1;

  //Coleta de dados da carta 2

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
    
  //Calculo da Densidade Populacional e do  PIB per Capita carta 2
    densidade2= (float) populacao2 / area2;
    cap2= (float) pib2 / populacao2;

  // Cálculo do Super Poder 
    superpoder1 = (float)populacao1 + area1 + (float)pib1 + (float)turistico1 + cap1 + (1.0f / densidade1);
    superpoder2 = (float)populacao2 + area2 + (float)pib2 + (float)turistico2 + cap2 + (1.0f / densidade2);

  //Informações das cartas listadas

   printf("Carta 1 \n");
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


   printf("Carta 2 \n");
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

 // Exibição da comparação
    printf("Comparação de Cartas\n");
   
    printf("Atributo: População\n");
    printf("Carta 1 %s: %lu\n", cidade1,populacao1);
    printf("Carta 2 %s: %lu\n", cidade2,populacao2);
   
   if(populacao1 > populacao2){
     printf("Carta 1 venceu\n");
   }
   else{
    printf("Carta 2 venceu\n");
   }
   
    printf("Atributo: Área\n");
    printf("Carta 1 %s: %f\n", cidade1,area1);
    printf("Carta 2 %s: %f\n", cidade2,area2);
  
   if(area1 > area2){
    printf("Carta 1 venceu\n");
   }
   else{
    printf("Carta 2 venceu\n");
   }
   
   printf("Atributo:PIB\n");
   printf("Carta 1 %s: %lld\n", cidade1,pib1);
   printf("Carta 2 %s: %lld\n", cidade2,pib2);
   
   if(pib1 > pib2){
    printf("Carta 1 venceu\n");
   }
   else{
    printf("Carta 2 venceu\n");
   }
    
    printf("Atributo: PIB per capita\n");
    printf("Carta 1 %s: %f\n", cidade1,cap1);
    printf("Carta 2 %s: %f\n", cidade2,cap2);
   
    if(cap1 > cap2){
    printf("Carta 1 venceu\n");
   }
   else{
    printf("Carta 2 venceu\n");
   }
    
    printf("Atributo: Densidade populacional\n");
    printf("Carta 1 %s: %f\n", cidade1,densidade1);
    printf("Carta 2 %s: %f\n", cidade2,densidade2);
   
    if(densidade1 < densidade2){
    printf("Carta 1 venceu\n");
   }
   else{
    printf("Carta 2 venceu\n");
   }
   
   return 0;


}