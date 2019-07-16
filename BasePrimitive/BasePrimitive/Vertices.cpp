//
//  Vertices.cpp
//  BasePrimitive
//
//  Created by yang song on 2019/6/2.
//  Copyright © 2019 yangsong. All rights reserved.
//

#include "Vertices.hpp"


GLfloat *getVertices(int *count) {
    static GLfloat vertices[] = {
        -0.5, 0, 0,
        0, 0.5, 0,
        0, 0, 0.5,
    };
    *count = sizeof(vertices) / sizeof(vertices[0]);
    // Address of stack memory associated with local variable
    // 如果 vertices 为临时变量在栈，出作用域被释放掉
    
    return vertices;
}


void setupVertexData(GLBatch *batch) {
    
    glPointSize(5);

    int count = 0;
    GLfloat *vertices = getVertices(&count);
    // 指定渲染的图元方式和顶点数量（x,y,z）为一个顶点
//    pointBatch.Begin(GL_POINTS, 3);
//    batch -> Begin(GL_LINE_LOOP, 3);
    batch -> Begin(GL_TRIANGLES, count);
    // 复制顶点数据，处理成向量顶点的形式
    batch -> CopyVertexData3f(vertices);
    // 结束处理，和begin成套
    batch -> End();
}
