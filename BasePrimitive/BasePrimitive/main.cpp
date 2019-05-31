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

void prepareToRender(int argc, char *argv[]) {
    // 设置工作空间，默认可执行文件目录
    gltSetWorkingDirectory(argv[0]);
    // 初始化窗口交互工具
    glutInit(&argc, argv);
    // 创建窗口
    glutInitWindowSize(800, 600);
    glutCreateWindow("base primitive");
    // 检查api可用性, 初始化上下文
    GLenum state = glewInit();
    if (GLEW_OK != state) {
        printf("api 不支持！\n");
    }
}

void render(void) {
}

void registerCallback(void) {
        // 注册渲染回调
    glutDisplayFunc(render);
}


int main(int argc, char *argv[]) {
//    static_assert(false, "请修改 PublicOpenGLHeaderPath 为你的工程目录（include上一级目录）: $(SRCROOT)/工程名");

    prepareToRender(argc, argv);

    registerCallback();
        // 开启监听循环
    glutMainLoop();
    return 0;
}
