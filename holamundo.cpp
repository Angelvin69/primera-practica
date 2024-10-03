#include <iostream>
#include <stdio.h>


int main()
{
    int menu;
    printf("\t menu de alumno");
    printf("\n 1:  Nuevo Alumno");
    printf("\n 2:  Actulizar");
    printf("\n 3:  Eliminar");
    scanf("%i",&menu);

    if (menu == 1){
        printf ("crear nuevo alumno");

    }
    if(menu == 2){
        printf("modifizar menu");
    }else
    if(menu == 3){
        printf("Eliminar alumno");
    }else{
        printf("El dato ingresado no es valido");
    }


    return 0;
}
   