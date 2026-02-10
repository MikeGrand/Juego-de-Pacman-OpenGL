# Juego-de-Pacman-OpenGL
Este proyecto es una implementación del clásico juego Pacman, desarrollada en C++ utilizando OpenGL y GLUT.
El programa renderiza un laberinto 2D mediante primitivas gráficas, controla el movimiento del jugador con teclado y simula el comportamiento de múltiples fantasmas usando una matriz de adyacencia para la navegación del mapa.

El objetivo principal del proyecto es aplicar conceptos de gráficos por computadora, programación orientada a objetos y lógica de movimiento en videojuegos.

## Características

- Renderizado 2D del laberinto usando OpenGL

- Movimiento del jugador (Pacman) controlado por teclado

- Implementación de 4 fantasmas con comportamiento automático

- Sistema de intersecciones basado en una matriz de adyacencia

- Carga y uso de texturas BMP mediante la clase RgbImage

## Separación del código en clases (Pacman, Fantasma)

## Controles
Tecla	Acción
W	Mover arriba
A	Mover izquierda
S	Mover abajo
D	Mover derecha

## Estructura del proyecto

main.cpp
Inicializa OpenGL, carga texturas, dibuja el laberinto y controla el ciclo principal del juego.

Pacman.h / Pacman.cpp
Maneja la lógica, movimiento y renderizado del jugador.

Fantasma.h / Fantasma.cpp
Implementa el comportamiento automático de los enemigos.

RgbImage.h / RgbImage.cpp
Permite cargar imágenes BMP como texturas OpenGL.

Archivos .bmp
Texturas utilizadas para Pacman y los fantasmas.

## Tecnologías utilizadas

- Lenguaje: C++

- Gráficos: OpenGL

- Librería de ventanas: GLUT

- Imágenes: BMP

## Contexto académico

Proyecto desarrollado como trabajo académico / parcial, enfocado en el aprendizaje de:

Renderizado gráfico 2D

Manejo de eventos por teclado

Programación orientada a objetos

Lógica básica de inteligencia artificial en videojuegos

## Requisitos

Compilador C++

OpenGL

GLUT (FreeGLUT recomendado)

## Ejecución

Compilar y ejecutar el proyecto desde un entorno compatible con OpenGL y GLUT.
Asegurarse de que los archivos .bmp se encuentren en el mismo directorio que el ejecutable.
