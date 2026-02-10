#ifndef FANTASMA_H
#define FANTASMA_H

#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Fantasma
{
    public:
        Fantasma(int, int, int, float);
        ~Fantasma();
        void MC( int[10][11], float*, float*);
        void draw( GLuint );
        void update();
        int dirOpuesta(int);

    protected:

    private:
        int matAdy[10][11];
        float* ejeX;
        float* ejeY;
        float coord[2];
        int direccion;
        int vDir[4];
        float velocidad;
        GLuint textura;
        GLuint cargarTextura(const char* nombreArchivo);
};

#endif // FANTASMA_H
