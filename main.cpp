#include <iostream>
#include "tienda.h"
using namespace std;

int main()
{
    Tienda tienda(10);
    Producto **producto = NULL;
    int opcion = 0, opcion2;
    while(opcion != 5)
    {
        cout << endl <<"=== TIENDA DE ROPA ===" << endl;
        cout << " 1 - dar de alta nuevo producto" << endl;
        cout << " 2 - buscar producto por codigo" << endl;
        cout << " 3 - buscar producto por nombre" << endl;
        cout << " 4 - imprimir tienda" << endl;
        cout << " 5 - salir del menu principal" << endl;
        cout << "ingrese opcion: "; cin >> opcion;
        cout << endl;
        switch(opcion)
        {
            case 1:
                tienda.darAltaNuevoProducto();
                break;
            case 2:
                producto = tienda.buscarProductoPorCodigo();
                if(producto == NULL)
                {
                    cout << "producto no encontrado" << endl;
                }
                break;
            case 3:
                producto = tienda.buscarProductoPorNombre();
                if(producto == NULL)
                {
                    cout << "producto no encontrado" << endl;
                }
                break;
            case 4:
                tienda.imprimirTienda();
                break;
            case 5:
                break;
            default:
                cout << "opcion no valida" << endl;
        }
        if((opcion == 2 || opcion == 3) && producto !=NULL)
        {
            opcion2 = 0;
            while(opcion2 != 1 && opcion2 != 6)
            {
                cout << "=== CON EL PRODUCTO  ===" << endl;
                cout << "codigo: " << (**producto).codigo << endl;
                cout << "nombre: " << (**producto).nombre << endl;
                cout << "precio: " << (**producto).precio << endl;
                cout << "stock: " << (**producto).stock << endl << endl;
                cout << " 1 - dar de baja un producto" << endl;
                cout << " 2 - modificar codigo" << endl;
                cout << " 3 - modificar nombre" << endl;
                cout << " 4 - modificar precio" << endl;
                cout << " 5 - modificar stock" << endl;
                cout << " 6 - salir del menu de producto" << endl;
                cout << "ingrese opcion: "; cin >> opcion2;
                switch(opcion2)
                {
                    case 1:
                        tienda.darBajaProducto(producto);
                        break;
                    case 2:
                        tienda.modificarCodigo(producto);
                        break;
                    case 3:
                        tienda.modificarNombre(producto);
                        break;
                    case 4:
                        tienda.modificarPrecio(producto);
                        break;
                    case 5:
                        tienda.modificarStock(producto);
                        break;
                    case 6:
                        break;
                    default:
                        cout << "opcion no valida" << endl;
                }
            }
        }
    }
}
