#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *archivo;
    char *basededatos = argv[1];
    char *nombreArchivo = argv[2];
    
    //strcpy copia el string, juntandolo podemos crear un string por trozos
    char ruta[100];
    strcpy(ruta,basededatos);
    strcat(ruta,"-");
    strcat(ruta,nombreArchivo);
    strcat(ruta,".txt");
    
    archivo = fopen(ruta,"a");
    char *texto = argv[3];
    fputs(strcat(texto,"\n"),archivo);
    fclose(archivo);
    return 0;
}