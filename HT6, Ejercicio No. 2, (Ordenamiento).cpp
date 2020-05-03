#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct poblacion{
	int edad ;
	float peso; ;
	float altura ;
};

void bubbleSort(poblacion list[], int tam);
void input();
int main( ){
	input();
	
	int a, c=0, e, p;
	float pa=0.00, pe=0.00, pp=0.00;
	ifstream fp;
    string Tmp;
	fp.open("poblacion.txt");
	while(fp>>e>>p>>a){
		c+=1;
		pa+=a;
		pe+=e;
		pp+=p;
	}
		
	cout<<"Promedio peso: "<<pp/c<<"\tPromedio edad:"<<pe/c<<"\tPromedio altura: "<<pa/c<<endl;
	poblacion pob_array[c];

	if (fp)
	{	
   		for (int counter = 0; counter < c; counter++){
        	fp >> pob_array[counter].edad;
        	fp >> pob_array[counter].peso;
        	fp >> pob_array[counter].altura;
    	}
	}
	else
    	puts("error"); //

	bubbleSort(pob_array, c);
                
	for (int counter = 0; counter < c; counter++)
	{
   	 	cout << pob_array[counter].edad << "\t";
   	 	cout << pob_array[counter].peso << "\t";
   	 	cout << pob_array[counter].altura <<endl;
	}
}

void bubbleSort(poblacion list[], int tam)
{
    poblacion temp;
    int i;
    int index;
    for (i = 1; i < tam; i++)
    {
     	//cout<<"i: posicion actual antes"<<list[i].num<<endl;
	    for (index = 0; index < tam - i; index++)
            if (list[index].edad > list[index + 1].edad)
            {
            	//cout<<"Posicion de intercambio:  "<<endl;
                temp = list[index];
                //cout<<"var temp"<<temp.num<<endl;
                list[index] =  list[index + 1];
                //cout<<" list[index+1]  " << list[index+1].num<<endl;
                list[index + 1] =  temp;
            }
       // cout<<"i: posicion actual despues"<<list[i].num<<endl;
    }
}
void input(){
	int n;
	ofstream fp;
	cout<<"Digite el número de personas a ingresar: "<<endl;
	cin>>n;
	poblacion personas[n];
	for(int i=0;i<n;i++){
		cout<<"Ingrese la edad de la persona No. "<<i+1<<endl;
		cin>>personas[i].edad;
		cout<<"Ingrese el peso (en lb) de la persona No. "<<i+1<<endl;
		cin>>personas[i].peso;
		cout<<"Ingrese la altura (en cm) de la persona No. "<<i+1<<endl;
		cin>>personas[i].altura;
	}
	try{
		fp.open("poblacion.txt",ios::app);
		for(int i=0;i<n;i++){
			fp<<personas[i].edad<<"\t"<<personas[i].peso<<"\t"<<personas[i].altura<<endl;		}
	}
	catch(exception X){
		cout<<"Error al abrir el archivo"<<endl;
		
	}
	fp.close();
}


/*
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct emp
{
	int num ; //clave de ordenamiento
	string name ;
	string age ;
	string bs ;
};

void bubbleSort(emp list[], int tam);

int main( )
{
	ifstream fp;
    string Tmp;
	fp.open("emp.txt");
	emp emp_array[5];

	if (fp)
	{	
   		for (int counter = 0; counter < 5; counter++)
    	{
        	fp >> emp_array[counter].num;
        	fp >> emp_array[counter].name;
        	fp >> emp_array[counter].age;
        	fp >> emp_array[counter].bs;
    	}
	}
	else
    	puts("error"); //

	bubbleSort(emp_array, 5);
                
	for (int counter = 0; counter < 5; counter++)
	{
   	 	cout << emp_array[counter].num << "\t";
   	 	cout << emp_array[counter].name << "\t";
   	 	cout << emp_array[counter].age << "\t";
  	  	cout << emp_array[counter].bs << endl;
	}
}

void bubbleSort(emp list[], int tam)
{
    emp temp;
    int i;
    int index;
    for (i = 1; i < tam; i++)
    {
     	//cout<<"i: posicion actual antes"<<list[i].num<<endl;
	    for (index = 0; index < tam - i; index++)
            if (list[index].num > list[index + 1].num)
            {
            //	cout<<"Posicion de intercambio:  "<<endl;
                temp = list[index];
              //  cout<<"var temp"<<temp.num<<endl;
                list[index] =  list[index + 1];
                //cout<<" list[index+1]  " << list[index+1].num<<endl;
                list[index + 1] =  temp;
            }
     //   cout<<"i: posicion actual despues"<<list[i].num<<endl;
    }
}*/
