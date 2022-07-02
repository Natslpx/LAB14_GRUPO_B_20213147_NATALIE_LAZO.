#ifndef TIENDA_H
#define TIENDA_H

#include<string>
using namespace std;

struct Producto
{
    string codigo;
    string nombre;
    float precio;
    int stock;
};

class Tienda
{
    Producto **productos; // arreglo dinamico de puntero a producto
    int capacidad; // capacidad del arreglo
    Producto **ultimo; // puntero al ultimo del arreglo
public:
    Tienda(int cap);
    ~Tienda();
    void darAltaNuevoProducto();
    void darBajaProducto(Producto **prod);
    Producto **buscarProductoPorNombre();
    Producto **buscarProductoPorCodigo();
    void modificarCodigo(Producto **prod);
    void modificarNombre(Producto **prod);
    void modificarPrecio(Producto **prod);
    void modificarStock(Producto **prod);
    void imprimirTienda();
};

#endif
