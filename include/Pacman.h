#ifndef PACMAN_H
#define PACMAN_H

#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Pacman
{
     public:
        Pacman(int, int, int, float);
        ~Pacman();
        void MC( int[10][11], float*, float*);
        void draw(GLuint);
        void update();
        void guardarLastDireccion(int);
        int dirOpuesta(int);





    protected:

        private:
        int matAdy[10][11];
        float* ejeX;
        float* ejeY;
        float coord[2];
        int direccion;
        int vDir[5];
        float velocidad;
        int lastDireccion;
        GLuint textura;
        GLuint cargarTextura(const char* nombreArchivo);




    private:
};

#endif // PACMAN_H
