#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int t;
	printf("cuantos trabajadores desea ingresar al sistema? : ");
	scanf("%i",&t);
	
	int Cedula[t], Cedula2, HorasLaboradas[t], PrecioPorHora[t], SalarioOrdinario[t], SalarioBruto[t], Opcion[t], Continuar, a = 0, b = 1;
	int  CantidadOperarios = 0, CantidadTecnicos = 0, CantidadProfesionales = 0;
	float SalarioNeto[t], Aumento[t], Deducciones;
	float NetoOperarios = 0, NetoTecnicos = 0, NetoProfesionales = 0, PromedioOperarios = 0, PromedioTecnicos = 0, PromedioProfesionales = 0;
	string Nombre[t][30];
    
	for(int i = 1; i <= t; i++){
		printf("---------------------------------------------------------------- \n");
		Aumento[i] = 0;
	    Deducciones = 0.0917;
	    Opcion[i] = 0;
	    printf("Ingrese el nombre del empleado: ");
	    scanf("%s",&Nombre[i]);
		printf("Ingrese el numero de cedula del trabajador: ");
		scanf("%i",&Cedula[i]);
		printf("Tipo de empleado: \n");
		printf("1-Operario \n");
		printf("2-Tecnico \n");
		printf("3-Profesional \n");
		do{
		    printf("Opcion: ");
	        scanf("%i",&Opcion[i]);
		if((Opcion[i] >= 4 || Opcion[i] <= 0 )){
			printf("Numero incorrecto, ingrese otro \n");
		}else{
			Opcion[i] = Opcion[i];
		}
        }while(Opcion[i] > 3);
        
        if(Opcion[i] == 1){
        	Aumento[i] = 0.15;
		}else if(Opcion[i] == 2){
			Aumento[i] = 0.1;
		}else{
			Aumento[i] = 0.05;
		}
		
		printf("Ingrese el total de horas laboradas: ");
		scanf("%i",&HorasLaboradas[i]);
		printf("Ingrese el precio por hora : ");
		scanf("%i",&PrecioPorHora[i]);
		
		SalarioOrdinario[i] = (HorasLaboradas[i] * PrecioPorHora[i]);
		SalarioBruto[i] = SalarioOrdinario[i] + (HorasLaboradas[i] * PrecioPorHora[i] * (Aumento[i]));
		SalarioNeto[i] = SalarioBruto[i] - (SalarioBruto[i] * Deducciones);

		
		Aumento[i] = Aumento[i] * 100; 
		Deducciones = Deducciones * 100;
		printf("---------------------------------------------------------------- \n");
		printf("Datos finales del trabajador: \n");
		printf("Numero de cedula: %i \n",Cedula[i]);
		printf("Nombre del empleado: %s \n", Nombre[i]);
		if(Opcion[i] == 1){
			printf("Tipo de empleado: Operario \n");
		    CantidadOperarios = CantidadOperarios + 1;
		    NetoOperarios = NetoOperarios + SalarioNeto[i];
		}else if(Opcion[i] == 2){
			printf("Tipo de empleado: Tecnico \n");
			CantidadTecnicos = CantidadTecnicos + 1;
			NetoTecnicos = NetoTecnicos + SalarioNeto[i];
		}else{
			printf("Tipo de empleado: Profesional \n");
			CantidadProfesionales = CantidadProfesionales + 1;
			NetoProfesionales = NetoProfesionales + SalarioNeto[i];
		}   
		printf("Salario por hora: %i \n", PrecioPorHora[i]);
		printf("Cantidad de horas: %i \n", HorasLaboradas[i]);
		printf("Salario ordinario: %i \n", SalarioOrdinario[i]);
		printf("Aumento: %.2f % \n", Aumento[i]);
		printf("Salario bruto: %i \n", SalarioBruto[i]);
		printf("Deducciones: %.2f %\n", Deducciones);
		printf("Salario neto: %.2f \n",SalarioNeto[i]);
	}
    
    if(CantidadOperarios>=1){
        PromedioOperarios = NetoOperarios / CantidadOperarios;
	}else{
		PromedioOperarios = 0;
	}
	
        if(CantidadTecnicos>=1){
        PromedioTecnicos = NetoTecnicos / CantidadTecnicos;
	}else{
		PromedioTecnicos = 0;
	}
	
        if(CantidadProfesionales>=1){
        PromedioProfesionales = NetoProfesionales / CantidadProfesionales;
	}else{
		PromedioProfesionales = 0;
    }
 	
 	
 	printf("---------------------------------------------------------------- \n");
    printf("Cantidad total de empleados tipo Operario ingresados: %i \n",CantidadOperarios);
    printf("Acumulado del salario neto de emplados tipo Operario: %.2f \n", NetoOperarios);
    printf("Promedio de salario neto de emplados tipo Operario: %.2f \n", PromedioOperarios );
    
    printf("---------------------------------------------------------------- \n");
    printf("Cantidad total de empleados tipo Tecnico ingresados: %i \n",CantidadTecnicos);
    printf("Acumulado del salario neto de emplados tipo Tecnico: %.2f \n", NetoTecnicos);
    printf("Promedio de salario neto de emplados tipo Tecnicos: %.2f \n", PromedioTecnicos);
    
    printf("---------------------------------------------------------------- \n");
    printf("Cantidad total de empleados tipo Profesional ingresados: %i \n",CantidadProfesionales);
    printf("Acumulado del salario neto de emplados tipo Profesional: %.2f \n", NetoProfesionales);
    printf("Promedio de salario neto de emplados tipo Profesionales: %.2f \n", PromedioProfesionales);
    
        do{
        printf("---------------------------------------------------------------- \n");	 
	    printf("Desea mostrar nuevamente las estadisticas de algun trabajador? Si = 1 No = 2 :");
	    do{
	    	scanf("%i",&Continuar);
	    	if(Continuar >= 3){
	    		printf("Numero incorrecto, intente de nuevo: ");
	    		a = 1;
	        }else if(Continuar == 1){
	        	a = 1;
	        	printf("Ingrese el numero de cedula del trabajador a buscar: ");
	        	scanf("%i",&Cedula2);
	        		for(int i = 0; i <= t-1; i++){
			if(Cedula2 == Cedula[i]){
				printf("Numero de cedula: %i \n",Cedula[i]);
		        printf("Nombre del empleado: %s \n", Nombre[i]);
		    if(Opcion[i] == 1){
			    printf("Tipo de empleado: Operario \n");
		        CantidadOperarios = CantidadOperarios + 1;
		        NetoOperarios = NetoOperarios + SalarioNeto[i];
		    }else if(Opcion[i] == 2){
			    printf("Tipo de empleado: Tecnico \n");
			    CantidadTecnicos = CantidadTecnicos + 1;
			    NetoTecnicos = NetoTecnicos + SalarioNeto[i];
		}   else{
			    printf("Tipo de empleado: Profesional \n");
			    CantidadProfesionales = CantidadProfesionales + 1;
			    NetoProfesionales = NetoProfesionales + SalarioNeto[i];
		}   
		printf("Salario por hora: %i \n", PrecioPorHora[i]);
		printf("Cantidad de horas: %i \n", HorasLaboradas[i]);
		printf("Salario ordinario: %i \n", SalarioOrdinario[i]);
		printf("Aumento: %.2f % \n", Aumento[i]);
		printf("Salario bruto: %i \n", SalarioBruto[i]);
		printf("Deducciones: %.2f %\n", Deducciones);
		printf("Salario neto: %.2f \n",SalarioNeto[i]);
		b = 1;
			}else{
				b = 0;
			}
		}
	        }else{
	        	a = 0;
			}
		}while(Continuar >= 3 || Continuar <= 0);
		if(b == 0){
			printf("El numero de cedula ingresado no se encuentra en el sistema \n");
		}  
	}while(a == 1);
	
	printf("Muchas gracias!!!");
	return 0;
}
