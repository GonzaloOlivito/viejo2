typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployeer;
typedef struct
{
    char nombreSector[25];
    int idSec;
} eSector;

int menu();
int altaEmpleado(eEmployeer vec[], int tam, int id, eSector vecS[], int tamSec);
int buscarId(int id, eEmployeer vec [], int tam);
int buscarLibre(eEmployeer vec[], int tam);
void inicializarEmpleados(eEmployeer vec[], int tam);
void mostrarUnEmpleado(eEmployeer x, eSector vec[], int tamSec);
void mostrarEmpleados(eEmployeer vec[], int tam, eSector vecS[], int tamSec);
int nombreSectores(int id, eSector vec[], int tam, char nombreSector[]);
int modificarEmpleado(eEmployeer vec[], int tam, eSector vecS[], int tamSec);
int menuModificacion();
void bajaEmpleado(eEmployeer vec[], int tam, eSector vecS[], int tamS);
void informes(eEmployeer vec[], int tam, eSector vecS[], int tamSec);
int menuSectores();

