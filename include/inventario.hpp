#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "Vector.hpp"
#include <iostream>
#include <string>
using namespace std;
const string ARCHIVO = "ejemplo.csv";
const int CANTIDADMAXIMA = 15;

class inventario{
    private:
        Vector Inventario;
        //Pre:nombre y tipo deben estar incializados.
        //Post:los convierte en objeto de item.
        Item* strToItem(string nombre, string tipo);
        //Pre:-
        //Post:Abre el archivo en modo lectura
        ifstream abrirArchivoLectura(string NombreArchivo);
        //Pre:-
        //Post:Abre archivo a leer.
        ofstream abrirArchivoEscritura(string NombreArchivo);
    public:
        inventario();
        //Pre:Vector incializado.
        //Post:Agrega el item elegido mientras tamanio menor a 15
        void agregarInventario(Item* nuevoItem);
        //Pre:Vector incializado.
        //Post:Elimina el item elegido.
        void eliminarInventario(string nombre);
        //Pre:Archivo debe estar creado.
        //Post: Llena el vector por linea.
        void archivoAVector();
        //Pre:Vector debe estar incializado.
        //Post:Escribe el archivo con lo que hay en el vector.
        void vectorAArchivo();
        //Pre:Inventario inciializado
        //Post:Devuelve el inventario
        void consultaInventario();

        ~inventario();
};

#endif