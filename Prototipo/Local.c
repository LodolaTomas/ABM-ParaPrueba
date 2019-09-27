#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "inputs.h"
#include "Local.h"


void hardcode_Localidad(eLocalidad arrayLocalidad[],int lenLocalidad)
{
    int i;
    int id[]={101,102,103};
    char localidad[][32]={"Avellaneda","Wilde","Lomas de Zamora"};
    int codigoPostal[]={1870,1872,1700};
    for(i=0;i<lenLocalidad;i++)
    {
        arrayLocalidad[i].id=id[i];
        strcpy(arrayLocalidad[i].descripcion,localidad[i]);
        arrayLocalidad[i].codPostal=codigoPostal[i];
    }



}
eLocalidad una_localidad(eLocalidad arrayLocalidad[],int lenLocalidad)
{
    eLocalidad auxLocalidad;
    int auxId;
    int i;

    mostrar_Localidades(arrayLocalidad,lenLocalidad);
    getValidInt("Elija una Localidad:","ERROR. Solo Numeros",100,103,&auxId);

    for(i=0;i<lenLocalidad;i++)
    {

        if(auxId==arrayLocalidad[i].id)
        {
            auxLocalidad=arrayLocalidad[i];
        }

    }

    return auxLocalidad;

}
void mostrar_unaLocalidad(eLocalidad unaLocalidad){

printf("%d %19s %11d\n",unaLocalidad.id,unaLocalidad.descripcion,unaLocalidad.codPostal );

}
void mostrar_Localidades(eLocalidad arrayLocalidad[],int lenLocalidad)
{
    int i;
    printf("%s %19s %15s\n\n","ID","Localidad","Cod.Postal");
    for(i=0;i<lenLocalidad;i++)
    {
        mostrar_unaLocalidad(arrayLocalidad[i]);
    }

}

int buscarLocalidadId(eLocalidad listaLocalidad[],int lenLocal,int idLocalidad)
{
    int i;
    int index=-1;

    for(i=0; i<lenLocal; i++)
    {
        if(idLocalidad==listaLocalidad[i].id)
        {
            index=i;
            break;
        }
    }

    return index;
}
