#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *archivo;
    char *operacion = argv[1];
    char *basededatos = argv[2];
    char *nombreArchivo = argv[3];
    
    char ruta[100];
    strcpy(ruta,basededatos);
    strcat(ruta,"-");
    strcat(ruta,nombreArchivo);
    strcat(ruta,".txt");
    
    
    if(strcmp(operacion,"select")==0){
        archivo = fopen(ruta,"r");
        printf("Te doy datos:\n");
        char linea[1024];
        //Vamos a atrapar dentro de la línea, el tamaño de la linea con respecto al archivo abierto
        //Mientras que lo de dentro no sea nulo va a funcionar
        while(fgets(linea,sizeof(linea),archivo) != NULL){
            printf("Linea: %s", linea);
        }
            
    }else if(strcmp(operacion,"insert")==0){
        archivo = fopen(ruta,"a");
        char *texto = argv[4];
        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);

    }else if(strcmp(operacion,"delete")==0){
        archivo = fopen(ruta,"r+"); //modo lectura y escritura
        char *texto = argv[4];
        char linea[1024];
        int encontrado = 0;
        char *borrado = argv[5];
        //fgets(linea,sizeof(linea),archivo);
        //printf("Linea: %s", linea);

        //compara el char - strcmp() si dos cadenas son identicas devuelve 0
        while(fgets(linea,sizeof(linea),archivo) != NULL && !encontrado){
            if (strstr(linea,texto)!=NULL){
                printf("cliente encontrado: %s \n", linea);
                if (strcmp(borrado,"eliminar")==0){
                    
                    printf("Cliente borrado");
                }
                
                encontrado=1;
            }else if(!encontrado){
                printf("El cliente no pertenece a la lista");
            }
            
            //printf("Linea: %s", linea);
        }
        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);
        
    }else {
        printf("La operación no es correcta");
    }
    return 0;
}