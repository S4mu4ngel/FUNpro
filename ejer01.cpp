//PROYECTO REGISTRO DE DATOS-NOTAS de alumnos y profesores (Fundamentos de programación) 

#include <iostream>
#include <cstdio>  //-->para que funcionen remove() y rename().
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

//ESTRUCTURA DE LOS ALUMNOS
struct alumno {
	int codigo;
	char nombres[50];
	char apellidos[50];
	char cursos[50];
	char metodo[50];
	double pcProm;
	int ep;
	int ef;
	int promed;
};

//ESTRUCTURA DE LOS PROFESORES
struct profesor{
    int codigo;
	char nombres[50];
	char apellidos[50];
	char cursos[50];	
};

//PROTOTIPOS PARA ALUMNOS
void mantenimientoDeAlumnos();
void crearRegistroAlumno();
void mostrarArchivoAlumno();
void editarArchivoAlumno();
void buscarArchivoAlumno();

//PROTOTIPOS PARA PROFESORES
void mantenimientoDeProfesores();
void crearRegistroProfesor();
void mostrarArchivoProfesor();
void editarArchivoProfesor();
void buscarArchivoProfesor();

//MANTENIMIENTO DE NOTAS
void mantenimientoDeNotas();
void registroDeNotas();
void editarNotas();
void reporteDeNotas();
void ordenarNotas();

int main(){
	system ("color f0");
	int opcion;
	char opc = 'S';
	
	while (opc == 'S'){
		system("cls");
		cout<<endl<<endl;
		cout << "\t\t  ======  UNIVERSIDAD PRIVADA DEL NORTE   ======";
        cout <<"\n\n               ";
        cout << "   ====  ""Sistema de Registro de Notas"" ====";
        cout << "\n\n";
        cout << "\n \t\t\t [1] Registro de Profesores";
        cout << "\n \t\t\t [2] Registro de Alumnos";
        cout << "\n \t\t\t [3] Registro de Notas";
        cout <<endl<<endl;
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        
        if(opcion>3 && opcion<=0){
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion){  
        	case 1:	mantenimientoDeProfesores(); break;
			case 2:	mantenimientoDeAlumnos(); break;
			case 3:	mantenimientoDeNotas(); break;	
		}	
		cout<<"Desea regresar al SISTEMA DE REGISTRO DE NOTAS? [S/N]: ";
	    fflush(stdin);
		opc=toupper(getchar()); 
	}
	system("Pause()");
//se agrega una pausa, porque espera a que el usuario presione alguna tecla para continuar con la ejecución del programa
	return 0;	
}

//COMENZAMOS CON EL MANTENIMIENTO DE ALUMNOS

void mantenimientoDeAlumnos(){
	int opcion;
	char opc = 'S';
	
	while (opc == 'S'){
        system("cls");
	    cout <<endl<<endl;
        cout << "\t\t  ====== MANTENIMIENTO DE ALUMNOS ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Registrar Alumno";
        cout << "\n \t\t\t 2. Mostrar Datos";
        cout << "\n \t\t\t 3. Editar Registro de Alumnos ";
        cout << "\n \t\t\t 4. Buscar Alumnos";
        cout << "\n \t\t\t 5. Mensaje de Salida";
        cout <<endl<<endl;
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        
        if(opcion>5 && opcion <= 0){
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion){
        	case 1: crearRegistroAlumno(); break;
         	case 2: mostrarArchivoAlumno();	break;
            case 3: editarArchivoAlumno(); break;
         	case 4: buscarArchivoAlumno(); break;
         	case 5: cout<<"\n\n";
         	 	    cout<<"Desea Regresar al MANTENIMIENTO DE ALUMNOS? [S/N]: ";
                    fflush(stdin);
				    opc=toupper(getchar());
			      	break;     
       }   
	}
	system("Pause()");		
}

void crearRegistroAlumno(){
	system("cls");
	
	FILE *F; // FILE es variable de tipo archivo y *file es el puntero;
	alumno A; // la estructura alumno con la variable A
	
	cout<<"---REGISTRANDO ALUMNO---"<<endl<<endl;
	do{
	cout<<"* Ingrese el codigo a registrar -> "; 
	cin>>A.codigo;
	}while(A.codigo <= 999 || A.codigo >= 9999);
	cout<<"* Ingrese el Nombre del Alumno   -> ";
	cin>>A.nombres;
	cout<<"* Ingrese el Apellido del Alumno -> ";
	cin>>A.apellidos;
	cout<<"* Curso a llevar del Alumno      -> ";
	cin>>A.cursos;
	
	F = fopen("datosAlumno.txt","a+"); //a+ (agregar) //fopen (abrir archivo)
    
    if (F == NULL){
    	cout<<"No se puede abrir el Archivo"<<endl;
    	exit(1);
	}	
	fwrite(&A,sizeof(A),1/* numero de archivoa a guardar*/,F/*(en donde se guarda)*/);
	fclose(F);
    cout<<endl;
	cout<<"Alumno archivado...\n\n"<<endl;
	
		system("Pause()");
}

void mostrarArchivoAlumno(){
	system("cls");
	
	alumno A; 
	FILE *J;
	
	J = fopen("datosAlumno.txt","a+");

	if (J == NULL){
		cout<<"No se puede Abrir el Archivo"<<endl;
		exit(1);
	}	
    cout<<"=============================================="<<endl;
    cout<<"CODIGO\tNOMBRE\t  APELLIDO\t  CURSO"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
    
    fread(&A,sizeof(A),1,J);
    while (!feof(J)){ // Mientras no sea fin del archivo recorre y lee cada archivo
    	cout<<A.codigo<<"\t";
    	cout<<A.nombres<<"\t  ";
    	cout<<A.apellidos<<right<<setw(15);
    	cout<<A.cursos;
    	cout<<"\n"<<endl;
    	fread(&A,sizeof(A),1,J);
	};	
	fclose(J);
	cout<<endl<<endl;
    system("Pause()");
}

void buscarArchivoAlumno(){
	system("cls");
	
	FILE *H;
	alumno A;	
	int codigo;
	cout<<"---------BUSCANDO ALUMNO---------"<<endl<<endl;
	cout<<"* Ingrese el Codigo a Buscar -> ";
	cin>>codigo; getchar();
	
	H = fopen("datosAlumno.txt","a+");
	
	if (H == NULL){
		cout<<"No se Puede abrir el Archivo"<<endl;
		exit(1);	
	}
    //fread() regresa siempre cuantas estructuras leyo
   cout<<"=============================================="<<endl;
    cout<<"CODIGO\tNOMBRE\t  APELLIDO\t  CURSO"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
    
    fread(&A, sizeof(A),1,H); 
    
    while (!feof(H)){
    	if (A.codigo == codigo){
    	    cout<<A.codigo<<"\t";
    	    cout<<A.nombres<<"\t  ";
    	    cout<<A.apellidos<<right<<setw(15);
    	    cout<<A.cursos;
    		cout<<"\n"<<endl;
		}
		fread(&A,sizeof(A),1,H);
	};
	fclose(H);
	system("Pause()");
}

void editarArchivoAlumno(){
	system("cls");
	
	FILE *FF; 
	FILE *GG; 
	alumno A;
	int hallado = 0;
	int remove01;
	int rename01;
	int codigo;
    cout<<"------EDITANTO DATOS-ALUMNO------"<<endl<<endl;
	cout<<"* Ingrese el Codigo a Editar -> ";
	cin>>codigo; getchar();
	
	FF = fopen("datosAlumno.txt","r+"); //  r+ == abre un fichero para lectura y escritura.

    if (FF == NULL){
    	cout<<"No se puede abrir el archivo\n "<<endl;
    	exit(1);
	}
	
	GG = fopen("Tempt.txt","a+"); //creamos un archivo temporal.
	
	if (GG == NULL){
		cout<<"No se puede abrir el Archivo\n";
		exit(1);
	}

    fread(&A,sizeof(A),1,FF); //cuantas structuras leyo
	
	while(!feof(FF)){
		if (A.codigo == codigo){
			cout<<"* Ingrese el Nuevo nombre del Alumno -> ";
			gets(A.nombres); //gets lee los caracteres y lo almacena como una cadena.
			cout<<"* Ingrese el Nuevo apellido del Alumno -> ";
			gets(A.apellidos);
			cout<<"* Ingrese el Nuevo Curso del Alumno -> ";
			gets(A.cursos);
			fwrite(&A,sizeof(A),1, GG); 
			hallado = 1;
		}
		else{
			fwrite(&A,sizeof(A),1,GG);
		}
		   fread(&A,sizeof(A),1,FF);	
	};
	fclose(FF);
	fclose(GG);

    remove01 = remove("datosAlumno.txt"); //remove() devuelve el valor 0 significa que elimino el archivo correctamente
    //cout<<"REMOVIDO"<<"  "<<remove01; 
    rename01 = rename("Tempt.txt","datosAlumno.txt"); //(antiguoArchivo,nuevoArchivo) devuelve 0 si se renombró el archivo correctamente
    //cout<<"RENOMBRADO"<<"  "<<rename01;

    if ( hallado == 0)
    	cout<<"No existe este CODIGO \n\n";
	else
	    cout<<endl;
		cout<<"Registro Actualizado exitosamente..."<<endl<<endl;
	system("Pause()");	
}

//AHORA SI VAMOS CON LO DE PROFESORES xd

void mantenimientoDeProfesores(){
	int opcion;
	char opc = 'S';
	
	while (opc == 'S'){
		system("cls");
	    cout <<endl<<endl;
        cout << "\t\t  ====== MANTENIMIENTO DE PROFESORES ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Registrar Profesor";
        cout << "\n \t\t\t 2. Mostrar Datos";
        cout << "\n \t\t\t 3. Editar Profesor ";
        cout << "\n \t\t\t 4. Buscar Profesor";
        cout << "\n \t\t\t 5. Mensaje de Salida";
        cout <<endl<<endl;
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        
        if(opcion>5 && opcion <=0){
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion){
        	case 1: crearRegistroProfesor(); break;
         	case 2: mostrarArchivoProfesor(); break;
            case 3: editarArchivoProfesor(); break;
         	case 4: buscarArchivoProfesor(); break;
         	case 5: cout<<endl<<endl;
         		    cout<<"Desea regresar a MANTENIMIENTO DE PROFESORES? [S/N]: ";
        		    fflush(stdin);
					opc=toupper(getchar()); 
					break;	         
        }  
	}
	system("Pause()");		
}

void crearRegistroProfesor(){
	system("cls");	
	
	FILE *P; 
	profesor B; //la estructura profesor acompaña a la variable B	
	cout<<"---REGISTRANDO PROFESOR---"<<endl<<endl;
	
	do{
	cout<<"* Ingrese el codigo a registrar --> "; 
	cin>>B.codigo;
    } while (B.codigo <= 999|| B.codigo >= 9999);
	cout<<"* Nombre del Profesor   -> ";
	cin>>B.nombres;
	cout<<"* Apellido del Profesor -> ";
	cin>>B.apellidos;
	cout<<"* Curso a Dictar        -> ";
	cin>>B.cursos;
	
	P= fopen("datosProfesor.txt","a+");
	
     
    if (P == NULL){
    	cout<<"No se puede abrir el Archivo"<<endl;
    	exit(1);
	}
	
	fwrite(&B,sizeof(B),1/* numero de archivoa a guardar*/,P/*(rn donde se guarda)*/);
	fclose(P);
	cout<<endl;
	cout<<"Profesor archivado...\n\n"<<endl;
		system("Pause()");
}

void mostrarArchivoProfesor(){
	system("cls");
	
	profesor B;
	FILE *G; 
	
	G = fopen("datosProfesor.txt","a+"); 

	if (G == NULL){
		cout<<"No se puede abrir el archivo\n"<<endl;
		exit(1);
	}
	cout<<"=============================================="<<endl;
    cout<<"CODIGO\tNOMBRE\tAPELLIDO\tCURSO A DICTAR"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
    //fread () regresa siempre cuantas estructuras leyo
    fread(&B,sizeof(B),1,G);
    while (!feof(G)) { 
    	cout<<B.codigo<<"\t";
    	cout<<B.nombres<<"\t";
    	cout<<B.apellidos<<setw(20);
    	cout<<B.cursos;
    	cout<<"\n"<<endl;
    	fread(&B,sizeof(B),1,G);
	};

	fclose(G);
	
	cout<<endl<<endl;
	system("Pause()");
}

void buscarArchivoProfesor(){
	system("cls");
	
	profesor B;
	FILE *H;
	int codigo;
	cout<<"--------BUSCANDO PROFESOR--------"<<endl<<endl;
	cout<<"* Ingrese el Codigo a Buscar --> ";
	cin>>codigo;getchar();

	H = fopen("datosProfesor.txt","a+");

	if (H == NULL ){
		cout<<"No se puede abrir el archivo\n"<<endl;
		exit(1);
	}

    cout<<"=============================================="<<endl;
    cout<<"CODIGO\tNOMBRE\tAPELLIDO\tCURSO A DICTAR"<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;
	fread(&B,sizeof(B),1,H);
	while(!feof(H)){
    	if(B.codigo == codigo){
        cout<<B.codigo<<"\t";
    	cout<<B.nombres<<"\t";
    	cout<<B.apellidos<<setw(20);
    	cout<<B.cursos;
    	cout<<"\n";
        }  
    	fread(&B,sizeof(B),1,H);
	};
	cout<<endl;
cout<<"Busqueda Exitosa..."<<endl;
	fclose(H);
	
	cout<<endl<<endl;
	system("Pause()");
}

void editarArchivoProfesor(){
	system("cls");
	profesor B;
	FILE *PP;
	FILE *GG;
	int hallado=0;
	int codigo;
	int removed01;
	int renamed01;
    cout<<"-----EDITANDO DATOS-PROFESOR-----"<<endl<<endl;
	cout<<"* Ingrese el codigo a editar --> ";
	cin>>codigo;getchar();
	
	PP = fopen("datosProfesor.txt","r+");
    
    if (PP == NULL){
    	cout<<"No se Puede abrir el Archivo\n"<<endl;
    	exit(1);
	}
	
	GG = fopen("Temporales.txt","a+");

	if (GG == NULL){
		cout<<"No se puede abrir el Archivo\n"<<endl;
		exit(1);
	}

	fread(&B,sizeof(B),1,PP);
	
	while(!feof(PP)){
		if (B.codigo == codigo){
			cout<<"* Ingrese un nuevo Nombre            -> ";
			 gets(B.nombres);
			cout<<"* Ingrese un nuevo Apellido          -> ";
			 gets(B.apellidos);
			cout<<"* Ingrese los nuevos Cursos a Dictar -> ";
			 gets(B.cursos);
			fwrite(&B,sizeof(B),1,GG);
			hallado = 1;
		}
		else{
			fwrite(&B,sizeof(B),1,GG); 
		}
		fread(&B,sizeof(B),1,PP);
	};
		fclose(PP);
        fclose(GG);
    
    removed01 = remove("datosProfesor.txt");//elimina los datos registrados anteriormente
    //cout<<"REMOVIDO"<<"  "<<removed01;
    renamed01 = rename("Temporales.txt","datosProfesor.txt");//renombrar el archivo;
    //cout<<"RENOMBRADO"<<"  "<<renamed01;

    if (hallado == 0)
		cout<<"No Existe ese CODIGO ....\n\n";
	else
	    cout<<endl;
		cout<<"Registro Actualizado exitosamente...\n\n"<<endl;    
		system("Pause()");
}

//ACA EL MANTENIMIENTO DE NOTAS 

void mantenimientoDeNotas(){
	system("cls");
    int opcion;
    int n;
	char opc = 'S';
    alumno A;
	
	while (opc == 'S'){
		system("cls");
	    cout <<endl<<endl;
        cout << "\t\t  ====== MANTENIMIENTO NOTAS ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Registrar Notas";
        cout << "\n \t\t\t 2. Reporte de Notas por Alumnos";
        cout << "\n \t\t\t 3. Editar Notas";
        cout << "\n \t\t\t 4. Ordenar Notas";
        cout << "\n \t\t\t 5. Mensaje de Salida";
        
        cout <<endl<<endl;
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        if(opcion>5 && opcion <= 0){
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion){
        	case 1: registroDeNotas(); break;
         	case 2: reporteDeNotas(); break;
         	case 3 : editarNotas();break;
         	case 4 :ordenarNotas(); break;
         	case 5 :	cout<<"\n\n";
         	 		cout<<"Desea regresar a MANTENIMIENTO DE NOTAS? [S/N]: ";
                    fflush(stdin);
					opc=toupper(getchar()); 
					break;
		    			
       } 
	}
		system("Pause()");		
}

void registroDeNotas(){   
    system("cls");
	FILE *FF;
	FILE *GG;
	alumno A;
	int hallado = 0;
	int remove01;
	int rename01;
	int codigo;
	cout<<"--------REGISTRANDO NOTAS--------"<<endl<<endl;
	cout<<"* Ingrese el codigo de alumno --> ";
	cin>>codigo;getchar(); 

	FF = fopen("datosAlumno.txt","r+"); 
    
    if (FF == NULL){
    	cout<<"No se puede abrir el archivo\n "<<endl;
    	exit(1);
	}
	GG = fopen("Tempt.txt","a+");

	if (GG == NULL){
		cout<<"No se puede abrir el Archivo\n";
		exit(1);
	}

     cout<<"==============================================="<<endl;
     cout<<"CODIGO\tNOMBRE\t\tAPELLIDO\tCURSOS"<<endl;
     cout<<"-----------------------------------------------"<<endl<<endl;
	
     fread(&A,sizeof(A),1,FF);

	while(!feof(FF)){
		if (A.codigo == codigo){
			cout<<A.codigo<<"\t";
    	    cout<<A.nombres<<"\t\t";
    	    cout<<A.apellidos<<"\t\t";
    	    cout<<A.cursos<<"\t\t";
    		cout<<endl<<endl;;
			cout<<"---INGRESE LAS NOTAS CORRESPONDIENTES---"<<endl<<endl;
    	 	cout<<"* Nota EX.PARCIAL: ";
    		cin>>A.ep;
    		cout<<"* Nota EX.FINAL: ";
    		cin>>A.ef;
			fwrite(&A, sizeof(A), 1, GG); 
			hallado = 1;	
		}
		else{
		    fwrite(&A,sizeof(A),1,GG);
		}
		   fread(&A,sizeof(A),1,FF);	
	};
	
	fclose(FF);
	fclose(GG);

    remove01 = remove("datosAlumno.txt");
    //cout<<"REMOVIDO"<<"  "<<remove01;
    rename01 = rename("Tempt.txt","datosAlumno.txt");
    //cout<<"AGREGADO NOTAS"<<"  "<<rename01;
    if ( hallado == 0)
    	cout<<"No existe este CODIGO \n\n";
	else
		cout<<"Registro Actualizado exitosamente..."<<endl;
	system("Pause()");
}
void editarNotas(){
	system("cls");
	alumno A;
	FILE *PP;
	FILE *GG;
	int hallado=0;
	int codigo;
	int removed01;
	int renamed01;
	
	cout<<"----------EDITANDO NOTAS----------"<<endl<<endl;

	cout<<"* Ingrese el codigo a editar ---> ";
	cin>>codigo;getchar();
	
	PP = fopen("datosAlumno.txt","r+");
    
    if (PP == NULL){
    	cout<<"No se Puede abrir el Archivo\n"<<endl;
    	exit(1);
	}
	
	GG = fopen("Temporales.txt","a+");

	if (GG == NULL){
		cout<<"No se puede abrir el Archivo\n"<<endl;
		exit(1);
	}
	
	fread(&A,sizeof(A),1,PP);
	
	while(!feof(PP)){
		if (A.codigo == codigo){
			
			 cout<<"* Ingrese nuevo valor de Ex.PARCIAL --> ";
			 cin>>A.ep;
			 cout<<"* Ingrese nuevo valor de EX.FINAL   --> ";
			 cin>>A.ef;
			fwrite(&A,sizeof(A),1,GG);
			hallado = 1;
		}
		else{
			fwrite(&A,sizeof(A),1,GG); 
		}
		fread(&A,sizeof(A),1,PP);
	};
		fclose(PP);
        fclose(GG);
    
    removed01 = remove("datosAlumno.txt");//elimina los datos registrados anteriormente
    //cout<<"REMOVIDO"<<"  "<<removed01;
    renamed01 = rename("Temporales.txt","datosAlumno.txt");//renombrar el archivo;
    //cout<<"RENOMBRADO"<<"  "<<renamed01;

    if (hallado == 0)
		cout<<"No Existe ese CODIGO ....\n\n";
	else
		cout<<"Registro Actualizado exitosamente...\n\n"<<endl;    
		system("Pause()");
}

void reporteDeNotas(){
	system("cls");
	
	alumno A; 
	FILE *J;
	
	J = fopen("datosAlumno.txt","a+");

	if (J == NULL){
		cout<<"No se puede Abrir el Archivo"<<endl;
		exit(1);
	}
	
	cout<<"==============================================================================================="<<endl;
    cout<<"CODIGO\tNOMBRE\t\tAPELLIDO\tCURSOS\t     EX.PARCIAL\t     EX.FINAL\t     PROM.TOTAL"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl<<endl;
    
    fread(&A,sizeof(A),1,J);
    while (!feof(J)){
    	A.pcProm=(A.ep*0.5)+(A.ef*0.5);
    	cout<<A.codigo<<"\t";
    	cout<<A.nombres<<"\t\t";
    	cout<<A.apellidos<<"\t\t";
    	cout<<A.cursos<<"\t\t";
    	cout<<A.ep<<"\t\t";
		cout<<A.ef<<"\t\t";
    	cout<<A.pcProm;
    	cout<<"\n"<<endl;
    	fread(&A,sizeof(A),1,J);
	};
	fclose(J);
	
	cout<<endl<<endl;
 system("Pause()");
}

void ordenarNotas( ){
	alumno A;
	FILE *J;

    J = fopen("datosAlumno.txt","a+");
    int cont=0;
    fread(&A,sizeof(A),1,J);

    while (!feof(J)){
    /* A.pcProm=(A.ep*0.5)+(A.ef*0.5);*/	
	cont=cont+1;
    fread(&A,sizeof(A),1,J);
	};
	fclose(J);
	
	alumno lista[cont];	
	
	J = fopen("datosAlumno.txt","a+");
    int reg=0;
	fread(&A,sizeof(A),1,J);
	
    while (!feof(J)){
    A.pcProm=(A.ep*0.5)+(A.ef*0.5);
    lista[reg]=A;
	reg=reg+1;
    fread(&A,sizeof(A),1,J);
	};
	
	fclose(J);
		
	alumno aux;
	for(int i=0;i<cont;i++){	
	for(int j=0;j<cont-(i+1);j++){
		if(lista[j].pcProm>lista[j+1].pcProm){
		aux=lista[j];
		lista[j]=lista[j+1];
		lista[j+1]=aux;
		}		
	  }	
	}
	cout<<endl;
	cout<<"* Ordenamiento de registro(Menor a Mayor) del PROMEDIO TOTAL: "<<endl<<endl;
	cout<<"======================================================================================="<<endl;
	cout<<"CODIGO  NOMBRES         APELLIDOS           PROM.TOTAL"<<endl;
	cout<<"---------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<cont;i++){
     aux=lista[i];
     cout<<aux.codigo<<"\t"<<aux.nombres<<"\t\t"<<aux.apellidos<<"\t\t\t"<<aux.pcProm<<endl;   
	}
	cout<<endl;
  system("pause");
}
