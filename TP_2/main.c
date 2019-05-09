#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000
#define VACIO 0
#define OCUPADO 1



int main()


{
    sEmployee empleados[TAM];
    int idAut=1;
    int bandera=0;
    char continuar='s';


    initEmployees(empleados,TAM);

    system("cls");

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            addEmployees(empleados, TAM, idAut);
            idAut++;
            bandera=1;
            break;
        case 2:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!.   Ingrese ALTA de empleado.  \n\n");
            }
            else
            {
                modifyEmployee(empleados,TAM);
            }
            system("\n\n  pause \n\n");

            break;
        case 3:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!.   Ingrese ALTA de empleado.  \n\n");
            }
            else
            {
                removeEmployee (empleados,TAM);
            }
            system("\n\n  pause \n\n");
            break;
        case 4:
            system("cls");
            if ( bandera==0 )
            {
                printf("\nNo se ingresaron datos!.  Ingrese  ALTA de empleado. \n\n");
            }
            else
            {
                sortEmployees(empleados,TAM);
            }

            system("\n\n  pause \n\n");
            break;
        case 5:
            system("cls");
            printf("\n\n Cerrando sistema ...\n\n");
            continuar='n';
            break;
        }

    }
    while(continuar== 's');


    return 0;
}

