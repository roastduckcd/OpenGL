//
//  Keyboard.cpp
//  BasePrimitive
//
//  Created by yang song on 2019/6/2.
//  Copyright © 2019 yangsong. All rights reserved.
//

#include "Keyboard.hpp"
#include "Vertices.hpp"



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
    setupVertexData(&pointBatch);
    // 手动调用
    glutPostRedisplay();
}
