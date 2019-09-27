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

