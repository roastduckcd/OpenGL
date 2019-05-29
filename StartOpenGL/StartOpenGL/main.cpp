//
//  main.cpp
//  StartOpenGL
//
//  Created by yang song on 2019/5/14.
//  Copyright © 2019 yangsong. All rights reserved.
//
#ifdef __APPLE__
    #include "TargetConditionals.h"
#endif

#include "GLTools.h"

//#include <GLUT/GLUT.h>
#include <glut/glut.h>

void menufunc(int);
void changeViewPort(int w, int h);
void render(void);
void interact(int, int, int);

// 着色器管理
GLShaderManager shaderManger;
// 批处理
GLBatch batchManger;
// 顶点数据
GLfloat vx = 0.2;
GLfloat vy = 0.5;
GLfloat vertex[] = {
    -vx, -vy, 0.0,
    -vx, vy, 0.0,
    vx, vy, 0.0,
    vx, -vy, 0.0
};

int main(int argc, char *argv[]) {

    // 设置工作目录
#ifdef _WIN32
    // 默认和可执行程序同目录
#elif __APPLE__
    #if TARGET_OS_MAC
        // 据说是 Resource 文件夹，实际仍是可执行文件路径，待测试
        gltSetWorkingDirectory(argv[0]);
    #endif
#endif

    // 初始化GLUT库，参数为 main 函数形参
    glutInit(&argc, argv);
    // 初始化显示模式
    glutInitDisplayMode(GLUT_RGBA);
    // 初始化窗口大小、标题
    glutInitWindowSize(800, 600);
    glutCreateWindow("三角形");
    glutCreateMenu(menufunc);
    // 注册回调函数
    // 1. 注册重塑回调：窗口 frame 改变则触发自定义函数
    glutReshapeFunc(changeViewPort);
    // 2. 注册显示回调：屏幕变化或者主动渲染触发自定义函数
    glutDisplayFunc(render);
    // 3. 注册键盘输入回调：键盘输入触发自定义函数
    glutSpecialFunc(interact);
    // 初始化GLEW库，检查 api 是否可用
    GLenum ApiStatus = glewInit();
    if (GLEW_OK != ApiStatus) {
        printf("api 不可用");
        return 1;
    }
    // 设置渲染环境
    // 1.1 设置背景色
    glClearColor(255/255.0, 252/255.0, 235/255.0, 1);
    // 1.2 初始化着色管理器
    shaderManger.InitializeStockShaders();
    // 1.3 设置图形顶点数组：三角形，一位数组形式
//    GLfloat vertex[] = {
//        -0.2, -0.5, 0.0,
//        -0.2, 0.5, 0.0,
//        0.2, 0.5, 0.0,
//        0.2, -0.5, 0.0
//    };
    // 1.4 使用批处理处理顶点数据
    // 1.4.1 开始：设定图元类型，顶点数量
    batchManger.Begin(GL_QUADS, 4);
    // 1.4.2 复制顶点数据
    batchManger.CopyVertexData3f(vertex);
    // 1.4.3 结束
    batchManger.End();

    // 开启 GLUT loop 监听消息，类似 runloop
    glutMainLoop();
    return 0;

}

void menufunc(int a) {
    printf("%d", a);
}


/**
 窗口大小改变，视口成比例改变
    macOS 窗口坐标左下角为原点
 */
void changeViewPort(int w, int h) {
    // 修改 x， y ？？
    glViewport(0, 0, w, h);
}

void render(void) {
    // 清空缓冲区：颜色、深度、模板缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    // 颜色设置, 一维数组 rgba
    GLfloat rgba[] = {1.0, 0, 0.5, 1};
    // 使用shaderManger获取存储着色器，以默认笛卡尔坐标系着色
    shaderManger.UseStockShader(GLT_SHADER_IDENTITY, rgba);
    // 使用批处理提交着色器
    batchManger.Draw();
    // 使用双重缓冲
    glutSwapBuffers();
//    glFlush();
}


/**
 平移变换

 @param key 键盘触发事件
 @param x , y   center
 */
void interact(int key, int x, int y) {
    printf("%d-%d", x, y);
    GLfloat transition = 0.05;
    switch (key) {
        case GLUT_KEY_LEFT:
            vx -= transition;
            break;
        case GLUT_KEY_UP:
            vy += transition;
            break;
        case GLUT_KEY_RIGHT:
            vx += transition;
            break;
        case GLUT_KEY_DOWN:
            vy -= transition;
            break;
    }

    batchManger.CopyVertexData3f(vertex);

    glutPostRedisplay();
}
