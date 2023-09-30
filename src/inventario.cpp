#include "../include/inventario.hpp"
#include "../include/Item.hpp"
#include "../include/Vector.hpp"
#include <fstream>

inventario::inventario(){
    Vector Inventario;
}

void inventario::agregarInventario(Item* nuevoItem){
    if (Inventario.tamanio() < CANTIDADMAXIMA){
        Inventario.alta(nuevoItem);
        cout << "Elemento agregado con exito!" << endl;
    }else{
        cout << "El inventario esta lleno" << endl;
        delete nuevoItem;
    }
}

void inventario::eliminarInventario(string nombre){
    size_t indice;
    bool encontrado = false;
    for(size_t i = 0; i < Inventario.tamanio(); i++){
        Item* itemPtr = Inventario[i];
        Item item = *itemPtr;
        if(Inventario[i] != nullptr && item == nombre && !encontrado){
            indice = i;
            encontrado = true;
        }
    }
    if(encontrado){
        Item* elementoEliminado = Inventario.baja(indice);
        delete elementoEliminado;
        cout << "Elemento eliminado con exito!" << endl;
    }else{
        cout << "Elemento no encontrado en el inventario." << endl;
    }
}

void inventario::consultaInventario(){
    for (size_t i = 0; i < Inventario.tamanio(); i++) {
        Inventario[i]->listarInformacion();
    }
}

ifstream inventario::abrirArchivoLectura(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo en modo lectura." << endl;
    }
    return archivo;
}

ofstream inventario::abrirArchivoEscritura(string nombreArchivo){
    ofstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo en modo escritura." << endl;
    }
    return archivo;
}

Item* inventario::strToItem(string nombre, string tipo) {
    Item *nuevoItem = new Item(nombre, tipo);
    return nuevoItem;
}

void inventario::archivoAVector(){
    string archivo = ARCHIVO;
    ifstream archivoLectura = abrirArchivoLectura(ARCHIVO);
    if(archivoLectura.is_open()){
        string linea;
        while(getline(archivoLectura,linea)){
            size_t coma = linea.find(',');
            string nombre,tipo;
            nombre = linea.substr(0, coma);
            tipo = linea.substr(coma+1);
            Item * nuevoItem = strToItem(nombre, tipo);
            Inventario.alta(nuevoItem);
        }
        archivoLectura.close();
    }
}

void inventario::vectorAArchivo(){
    string archivo = ARCHIVO;
    ofstream archivoEscritura = abrirArchivoEscritura(ARCHIVO);
    if (archivoEscritura.is_open()){
        for (size_t i = 0; i < Inventario.tamanio(); ++i) {
            archivoEscritura << *Inventario[i] << endl;
        }
    }
    archivoEscritura.close();
}

inventario::~inventario() {
    for (size_t i = 0; i < Inventario.tamanio(); i++) {
        delete Inventario[i];
    }
}


