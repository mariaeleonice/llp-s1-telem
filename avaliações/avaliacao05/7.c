#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
 
 char arq[100];
 printf("Digite o nome do arquivo a ser lido: ");
 fgets(arq, 100, stdin);
 arq[strcspn(arq, "\n")] = '\0'; 

 FILE* arquivo = fopen(arq, "r");
 FILE* copiaarquivo = fopen("copiaarq.txt", "w");

 char let;
 int caractere;

 while((caractere = getc(arquivo)) != EOF){
  let = tolower(caractere);

  if(let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u'){
   fputc('*', copiaarquivo);
  }else{
    fputc(caractere, copiaarquivo);
   }
 }

 fclose(arquivo);
 fclose(copiaarquivo);

 return 0;
}
