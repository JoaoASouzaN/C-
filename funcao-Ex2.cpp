#include <stdio.h>
#include <stdlib.h>

int separador(){
    printf("---------------\n");
}
int contador(int vezes){
    int i=0;
    
    do{
    
        separador();
        i++;
    
    }while(i<=vezes);
}
int mensagem(){
    printf("Ola Mundo\n");
}

int main(){
    int repetidor;
    printf("Digite a quantidade de separadores: ");
    scanf("%d",&repetidor);
    
    contador(repetidor);
    mensagem();
    contador(repetidor);
    
    system("pause");
    return 0;
}
