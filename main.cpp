#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Crea un espacio de memoria en el heap, asigna el valor dado y devuelve su direccion de memoria
int* obtenerDireccion(int valor)
{
    int *dir= new int;
    *dir=valor;
    return dir;
}

//Intercambia los valores ubicados en las posiciones previamente dadas. Asigna el valor donde apuntaba la valor1 a donde apunta valor2 y vice versa.
//Nota: la template debe de poder aceptar cualquier tipo primitivo
template <typename T>
void intercambiar(T* valor1,T* valor2)
{
 T valu;
 valu=*valor1;
 T valu2;
 valu2=*valor2;
 *valor1=valu;
 *valor2=valu2;
}

//Devuelve true si todos los elementos del vector dado son positivos, de lo contrario devuelve false.
double sonPositivos(vector<int>elementos)
{
    for(int num=0; num>=elementos.size(); num++)
    {
    if(elementos[num]<0)
    {
        return false;
    }
    return true;
    }

}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las clases MedioDeTransporte, Carro y Moto descritas en el diagrama UML adjunto

//**Figura**
//El constructor vacio no hace nada
//getTipo(): devuelve "Figura"


//**Cuadrado**
//Constructor: inicializa el atributo lado, dado su parametro
//getArea(): devuelve el lado elevado a la dos
//getTipo(): devuelve "Cuadrado"
//operator+=: suma su parametro al altributo lado

//**Rectangulo**
//Constructor: inicializa los atributos de clase dado los paramentros
//getArea(): devuelve base multiplicado por la altura
//getTipo(): devuelve "Rectangulo"

class Figura
{
public:
    Figura()
    {

    }
virtual string getTipo()
{
    return "Figura";

}
virtual int getArea()=0;


};
class Cuadrado: public Figura
{
    int lado;
    Cuadrado(int lado)
    {
        this->lado=lado;
    }
int getArea()
{
    return (lado*lado);
}
string  getTipo()
{
    return "Cuadrado";
}
void operator+=(int lado)
{
    this->lado+=lado;

}
};

class Rectangulo: public Figura
{
    int base;
    int altura;
    Rectangulo(int base, int altura)
    {
        this->base=base;
        this->altura=altura;
    }
int getArea()
{
    return (base*altura);
}
string  getTipo()
{
    return "Rectangulo";
}

};
///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////

void evaluar()
{
    double nota = 0;

    cout<<"obtenerDireccion():\t";
    if(obtenerDireccion(10)!=NULL && *obtenerDireccion(10)==10
        && obtenerDireccion(42)!=NULL && *obtenerDireccion(42)==42
        && obtenerDireccion(234123)!=NULL && *obtenerDireccion(234123)==234123
       && obtenerDireccion(0)!=NULL && *obtenerDireccion(0)==0
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    int *arr = new int[3];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;

    float *arr2 = new float[5];
    arr2[0]=1;
    arr2[1]=0;
    arr2[2]=2;
    arr2[3]=7;
    arr2[4]=0;

    string *arr3 = new string[2];
    arr3[0]="hola";
    arr3[1]="mundo";
    string ejemplo="ejemplo";

    cout<<"intercambiar():\t\t";

    int* i1 = new int(10);
    int* i2 = new int(30);

    string* i3=new string("hola");
    string* i4=new string("mundo");

    intercambiar(i1,i2);
    intercambiar(i3,i4);

    if(*i1==30
        && *i2==10
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    vector<int>v1,v2,v3,v4;

    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(-2);

    v2.push_back(7);
    v2.push_back(3);
    v2.push_back(643);
    v2.push_back(23);

    v3.push_back(6543);
    v3.push_back(34);
    v3.push_back(64);
    v3.push_back(26);
    v3.push_back(0);
    v3.push_back(35);

    v4.push_back(-1);
    v4.push_back(3);

    cout<<"sonPositivos():\t\t";
    if(!sonPositivos(v1)
       && sonPositivos(v2)
       && sonPositivos(v3)
       && !sonPositivos(v4)
        )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/6"<<endl<<endl;
}

void evaluar2()
{
    double nota = 0;

//    cout<<"**Clase Cuadrado**"<<endl;
//    cout<<"Test constructor:\t";
//    Cuadrado c1(10);
//    Cuadrado c2(5);
//    Cuadrado c3(3);
//    Figura *f=new Cuadrado(4);
//
//    if(c1.lado==10
//        && c2.lado==5
//        && c3.lado==3
//        && ((Cuadrado*)f)->lado==4
//        )
//    {
//        nota+=1;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }
//
//    cout<<"Test getTipo():\t\t";
//
//    if(c1.getTipo() == "Cuadrado"
//        && c2.getTipo() == "Cuadrado"
//        && c3.getTipo() == "Cuadrado"
//        && f->getTipo()=="Cuadrado"
//        )
//    {
//        nota+=1;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }
//
//    cout<<"Test getArea():\t\t";
//
//    if(c1.getArea() == 100
//        && c2.getArea() == 25
//        && c3.getArea() == 9
//        && f->getArea()==16
//        )
//    {
//        nota+=2;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }
//
//
//    cout<<"Test operator+=():\t";
//    c1+=3;
//    c2+=-1;
//    c3+=3000;
//    *((Cuadrado*)f)+=1;
//    if(c1.lado==13
//        && c2.lado==4
//        && c3.lado==3003
//        && ((Cuadrado*)f)->lado==5
//        )
//    {
//        nota+=1;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }
//
//
//
//    cout<<"**Clase Rectangulo**"<<endl;
//    cout<<"Test constructor:\t";
//    Rectangulo r1(10,2);
//    Rectangulo r2(3,5);
//    Rectangulo r3(4,1);
//    Figura *f2=new Rectangulo(2,3);
//
//    if(r1.base==10
//        && r1.altura==2
//        && r2.base==3
//        && r2.altura==5
//        && r3.base==4
//        && r3.altura==1
//        && ((Rectangulo*)f2)->base==2
//        && ((Rectangulo*)f2)->altura==3
//        )
//    {
//        nota+=1;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }
//
//    cout<<"Test getTipo():\t\t";
//
//    if(r1.getTipo() == "Rectangulo"
//        && r2.getTipo() == "Rectangulo"
//        && r3.getTipo() == "Rectangulo"
//        && f2->getTipo()=="Rectangulo"
//        )
//    {
//        nota+=1;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }
//
//    cout<<"Test getArea():\t\t";
//
//    if(r1.getArea() == 20
//        && r2.getArea() == 15
//        && r3.getArea() == 4
//        && f2->getArea()==6
//        )
//    {
//        nota+=2;
//        cout<<"Correcto"<<endl;
//    }else
//    {
//        cout<<"Incorrecto"<<endl;
//    }

    cout<<endl<<"Nota: "<<nota<<"/9"<<endl;
}
