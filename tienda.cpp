#include <iostream>
#include "tienda.h"
using namespace std;

Tienda::Tienda(int cap=10) // capacidad por defecto de 10
{
    capacidad = cap;
    productos = new Producto*[capacidad];
    for(Producto **ptr = productos; ptr != (productos + capacidad); ptr++) // nos aseguramos que el arreglo no tenga basura
    {
        *ptr = NULL;
    }
    ultimo = productos;
}

Tienda::~Tienda()
{
    for(Producto **ptr = productos; ptr != ultimo; ptr++)
    {
        delete *ptr;
        *ptr = NULL;
    }
    delete productos;
    productos = NULL;
    ultimo = NULL;
}

void Tienda::darAltaNuevoProducto()
{
    if(ultimo == (productos + capacidad))
    {
        cout << "arreglo lleno, no se hacen modificaciones";
    }
    else
    {
        *ultimo = new Producto;
        cout << "ingrese codigo: "; cin >> (**ultimo).codigo;
        cout << "ingrese nombre: "; cin >> (**ultimo).nombre;
        cout << "ingrese precio: "; cin >> (**ultimo).precio;
        cout << "ingrese stock: "; cin >> (**ultimo).stock;
        ultimo++;
    }
}

void Tienda::darBajaProducto(Producto **prod)
{
    Producto *borrar = *prod;
    ultimo--;
    *prod = *ultimo;
    delete borrar;
}

Producto **Tienda::buscarProductoPorNombre()
{
    Producto **ptr;
    string nomb;
    cout << "ingrese nombre a buscar: "; cin >> nomb;
    for(ptr = productos; ptr != ultimo; ptr++)
    {
        if((**ptr).nombre == nomb)
            return ptr;
    }
    return NULL;
}

Producto **Tienda::buscarProductoPorCodigo()
{
    Producto **ptr;
    string cod;
    cout << "ingrese codigo a buscar: "; cin >> cod;
    for(ptr = productos; ptr != ultimo; ptr++)
    {
        if((**ptr).codigo == cod)
            return ptr;
    }
    return NULL;
}

void Tienda::modificarCodigo(Producto **prod)
{
    cout << "ingrese nuevo codigo: "; cin >> (**prod).codigo;
}

void Tienda::modificarNombre(Producto **prod)
{
    cout << "ingrese nuevo nombre: "; cin >> (**prod).nombre;
}

void Tienda::modificarPrecio(Producto **prod)
{
    cout << "ingrese nuevo precio: "; cin >> (**prod).precio;
}

void Tienda::modificarStock(Producto **prod)
{
    cout << "ingrese nuevo stock: "; cin >> (**prod).stock;
}

void Tienda::imprimirTienda()
{
    cout << "=== TIENDA ===" << endl;
    for(Producto **ptr = productos; ptr != ultimo; ptr++)
    {
        cout <<  "codigo: " << (**ptr).codigo;
        cout <<  " nombre: " << (**ptr).nombre;
        cout <<  " precio: " << (**ptr).precio;
        cout <<  " stock: " << (**ptr).stock << endl;
    }
    cout << "==============" << endl;
}
