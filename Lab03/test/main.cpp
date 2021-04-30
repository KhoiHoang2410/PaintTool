//
//  main.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "GlobalVar.hpp"
#include <GLUT/GLUT.h>
using namespace std;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(GlobalVar::width, GlobalVar::height);
    glutInitWindowPosition(100, 100);
    
    GlobalVar::window_id = glutCreateWindow(GlobalVar::windowName.c_str());
    GlobalVar::createMenu();
    
    gluOrtho2D(0.0, GlobalVar::width, 0.0, GlobalVar::height);
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutMouseFunc(GlobalVar::mouseFunc);
    glutMotionFunc(GlobalVar::motionFunc);
    
    glutKeyboardFunc(GlobalVar::keyboardFunc);
    glutSpecialFunc(GlobalVar::specialFunc);
    
    glutDisplayFunc(&GlobalVar::Render);
    
    glutMainLoop();
        
    return 0;
}
