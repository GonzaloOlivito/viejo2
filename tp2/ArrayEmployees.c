#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include "utn.h"
#include "ArrayEmployees.h"

/** \brief Funcion que contiene menu principal
 *
 * \return Retorna la opcion elegida
 *
 */
int menu()
{
    system("cls");
    int opcion;
    printf("******MENU******\n\n");
    printf("1. ALTA EMPLEADO\n");
    printf("2. MODIFICAR EMPLEADO\n");
    printf("3. BAJA EMPLEADO\n");
    printf("4. INFORMES\n");
    printf("5. SALIR\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
/** \brief Funcion que inicializa todos los empleados en 0
 *
 * \param vec[] eEmployeer es la estructura de empleados
 * \param tam es el tamaño de dicha estructura
 * \return void no retorna ningun valor
 *
 */
void inicializarEmpleados(eEmployeer vec[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        vec[i].isEmpty = 0;
    }

}
/** \brief Funcion que busca un lugar libre
 *
 * \param se le pasa el vector de la estructura
 * \param se le pasa el tamaño
 * \return retorna el lugar lire en caso de no haber error
 *
 */

int buscarLibre(eEmployeer vec[], int tam)
{
    int indice=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief Busca el id de la estructura
 *
 * \param id int
 * \param vec[] eEmployeer
 * \param tam int
 * \return int Retorna el id en caso de no haber error
 *
 */
int buscarId(int id, eEmployeer vec[], int tam)
{
    int indice= -1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vec[i].id==id && vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int nombreSectores(int id, eSector vecS[], int tamSec, char nuevoNombreSector[])
{
    int retorno=0;
    int i;
    for(i=0; i<tamSec; i++)
    {
        if(id == vecS[i].idSec)
        {
            strcpy(nuevoNombreSector,vecS[i].nombreSector);
            retorno = 1;
            break;
        }
    }
    return retorno;
}
/** \brief Muestra un solo empleado
 *
 * \param x eEmployeer
 * \param vecS[] eSector
 * \param tamSec int
 * \return void
 *
 */
void mostrarUnEmpleado(eEmployeer x, eSector vecS[],int tamSec)
{
    char nombreSector[20];
    nombreSectores(x.sector,vecS,tamSec,nombreSector);

    printf("%d      %10s      %10s      %.2f     %10s\n", x.id, x.lastName, x.name, x.salary,nombreSector);


}
/** \brief Muestra todos los empleados de la estructura
 *
 * \param vec[] eEmployeer
 * \param tam int
 * \param vecS[] eSector
 * \param tamSec int
 * \return void
 *
 */
void mostrarEmpleados(eEmployeer vec[], int tam, eSector vecS[], int tamSec)
{
    int buffer=0;
    int i;
    printf("ID      APELLIDO        NOMBRE        SUELDO      SECTOR\n\n\n");
    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            mostrarUnEmpleado(vec[i],vecS,tamSec);
            buffer++;
        }
    }
    if(buffer==0)
    {
        printf("No hay empleados cargados en el sistema.\n");
    }
}
/** \brief Funcion para dar de alta un empleado
 *
 * \param vec[] eEmployeer se le pasa la estructura de los empleados
 * \param tam int el tamaño de la estructura de empleados
 * \param id int el numero de id ya que es automatico
 * \param vecS[] eSector la estructura de los sectores
 * \param tamSec int el tamaño de la estructura de sectores
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int altaEmpleado(eEmployeer vec[], int tam, int id, eSector vecS[], int tamSec)
{
    int retorno=0;
    int indice;
    system("cls");

    printf("******ALTA EMPLEADO******\n\n");
    indice=buscarLibre(vec,tam);
    if(indice==-1)
    {
        printf("Sistema completo!!\n");
    }
    else
    {

        vec[indice].id=id;
        getString(51,2,"Ingrese el nombre: ",vec[indice].name);
        getString(51,2,"Ingrese el apellido. ",vec[indice].lastName);
        getFloat(0,99999,&vec[indice].salary,"Ingrese el sueldo: ");
        vec[indice].sector=menuSectores();
        vec[indice].isEmpty=1;

        retorno=1;

        printf("\nAlta exitosa!!\n\n");
    }
    return retorno;
}
/** \brief Funcion utilizada para modificar algun dato o valor de un empleado
 *
 * \param vec[] eEmployeer
 * \param tam int
 * \param vecS[] eSector
 * \param tamSec int
 * \return int retorna 1 en caso de exito, 0 en caso de error
 *
 */
int modificarEmpleado(eEmployeer vec[], int tam, eSector vecS[], int tamSec)
{
    int retorno = 0;
    int id;
    int indice;
    char salir = 's';
    printf("Modifacion\n\n\n");
    mostrarEmpleados(vec,tam,vecS,tamSec);
    printf("Ingrese id a modificar: ");
    scanf("%d", &id);

    indice = buscarId(id,vec,tam);
    if(indice == -1)
    {
        printf("No existe el empleado que se intenta modificar.\n");

    }
    else{
        system("cls");
        mostrarUnEmpleado(vec[indice],vecS,tamSec);
        do
        {
            switch(menuModificacion())
            {
            case 1:
                getString(51,2,"Ingrese nuevo nombre:", vec[indice].name);
                printf("\nOperacion realizada con exito!\n");
                break;
            case 2:
                getString(51,2,"Ingrese nuevo apellido:", vec[indice].lastName);
                printf("\nOperacion realizada con exito!\n");
                break;
            case 3:
           getFloat(0,999999, &vec[indice].salary, "Ingrese nuevo salario: ");
                printf("\nOperacion realizada con exito!\n");
                break;
            case 4:
                vec[indice].sector=menuSectores();
                printf("\nOperacion realizada con exito \n");
            case 5:
                printf("Confirma salir? s/n:");
            fflush(stdin);
            salir = getche();
                break;
            default:
                printf("\nIngrese una opcion valida!\n");
            }
        }while(salir == 'n');

        retorno = 1;
    }
    return retorno;
}
/** \brief Funcion que se utiliza para cambiar el estado de un empleado
 *
 * \param vec[] eEmployeer
 * \param tam int
 * \param vecS[] eSector
 * \param tamS int
 * \return void
 *
 */
void bajaEmpleado(eEmployeer vec[], int tam, eSector vecS[], int tamS)
{
    int id;
    int busqueda;

    printf("Baja empleado\n\n");

    mostrarEmpleados(vec,tam,vecS,tamS);

    printf("\nIngrese numero de id a dar de baja: ");
    scanf("%d",&id);

    busqueda=buscarId(id,vec,tam);

    if(busqueda==-1)
    {
        printf("No existe ese numero de id en el sistema\n");
    }
    else
    {
            vec[busqueda].isEmpty=0;
            printf("\nOperacion realizada con exito\n");


    }
}

/** \brief Menu creado para la eleccion del sector del empleado
 *
 * \return int retorna la opcion
 *
 */
int menuSectores()
{
    int opcion;

    printf("Ingrese sector del empleado:\n");
    printf("1. Sistemas \n");
    printf("2. Recursos Humanos\n");
    printf("3. Contaduria\n");
    printf("4. Legales\n");
    printf("5. Gerencia\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    while(opcion<0 || opcion > 5)
    {
        printf("\nOpcion no valida, reintente: ");
        scanf("%d", &opcion);
    }

    return opcion;
}
/** \brief Menu creado para la modificacion de datos del personal
 *
 * \return int retorna la opcion
 *
 */
int menuModificacion()
{
    int opcion;
    system("cls");
    printf("***** Modificacion *****\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Salario.\n");
    printf("4. Sector.\n\n");
    printf("5. Volver al menu principal.\n\n");
    printf("Ingrese la opcion deseada: ");
    scanf("%d",&opcion);

    return opcion;
}
/** \brief Funcion creada para realizar un menu de informes
 *
 * \return int retorna la opcion elegida
 *
 */
int menuInformes()
{
    int opcion;

    system("cls");
    printf("Menu de informes\n\n");
    printf("1. Listado de empleados por donde alfabetico por Apellido y Sector.\n");
    printf("2. Total y promedio de los salarios, y empleados superen el salario promedio.\n\n");
    printf("3. Volver al menu principal\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
/** \brief Funcion utilizada para ordenar los empleados por apellido de la A a la Z
 *
 * \param vec[] eEmployeer
 * \param tam int
 * \return void
 *
 */
void ordenarEmpleados(eEmployeer vec[], int tam)
{
    eEmployeer aux;
int i;
int j;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(vec[i].lastName,vec[j].lastName)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(strcmp(vec[i].lastName,vec[j].lastName) == 0 && vec[i].sector > vec[j].sector)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }

        }
    }

}
/** \brief Funcion utilizada para calcular promedios de sueldos
 *
 * \param vec[] eEmployeer
 * \param tam int
 * \return void
 *
 */
void promedioTotal(eEmployeer vec[], int tam)
{
    int i;
    int contadorSueldos=0;
    int contadorEmpleados =0;
    float totalSueldos=0;
    float promedioSueldos=0;

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            totalSueldos+=vec[i].salary;
            contadorSueldos++;
        }
    }

    promedioSueldos=(float)totalSueldos/contadorSueldos;

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1 && vec[i].salary>promedioSueldos)
        {
            contadorEmpleados++;
        }
    }


    system("cls");

    printf("\nSueldos totales: %.2f",totalSueldos);
    printf("\nPromedios de sueldo: %.2f",promedioSueldos);
    printf("\nEmpleados que superan sueldo promedio: %d\n\n",contadorEmpleados);
    system("pause");


}
/** \brief Funcion utilizada para realizar informes
 *
 * \param vec[] eEmployeer
 * \param tam int
 * \param vecS[] eSector
 * \param tamSec int
 * \return void
 *
 */
void informes(eEmployeer vec[], int tam, eSector vecS[], int tamSec)
{
    char salir = 'n';
    do
    {
        system("cls");

        switch(menuInformes())
        {
        case 1:
            ordenarEmpleados(vec,tam);
            system("cls");
            mostrarEmpleados(vec,tam,vecS,tamSec);
            system("pause");
            break;

        case 2:
            promedioTotal(vec,tam);
            break;

        case 3:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;


        default:
            printf("ingrese opcion valida.");

        }

    }
    while(salir == 'n');


}

