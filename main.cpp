#include <GL/glut.h>
#include <stdlib.h>
#include "Fantasma.h"
#include "Pacman.h"
#include "RgbImage.h"
#define NTextures 2 //se define la cantidad de texturas que se manejaran

GLuint	texture[NTextures];

int matAdy[10][11];
float Filas[450];
float Columnas[500];

Pacman pacman(10, 411, 50, 1);

Fantasma fantasma1(210, 171, 1, 1);
Fantasma fantasma2(186, 219, 1, 1);
Fantasma fantasma3(210, 219, 0, 1);
Fantasma fantasma4(234, 219, 3, 1);

void initMatAdy()
{
    int i;
    matAdy[0][0] = 10; matAdy[0][1] = -1; matAdy[0][2] = 50; matAdy[0][3] = -1; matAdy[0][4] = 30; matAdy[0][5] = -1; matAdy[0][6] = 10; matAdy[0][7] = -1; matAdy[0][8] = 50; matAdy[0][9] = -1; matAdy[0][10] = 30;
    matAdy[1][0] = 80; matAdy[1][1] = -1; matAdy[1][2] = 90; matAdy[1][3] = 50; matAdy[1][4] = 70; matAdy[1][5] = -1; matAdy[1][6] = 70; matAdy[1][7] = 50; matAdy[1][8] = 90; matAdy[1][9] = -1; matAdy[1][10] = 60;
    matAdy[2][0] = 20; matAdy[2][1] = -1; matAdy[2][2] = 60; matAdy[2][3] = 20; matAdy[2][4] = 30; matAdy[2][5] = -1; matAdy[2][6] = 10; matAdy[2][7] = 40; matAdy[2][8] = 80; matAdy[2][9] = -1; matAdy[2][10] = 40;
    matAdy[3][0] = -1; matAdy[3][1] = -1; matAdy[3][2] = -1; matAdy[3][3] = 10; matAdy[3][4] = 70; matAdy[3][5] = 5 ; matAdy[3][6] = 70; matAdy[3][7] = 30; matAdy[3][8] = -1; matAdy[3][9] = -1; matAdy[3][10] = -1;
    matAdy[4][0] = -1; matAdy[4][1] = -1; matAdy[4][2] = 80; matAdy[4][3] = 60; matAdy[4][4] = 6 ; matAdy[4][5] = 7 ; matAdy[4][6] = 8 ; matAdy[4][7] = 80; matAdy[4][8] = 60; matAdy[4][9] = -1; matAdy[4][10] = -1;
    matAdy[5][0] = -1; matAdy[5][1] = -1; matAdy[5][2] = -1; matAdy[5][3] = 80; matAdy[5][4] = -1; matAdy[5][5] = -1; matAdy[5][6] = -1; matAdy[5][7] = 60; matAdy[5][8] = -1; matAdy[5][9] = -1; matAdy[5][10] = -1;
    matAdy[6][0] = 10; matAdy[6][1] = -1; matAdy[6][2] = 90; matAdy[6][3] = 70; matAdy[6][4] = 30; matAdy[6][5] = -1; matAdy[6][6] = 10; matAdy[6][7] = 70; matAdy[6][8] = 90; matAdy[6][9] = -1; matAdy[6][10] = 30;
    matAdy[7][0] = 20; matAdy[7][1] = 30; matAdy[7][2] = 80; matAdy[7][3] = 50; matAdy[7][4] = 70; matAdy[7][5] = -1; matAdy[7][6] = 70; matAdy[7][7] = 50; matAdy[7][8] = 60; matAdy[7][9] = 10; matAdy[7][10] = 40;
    matAdy[8][0] = 10; matAdy[8][1] = 70; matAdy[8][2] = 40; matAdy[8][3] = 20; matAdy[8][4] = 30; matAdy[8][5] = -1; matAdy[8][6] = 10; matAdy[8][7] = 40; matAdy[8][8] = 20; matAdy[8][9] = 70; matAdy[8][10] = 30;
    matAdy[9][0] = 20; matAdy[9][1] = -1; matAdy[9][2] = -1; matAdy[9][3] = -1; matAdy[9][4] = 70; matAdy[9][5] = -1; matAdy[9][6] = 70; matAdy[9][7] = -1; matAdy[9][8] = -1; matAdy[9][9] = -1; matAdy[9][10] = 40;

    for(i = 0; i<447; i++){
        Filas[i] = -1.0;
    }
    for(i = 0; i<495; i++){
        Columnas[i] = -1.0;
    }
    Filas[10] = 0.0; Filas[42] = 1.0; Filas[90] = 2.0; Filas[138] = 3.0; Filas[186] = 4.0; Filas[210] = 5.0; Filas[234] = 6.0; Filas[282] = 7.0; Filas[330] = 8.0; Filas[378] = 9.0; Filas[410] = 10.0;
    Columnas[11] = 0.0; Columnas[75] = 1.0; Columnas[123] = 2.0; Columnas[171] = 3.0; Columnas[219] = 4.0; Columnas[267] = 5.0; Columnas[315] = 6.0; Columnas[363] = 7.0; Columnas[411] = 8.0; Columnas[459] = 9.0;
}

void init(void)
{
    initMatAdy();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,447,495,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void loadTextureFromFile(char *filename, int numImagen)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &texture[numImagen]);
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[numImagen]);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

void drawLaberinto() {

    glColor3f(1.0, 0.0, 0.0); // Color Rojo

    glLineWidth(3.0);

    glBegin(GL_LINES);

    glVertex2f(8, 1);       glVertex2f(439, 1); // Limite superior 1
    glVertex2f(439, 1);     glVertex2f(446, 8);

    glVertex2f(8, 1);
    glVertex2f(439, 1);

    glVertex2f(446, 8);     glVertex2f(446, 151);  // Limite derecho 1
    glVertex2f(446, 151);   glVertex2f(439, 158);
    glVertex2f(439, 158);   glVertex2f(368, 158);
    glVertex2f(368, 158);   glVertex2f(366, 160);
    glVertex2f(366, 160);   glVertex2f(366, 207);
    glVertex2f(366, 207);   glVertex2f(368, 209);
    glVertex2f(368, 209);   glVertex2f(439, 209);
    glVertex2f(439, 209);   glVertex2f(446, 216);
    glVertex2f(446, 216);   glVertex2f(446, 247);
    glVertex2f(446, 247);   glVertex2f(439, 254);
    glVertex2f(439, 254);   glVertex2f(368, 254);
    glVertex2f(368, 254);   glVertex2f(366, 256);
    glVertex2f(366, 256);   glVertex2f(366, 303);
    glVertex2f(366, 303);   glVertex2f(368, 305);
    glVertex2f(368, 305);   glVertex2f(439, 305);
    glVertex2f(439, 305);   glVertex2f(446, 312);
    glVertex2f(446, 312);   glVertex2f(446, 487);
    glVertex2f(446, 487);   glVertex2f(439, 494);

    glVertex2f(439, 494);   glVertex2f(8, 494); //Limite inferior 1
    glVertex2f(8, 494);     glVertex2f(1, 487);

    glVertex2f(1, 487);     glVertex2f(1, 312); //Limite izquierdo 1
    glVertex2f(1, 312);     glVertex2f(8, 305);
    glVertex2f(8, 305);     glVertex2f(79, 305);
    glVertex2f(79, 305);    glVertex2f(81, 303);
    glVertex2f(81, 303);    glVertex2f(81, 256);
    glVertex2f(81, 256);    glVertex2f(79, 254);
    glVertex2f(79, 254);    glVertex2f(8, 254);
    glVertex2f(8, 254);     glVertex2f(1, 247);
    glVertex2f(1, 247);     glVertex2f(1, 216);
    glVertex2f(1, 216);     glVertex2f(8, 209);
    glVertex2f(8, 209);     glVertex2f(79, 209);
    glVertex2f(79, 209);    glVertex2f(81, 207);
    glVertex2f(81, 207);    glVertex2f(81, 160);
    glVertex2f(81, 160);    glVertex2f(79, 158);
    glVertex2f(79, 158);    glVertex2f(8, 158);
    glVertex2f(8, 158);     glVertex2f(1, 151);
    glVertex2f(1, 151);     glVertex2f(1, 8);
    glVertex2f(1, 8);       glVertex2f(8, 1);

    glVertex2f(10, 7);      glVertex2f(213, 7); //Limite superior 2
    glVertex2f(213, 7);     glVertex2f(216, 10);
    glVertex2f(216, 10);    glVertex2f(216, 67);
    glVertex2f(216, 67);    glVertex2f(220, 71);
    glVertex2f(220, 71);    glVertex2f(227, 71);
    glVertex2f(227, 71);    glVertex2f(231, 67);
    glVertex2f(231, 67);    glVertex2f(231, 10);
    glVertex2f(231, 10);    glVertex2f(234, 7);
    glVertex2f(234, 7);     glVertex2f(437, 7);
    glVertex2f(437, 7);     glVertex2f(440, 10);

    glVertex2f(440, 10);    glVertex2f(440, 149); // Limite derecho 2
    glVertex2f(440, 149);   glVertex2f(437, 152);
    glVertex2f(437, 152);   glVertex2f(364, 152);
    glVertex2f(364, 152);   glVertex2f(360, 156);
    glVertex2f(360, 156);   glVertex2f(360, 211);
    glVertex2f(360, 211);   glVertex2f(364, 215);
    glVertex2f(364, 215);   glVertex2f(437, 215);
    glVertex2f(437, 215);   glVertex2f(440, 218);
    glVertex2f(440, 218);   glVertex2f(440, 245);
    glVertex2f(440, 245);   glVertex2f(437, 248);
    glVertex2f(437, 248);   glVertex2f(364, 248);
    glVertex2f(364, 248);   glVertex2f(360, 252);
    glVertex2f(360, 252);   glVertex2f(360, 307);
    glVertex2f(360, 307);   glVertex2f(364, 311);
    glVertex2f(364, 311);   glVertex2f(437, 311);
    glVertex2f(437, 311);   glVertex2f(440, 314);
    glVertex2f(440, 314);   glVertex2f(440, 389);
    glVertex2f(440, 389);   glVertex2f(437, 392);
    glVertex2f(437, 392);   glVertex2f(412, 392);
    glVertex2f(412, 392);   glVertex2f(408, 396);
    glVertex2f(408, 396);   glVertex2f(408, 403);
    glVertex2f(408, 403);   glVertex2f(412, 407);
    glVertex2f(412, 407);   glVertex2f(437, 407);
    glVertex2f(437, 407);   glVertex2f(440, 410);
    glVertex2f(440, 410);   glVertex2f(440, 485);
    glVertex2f(440, 485);   glVertex2f(437, 488);

    glVertex2f(437, 488);   glVertex2f(10, 488); //Limite inferior 2
    glVertex2f(10, 488);    glVertex2f(7, 485);

    glVertex2f(7, 485);     glVertex2f(7, 410); // Limite izquierdo 2
    glVertex2f(7, 410);     glVertex2f(10, 407);
    glVertex2f(10, 407);    glVertex2f(35, 407);
    glVertex2f(35, 407);    glVertex2f(39, 403);
    glVertex2f(39, 403);    glVertex2f(39, 396);
    glVertex2f(39, 396);    glVertex2f(35, 392);
    glVertex2f(35, 392);    glVertex2f(10, 392);
    glVertex2f(10, 392);    glVertex2f(7, 389);
    glVertex2f(7, 389);     glVertex2f(7, 314);
    glVertex2f(7, 314);     glVertex2f(10, 311);
    glVertex2f(10, 311);    glVertex2f(83, 311);
    glVertex2f(83, 311);    glVertex2f(87, 307);
    glVertex2f(87, 307);    glVertex2f(87, 252);
    glVertex2f(87, 252);    glVertex2f(83, 248);
    glVertex2f(83, 248);    glVertex2f(10, 248);
    glVertex2f(10, 248);    glVertex2f(7, 245);
    glVertex2f(7, 245);     glVertex2f(7, 218);
    glVertex2f(7, 218);     glVertex2f(10, 215);
    glVertex2f(10, 215);    glVertex2f(83, 215);
    glVertex2f(83, 215);    glVertex2f(87, 211);
    glVertex2f(87, 211);    glVertex2f(87, 156);
    glVertex2f(87, 156);    glVertex2f(83, 152);
    glVertex2f(83, 152);    glVertex2f(10, 152);
    glVertex2f(10, 152);    glVertex2f(7, 149);
    glVertex2f(7, 149);     glVertex2f(7, 10);
    glVertex2f(7, 10);      glVertex2f(10, 7);

    glColor3f(0.0, 1.0, 0.0); // Color verde

    glVertex2f(44, 41);     glVertex2f(83, 41); //Obstaculo 1
    glVertex2f(83, 41);     glVertex2f(86, 44);
    glVertex2f(86, 44);     glVertex2f(86, 67);
    glVertex2f(86, 67);     glVertex2f(83, 70);
    glVertex2f(83, 70);     glVertex2f(44, 70);
    glVertex2f(44, 70);     glVertex2f(41, 67);
    glVertex2f(41, 67);     glVertex2f(41, 44);
    glVertex2f(41, 44);     glVertex2f(44, 41);

    glVertex2f(124, 41);    glVertex2f(179, 41); //Obstaculo 2
    glVertex2f(179, 41);    glVertex2f(182, 44);
    glVertex2f(182, 44);    glVertex2f(182, 67);
    glVertex2f(182, 67);    glVertex2f(179, 70);
    glVertex2f(179, 70);    glVertex2f(124, 70);
    glVertex2f(124, 70);    glVertex2f(121, 67);
    glVertex2f(121, 67);    glVertex2f(121, 44);
    glVertex2f(121, 44);    glVertex2f(124, 41);

    glVertex2f(268, 41);    glVertex2f(323, 41); //Obstaculo 3
    glVertex2f(323, 41);    glVertex2f(326, 44);
    glVertex2f(326, 44);    glVertex2f(326, 67);
    glVertex2f(326, 67);    glVertex2f(323, 70);
    glVertex2f(323, 70);    glVertex2f(268, 70);
    glVertex2f(268, 70);    glVertex2f(265, 67);
    glVertex2f(265, 67);    glVertex2f(265, 44);
    glVertex2f(265, 44);    glVertex2f(268, 41);

    glVertex2f(364, 41);    glVertex2f(403, 41); //Obstaculo 4
    glVertex2f(403, 41);    glVertex2f(406, 44);
    glVertex2f(406, 44);    glVertex2f(406, 67);
    glVertex2f(406, 67);    glVertex2f(403, 70);
    glVertex2f(403, 70);    glVertex2f(364, 70);
    glVertex2f(364, 70);    glVertex2f(361, 67);
    glVertex2f(361, 67);    glVertex2f(361, 44);
    glVertex2f(361, 44);    glVertex2f(364, 41);

    glVertex2f(44, 105);    glVertex2f(83, 105); //Obstaculo 5
    glVertex2f(83, 105);    glVertex2f(86, 108);
    glVertex2f(86, 108);    glVertex2f(86, 115);
    glVertex2f(86, 115);    glVertex2f(83, 118);
    glVertex2f(83, 118);    glVertex2f(44, 118);
    glVertex2f(44, 118);    glVertex2f(41, 115);
    glVertex2f(41, 115);    glVertex2f(41, 108);
    glVertex2f(41, 108);    glVertex2f(44, 105);

    glVertex2f(124, 105);   glVertex2f(131, 105); //Obstaculo 6
    glVertex2f(131, 105);   glVertex2f(134, 108);
    glVertex2f(134, 108);   glVertex2f(134, 149);
    glVertex2f(134, 149);   glVertex2f(138, 153);
    glVertex2f(138, 153);   glVertex2f(179, 153);
    glVertex2f(179, 153);   glVertex2f(182, 156);
    glVertex2f(182, 156);   glVertex2f(182, 163);
    glVertex2f(182, 163);   glVertex2f(179, 166);
    glVertex2f(179, 166);   glVertex2f(138, 166);
    glVertex2f(138, 166);   glVertex2f(134, 170);
    glVertex2f(134, 170);   glVertex2f(134, 211);
    glVertex2f(134, 211);   glVertex2f(131, 214);
    glVertex2f(131, 214);   glVertex2f(124, 214);
    glVertex2f(124, 214);   glVertex2f(121, 211);
    glVertex2f(121, 211);   glVertex2f(121, 108);
    glVertex2f(121, 108);   glVertex2f(124, 105);

    glVertex2f(172, 105);   glVertex2f(275, 105); //Obstaculo 7
    glVertex2f(275, 105);   glVertex2f(278, 108);
    glVertex2f(278, 108);   glVertex2f(278, 115);
    glVertex2f(278, 115);   glVertex2f(275, 118);
    glVertex2f(275, 118);   glVertex2f(234, 118);
    glVertex2f(234, 118);   glVertex2f(230, 122);
    glVertex2f(230, 122);   glVertex2f(230, 163);
    glVertex2f(230, 163);   glVertex2f(227, 166);
    glVertex2f(227, 166);   glVertex2f(220, 166);
    glVertex2f(220, 166);   glVertex2f(217, 163);
    glVertex2f(217, 163);   glVertex2f(217, 122);
    glVertex2f(217, 122);   glVertex2f(213, 118);
    glVertex2f(213, 118);   glVertex2f(172, 118);
    glVertex2f(172, 118);   glVertex2f(169, 115);
    glVertex2f(169, 115);   glVertex2f(169, 108);
    glVertex2f(169, 108);   glVertex2f(172, 105);

    glVertex2f(316, 105);   glVertex2f(323, 105); //Obstaculo 8
    glVertex2f(323, 105);   glVertex2f(326, 108);
    glVertex2f(326, 108);   glVertex2f(326, 211);
    glVertex2f(326, 211);   glVertex2f(323, 214);
    glVertex2f(323, 214);   glVertex2f(316, 214);
    glVertex2f(316, 214);   glVertex2f(313, 211);
    glVertex2f(313, 211);   glVertex2f(313, 170);
    glVertex2f(313, 170);   glVertex2f(309, 166);
    glVertex2f(309, 166);   glVertex2f(268, 166);
    glVertex2f(268, 166);   glVertex2f(265, 163);
    glVertex2f(265, 163);   glVertex2f(265, 156);
    glVertex2f(265, 156);   glVertex2f(268, 153);
    glVertex2f(268, 153);   glVertex2f(309, 153);
    glVertex2f(309, 153);   glVertex2f(313, 149);
    glVertex2f(313, 149);   glVertex2f(313, 108);
    glVertex2f(313, 108);   glVertex2f(316, 105);

    glVertex2f(364, 105);   glVertex2f(403, 105); //Obstaculo 9
    glVertex2f(403, 105);   glVertex2f(406, 108);
    glVertex2f(406, 108);   glVertex2f(406, 115);
    glVertex2f(406, 115);   glVertex2f(403, 118);
    glVertex2f(403, 118);   glVertex2f(364, 118);
    glVertex2f(364, 118);   glVertex2f(361, 115);
    glVertex2f(361, 115);   glVertex2f(361, 108);
    glVertex2f(361, 108);   glVertex2f(364, 105);


    glVertex2f(124, 249);   glVertex2f(131, 249); //Obstaculo 10
    glVertex2f(131, 249);   glVertex2f(134, 252);
    glVertex2f(134, 252);   glVertex2f(134, 307);
    glVertex2f(134, 307);   glVertex2f(131, 310);
    glVertex2f(131, 310);   glVertex2f(124, 310);
    glVertex2f(124, 310);   glVertex2f(121, 307);
    glVertex2f(121, 307);   glVertex2f(121, 252);
    glVertex2f(121, 252);   glVertex2f(124, 249);

    glVertex2f(172, 297);   glVertex2f(275, 297); //Obstaculo 11
    glVertex2f(275, 297);   glVertex2f(278, 300);
    glVertex2f(278, 300);   glVertex2f(278, 307);
    glVertex2f(278, 307);   glVertex2f(275, 310);
    glVertex2f(275, 310);   glVertex2f(234, 310);
    glVertex2f(234, 310);   glVertex2f(230, 314);
    glVertex2f(230, 314);   glVertex2f(230, 355);
    glVertex2f(230, 355);   glVertex2f(227, 358);
    glVertex2f(227, 358);   glVertex2f(220, 358);
    glVertex2f(220, 358);   glVertex2f(217, 355);
    glVertex2f(217, 355);   glVertex2f(217, 314);
    glVertex2f(217, 314);   glVertex2f(213, 310);
    glVertex2f(213, 310);   glVertex2f(172, 310);
    glVertex2f(172, 310);   glVertex2f(169, 307);
    glVertex2f(169, 307);   glVertex2f(169, 300);
    glVertex2f(169, 300);   glVertex2f(172, 297);

    glVertex2f(316, 249);   glVertex2f(323, 249); //Obstaculo 12
    glVertex2f(323, 249);   glVertex2f(326, 252);
    glVertex2f(326, 252);   glVertex2f(326, 307);
    glVertex2f(326, 307);   glVertex2f(323, 310);
    glVertex2f(323, 310);   glVertex2f(316, 310);
    glVertex2f(316, 310);   glVertex2f(313, 307);
    glVertex2f(313, 307);   glVertex2f(313, 252);
    glVertex2f(313, 252);   glVertex2f(316, 249);

    glVertex2f(44, 345);    glVertex2f(83, 345); //Obstaculo 13
    glVertex2f(83, 345);    glVertex2f(86, 348);
    glVertex2f(86, 348);    glVertex2f(86, 403);
    glVertex2f(86, 403);    glVertex2f(83, 406);
    glVertex2f(83, 406);    glVertex2f(76, 406);
    glVertex2f(76, 406);    glVertex2f(73, 403);
    glVertex2f(73, 403);    glVertex2f(73, 362);
    glVertex2f(73, 362);    glVertex2f(69, 358);
    glVertex2f(69, 358);    glVertex2f(44, 358);
    glVertex2f(44, 358);    glVertex2f(41, 355);
    glVertex2f(41, 355);    glVertex2f(41, 348);
    glVertex2f(41, 348);    glVertex2f(44, 345);

    glVertex2f(124, 345);   glVertex2f(179, 345); //Obstaculo 14
    glVertex2f(179, 345);   glVertex2f(182, 348);
    glVertex2f(182, 348);   glVertex2f(182, 355);
    glVertex2f(182, 355);   glVertex2f(179, 358);
    glVertex2f(179, 358);   glVertex2f(124, 358);
    glVertex2f(124, 358);   glVertex2f(121, 355);
    glVertex2f(121, 355);   glVertex2f(121, 348);
    glVertex2f(121, 348);   glVertex2f(124, 345);

    glVertex2f(268, 345);   glVertex2f(323, 345); //Obstaculo 15
    glVertex2f(323, 345);   glVertex2f(326, 348);
    glVertex2f(326, 348);   glVertex2f(326, 355);
    glVertex2f(326, 355);   glVertex2f(323, 358);
    glVertex2f(323, 358);   glVertex2f(268, 358);
    glVertex2f(268, 358);   glVertex2f(265, 355);
    glVertex2f(265, 355);   glVertex2f(265, 348);
    glVertex2f(265, 348);   glVertex2f(268, 345);

    glVertex2f(364, 345);   glVertex2f(403, 345); //Obstaculo 16
    glVertex2f(403, 345);   glVertex2f(406, 348);
    glVertex2f(406, 348);   glVertex2f(406, 355);
    glVertex2f(406, 355);   glVertex2f(403, 358);
    glVertex2f(403, 358);   glVertex2f(378, 358);
    glVertex2f(378, 358);   glVertex2f(374, 362);
    glVertex2f(374, 362);   glVertex2f(374, 403);
    glVertex2f(374, 403);   glVertex2f(371, 406);
    glVertex2f(371, 406);   glVertex2f(364, 406);
    glVertex2f(364, 406);   glVertex2f(361, 403);
    glVertex2f(361, 403);   glVertex2f(361, 348);
    glVertex2f(361, 348);   glVertex2f(364, 345);

    glVertex2f(44, 441);    glVertex2f(117, 441); //Obstaculo 17
    glVertex2f(117, 441);   glVertex2f(121, 437);
    glVertex2f(121, 437);   glVertex2f(121, 396);
    glVertex2f(121, 396);   glVertex2f(124, 393);
    glVertex2f(124, 393);   glVertex2f(131, 393);
    glVertex2f(131, 393);   glVertex2f(134, 396);
    glVertex2f(134, 396);   glVertex2f(134, 437);
    glVertex2f(134, 437);   glVertex2f(138, 441);
    glVertex2f(138, 441);   glVertex2f(179, 441);
    glVertex2f(179, 441);   glVertex2f(182, 444);
    glVertex2f(182, 444);   glVertex2f(182, 451);
    glVertex2f(182, 451);   glVertex2f(179, 454);
    glVertex2f(179, 454);   glVertex2f(44, 454);
    glVertex2f(44, 454);    glVertex2f(41, 451);
    glVertex2f(41, 451);    glVertex2f(41, 444);
    glVertex2f(41, 444);    glVertex2f(44, 441);

    glVertex2f(172, 393);   glVertex2f(275, 393); //Obstaculo 18
    glVertex2f(275, 393);   glVertex2f(278, 396);
    glVertex2f(278, 396);   glVertex2f(278, 403);
    glVertex2f(278, 403);   glVertex2f(275, 406);
    glVertex2f(275, 406);   glVertex2f(234, 406);
    glVertex2f(234, 406);   glVertex2f(230, 410);
    glVertex2f(230, 410);   glVertex2f(230, 451);
    glVertex2f(230, 451);   glVertex2f(227, 454);
    glVertex2f(227, 454);   glVertex2f(220, 454);
    glVertex2f(220, 454);   glVertex2f(217, 451);
    glVertex2f(217, 451);   glVertex2f(217, 410);
    glVertex2f(217, 410);   glVertex2f(213, 406);
    glVertex2f(213, 406);   glVertex2f(172, 406);
    glVertex2f(172, 406);   glVertex2f(169, 403);
    glVertex2f(169, 403);   glVertex2f(169, 396);
    glVertex2f(169, 396);   glVertex2f(172, 393);

    glVertex2f(268, 441);   glVertex2f(309, 441); //Obstaculo 19
    glVertex2f(309, 441);   glVertex2f(313, 437);
    glVertex2f(313, 437);   glVertex2f(313, 396);
    glVertex2f(313, 396);   glVertex2f(316, 393);
    glVertex2f(316, 393);   glVertex2f(323, 393);
    glVertex2f(323, 393);   glVertex2f(326, 396);
    glVertex2f(326, 396);   glVertex2f(326, 437);
    glVertex2f(326, 437);   glVertex2f(330, 441);
    glVertex2f(330, 441);   glVertex2f(403, 441);
    glVertex2f(403, 441);   glVertex2f(406, 444);
    glVertex2f(406, 444);   glVertex2f(406, 451);
    glVertex2f(406, 451);   glVertex2f(403, 454);
    glVertex2f(403, 454);   glVertex2f(268, 454);
    glVertex2f(268, 454);   glVertex2f(265, 451);
    glVertex2f(265, 451);   glVertex2f(265, 444);
    glVertex2f(265, 444);   glVertex2f(268, 441);

    glColor3f(0.0, 0.0, 1.0);

    glVertex2f(169, 201);   glVertex2f(206, 201); //Obstaculo 20
    glVertex2f(206, 201);   glVertex2f(206, 206);
    glVertex2f(206, 206);   glVertex2f(174, 206);
    glVertex2f(174, 206);   glVertex2f(174, 257);
    glVertex2f(174, 257);   glVertex2f(273, 257);
    glVertex2f(273, 257);   glVertex2f(273, 206);
    glVertex2f(273, 206);   glVertex2f(241, 206);
    glVertex2f(241, 206);   glVertex2f(241, 201);
    glVertex2f(241, 201);   glVertex2f(278, 201);
    glVertex2f(278, 201);   glVertex2f(278, 262);
    glVertex2f(278, 262);   glVertex2f(169, 262);
    glVertex2f(169, 262);   glVertex2f(169, 201);

    glEnd();
        glColor3f (1,1,1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawLaberinto();

    glPushMatrix();
    pacman.MC(matAdy, Filas, Columnas);
    pacman.update();
    pacman.draw(texture[0]);
    glPopMatrix();

    glPushMatrix();
    fantasma1.MC(matAdy, Filas, Columnas);
    fantasma1.update();
    fantasma1.draw(texture[1]);
    glPopMatrix();

    glPushMatrix();
    fantasma2.MC(matAdy, Filas, Columnas);
    fantasma2.update();
    fantasma2.draw(texture[2]);
    glPopMatrix();

    glPushMatrix();
    fantasma3.MC(matAdy, Filas, Columnas);
    fantasma3.update();
    fantasma3.draw(texture[3]);
    glPopMatrix();

    glPushMatrix();
    fantasma4.MC(matAdy, Filas, Columnas);
    fantasma4.update();
    fantasma4.draw(texture[4]);
    glPopMatrix();

    glFlush();
    Sleep(7);
}


void key(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'w':
        pacman.guardarLastDireccion(0);
        break;
    case 'd':
        pacman.guardarLastDireccion(1);
        break;
    case 's':
        pacman.guardarLastDireccion(2);
        break;
    case 'a':
        pacman.guardarLastDireccion(3);
        break;
    }
}

void resizeWindow(int w, int h)
{
	float viewWidth = 2.0;
	float viewHeight = 2.0;
	glViewport(0, 0, w, h);
	h = (h==0) ? 1 : h;
	w = (w==0) ? 1 : w;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if ( h < w ) {
		viewWidth *= (float)w/(float)h;
	}
	else {
		viewHeight *= (float)h/(float)w;
	}
	glOrtho( -viewWidth, viewWidth, -viewHeight, viewHeight, -1.0, 1.0 );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

char* filename0 = "Pacman.bmp";
char* filename1 = "Fantasma1.bmp";
char* filename2 = "Fantasma2.bmp";
char* filename3 = "Fantasma3.bmp";
char* filename4 = "Fantasma4.bmp";

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(650, 700);
    glutCreateWindow("Pacman");

    loadTextureFromFile( filename0, 0 );
    loadTextureFromFile( filename1, 1 );
    loadTextureFromFile( filename2, 2 );
    loadTextureFromFile( filename3, 3 );
    loadTextureFromFile( filename4, 4 );

    init();
    glutDisplayFunc(display);
    glutIdleFunc(display); // Llamada a display cuando la app no está ocupada
    glutKeyboardFunc(key);
    glutMainLoop();

    return 0;
}
