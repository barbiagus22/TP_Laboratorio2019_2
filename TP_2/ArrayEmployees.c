#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define VACIO 0
#define OCUPADO 1

/** \brief es un menu de opcion.
 *
 * \param no recibe paramertros.
 * \param no recibe paramertros.
 * \return la opcion eleigda-
 *
 */

int menu()
{
    int opcion;
    char opcionAux[6];

    system("cls");
    printf("\n ***** MENU DE OPCIONES : Nomina Empleados *****\n\n");
    printf(" 1- Alta\n");
    printf(" 2- Modificar\n");
    printf(" 3- Baja\n");
    printf(" 4- Informes \n");
    printf(" 5- Salir\n\n");


    while(!getStringNumeros("Ingrese opcion: ",opcionAux));

    opcion=atoi(opcionAux);
    printf("%d", opcion);

    if(opcion< 1 || opcion> 5)
    {
        printf("\n Error! Ingrese opcion correcta.\n\n");
        system("pause");
        fflush(stdin);
    }

    return opcion;
}

/** \brief inicializa todas el array 1 que indica vacio.
 *
 * \param estructura de empleados.
 * \param cantidad de datos del sistema.
 * \return no retorna valor.
 *
 */

void initEmployees ( sEmployee empleados [], int tam)
{
    for (int i=0 ; i< tam; i++)
    {
        empleados[i].isEmpty= VACIO;
    }
}

/** \brief muestra un empleados
 *
 * \param la estrutura empleado.
 * \param ///
 * \return no retorna valor.
 *
 */

void mostrarEmpleado (sEmployee  empleado)

{
    printf("\t\%d\t\t\%s\t\t\%s\t\t\%2.0f\t\t\%d\t\t\n ", empleado.id,empleado.name, empleado.lastname, empleado.salary, empleado.sector );

}

/** \brief para mostrar todos los empleados del la estrutura.
 *
 * \param la estrutura empleado.
 * \param cantidad de datos del sistema, tamaño.
 * \return no retorna valor.
 *
 */

void printEmployeess (sEmployee empleados [], int tam)
{
    system("cls");
    printf("\n  ******  DETALLLE DE EMPLEADOS  ****** \n\n");

    printf("\n \tID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");

    for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(empleados[i]);
        }

    }

}

/** \brief busca el indice vacio donde cargar un empleado.
 *
 * \param la estrutura empleado
 * \param el tamaño de la estrutura-
 * \return el indice se que encuentea vacio.
 *
 */

int buscarLibre( sEmployee empleados [], int tam)

{
    int indice= -1;

    for (int i= 0 ; i<tam; i ++)
    {
        if (empleados[i].isEmpty== VACIO)
        {
            indice=i;
        }
    }
    return indice;
}

/** \brief busca el indice donde se encuentra un  empleado por numero de id.
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return el indice donde se encuentra ese id de empleado.
 *
 */

int findEmployeeById( sEmployee empleados [], int tam, int idAuto)

{
    int indice= -1 ;

    for (int i=0 ; i<tam ; i++)
    {
        if ( empleados[i].id ==idAuto && empleados[i].isEmpty== OCUPADO)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief alta de un empleado.
 *
 * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \param id de los empledos. autoincremental.
 * \return no tiene retorno.
 *
 */


void addEmployees ( sEmployee empleados [], int tam, int idAut)

{

    int indice;

    system("cls");
    printf(" **** ALTA DE EMPLEADOS **** \n\n");

    indice = buscarLibre(empleados, tam);

    if (indice == -1 )
    {
        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }

    else
    {
        empleados[indice] = altaempleado(idAut);
        empleados[indice].id= idAut;
        empleados[indice].isEmpty=OCUPADO;
        printf("\n\nEmpleado dado de alta.\n\n");
        system("\n\npause");


    }

}
/** \brief alta de emleados. solicita ingreso de datos.
 *
 * \param recibe el id donde cargar ese empleado
 * \param //
 * \return el empleado cargado en ese id-
 *
 */

sEmployee altaempleado (int idAut)

{

    sEmployee empleado;

    char nameAux [25];
    char lastNameAux [25];
    char salarioAux[11];
    char sectorAux[11];

    system("cls");

    printf("\n ****  ALTA DE EMPLEADOS  **** \n\n");

    printf("ID Empleado: %d ",idAut );

    while(!getStringLetras("\n\n Ingrese nombre del empleado: ",nameAux));

    while(!getStringLetras("\nIngrese apellido del empleado: ",lastNameAux));

    while(!getStringNumeros("\nIngrese salario del empleado:  ",salarioAux));
    empleado.salary=atof(salarioAux);

    while(empleado.salary<=0 )// VALLIDAR QUE SEA MAYOR A UN NUMERO Y COPIARLO EN EL VALOR DE LA ESTRUCTURA.

    {
        printf("\n El importe debe ser mayor a 0 \n");
        while(!getStringNumeros("\nInsegre nuevo salario:  ",salarioAux));
        if (empleado.salary<=0)
        {
            empleado.salary=atof(salarioAux);
            break;
        }
    }

    while(!getStringNumeros("\nIngrese sector del empleado: ",sectorAux));

    strcpy(empleado.name,nameAux) ;
    strcpy(empleado.lastname,lastNameAux);
    empleado.sector=atoi(sectorAux);


    return empleado;
}
/** \brief modifica datos de un empleado.
 *
  * \param la estructura empleados.
 * \param tamaño de la estructura.
 * \return no tiene retorno.
 *
 */

void modifyEmployee (sEmployee empleados [], int tam )
{
    int idAut;
    int indice;
    int opcion;
    char nameAux [25];
    char lastNameAux [25];
    char salarioAux[11];
    char sectorAux[11];
    char idAux[10];

    system("cls");
    printf("\n ******  MODIFICACION EMPLEADOS  ****** \n");

    printEmployeess(empleados,tam);

    while(!getStringNumeros("\n Ingrese ID de empleado que desea MODIFICAR:  ", idAux));
    idAut= atoi(idAux);

    indice = findEmployeeById(empleados, tam, idAut);
    if( indice == -1)
    {
        printf("\n\nERROR, No hay empleado con el ID:  %d \n\n", idAut);
    }
    else
    {

        system("cls");
        printf("\n ******  MODIFICACION EMPLEADOS  ****** \n");
        printf("\n \tID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");
        mostrarEmpleado(empleados[indice]);
        printf(" \n\n");

        printf(" \n Que desea modificar? \n");
        printf("1. Nombre \n");
        printf("2. Apellido \n");
        printf("3. Salario \n");
        printf("4. Sector \n");
        printf("\n Ingrese opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            while( !getStringLetras("\nInsegre nuevo nombre: \n",nameAux));
            strcpy(empleados[indice].name,nameAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 2:
            while(!getStringLetras("\nInsegre nuevo apellido: \n", lastNameAux));
            strcpy(empleados[indice].lastname,lastNameAux);
            printf("\nModificacion Realizada\n\n");
            break;
        case 3:
            while(!getStringNumeros("\nInsegre nuevo salario: \n", salarioAux));
            empleados[indice].salary= atof(salarioAux);

            while(empleados[indice].salary<=0 )// VALLIDAR QUE SEA MAYOR A UN NUMERO Y COPIARLO EN EL VALOR DE LA ESTRUCTURA.

            {
                printf("\n El importe debe ser mayor a 0 \n");
                while(!getStringNumeros("\nInsegre nuevo salario:  ",salarioAux));
                if (empleados[indice].salary<=0)
                {
                    empleados[indice].salary =atof(salarioAux);
                    break;
                }
            }
            printf("\nModificacion Realizada\n\n");
            break;
        case 4:
            while(!getStringNumeros("\nInsegre nuevo Sector: \n", sectorAux));
            empleados[indice].sector=atoi(sectorAux);
            printf("\nModificacion Realizada\n\n");
            break;
        default:
            printf("\nNo es una opcion valida.\n\n");
            break;
        }
    }

}

/** \brief dada de baja un empleado solicitando  numero de id-
 *
 * \param estructura empleados.
 * \param tamaño de empleado-
 * \return no tiene retorno-
 *
 */

void removeEmployee (sEmployee empleados [], int tam)
{

    int idAut;
    int indice;
    char idAux[20];

    system("cls");
    printf("\n ******  BAJA DE EMPLEADOS  ****** \n");

    printEmployeess(empleados,tam);

    while(!getStringNumeros("\n Ingrese ID del empleado a dar de BAJA :  ", idAux) );
    idAut= atoi(idAux);

    indice = findEmployeeById(empleados, tam, idAut);
    if( indice == -1)
    {
        printf("\n ERROR, No hay empleado con el ID:  %d \n\n", idAut);

    }
    else
    {

        printf(" \n\n");
        empleados[indice].isEmpty = VACIO;
        system("cls");
        printf(" \n\n Baja efectuada \n\n");

    }
}
/** \brief realiza un informe sobre datos ordenamiento y suma se sueldos.
 *
 * \param la estructura empleados.
 * \param el tamaño de la estructura.
 * \return no tiene retorno.
 *
 */


void sortEmployees (sEmployee empleados [], int tam)

{

    int opcion;
    int ordenar;



    system("cls");
    printf("\n ******  INFOMES EMPLEADOS  ****** \n\n");
    printf("1. Empleados ordenados alfabeticamente por Apellido y Sector. \n");
    printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.  \n");
    printf("\n Ingrese una opcion :  ");
    scanf("%d", &opcion);

    switch(opcion)
    {
    case 1:

        system("cls");
        printf("\n ******  INFOMES EMPLEADOS  ****** \n");
        printf("\n1.Ordenar por apellido.");
        printf("\n2.Ordenar por sector.");
        printf("\n\nIngrese una opcion:  ");
        scanf("%d", &ordenar);
        {
            switch (ordenar)
            {
            case 1:
                ordenarPorApellido(empleados, tam);
                break;
            case 2:
                ordenarPorSector(empleados,tam);
                system("pause");
                break;
            }

        }
        break;
    case 2:
        salariosEmpleados(empleados, tam);
        break;
    }


}


/** \brief ordena de forma ascendete los apellido
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */
void ordenarPorApellido(sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( strcmp(empleados[j].lastname,empleados[i].lastname )<0 && empleados[j].isEmpty==OCUPADO && empleados[i].isEmpty==OCUPADO)
            {


                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;
            }
            else if (strcmp(empleados[j].lastname,empleados[i].lastname)== 0 && empleados[i].isEmpty==OCUPADO && empleados[j].isEmpty==OCUPADO)
            {
                if (strcmp(empleados[j].name,empleados[i].name)>0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=auxEmpleado;
                }
            }
        }
    }

    system("cls");
    printf("\n\n El orden de empleados por APELLIDO fue efecuado.\n\n");
    printf("\n \tID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");
    for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty ==OCUPADO)
        {
            mostrarEmpleado(empleados[i]);
        }

    }

}


/** \brief ordena por sector de manera alfabetica ascendente y sin son iguales los ordena por apellido.
 *
 * \param estructura empleado.
 * \param tamaña de la estructura.
 * \return no tiene retorno.
 *
 */

void ordenarPorSector(sEmployee empleados [], int tam )

{
    sEmployee auxEmpleado;

    for(int i=0 ; i< tam-1 ; i++)
    {
        for(int j= i+1; j<tam; j++)
        {
            if ( (empleados[j].sector < empleados[i].sector) && empleados[j].isEmpty==OCUPADO && empleados[i].isEmpty==OCUPADO)
            {


                auxEmpleado=empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxEmpleado;
            }
            else if ((empleados[j].sector == empleados[i].sector) && empleados[i].isEmpty==OCUPADO && empleados[j].isEmpty==OCUPADO)
            {
                if (strcmp(empleados[j].lastname,empleados[i].lastname)<0)
                {
                    auxEmpleado=empleados[i];
                    empleados[i]=empleados[j];
                    empleados[j]=auxEmpleado;
                }
            }
        }
    }

    system("cls");
    printf("\n\n El orden de empleados por SECTOR fue efecuado.\n");
    printf("\n \tID \t\tNOMBRE \t\tAPELLIDO  \tSALARIO \tSECTOR\n ");
    for (int i=0; i<tam ; i++)
    {

        if( empleados[i].isEmpty ==OCUPADO)
        {
            mostrarEmpleado(empleados[i]);
        }

    }
}

void salariosEmpleados (sEmployee empleados [], int tam)
{


    float totalSalary=0;
    int totalempleados=0;
    float promedioSalary=0;
    int contadordeSalaryMayoralamedia=0;

    for (int i=0; i<tam ; i++)
    {
        if (empleados[i].isEmpty==OCUPADO)
        {
            totalSalary= empleados[i].salary + totalSalary;
            totalempleados++;

        }

    }

    promedioSalary= totalSalary/totalempleados;


    for (int i=0; i<tam ; i++)
    {
        if (empleados[i].salary >= promedioSalary  && empleados[i].isEmpty== OCUPADO)

        {
            contadordeSalaryMayoralamedia++;
        }
    }

    system("cls\n");
    printf("\n - El total de salarios es : %.2f\n", totalSalary );
    printf("\n - EL promedios de salario es de :  %.2f\n", promedioSalary);
    printf("\n - Empleados que superan o igualan el salario promedio : %d\n\n", contadordeSalaryMayoralamedia);

}


/** \brief solicita mje al usuario para el ingrese de un dato tipo flotante..
 *
 * \param Mensaje a ser mostrado al usuario.
 * \param //
 * \return el numero ingresado por el usuario.
 *
 */


float getFloat(char msj[])
{
    float aux;
    printf("%s",msj);
    scanf("%f",&aux);
    return aux;
}

/** \brief solicita mje al usuario para el ingrese de un dato tipo entero.
 *
 * \param Mensaje a ser mostrado al usuario.
 * \param //
 * \return el numero ingresado por el usuario.
 *
 */

int getInt(char msj[] )
{
    int resultado;
    printf("%s",msj);
    scanf("%d",&resultado);
    return resultado;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */

char getChar(char msj[])
{
    char aux;
    printf("%s",msj);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */


int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0' || str[i]!= NULL )
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int soloLetras(char str[])
{
    int i=0;
    int retorno = 1;
    if(str[i] == '\0')
        retorno = 0;
    else
    {
        while(str[i] != '\0'  )
        {
            if(  (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return no tiene retorno.
 */

void getString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int getStringLetras(char msj[],char input[])
{
    char aux[256];
    getString(msj,aux);

    if (msj != NULL)
    {
        if(soloLetras(aux))
        {
            strcpy(input,aux);
            return 1;
        }
        else
        {
            printf("\nError!, ingrese solo letras.\n");
        }
    }



    return 0 ;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int getStringNumeros(char mensaje[],char input[])
{

    char aux[256];
    getString(mensaje,aux);


    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    else
    {
        printf("Error, ingrese solo numeros.");
    }

    return 0;
}



