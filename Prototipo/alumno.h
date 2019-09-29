#define OCUPADO 1
#define LIBRE 0



typedef struct
{
    int legajo;
    char name[32];
    char lastname[32];
    int promedio;
    int idLocalidad;
    int estado;

}eAlumno;


eAlumno cargarAlumno(eLocalidad arrayLocalidad[], int lengLocalidad);
int buscar_Libre(eAlumno listadoDeAlumnos[],int lengAlumnos);
void agregarAlumno(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad);
void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam);
void mostrarUnAlumno(eAlumno miAlumno, eLocalidad miLocalidad);
void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam, eLocalidad listaLocalidad[], int lenLocal);

void submenu_Mostrar(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad);
void mostrar_porLocalidad(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad);

void mostrar_SoloAvellaneda(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad);
void mostrar_MenosHabitantes(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad);

void pausa();
void borrar();
