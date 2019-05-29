//
//  Primitive.cpp
//  BasePrimitive
//
//  Created by yang song on 2019/5/21.
//  Copyright © 2019 yangsong. All rights reserved.
//


#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#include "GLTools.h"

#include <GLUT/GLUT.h>


GLShaderManager shaderManager;


void renderSquare(void) {
        // 1.1 设置背景色
    glClearColor(255 / 255.0, 252 / 255.0, 235 / 255.0, 1);
        // 1.2 清空颜色、深度、模板换缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        // 1.3 设置颜色
    glColor4f(148 / 255.0, 65 / 255.0, 148 / 255.0, 1);
        // 1.4 设置坐标系 glOrtho
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1, 1);
        // 1.5 开始渲染 glbegin beginMode
        // 不同mode需要重新begin end
    glBegin(GL_LINE_LOOP);
        // 1.6 设置顶点（正方形，圆形，）
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
        // 1.7 结束渲染
    glEnd();
        // 1.8 刷新缓冲区
    glFlush();
}

void renderCircle(void) {
    // 1.1 设置背景色
    glClearColor(255 / 255.0, 252 / 255.0, 235 / 255.0, 1);
    // 1.2 清空颜色、深度、模板换缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    // 1.3 设置颜色
    glColor4f(148 / 255.0, 65 / 255.0, 148 / 255.0, 1);
    // 1.4 设置坐标系 glOrtho
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1, 1);
    // 1.5 开始渲染 glbegin beginMode
    // 不同mode需要重新begin end
    glBegin(GL_POLYGON);
    // 1.6 设置顶点（正方形，圆形，）
    GLfloat R = 0.5;
    for (int i=0; i<55; i++) {
        printf("%f - %f\n", M_PI, R * cos(i*100 / 360.0));
        glVertex2f(R * cos(i*100 / 360.0), R * sin(i*100 / 360.0));
    }
    // 1.7 结束渲染
    glEnd();
    // 1.8 刷新缓冲区
    glFlush();
}

void renderStar(void) {
        // 1.1 设置背景色
    glClearColor(255 / 255.0, 252 / 255.0, 235 / 255.0, 1);
        // 1.2 清空颜色、深度、模板换缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        // 1.3 设置颜色
    glColor4f(148 / 255.0, 65 / 255.0, 148 / 255.0, 1);
        // 1.4 设置坐标系 glOrtho
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1, 1);
        // 1.5 开始渲染 glbegin beginMode
        // 不同mode需要重新begin end
    glBegin(GL_LINE_LOOP);
        // 1.6 设置顶点（正方形，圆形，）
    GLfloat R = 0.5;
    // 正五边形
//    for (int i=0; i<5; i++) {
//        printf("%f - %f\n", M_PI, R * cos(i*72 / 360.0));
//        glVertex2f(R * cos(i*72*M_PI/ 180.0), R * sin(i*72*M_PI/ 180.0));
//    }
    // 正五角星
    glVertex2f(R * cos(3*72*M_PI/ 180.0), R * sin(3*72*M_PI/ 180.0));
    glVertex2f(R * cos(1*72*M_PI/ 180.0), R * sin(1*72*M_PI/ 180.0));
    glVertex2f(R * cos(4*72*M_PI/ 180.0), R * sin(4*72*M_PI/ 180.0));
    glVertex2f(R * cos(2*72*M_PI/ 180.0), R * sin(2*72*M_PI/ 180.0));
    glVertex2f(R * cos(5*72*M_PI/ 180.0), R * sin(5*72*M_PI/ 180.0));
    glVertex2f(R * cos(3*72*M_PI/ 180.0), R * sin(3*72*M_PI/ 180.0));
//    glVertex2f(R * cos(4*72*M_PI/ 180.0), R * sin(4*72*M_PI/ 180.0));
        // 1.7 结束渲染
    glEnd();
        // 1.8 刷新缓冲区
    glFlush();
}

int main (int argc, char *argv[]) {
    

    glutInit(&argc, argv);

    glutCreateWindow("primitive");

    glutDisplayFunc(renderStar);

    glutMainLoop();
    return 0;
}
