//
//  Vertices.hpp
//  BasePrimitive
//
//  Created by yang song on 2019/6/2.
//  Copyright © 2019 yangsong. All rights reserved.
//

#ifndef Vertices_hpp
#define Vertices_hpp

#include <stdio.h>

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#include "GLTools.h"
#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

GLfloat *getVertices(int *count);
void setupVertexData(GLBatch *batch);

#endif /* Vertices_hpp */
