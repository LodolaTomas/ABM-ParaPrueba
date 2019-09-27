#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Local.h"
#include "alumno.h"

#define LL 3
//lengh localidad
#define LA 5
//lengh Alumnos


int main()
{
    eLocalidad listaDelocalidades[LL];//={{100,"Avellaneda",1864},{101,"Wilde",1863},{102,"Lomas de Zamora",1803}};
    eAlumno listaDeAlumnos[LA];
    hardcode_Localidad(listaDelocalidades,LL);
    hardCodearAlumnos(listaDeAlumnos,LA);

    /*
    int i;
    for(i=0;i<LA;i++)
    {
    if(listaDeAlumnos[i].estado==LIBRE)
    {
        listaDeAlumnos[i]=cargarAlumno(listaDelocalidades,LL);
    }
    }*/


    mostrarListadoAlumnos(listaDeAlumnos,LA,listaDelocalidades,LL);


    return 0;
}



