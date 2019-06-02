//
//  Vertices.cpp
//  BasePrimitive
//
//  Created by yang song on 2019/6/2.
//  Copyright © 2019 yangsong. All rights reserved.
//

#include "Vertices.hpp"


void setupVertexData(GLBatch *batch) {
    GLfloat vertexes[] = {
        0.5, 0, 0,
        0, 0.5, 0,
        0, 0, 0.5,
    };
    glPointSize(5);
        // 指定渲染的图元方式和顶点数量（x,y,z）为一个顶点
        //    pointBatch.Begin(GL_POINTS, 3);
    batch -> Begin(GL_LINE_LOOP, 3);
        // 复制顶点数据，处理成向量顶点的形式
   batch -> CopyVertexData3f(vertexes);
        // 结束处理，和begin成套
    batch -> End();
}
