#include <stdio.h>

int captura(void);
void arregloAlumnos(float calificacion[50], int N);
float promedio(float calificacion[50], int N);

int main()
{
    int numeroAlumnos;
    float calificacion[50], prom;
    
    numeroAlumnos = captura();
    arregloAlumnos(calificacion, numeroAlumnos);
    prom = promedio(calificacion, numeroAlumnos);
    printf("El promedio es: %.2f\n", prom);
    return 0;
}

int captura()
{
    FILE *archivo;
    char alumno[50];
    float calificacion;
    int N, i;
    
    archivo = fopen("calificaciones.dat", "wb");
    
    printf("Ingresa el número de alumnos: ");
    scanf("%d",&N);
    for(i = 0; i < N; i++)
    {
        printf("Ingresa el nombre del alumno no.%d: ", i + 1);
        fflush(stdin);
        scanf("%s", &alumno[0]);
        printf("Ingresa la calificación del alumno no.%d: ", i + 1);
        scanf("%f", &calificacion);
        fwrite(alumno, sizeof(char), 1, archivo);
        fwrite(&calificacion, sizeof(float), 1, archivo);
    }
    
    fclose(archivo);
    
    return N;
}

void arregloAlumnos(float calificacion[50], int N)
{
    FILE *archivo;
    int i;
    char nombre;
    
    archivo = fopen("calificaciones.dat", "rb");
    
    for(i = 0; i < N; i++)
    {
        fread(&nombre, sizeof(char), 1, archivo);
        fread(&calificacion[i], sizeof(float), 1, archivo);
    }
    fclose(archivo);
}

float promedio(float calificacion[50], int N)
{
    int i;
    float promedio = 0;
    
    for(i = 0; i < N; i++)
    {
        promedio += calificacion[i];
    }
    promedio /= i;
    
    return promedio;
}
