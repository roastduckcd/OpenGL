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

    GLfloat step = 0.025;
    if(key == GLUT_KEY_UP) {
        
    }

    if(key == GLUT_KEY_DOWN) {

    }

    if(key == GLUT_KEY_LEFT) {

    }

    if(key == GLUT_KEY_RIGHT) {
        
    }
    // 手动调用
    glutPostRedisplay();
}
