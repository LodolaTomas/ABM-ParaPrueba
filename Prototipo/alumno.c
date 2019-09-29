#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "inputs.h"
#include "Local.h"
#include "alumno.h"



eAlumno cargarAlumno(eLocalidad arrayLocalidad[],int lengLocalidad)
{
    eAlumno auxAlumno;
    eLocalidad unaLocalidad;

    getValidInt("Ingrese un legajo:","legajo solo de numeros",0,1000,&auxAlumno.legajo);
    getValidString("Ingrese un Nombre:","Solo letras",auxAlumno.name);
    getValidString("Ingrese un Apellido:","Solo letras",auxAlumno.lastname);
    getValidInt("Ingrese el Promedio:","promedio, Solo Numeros",0,10,&auxAlumno.promedio);
    unaLocalidad=una_localidad(arrayLocalidad,lengLocalidad);
    auxAlumno.idLocalidad=unaLocalidad.id;
    auxAlumno.estado=OCUPADO;



    return auxAlumno;
}

int buscar_Libre(eAlumno listadoDeAlumnos[],int lengAlumnos)
{
    int indice = -1;
    int i;

    for(i=0; i<lengAlumnos; i++)
    {
        if(listadoDeAlumnos[i].estado==LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;//retorno -1 sino encontro un lugar libre
}

void agregarAlumno(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{
    int indice;

    indice = buscar_Libre(listadoDeAlumnos, lengAlumnos);

    if(indice!=-1)
    {
        //hay lugar
        listadoDeAlumnos[indice] = cargarAlumno(arrayLocalidad,lengLocalidad);
    }
    else
    {
        printf("\n\nNo hay espacio disponible\n\n");
    }

}

void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int legajo[]= {101,102,105};
    float promedio[]= {6.66, 4,7.66};
    char nombre[][25]= {"Juan","Maria josefina","Maria"};
    int localidad[]= {101,103,102};
    for(i=0; i<3; i++)
    {
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].name, nombre[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];

    }
}
void mostrarUnAlumno(eAlumno miAlumno,eLocalidad miLocalidad)
{

    printf("%4d %20s %15d %25s\n",miAlumno.legajo,miAlumno.name, miAlumno.promedio, miLocalidad.descripcion);

}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listaLocalidad[],int lenLocal)
{
    int i;
    int index;

    printf("\n%4s %20s %15s %25s\n","Id","Nombre","Promedio","Localidad");
    for(i=0; i<tam; i++)
    {

        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            index  = buscarLocalidadId(listaLocalidad,lenLocal,listadoDeAlumnos[i].idLocalidad);
            if(index!=-1)
            {
                mostrarUnAlumno(listadoDeAlumnos[i],listaLocalidad[index]);
            }
        }
    }
    printf("\n");
}

void submenu_Mostrar(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{

    int opcion;


    do
    {
        printf("%30s\n","SUB MENU MOSTRAR");
        getValidInt("1. Mostrar todos los alumnos con la descripcion de su localidad\n2. Mostrar todas las localidades\n3. Mostrar por cada localidad, todos los alumnos que viven en ella\n4. Mostrar los alumnos que viven en Avellaneda\n5. Mostrar la localidad con menos habitantes\n6. Salir al menu\nElija una opcion: ",
                    "Error. Solo numeros, Elija las opciones correspodientes.",1,6,&opcion);

        switch(opcion)
        {

        case 1:
            borrar();
            mostrarListadoAlumnos(listadoDeAlumnos, lengAlumnos,arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 2:
            borrar();
            mostrar_Localidades(arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 3:
            borrar();
            mostrar_porLocalidad(listadoDeAlumnos, lengAlumnos,arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 4:
            borrar();
            mostrar_SoloAvellaneda(listadoDeAlumnos, lengAlumnos,arrayLocalidad,lengLocalidad);
            pausa();
            break;
        case 5:
            borrar();
            pausa();
            break;
        }
        borrar();
    }
    while(opcion!=6);

}

void mostrar_porLocalidad(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{
    int i,j;

    for(i=0; i<lengLocalidad; i++)
    {

        printf("%30s\n",arrayLocalidad[i].descripcion);

        for(j=0; j<lengAlumnos; j++)
        {

            if(arrayLocalidad[i].id==listadoDeAlumnos[j].idLocalidad)
            {
                mostrarUnAlumno(listadoDeAlumnos[j],arrayLocalidad[i]);

            }
        }

        printf("\n");
    }


}
void mostrar_SoloAvellaneda(eAlumno listadoDeAlumnos[],int lengAlumnos,eLocalidad arrayLocalidad[],int lengLocalidad)
{
    int i,j;

    char option[]= {"Avellaneda"};

    for(i=0; i<lengLocalidad; i++)
    {

        if(strcmp(arrayLocalidad[i].descripcion,option)==0)
        {
            printf("%30s\n",arrayLocalidad[i].descripcion);

            for(j=0; j<lengAlumnos; j++)
            {

                if(arrayLocalidad[i].id==listadoDeAlumnos[j].idLocalidad)
                {
                    mostrarUnAlumno(listadoDeAlumnos[j],arrayLocalidad[i]);

                }
            }
        }
        printf("\n");
    }

}

void pausa()
{
    //if(sysOp==1)
    //
    system("read -p 'Press Enter to continue...' var");
    //}
    //if (sysOp==2)
    //{
    //    system("pause");
    //}
}
void borrar()
{
    //if(sysOp==1)
    //{
    system("clear");
    //}
    //if (sysOp==2)
    //{
    //    system("cls");
    //}
}
