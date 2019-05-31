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

GLBatch pointBatch;
GLShaderManager shaderManager;

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
    shaderManager.InitializeStockShaders();
}

void render(void) {

    GLfloat rgbaColor[] = {1,0,0,1};
    // 指定着色器
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, rgbaColor);
    // 开始绘制
    pointBatch.Draw();
    // 交换缓冲区
    glutSwapBuffers();
}

void registerCallback(void) {
        // 注册渲染回调
    glutDisplayFunc(render);
}

void simplistPipeline(void) {
    glClear(GL_COLOR_BUFFER_BIT);
        // 设置坐标轴范围
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10, 10);
        // 指定渲染图形的颜色
    glColor4f(1, 0, 0, 1);
        // 设置点的大小
    glPointSize(5);
        // 设定图元样式为点
    glBegin(GL_POINTS);
        // 设定图元样式为环
//    glBegin(GL_LINE_LOOP);

    glVertex3f(3, 0, 0);
    glVertex3f(0, 3, 0);
    glVertex3f(0, 0, 3);
        // 随glBegin配套出现
    glEnd();
        // 强制刷新缓冲区
    glFlush();
        // 交换缓冲区
        //    glutSwapBuffers();
}

void setupVertexData() {
    GLfloat vertexes[] = {
        0.5, 0, 0,
        0, 0.5, 0,
        0, 0, 0.5,
    };
    glPointSize(5);
        // 指定渲染的图元方式和顶点数量（x,y,z）为一个顶点
//    pointBatch.Begin(GL_POINTS, 3);
    pointBatch.Begin(GL_LINE_LOOP, 3);
        // 复制顶点数据，处理成向量顶点的形式
    pointBatch.CopyVertexData3f(vertexes);
        // 结束处理，和begin成套
    pointBatch.End();
}


int main(int argc, char *argv[]) {
//    static_assert(false, "请修改 PublicOpenGLHeaderPath 为你的工程目录（include上一级目录）: $(SRCROOT)/工程名");

    prepareToRender(argc, argv);

    registerCallback();

//    simplistPipeline();
    setupVertexData();

        // 开启监听循环
    glutMainLoop();
    return 0;
}
