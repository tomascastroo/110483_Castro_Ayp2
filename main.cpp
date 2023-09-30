#include "include/Vector.hpp"
#include <iostream>
#include "include/inventario.hpp"
using namespace std;

string captarMensaje(string &mensaje, string orden){
    cout << orden;
    cin >> mensaje;
    return mensaje;
}

Item* crearItem(){
    string nombre;
    nombre = captarMensaje(nombre, "Ingrese el nombre del ítem: ");
    string tipo;
    tipo = captarMensaje(tipo, "Ingrese el tipo del ítem(curativo, puzzle, munición): ");
    if(tipo != "Puzzle" && tipo != "PUZZLE" && tipo != "puzzle"
       && tipo != "MUNICION" && tipo != "municion"  && tipo != "Municion"
       && tipo != "CURATIVO" && tipo != "curativo"  && tipo != "Curativo"){
        tipo = captarMensaje(tipo, "Ingrese un tipo de ítem válido: ");
    }
    Item* nuevoItem = new Item(nombre, tipo);
    return nuevoItem;
}

void accionUsuario(inventario &Inventario){
    string accion;
    bool salir = false;
    accion = captarMensaje(accion, "Acción sobre el inventario: ");
    if((accion == "ALTA"|| accion == "alta") && !salir){
        Item* nuevoItem = crearItem();
        Inventario.agregarInventario(nuevoItem);
        accionUsuario(Inventario);
    }else if((accion == "BAJA" || accion == "baja") && !salir){
        string nombre;
        nombre = captarMensaje(nombre, "Ingrese el nombre del ítem a eliminar: ");
        Inventario.eliminarInventario(nombre);
        accionUsuario(Inventario);
    }else if((accion == "CONSULTA" || accion == "consulta")  && !salir){
        Inventario.consultaInventario();
        accionUsuario(Inventario);
    }else if((accion == "SALIR" || accion == "salir") && !salir){
        Inventario.vectorAArchivo();
        salir = true;
    }
}

int main() {
    inventario Inventario;
    Inventario.archivoAVector();
    accionUsuario(Inventario);
    return 0;
}
