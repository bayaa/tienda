#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct tienda
{
    int dato;
    struct tienda *siguiente;
}*inicio,*aux,*actual;
void eliminartienda(int);
void insertartienda(int);
void mostrartienda();
void ordenar(int);
void posicion(int);

int main()
{
    inicio = NULL;
    int dato;
    int salida,cuenta=0;
    int menu;
    do
    {
        cout<<"\n\n-----------------------TIENDA (PRECIOS A LOS PRODUCTOS)--------------------\n";
        cout<<"\t\nMENU\n\t(1)INSERTAR  PRECIOPRODUCTO\n\t(2)MOSTRAR PRODUCTO COSTO\n\t(3)BORRAR COSTO PRODUCTO\n\t(4)SALIR\n";
        cin>>menu;
        switch(menu)
        {
        case 1:
            cout << "\tSALIR OPRIMA  -1" << endl;
            do
            {
                cout << "\t PRECIO PRODUCTO  : >>>>>>>>   ";
                cin >> dato;
                if(dato != -1)
                {
                    cuenta++;
                    insertartienda(dato);
                }


            }
            while (dato != -1 );

            break;
        case 2:
            cout<<"\t\tPRODUCTOS\n";
            mostrartienda();


            break;
        case 3:
            int variable,respuesta;
            do
            {
                mostrartienda();
                cout<<"\tEliminar producto (FIN -1)"<<endl;
                cin>>variable;
                eliminartienda(variable);

            }
            while (variable!= -1);
            cout<<"\t\tPRODUCTOS\n";
            mostrartienda();
            break;

        default:
            break;



        }
    }
    while (menu !=4);



    cout<<"\n\tFINAL";




    //cin.get();
    return 0;
}

void insertartienda(int valor)
{
    actual=inicio;
    if(actual == NULL)
    {
        aux = new tienda();
        aux->dato = valor;
        aux->siguiente = NULL;
        inicio = aux;
    }
    else
    {
        while(actual->siguiente != NULL)
        {
            actual=actual->siguiente;
        }
        aux = new tienda();
        aux->dato = valor;
        aux->siguiente = NULL;
        actual->siguiente = aux;
    }

}

void mostrartienda()
{
    actual = inicio;
    int contador=0;
    do
    {
        contador++;
        cout <<"\t\t"<<" producto  .-  "<< contador <<"      " << actual->dato << " " << endl;
        actual=actual->siguiente;
    }
    while(actual!= NULL);

}

void posicion(int valor)
{
    actual = inicio;
    int contador=0;
    do
    {
        contador++;
        if(contador == valor)
        {
            cout <<"\t\t"<< contador <<".- " << actual->dato << " " << endl;
        }

        actual=actual->siguiente;
    }
    while(actual!= NULL);
}
void ordenar(int cantidad)
{
    tienda *aux1;
    //aux1 = inicio;

    do
    {
        actual=inicio;
        while (actual->siguiente != NULL)
        {

            aux = actual->siguiente;

            while(aux != NULL)
            {

                if(actual->dato > actual->siguiente->dato)
                {

                    aux1->dato = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = aux1->dato;

                }
                aux = aux->siguiente;

            }

            actual = actual->siguiente;
        }

        cantidad--;
    }
    while(cantidad != 0);
}
void eliminartienda(int valor)
{
    if(inicio!=NULL)
    {
        aux=NULL;
        actual=inicio;
        while((actual!=NULL) && (actual->dato!=valor))
        {
            aux=actual;
            actual=actual->siguiente;
        }
        if(actual==NULL)
        {
            cout<<"\n\n\t\t\tDATO NO EXISTE"<<endl;
        }
        else if(aux==NULL)
        {
            inicio=inicio->siguiente;
            delete actual;
        }
        else
        {
            aux->siguiente=actual->siguiente;
            delete actual;
        }
    }
}
