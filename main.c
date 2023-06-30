#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char palavra_usuario[50], letra, palavra_secreta[50];
  int tamanho_do_jogo = 0, i = 0, chances = 8, acertos = 0, acerto = 0;

  printf("=========================================\n");
  printf("| Fale para o seu amigo tampar os olhos |\n");
  printf("=========================================\n");

  printf("Digite a palavra SECRETA: ");
  scanf("%s", palavra_usuario);
  system("clear");

  //Lê o tamanho da palavra que o usuário escolheu
  while (palavra_usuario[i] != '\0') {
    i++;
    tamanho_do_jogo++;
  }

  for (i = 0; i < tamanho_do_jogo; i++) {
    palavra_secreta[i] = '-';
  }
  palavra_secreta[tamanho_do_jogo] = '\0';

  char teclado[] = "abcdefghijklmnopqrstuvwxyz";
  
// Declara e inicializa um array de caracteres contendo todas as letras do alfabeto.
  while (chances > 0 && acertos < tamanho_do_jogo) {
    printf("Chances = %d \n\n", chances);

    // Exibe o teclado
    printf("Teclado: ");
    for (i = 0; i < 26; i++) {
      int encontrado = 0;
      for (int j = 0; j < tamanho_do_jogo; j++) {
        if (teclado[i] == palavra_usuario[j] && palavra_secreta[j] != '-') {
          encontrado = 1;
          break;
        }
      }
      if (encontrado) {
        printf("_ ");
      } else {
        printf("%c ", teclado[i]);
      }
    }
    printf("\n");

    // Exibe a palavra secreta
    printf("Palavra secreta: %s\n", palavra_secreta);

    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    acerto = 0;
    for (i = 0; i < tamanho_do_jogo; i++) {
      if (palavra_usuario[i] == letra && palavra_secreta[i] == '-') {
        acerto = 1;
        palavra_secreta[i] = letra;
        acertos++;
      }
    }

    if (acerto == 0) {
      chances--;
    }

    system("clear");
  }

  if (acertos == tamanho_do_jogo) {
    printf("================================================\n");
    printf("| PARABÉNS!!! Você descobriu a palavra secreta |\n");
    printf("================================================\n");
    printf("A palavra secreta era: %s\n", palavra_usuario);
  } else {
    printf("===========================================\n");
    printf("| Infelizmente você não conseguiu acertar |\n");
    printf("===========================================\n");
    printf("A palavra secreta era: %s\n", palavra_usuario);
  }
  return 0;
}