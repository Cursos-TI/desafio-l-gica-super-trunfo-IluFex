#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[20];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

void cadastrarCarta(Carta *carta, int numero) {
    printf("\n📥 Cadastro da Carta %d:\n", numero);
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", carta->codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nome);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões R$): ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidade = carta->area != 0 ? carta->populacao / carta->area : 999999;
}

void exibirCarta(Carta c, int numero) {
    printf("\n📄 Carta %d - %s (%s)\n", numero, c.nome, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
}

int compararAtributo(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: return (c1.populacao > c2.populacao) ? 1 : (c1.populacao < c2.populacao) ? 2 : 0;
        case 2: return (c1.area > c2.area) ? 1 : (c1.area < c2.area) ? 2 : 0;
        case 3: return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? 2 : 0;
        case 4: return (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : (c1.pontosTuristicos < c2.pontosTuristicos) ? 2 : 0;
        case 5: return (c1.densidade < c2.densidade) ? 1 : (c1.densidade > c2.densidade) ? 2 : 0;
        default: return -1;
    }
}

void menuAtributos() {
    printf("\n📊 Atributos Disponíveis:\n");
    printf("1. População (maior vence)\n");
    printf("2. Área (maior vence)\n");
    printf("3. PIB (maior vence)\n");
    printf("4. Pontos Turísticos (maior vence)\n");
    printf("5. Densidade Populacional (menor vence)\n");
}

void resultadoComparacao(int res1, int res2, Carta c1, Carta c2) {
    if (res1 == res2 && res1 != 0)
        printf("🏆 Vencedora: %s\n", res1 == 1 ? c1.nome : c2.nome);
    else if (res1 == 0 && res2 == 0)
        printf("🤝 Empate nos dois atributos!\n");
    else if (res1 == 0)
        printf("🏆 Vencedora: %s (venceu no segundo atributo)\n", res2 == 1 ? c1.nome : c2.nome);
    else if (res2 == 0)
        printf("🏆 Vencedora: %s (venceu no primeiro atributo)\n", res1 == 1 ? c1.nome : c2.nome);
    else
        printf("⚖️ Empate técnico: uma cidade venceu em um atributo e perdeu no outro.\n");
}

int main() {
    Carta carta1, carta2;
    int attr1, attr2;

    printf("🎮 Super Trunfo - Cidades (Nível Mestre)\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    menuAtributos();
    printf("\nEscolha o primeiro atributo para comparação: ");
    scanf("%d", &attr1);
    printf("Escolha o segundo atributo para comparação: ");
    scanf("%d", &attr2);

    if (attr1 < 1 || attr1 > 5 || attr2 < 1 || attr2 > 5 || attr1 == attr2) {
        printf("❌ Atributos inválidos ou repetidos!\n");
        return 1;
    }

    int res1 = compararAtributo(carta1, carta2, attr1);
    int res2 = compararAtributo(carta1, carta2, attr2);

    printf("\n🔍 Resultado da comparação:\n");
    resultadoComparacao(res1, res2, carta1, carta2);

    return 0;
}
