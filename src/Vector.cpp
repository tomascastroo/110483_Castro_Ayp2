#include "../include/Vector.hpp"

Vector::Vector(){
    cantidadDatos = 0;
    tamanioMaximo = 0;
    datos = nullptr;
}

size_t Vector::tamanio(){
    return cantidadDatos;
}

bool Vector::vacio(){
    if(tamanio() == 0){
        return true;
    }else{
        return false;
    }
}

void Vector::ordenarIzquierda(size_t indice){
    for (size_t i = indice; i < cantidadDatos - 1; i++){
        datos[i] = datos[i+1];
    }
}

void Vector::ordenarDerecha(size_t indice){
    for (size_t i = cantidadDatos; i > indice; i--){
        datos[i] = datos[i-1];
    }
}

void Vector::alta(Item* dato, size_t indice){
    if(indice <= cantidadDatos){
        if (cantidadDatos == 0){
            tamanioMaximo = 1;
            datos = new Item*[tamanioMaximo];
        }else if(cantidadDatos == tamanioMaximo){
            tamanioMaximo *= 2;
            Item** nuevo = new Item*[tamanioMaximo];
            for(size_t i = 0; i < cantidadDatos; i++){
                nuevo[i] = datos[i];
            }
            delete[] datos;
            datos = nuevo;
        }
        for (size_t i = cantidadDatos; i > indice; i--){
            datos[i] = datos[i-1];
        }
        datos[indice] = dato;
        cantidadDatos++;
    }else{
        throw VectorException();
    }
}

void Vector::alta(Item* dato){
    if (cantidadDatos == 0){
        tamanioMaximo = 1;
        datos = new Item*[tamanioMaximo];
        datos[0] = dato;
    } else if (cantidadDatos == tamanioMaximo){
        tamanioMaximo *= 2;
        Item** nuevo = new Item*[tamanioMaximo];
        for (size_t i = 0; i < cantidadDatos; i++){
            nuevo[i] = datos[i];
        }
        delete[] datos;
        datos = nuevo;
    }
    datos[cantidadDatos] = dato;
    cantidadDatos++;
}

Item* Vector::baja(){
    if (vacio()){
        throw VectorException();
    }
    Item* elementoAEliminar = datos[cantidadDatos-1];
    cantidadDatos--;
    if (cantidadDatos < tamanioMaximo/2){
        tamanioMaximo /= 2;
        Item** nuevo = new Item*[tamanioMaximo];
        for (size_t i = 0; i < cantidadDatos; i++){
            nuevo[i] = datos[i];
        }
        delete[] datos;
        datos = nuevo;
    }
    return elementoAEliminar;
}

Item* Vector::baja(size_t indice) {
    if(indice >= cantidadDatos){
        throw VectorException();
    }
    Item* elementoAEliminar = datos[indice];
    ordenarIzquierda(indice);
    cantidadDatos--;
    if (cantidadDatos < tamanioMaximo/2){
        tamanioMaximo /= 2;
        Item** nuevo = new Item*[tamanioMaximo];
        for (size_t i = 0; i < cantidadDatos; i++){
            nuevo[i] = datos[i];
        }
        delete[] datos;
        datos = nuevo;
    }
    return elementoAEliminar;
}

Item*& Vector::operator[](size_t indice) {
    if (indice < tamanio()) {
        return datos[indice];
    } else {
        throw VectorException();
    }
}

Vector::~Vector(){
    delete [] datos;
}