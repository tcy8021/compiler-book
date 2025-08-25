#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  printf(".intel_syntax noprefix\n");
  printf(".globl main\n");
  printf("main:\n");
  printf("  mov rax, %d\n", atoi(argv[1]));
  printf("  ret\n");

  // アセンブルするときに以下のような警告を出さないようにアセンブリの末尾に追加
  // "/usr/bin/ld: warning: /tmp/ccXAZml1.o: missing .note.GNU-stack section implies executable stack"
  // "/usr/bin/ld: NOTE: This behaviour is deprecated and will be removed in a future version of the linker"
  printf(".section .note.GNU-stack,\"\",@progbits\n");
  return 0;
}