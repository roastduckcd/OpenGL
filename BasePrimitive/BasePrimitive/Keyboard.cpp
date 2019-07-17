//
//  Keyboard.cpp
//  BasePrimitive
//
//  Created by yang song on 2019/6/2.
//  Copyright © 2019 yangsong. All rights reserved.
//

#include "Keyboard.hpp"
#include "Vertices.hpp"

#define GLUT_KEY_SPACE 32

// c++ 不能卸载h文件
GLenum primi;

void specialKeyAction(int key, int x, int y) {

    int count = 0;
    GLfloat *vertices = getVertices(&count);

    GLfloat step = 0.25;
    if(key == GLUT_KEY_RIGHT) {
        vertices[0] += step;
        vertices[3] += step;
        vertices[6] += step;
    }

    if(key == GLUT_KEY_DOWN) {
        vertices[1] -= step;
        vertices[4] -= step;
        vertices[7] -= step;
    }

    if(key == GLUT_KEY_LEFT) {
        vertices[0] -= step;
        vertices[3] -= step;
        vertices[6] -= step;
    }

    if(key == GLUT_KEY_UP) {
        vertices[1] += step;
        vertices[4] += step;
        vertices[7] += step;
    }
    setupVertexData(&pointBatch, primi);
    // 手动调用
    glutPostRedisplay();
}

static int step = -1;

void asciiKeyAction(unsigned char key, int x, int y) {
    if (GLUT_KEY_SPACE == key) {
        step >= 4 ? step = 0 : step ++;
    }
    switch (step) {
        case 0:
            primi = GL_POINTS;
            glutSetWindowTitle("point");
            glPointSize(5);
            break;
        case 1:
            primi = GL_LINES;
            glutSetWindowTitle("lines");
            glLineWidth(4);
            break;
        case 2:
            primi = GL_LINE_LOOP;
            glutSetWindowTitle("line_loop");
            glLineWidth(4);
            break;
        case 3:
            primi = GL_LINE_STRIP;
            glutSetWindowTitle("line_strip");
            glLineWidth(4);
            break;
        case 4:
            primi = GL_TRIANGLES;
            glutSetWindowTitle("triangle");
            glLineWidth(4);
            break;
        default:
            break;
    }
    setupVertexData(&pointBatch, primi);
    glutPostRedisplay();
}
