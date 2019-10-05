#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define TAM 3
#define TAMS 5



int main()
{
    int id=100;
    char salir = 'n';
    int altaOk;
    eEmployeer lista[TAM];
    eSector listaSectores[TAMS];
    inicializarEmpleados(lista,TAM);

    do
    {
        switch(menu())
        {
        case 1:
            altaOk=altaEmpleado(lista,TAM,id,listaSectores,TAMS);
                if(altaOk==1)
                {
                 id++;
                }
            break;
        case 2:
            system("cls");
            modificarEmpleado (lista,TAM,listaSectores,TAMS);
            break;
        case 3:
            system("cls");
            bajaEmpleado(lista,TAM,listaSectores,TAMS);
            break;
        case 4:
            informes(lista,TAM,listaSectores,TAMS);
            break;
        case 5:
            printf("Confirma salir?s/n:");
            fflush(stdin);
            salir = getche();
            break;
        default:
            printf("Opcion no valida, reintente.\n");
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}
