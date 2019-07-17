//
//  Keyboard.hpp
//  BasePrimitive
//
//  Created by yang song on 2019/6/2.
//  Copyright © 2019 yangsong. All rights reserved.
//

#ifndef Keyboard_hpp
#define Keyboard_hpp

#include <stdio.h>
#include "GLTools.h"

extern GLBatch pointBatch;

void specialKeyAction(int key, int x, int y);
void asciiKeyAction(unsigned char key, int x, int y);


#endif /* Keyboard_hpp */
