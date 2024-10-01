// practice.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//TAREA
//bubble -> en clase, añadir template, que acepte lo que sea
//leer parte 3

#include <iostream>

template <class T>
class sortType {
public:
    virtual bool operator()(T a, T b) = 0 {};
};

template <class T>
class asc : public sortType<T> {
public:
    bool operator()(T a, T b) override{
        return b < a;
    }
};

template <class T>
class des : public sortType<T> {
public:
    bool operator()(T a, T b) override{
        return a < b;
    }
};

template <class O, class T>
class bubble {
public:
    bool keep;
    O* p;
    //bubble() {
    //    p = 0;
    //}

    void sort(O* ini, O* fin, T* op) {
        keep = 1;
        while ((ini < fin) && keep) {
            keep = 0;
            for (p = ini; p < fin; p++) {
                if (op->operator()(*p, *(p + 1))) {
                    std::swap(*p, *(p + 1));
                    keep = 1;
                }
            }
            fin--;
        }
    }
    /*void swap(O& a, O& b) {
        O tmp;
        tmp = a;
        a = b;
        b = tmp;
    }*/
    void print(O* ini, O* fin) {
        for (p = ini; p <= fin; p++)
            std::cout << *p << " ";
        printf("\n");
    }
};

int
main()
{
    int A[5] = { 3,1,32,63,7 };
    sortType<int>* dad1;
    asc<int> sonAsc;
    des<int> sonDes;
    bubble<int, sortType<int>> b1;

    dad1 = &sonAsc;
    b1.sort(A, A + 4, dad1);
    b1.print(A, A + 4);

    dad1 = &sonDes;
    b1.sort(A, A + 4, dad1);
    b1.print(A, A + 4);

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln