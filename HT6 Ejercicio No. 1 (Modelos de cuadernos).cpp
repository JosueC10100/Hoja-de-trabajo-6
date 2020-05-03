#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
void menu();
void input();
void delet();
void report();
void modify();

float mod1(int c);
float mod2(int c);
float mod3(int c);
float mod4(int c);

struct struct_mod{
	int cantidad;
	float tot_rec;
};
struct struc_lec{
	int cantidad;
	float tot_rec;
};
int main(){
	menu();
}
void menu(){
	int option;
	do{
		system("CLS");
		cout<<"Seleccione la opción: "<<endl;
		cout<<"1. Ingresar venta diaria "<<endl;
		cout<<"2. Eliminar registro "<<endl;
		cout<<"3. Modificar registro "<<endl;
		cout<<"4. Generar reporte mensual "<<endl;
		cout<<"5. Salir "<<endl;
		cin>>option;
		if(option==1)
			input();
		else if(option==2)
			delet();
		else if(option==3)
			modify();
		else if(option==4)
			report();
		else if(option==5)
			break;
		else
			break;
	}while(option!=5);
}
void input(){
	int day;
	int i;
	float precio=0;
	ofstream file;
	struct_mod modelo[4];
	system("CLS");
	cout<<"Ingrese el día a registrar: "<<endl;
	cin>>day;
	for(i=0;i<4;i++){
		cout<<"Ingrese la cantidad del modelo No. "<<i+1<<endl;
		cin>>modelo[i].cantidad;
		if(i==0)
			precio = mod1(modelo[i].cantidad);
		else if(i==1)
			precio = mod2(modelo[i].cantidad);
		else if(i==2)
			precio = mod3(modelo[i].cantidad);
		else if(i==3)
			precio = mod4(modelo[i].cantidad);	
		modelo[i].tot_rec += precio;
	}
	for(i=0;i<4;i++){
		cout<<"Modelo: "<<i+1<<"\t"<<modelo[i].tot_rec<<endl;
	}
	
	try{
		file.open("Cuadernos.txt",ios::app);
		for(i=0;i<4;i++){
			file<<day<<"\t"<<i+1<<"\t"<<modelo[i].cantidad<<endl;
		}
	}
	catch(exception X){
		system("CLS");
		cout<<"Error en la manipulación del archivo"<<endl;
	}
	file.close();
	system("PAUSE");
}
void delet(){
	int adia, amodelo, acant, respuesta, cont, nmodelo, ncant, flag, mod;
	remove("temporal.txt");
	ifstream db_a;
	ofstream db_n;
	db_a.open("Cuadernos.txt",ios::in);
	db_n.open("temporal.txt",ios::out);
	cout<<"Ingrese día a eliminar: "<<endl;
	cin>>cont;
	while(db_a>>adia>>amodelo>>acant){
		if(cont==adia){
			cout<<"Registro eliminado"<<endl;	
			flag = 1;
		}	
		else if(cont!=adia){
			db_n<<adia<<"\t"<<amodelo<<"\t"<<acant<<endl;
		}
	}
	db_a.close();	
	db_n.close();
	if(flag==1){
		remove("Cuadernos.txt");
		rename("temporal.txt","Cuadernos.txt");
	}
	system("PAUSE");
} 
void report(){
	
	ifstream file;
	int i;
	int d,m,c;
	float suma[4];
	float sc[4];
	float mayor = -1;
	system("CLS");
	cout<<"Reporte"<<endl;
	struc_lec dias[30];
	try{
		file.open("Cuadernos.txt",ios::in);
		while(file>>d>>m>>c){
			cout<<"Día:\t"<<d<<"\tModelo:\t"<<m<<"\tCantidad\t"<<c<<endl;
			if(m==1){
				suma[0] +=(c*10);
				sc[0]+=c;
			}
			else if(m==2){
				suma[1] +=(c*15);
				sc[1]+=c;
			}
			else if(m==3){
				suma[2] +=(c*18.50);
				sc[2]+=c;
			}
			else if(m==4){
				suma[3] +=(c*25);
				sc[3]+=c;
			}
			/*for(int i=0;i<31;i++){

				if(d==i){
					dias[i].cantidad += c;
					cout<<"Cantidad hasta el momento: "<<dias[i].cantidad<<endl;
			}			//estructura para ir sumando ahí los valores, puedo usar funciones también
			}*/				//Algoritmo verifica durante el while y ejecuta el for para cada linea, si aplica lo añade
		}
		//for(int i=0;i<31;i++){	
		//	cout<<"Día:\t"<<i+1<<"\t"<<dias[i].cantidad<<endl;
		//	}
		}
		catch(exception X){
			cout<<"No se pudo abrir el archivo"<<endl;
		}/*
	struct_mod modelo[4];
	for(i=0;i<4;i++){
		cout<<"Modelo: "<<i+1<<"\t"<<modelo[i].cantidad<<endl;
	}*/
		for(i=0;i<4;i++){
			if(sc[i]>mayor){
				mayor = sc[i];
			}
			cout<<"Cantidad vendida por modelo: "<<endl;
			cout<<"Modelo No. "<<i+1<<"\t"<<suma[i]<<endl;
			cout<<"Cant: "<<sc[i]<<endl;
			cout<<"Modelo de mayor venta: "<<mayor<<endl;
			}	
		file.close();
		system("PAUSE");
}
void modify(){
	int adia, amodelo, acant, respuesta, ndia, nmodelo, ncant, flag, mod;
	remove("temporal.txt");
	ifstream db_a;
	ofstream db_n;
	db_a.open("Cuadernos.txt",ios::in);
	db_n.open("temporal.txt",ios::out);
	cout<<"Ingrese día a modificar: "<<endl;
	cin>>ndia;
	cout<<"Ingrese modelo a modificar "<<endl;
	cin>>mod;
	cout<<"Ingrese nueva cantidad "<<endl;
	cin>>ncant;
	cout<<"\n"<<endl;
	//}while(mod!=5);		
	while(db_a>>adia>>amodelo>>acant){
		if(ndia==adia){
			if(amodelo==mod){
				db_n<<adia<<"\t"<<amodelo<<"\t"<<ncant<<endl;	
			}
			else if(amodelo!=mod){
				db_n<<adia<<"\t"<<amodelo<<"\t"<<acant<<endl;
			}
			flag = 1;
			cout<<"Archivo Actualizado..."<<endl;
		}
		else if(adia!=ndia){
			db_n<<adia<<"\t"<<amodelo<<"\t"<<acant<<endl;
		}
	}
	db_a.close();	
	db_n.close();
	if(flag==1){
		remove("Cuadernos.txt");
		rename("temporal.txt","Cuadernos.txt");
	}
	system("PAUSE");
}
float mod1(int c){
	float valor;
	valor = c*10.00;
	return valor;
}
float mod2(int c){
	float valor;
	valor = c*15.00;
	return valor;
}
float mod3(int c){
	float valor;
	valor = c*18.50;
	return valor;
}
float mod4(int c){
	float valor;
	valor = c*25.00;
	return valor;
}
/* Código para eliminar datos
db_a.open("Cuadernos.txt",ios::in);
db_n.open("temporal.txt,ios::out);

cout<<"Ingrese el ID al que modificará la información: "<<endl;
cin>>aux;
do{
	cout<<"Ingrese nota a modificar: "<<endl;
	cin>>inota;
	cout<<"Está seguro? S/N "<<endl;
	cin>>respuesta;
	cout<<"\n"<<endl;
	respuesta = toupper(respuesta);

	while(db_a>>oid>>onombre>>onota){ 
	if(aux==oid){
		db_n<<oid<<"\t"<<onombre<<"\t"<<inota<<endl;
		cout<<"Archivo Actualizado..."<<endl;
		flag = 1;
	else if(aux!=oid){
		db_n<<oid<<"\t"<<onombre<<"\t"<<inota<<endl;
	}
	db_a.close();	
	db_n.close();
	if(flag==1){
		remove("colegio.txt");
		remove("temporal.txt","colegio.txt")
	}
	system("PAUSE");
} */
