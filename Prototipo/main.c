#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Local.h"
#include "alumno.h"
//settings-Enviroment-GeneralSetings-TerminaltoLunchConsolePrograms
//settings-Editor-GeneralSettings-EditorSettings-Fonts-Manjari
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

    agregarAlumno(listaDeAlumnos,LA,listaDelocalidades,LL);
    submenu_Mostrar(listaDeAlumnos,LA,listaDelocalidades,LL);


    return 0;
}



