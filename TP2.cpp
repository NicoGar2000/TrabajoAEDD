#include <iostream>
#include<stdio.h>
#include <string>
#include <fstream>
#include <cstring>
#include <ios>
#include <algorithm>
#include <cstdlib>
#include <conio.h>
#include <sstream>
#include <windows.h>
#include <iomanip>
using namespace std;
struct nodoTareaResuelta{
	string NroLegajo;
	int TemaParcial; // 1..6 Temas, 7 y 8 Parciales
	float Porcentaje; // porcentaje
	nodoTareaResuelta * ptrSiguiente;
};
void GenerarLista(nodoTareaResuelta *&,string,int,float);
void login(string);
void informe(string,float&,float&,string,float,float,float,float,float,string,string,string);
void MenuPrincipal(string,string,string,float&,float&,string,string,string,string);
void ActualizacionFicha(float&,float&,string);
void InformesDesempenio(string,string,string,float&,float&,string,string,string,string);
void IngresarProblema(string);
void Ingresar_calif(float&,float&,string);
void PerfomanceIndividual(string,string,float&,float&,float&,float&,float&,float&,float&,string);
void GuardarLista(nodoTareaResuelta *,string);
int main() { //BIENVENIDOS//

	string texto;
	system ("color F5");
	ifstream archivo;
	archivo.open("usuarios.txt");
	if(archivo.fail()){
		cout<<"No existe grupo registrado ";
	}
	else if(!archivo.eof()){
		getline(archivo,texto);

			cout<<"						=========================="<<endl;
			cout<<"						 Bienvenidos "<<texto<<endl;
			cout<<"						=========================="<<endl;


	archivo.close();
	system("pause");
	system("cls");
	login(texto);
	}
	return 0;
} 
void login(string texto){
	float par1=0,par2=0;
	string LEGAJO;
	string legajo1, password1,apellido1,nombre1;
	string legajo2,password2,apellido2,nombre2;
	string legajo3,password3,apellido3,nombre3;
	string ApellidoF;
	int i=0,f=3;
	string l1,l2;
	string NombreF;
	string alumno1[15];
	ifstream archivo;
	archivo.open("usuarios.txt");
	for(int i=0;i<5;i++){
		archivo>>alumno1[i];
	}
	legajo1 = alumno1[1];
	password1 = alumno1[2];
	apellido1 = alumno1[3];
	nombre1 = alumno1[4];
	archivo.close();
	

	string alumno2[15];
	archivo.open("usuarios.txt");
	for(int k=0;k<9;k++){
		archivo>>alumno2[k];
	}
	legajo2 = alumno2[5];
	password2 = alumno2[6];
	apellido2 = alumno2[7];
	nombre2 = alumno2[8];
	archivo.close();
	

	string alumno3[15];
	archivo.open("usuarios.txt");
	for(int i=0;i<15;i++){
		archivo>>alumno3[i];
	}
	
	legajo3 = alumno3[9];
	password3 = alumno3[10];
	apellido3 = alumno3[11];
	nombre3 = alumno3[12];
	archivo.close();
	do{
		cout<<"Ingrese su legajo: ";
		if(i<3){
			getline(cin,l1);
		}i++;
		
		if((legajo1 == l1) !=0) {
			cout<<"Ingrese su clave: ";
				char caracter;
				caracter = getch();
				l2 = "";
				while(caracter != 13){
					if(caracter != 8){
					l2.push_back(caracter);
					cout<<"*";
				}else{
					if(l2.length() > 0){
						cout<< "\b \b";	
						l2 = l2.substr(0, l2.length() -1);
					}
				}
					caracter = getch();
				}
				
				
				system("cls");
			if(password1 == l2){
				NombreF = nombre1;
				ApellidoF = apellido1;
				system("cls");
				MenuPrincipal(texto,NombreF,ApellidoF,par1,par2,l1,legajo1,legajo2,legajo3);
			}
		}
		if((legajo2 == l1) !=0) {
			cout<<"Ingrese clave: ";
			char caracter;
			caracter = getch();
			l2 = "";
			while(caracter != 13){
				if(caracter != 8){
					l2.push_back(caracter);
					cout<<"*";
				}else{
					if(l2.length() > 0){
						cout<< "\b \b";	
						l2 = l2.substr(0, l2.length() -1);
					}
				}
				caracter = getch();
			}
			system("cls");
		if(password2 == l2){
				system("cls");
				NombreF = nombre2;
				ApellidoF = apellido2;
				MenuPrincipal(texto,NombreF,ApellidoF,par1,par2,l1,legajo1,legajo2,legajo3);
			}
		}
		
		if((legajo3 == l1) !=0) {
			cout<<"Ingrese clave: ";
			char caracter;
			caracter = getch();
			l2 = "";
			while(caracter != 13){
				if(caracter != 8){
					l2.push_back(caracter);
					cout<<"*";
				}else{
					if(l2.length() > 0){
						cout<< "\b \b";	
						l2 = l2.substr(0, l2.length() -1);
					}
				}
				caracter = getch();
			}
			system("cls");
			if(password3 == l2){
				system("cls");
				NombreF = nombre3;
				ApellidoF = apellido3;
				MenuPrincipal(texto,NombreF,ApellidoF,par1,par2,l1,legajo1,legajo2,legajo3);
			}
		}
		else
			{
			cout<<"Legajo o password incorrecto ,les queda "<<f-1<<" intentos"<<endl;
			f--;
			system("pause");
			system("cls");
		}
		
		if(f==0){
			cout<<"Ah superado el numera maximo de intentos. Reinicie el programa"<<endl;
			exit(0);
		}
	}while(f<4);
	
}



void MenuPrincipal(string texto,string NombreF,string ApellidoF,float& par1,float& par2,string LEGAJO,string legajo1,string legajo2,string legajo3){
	char opc;
	int c=0;
	do{

	cout<<"						Menu Principal Algo-Tracker"<<endl;
	cout<<"						==========================="<<endl;
	cout<<"						a.- Actualizar Ficha       "<<endl;
	cout<<"						b.-Informes de Desempeño   "<<endl;
	cout<<"						                           "<<endl;
	cout<<"						s.- Cerrar la Aplicación   "<<endl;
	cout<<"						==========================="<<endl;
	
	cin>>opc;
	switch(opc){
		if(opc == 'a'||'b'||'c'||'s'){
	case 'a':
		system("cls");
		ActualizacionFicha(par1,par2,LEGAJO);
		system ("cls");
		break;
		
	case 'b':
		system("cls");
		InformesDesempenio(texto,NombreF,ApellidoF,par1,par2,LEGAJO,legajo1,legajo2,legajo3);
		system ("cls");
		break;
	
	
case 's':
		   int opc2;

		   system ("cls");
		   cout<<"¿Esta seguro de que desea abandonar el programa?"<<endl;
		   cout<<"1- SI"<<endl;
		   cout<<"2- NO"<<endl;
		   cin>>opc2;
		   if (opc2==2){
			   system("cls");
			   if(c==0){
				   MenuPrincipal(texto,NombreF,ApellidoF,par1,par2,LEGAJO,legajo1,legajo2,legajo3);
				   c++;
			   }
			   
		   }else{
			   if (opc2==1){
				   system("cls");

				   exit(0); //VEEER---------------------------------------------------------
			   }
		   }
		   break;
		}
default :  system("cls");
		   cout<<"La tecla ingresada no es correcta, por favor intente nuevamente"<<endl;
system("pause");
system("cls");
break;
	}
	
	}while(opc!='s');

}

void ActualizacionFicha(float& par1,float& par2,string LEGAJO){
		char opcion;
		do{
		cout<<"						Menu Actualizacion Ficha"<<endl;
		cout<<"						========================"<<endl;
		cout<<"						a.- Registrar Problema Resuelto"<<endl;
		cout<<"						b.- Registrar Clasificacion de Parcial"<<endl;
		cout<<"						s.- Volver Menu Principal"<<endl;
		cout<<"						========================"<<endl;
		cin>>opcion;
		switch(opcion){
		case 'a' :
			system("cls");
			IngresarProblema(LEGAJO);
			system("cls");
			break;
			
		case 'b' :
			system("cls");
			Ingresar_calif(par1,par2,LEGAJO);
			system("cls");
			break;
		case 's':
			opcion = 'j';
			break;
		default: cout<<"La tecla ingresada no es correcta, por favor intente nuevamente"<<endl;
		system("pause");
		break;
		
		}
		
	}while(opcion!='j');
}

void InformesDesempenio(string texto,string NombreF,string ApellidoF,float& par1,float& par2,string LEGAJO,string legajo1, string legajo2, string legajo3){
	char opc;
	float cont1=0,cont2=0,cont3=0,cont4=0,cont5=0;
	do{
	cout<<"						Menu Informes"<<endl;
	cout<<"						==============="<<endl;
	cout<<"						a.- Perfomance Individual"<<endl;
	cout<<"						b.- Perfomance Equipo"<<endl;
	cout<<"						                      "<<endl;
	cout<<"						s.- Volver a MenuPrincipal"<<endl;
	cout<<"						==============="<<endl;
	cin>>opc;
	switch(opc){
	case 'a':
		system("cls");
		PerfomanceIndividual(NombreF,ApellidoF,par1,par2,cont1,cont2,cont3,cont4,cont5,LEGAJO);
		system ("pause");
		system("cls");
		break;
		
	case 'b':
		system("cls");
		informe(texto,par1,par2,LEGAJO,cont1,cont2,cont3,cont4,cont5,legajo1,legajo2,legajo3);
		system ("pause");
		system("cls");
		break;
	case 's':
		opc = 'j';
		break;
	default:
		system("cls");
		cout<<"La tecla ingresada no es correcta, por favor intente nuevamente"<<endl;
		system("pause");
		system("cls");
		break;
	}
	
	}while(opc!='j');
}

void IngresarProblema(string LEGAJO){
	int vector[300];
	ifstream vect;
	vect.open("problemasyevaluaciones.txt",ios::app);
	for(int i=0;i<200;i++){
		vect>>vector[i];
	}
	vect.close();

	int numero[100],N=92,j=0,Codigo;
	bool band=false;
	bool bandera=false;
	ifstream Archivo;
	ofstream archivo;
	archivo.open("problemasyevaluaciones.txt",ios::app);
	Archivo.open("problemas-temas.txt");
	Archivo.ignore(0);
	for(int i=0;i<N;i++){
		Archivo>>numero[i];
	}
	
	Archivo.close();
	cout<<"					------------------------------------------------------"<<endl;
	cout<<"					Por favor, ingrese el codigo de el ejercicio resuelto "<<endl;
	cout<<"					------------------------------------------------------"<<endl;
	cin>>Codigo;
	system("cls");
	
	
	
	while(band!=true){
		if(Codigo==1 || Codigo==2 || Codigo==3 || Codigo==4 || Codigo==5){
			cout<<"			-----------------------------------------------------------------------"<<endl;
			cout<<"			El codigo ingresado no pertenece a ningun ejercicio, intente nuevamente"<<endl;
			cout<<"			-----------------------------------------------------------------------"<<endl;
			system("pause");
			system("cls");
			band=true;
		}
		if(numero[j]==Codigo){
			for(int i=0;i<200;i++){
				if(vector[i]==Codigo){
					bandera=true;
				}
			}
			if(bandera==false){
			cout<<"					----------------------------------------"<<endl;
			cout<<"					El codigo ha sido guardado exitosamente!"<<endl;
			cout<<"					----------------------------------------"<<endl;
			archivo<<LEGAJO<<" "<<Codigo<<endl;
			system("pause");
			system("cls");
			}else{
				if(bandera==true){
					cout<<"--------------------------------------------------------------------------------------"<<endl;
					cout<<" El codigo ingresado, ya ha sido ingresado anteriormente, por favor intentelo de nuevo"<<endl;
					cout<<"--------------------------------------------------------------------------------------"<<endl;
					system("pause");
					system("cls");
				}
			}
			band=true;
			
			
		}else{
			if(j>92){
				cout<<"			-----------------------------------------------------------------------"<<endl;
				cout<<"			El codigo ingresado no pertenece a ningun ejercicio, intente nuevamente"<<endl;
				cout<<"			-----------------------------------------------------------------------"<<endl;
				system("pause");
				system("cls");
				band=true;
			}
		}
		j++;
		
	}
	
	archivo.close();
	
	
	
	
	
}
void Ingresar_calif(float& par1,float& par2,string LEGAJO){

	ofstream file;
	ofstream dir;
	dir.open("problemasyevaluaciones.txt",ios::app);
	file.open("problemasyevaluaciones.txt",ios::app);
	
	int aux;
	cout<<"					-------------------------------------------------------"<<endl;
	cout<<"					Por favor ingrese la nota de que parcial desea ingresar"<<endl;
	cout<<"					-------------------------------------------------------"<<endl;
	cout<<"Ingrese opcion 1 para registrar Parcial 1"<<endl;
	cout<<"Ingrese opcion 2 para registrar parcial 2"<<endl;
	
	
	cin>>aux;

	system("cls");
	
	if(aux==1){

		cout<<"Ingrese su calificacion: ";
		cin>>par1;
		if(par1>=0 && par1<=100){
			file<<LEGAJO<<" "<<par1<<endl;
			cout<<"Registrado exiosamente!"<<endl;
			system("Pause");
			system("cls");
		}
			else{
			cout<<"La nota ingresada no es valida, por favor intente nuevamente"<<endl;
		}
		}

		if(aux==2){
			cout<<"Ingrese su calificacion: ";
			cin>>par2;
			if(par2>=0 && par2<=100){
				dir<<LEGAJO<<" "<<par2<<endl;
				cout<<"Registrado exiosamente!"<<endl;
				system("Pause");
				system("cls");
			}
				else{cout<<"La nota ingresada no es valida, por favor intente nuevamente"<<endl;
			}
		}
			if(aux!=1 && aux!=2){
				cout<<"La tecla ingresada no es correcta, por favor intente de nuevo"<<endl;
				system("pause");
				system("cls");
			}
		
	dir.close();
	file.close();
	
	
	
}

	
void PerfomanceIndividual(string NombreF,string ApellidoF,float& par1,float& par2,float& cont1,float& cont2,float& cont3,float& cont4,float& cont5,string LEGAJO){      
	string temasOK[8];
	ifstream temas;
	ifstream problemas;
	ifstream file;
	ofstream archivo;
	archivo.open("informe-legajo-rendimiento.txt",ios::app);
	file.open("problemasyevaluaciones.txt");
	problemas.open("problemas.txt");
	temas.open("temas.txt");
	for(int i=0;i<8;i++){
	getline(temas,temasOK[i]);
	}
	int vector[200];
	for(int i=0;i<200;i++){
		file>>vector[i];
	}
	file.close();
	int NumLEG;
	stringstream ll(LEGAJO);
	ll>>NumLEG;
	for(int i=0;i<200;i+=2){
		if(vector[i]==NumLEG){
	cout<<"Informe de Problemas Resueltos : Alumno "<<NombreF<<" "<<ApellidoF<<endl;
	cout<<temasOK[0]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 1022)&&(vector[i+1] > 1000)){
			cont1++;
			cout<<vector[i+1]<<" Logrados exitosamente. "<<endl;
			
		}
	}
	cout<<"Total: "<<cont1<<"/13"<<endl;
	
	cout<<temasOK[1]<<endl;
	for(int i=0;i<100;i++){;
		if((vector[i+1] < 1052)&&(vector[i+1] > 1035)){
			cont2++;
			cout<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
		
	}
	cout<<"Total: "<<cont2<<"/6"<<endl;
	cout<<temasOK[2]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 1128)&&(vector[i+1] > 1066)){
			cont3++;
			cout<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
	
	}
	cout<<"Total: "<<cont3<<"/11"<<endl;
	cout<<temasOK[3]<<endl;
	for(int i=0;i<100;i++){
		file>>vector[i+1];
		if((vector[i+1] < 1181)&&(vector[i+1] > 1129)){
			cont4++;
			cout<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
	}
	cout<<"Total: "<<cont4<<"/9"<<endl;
	cout<<temasOK[1]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 2294)&&(vector[i+1] > 1180)){
			cont5++;
			cout<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
	}
	cout<<"Total: "<<cont5<<"/7"<<endl;
	if(par1>50){
	cout<<"Parcial 1: "<<par1<<" (Aprobado)"<<endl;
	}else{
		cout<<"Parcial 1: "<<par1<<" (No aprobado)"<<endl;
	}
	if(par2>50){
	cout<<"Parcial 2: "<<par2<<" (Aprobado)"<<endl;
	}else{
		cout<<"Parcial 2: "<<par2<<" (No aprobado)"<<endl;
	}
	
	archivo<<"Informe de Problemas Resueltos : Alumno "<<NombreF<<" "<<ApellidoF<<endl;
	archivo<<temasOK[0]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 1022)&&(vector[i+1] > 1000)){
			cont1++;
			archivo<<vector[i+1]<<" Logrados exitosamente. "<<endl;
			
		}
	}
	archivo<<"Total: "<<cont1<<"/13"<<endl;
	
	archivo<<temasOK[1]<<endl;
	for(int i=0;i<100;i++){
		
		if((vector[i+1] < 1052)&&(vector[i+1] > 1035)){
			cont2++;
			archivo<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
		
	}
	archivo<<"Total: "<<cont2<<"/6"<<endl;
	archivo<<temasOK[2]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 1128)&&(vector[i+1] > 1066)){
			cont3++;
			archivo<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
		
	}
	archivo<<"Total: "<<cont3<<"/11"<<endl;
	archivo<<temasOK[3]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 1181)&&(vector[i+1] > 1129)){
			cont4++;
			archivo<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
	}
	archivo<<"Total: "<<cont4<<"/9"<<endl;
	archivo<<temasOK[1]<<endl;
	for(int i=0;i<100;i++){
		if((vector[i+1] < 2294)&&(vector[i+1] > 1180)){
			cont5++;
			archivo<<vector[i+1]<<" Logrados exitosamente. "<<endl;
		}
	}
	archivo<<"Total: "<<cont5<<"/7"<<endl;
	if(par1>50){
		archivo<<"Parcial 1: "<<par1<<" (Aprobado)"<<endl;
	}else{
		archivo<<"Parcial 1: "<<par1<<" (No aprobado)"<<endl;
	}
	if(par2>50){
		archivo<<"Parcial 2: "<<par2<<" (Aprobado)"<<endl;
	}else{
		archivo<<"Parcial 2: "<<par2<<" (No aprobado)"<<endl;
	}
	}
	}
	archivo.close();
	problemas.close();
}

void informe(string texto, float& par1, float& par2,string LEGAJO,float cont1,float cont2,float cont3,float cont4,float cont5,string legajo1,string legajo2, string legajo3){
	int ID[100];
	int c1=0,c2=0,c3=0,c4=0,c5=0;
	ifstream archivo;
	archivo.open("problemas-temas.txt");
	ofstream Archivo;
	Archivo.open("informe-grupo-rendimiento.txt",ios::app);
	for(int i=0;i<92;i++){
		archivo>>ID[i];
	}
	archivo.close();
	int vector[300];
	ifstream vect;
	vect.open("problemasyevaluaciones.txt",ios::app);
	for(int i=0;i<200;i++){
		vect>>vector[i];
	}
	vect.close();
	int l1,l2,l3;
stringstream ss(legajo1);
ss>>l1;
stringstream aa(legajo2);
aa>>l2;
stringstream uu(legajo3);
uu>>l3;
	int j=0,k=0,l=0;
	cout<<"		|  ID   | Tema | Legajo 1 | legajo 2 | Legajo 3 |"<<endl;
	cout<<"		-------------------------------------------------"<<endl;
	for(int t=0;t<92;t+=2){
		if(vector[t]==l1){
			for(int i=0;i<92;i++){
			if(ID[i]==vector[t+1]){
				j=1;
			}
			}
		}
		if(vector[t]==l2){
			for(int i=0;i<92;i++){
			if(ID[i]==vector[t+1]){
				k=1;
			}
			}
		}
		if(vector[t]==l3){
			for(int i=0;i<92;i++){
			if(ID[i]==vector[t+1]){
				l=1;
			}
			}
		}
		cout<<"		| "<<ID[t]<<"  |"<<"  "<<ID[t+1]<<"   |"<<"    "<<j<<"     |    "<<k<<"     |    "<<l<<"     |"<<endl;
		cout<<"		-------------------------------------------------"<<endl;
   
	if(vector[t+1]>1000&&vector[t+1]<1022&&(j==1 || k==1 || l==1)){
		c1++;
	}else{
		if(vector[t+1]>1022&&vector[t+1]<1052&&(j==1 || k==1 || l==1)){
			c2++;
		}else{	if(vector[t+1]>1052&&vector[t+1]<1099&&(j==1 || k==1 || l==1)){
			c3++;
		}else{	if(vector[t+1]>=1099&&vector[t+1]<1181&&(j==1 || k==1 || l==1)){
			c4++;
		}else{	if(vector[t+1]>=1181&&vector[t+1]<2294&&(j==1 || k==1 || l==1)){
			c5++;
		}
	}
		}}}
	j=0;
	k=0;
	l=0;
	}
	system("pause");
    system("cls");
	nodoTareaResuelta *lista=NULL;
	
float porcentaje1=c1*100/13;
float porcentaje2=c2*100/6;
float porcentaje3=c3*100/11;
float porcentaje4=c4*100/9;
float porcentaje5=c5*100/7;
	GenerarLista(lista,LEGAJO,1,porcentaje1);
	GenerarLista(lista,LEGAJO,2,porcentaje2);
	GenerarLista(lista,LEGAJO,3,porcentaje3);
	GenerarLista(lista,LEGAJO,4,porcentaje4);
	GenerarLista(lista,LEGAJO,5,porcentaje5);
	GenerarLista(lista,LEGAJO,7,par1);
	GenerarLista(lista,LEGAJO,8,par2);
	
	GuardarLista(lista,texto);
	
	

}
void GenerarLista(nodoTareaResuelta *&lista, string legajo, int tema, float porcentaje){
	nodoTareaResuelta *Alumno = new nodoTareaResuelta();
	Alumno->NroLegajo = legajo;
	Alumno->TemaParcial = tema;
	Alumno->Porcentaje = porcentaje;
	
	nodoTareaResuelta *aux=lista;
	nodoTareaResuelta *aux2;
	
	while(aux!=NULL){
		aux2 = aux;
		aux = aux->ptrSiguiente;
	}
	if(lista==aux){
		lista = Alumno;
	}else{
		aux2->ptrSiguiente = Alumno;
	}
	Alumno->ptrSiguiente = aux;
	
	
	
	
	
}
void GuardarLista(nodoTareaResuelta *lista,string texto){
	ofstream archivo;
	archivo.open("informe-grupo-rendimiento.txt",ios::app);
	cout<<"Equipo: "<<"'"<<texto<<"'"<<endl;
	archivo<<"Equipo: "<<"'"<<texto<<"'"<<endl;
	nodoTareaResuelta *actual = new nodoTareaResuelta();
	actual = lista;
	while (actual!=NULL){
		if(actual->TemaParcial==7){
			cout<<fixed<<setprecision (1);
			cout<<"Parcial 1: "<<actual->Porcentaje<<"%"<<endl;
			archivo<<fixed<<setprecision (1);
			archivo<<"Parcial 1: "<<actual->Porcentaje<<"%"<<endl;
		}else{
			if(actual->TemaParcial==8){
				cout<<fixed<<setprecision (1);
				cout<<"Parcial 2: "<<actual->Porcentaje<<"%"<<endl;
				archivo<<fixed<<setprecision (1);
				archivo<<"Parcial 2: "<<actual->Porcentaje<<"%"<<endl;
			}else{
		cout<<fixed<<setprecision (1);
		cout<<"Tema "<<actual->TemaParcial<<": "<<actual->Porcentaje<<"%"<<endl;
		archivo<<fixed<<setprecision (1);
		archivo<<"Tema "<<actual->TemaParcial<<": "<<actual->Porcentaje<<"%"<<endl;
		}
	}
		actual = actual->ptrSiguiente;
}
}
