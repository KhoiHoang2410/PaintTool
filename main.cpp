//
//  main.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "include/GlobalVar.hpp"
#include <GLUT/GLUT.h>
using namespace std;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(GlobalVar::width, GlobalVar::height);
    glutInitWindowPosition(100, 100);
    
    GlobalVar::windowID = glutCreateWindow(GlobalVar::windowName.c_str());
        
    glutMouseFunc(GlobalVar::mouseFunc);
    glutMotionFunc(GlobalVar::motionFunc);
    glutKeyboardFunc(GlobalVar::keyboardFunc);
    glutSpecialFunc(GlobalVar::specialFunc);
    glutDisplayFunc(&GlobalVar::Render);
    
    GlobalVar::createMenu();
    gluOrtho2D(0.0, GlobalVar::width, 0.0, GlobalVar::height);    
    glClear(GL_COLOR_BUFFER_BIT);

    glutMainLoop();
        
    return 0;
}
