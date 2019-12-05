#include <stdio.h>

void tengroup(int amount, char plusminus) {
  printf(">");
  while (amount > 0) {
    printf("+");
    amount--;
  }
  printf("[<");
  for (int i=0; i < 10; i++){
    printf("%c", plusminus);
  }
  printf(">-]<");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Need one argument.\n");
    return 1;
  }
  int state = 0;
  for(int i = 0; argv[1][i] != '\0'; i++) {
    char letter = argv[1][i];
    while (letter != state) {
      if (letter > state) {
        int difference = (letter - state);
        if(difference > 11) {
          difference -= difference % 10;
          state += difference;
          tengroup(difference / 10, '+');
        } else {
          printf("+");
          state++;
        }
      } else if (letter < state) {
        int difference = (state - letter);
        if(difference > 11) {
          difference -= difference % 10;
          state -= difference;
          tengroup(difference / 10, '-');
        } else {
          printf("-");
          state--;
        }
      }
    }
    printf(".");
    if (state == ' ') {
      printf("\n");
    }
  }
  printf("\n");
  return 0;
}

