#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *archivo;
    char *operacion = argv[1];
    //strcmp es String Compare, compara 2 strings
    if(strcmp(operacion,"select")==0){
        printf("Te doy datos");
    }else if(strcmp(operacion,"insert")==0){
        char *basededatos = argv[2];
        char *nombreArchivo = argv[3];

        char ruta[100];
        strcpy(ruta,basededatos);
        strcat(ruta,"-");
        strcat(ruta,nombreArchivo);
        strcat(ruta,".txt");

        archivo = fopen(ruta,"a");
        char *texto = argv[4];

        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);
        
    }else {
        printf("La operación no es correcta");
    }
    return 0;
}