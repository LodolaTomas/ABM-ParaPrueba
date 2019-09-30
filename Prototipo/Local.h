typedef struct{

int id;
char descripcion[32];
int codPostal;

}eLocalidad;


eLocalidad una_localidad(eLocalidad arrayLocalidad[], int lenLocalidad);
void mostrar_unaLocalidad(eLocalidad unaLocalidad);
void mostrar_Localidades(eLocalidad arrayLocalidad[] ,int lenLocalidad);
void hardcode_Localidad(eLocalidad arrayLocalidad[],int lenLocalidad);
int buscarLocalidadId(eLocalidad listaLocalidad[], int lenLocal, int idLocal);



















