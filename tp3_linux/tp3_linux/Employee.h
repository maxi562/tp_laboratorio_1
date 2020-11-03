#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
Employee* employee_newParametrosAlta(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldo);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_setIdTexto(Employee* this,char* id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setHorasTrabajadasTexto(Employee* this,char* horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_setSueldoTexto(Employee* this,char* sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int esNombre(char* cadena,int longitud);
int esNumerica(char* cadena, int limite);
int esFlotante(char* cadena);

int employee_buscar(LinkedList* this,char* nombre,int* id);
void employee_imprimirEmpleado(Employee* this);

int employee_compareById(Employee* primero,Employee* segundo);
int employee_compareByName(Employee* primero,Employee* segundo);
int employee_compareByHoras(Employee* primero,Employee* segundo);
int employee_compareBySueldo(Employee* primero,Employee* segundo);


#endif // employee_H_INCLUDED
