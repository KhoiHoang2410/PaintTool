//
//  GlobalVar.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include <GLUT/GLUT.h>
#include "GlobalVar.hpp"
#include <math.h>

void GlobalVar::setWidth(int w) {
    width = w;
}

void GlobalVar::setHeight(int h) {
    height = h;
}

int GlobalVar::getWidth() {
    return width;
}

int GlobalVar::getHeight() {
    return height;
}

void GlobalVar::setResolution(int w, int h) {
    width = w;
    height = h;
}

string GlobalVar::getWindowName() {
    return windowName;
}

string GlobalVar::getTestFileName() {
    return testFileName;
}

void GlobalVar::setWindowName(std::string name) {
    windowName = name;
}

Point GlobalVar::getMiddle() {
    return Point(getWidth() / 2, getHeight() / 2);
}

double GlobalVar::getPi() {
    return acos(-1);
}

bool GlobalVar::checkWidth(int center, int range) {
    return 0 <= center - range || center + range < width;
}

bool GlobalVar::checkHeight(int center, int range) {
    return 0 <= center - range || center + range < height;
}

bool GlobalVar::checkWidth(int center) {
    return 0 <= center && center < width;
}

bool GlobalVar::checkHeight(int center){
    return 0 <= center && center < height;
}

void GlobalVar::mouseFunc(int button, int state, int x, int y) {
    if (idTitle == FREESTYLE) {
        if (button == GLUT_LEFT_BUTTON and state == GLUT_UP) {
            if (isFirstTimeFreeStyle) {
                Pcur = Ppre = Point(x, GlobalVar::getHeight() - y);
                isFirstTimeFreeStyle = 0;
            }
            else {
                Ppre = Pcur;
                Pcur = Point(x, GlobalVar::getHeight() - y);
            }
            isFinishHoldLeft = 1;
        }
        
        if (button == GLUT_RIGHT_BUTTON and state == GLUT_UP) {
            isFinishHoldRight = 1;
            isFirstTimeFreeStyle = 1;
        }
    }
    else {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            isHoldLeft = 1;
            Ppre = Pcur = Point(x, GlobalVar::getHeight() - y);
        }

        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            isFinishHoldLeft = 1;
            isHoldLeft = 0;
            Pcur = Point(x, GlobalVar::getHeight() - y);
        }
    }
    
    glutPostRedisplay();
}

void GlobalVar::motionFunc(int x, int y) {
    if (idTitle == FREESTYLE) return;
    Pcur = Point(x, GlobalVar::getHeight() - y);
    glutPostRedisplay();
}

void GlobalVar::menu(int num) {
    idTitle = num;
    glutPostRedisplay();
}

void GlobalVar::createMenu() {
    int triangle_id = glutCreateMenu(menu);
    glutAddMenuEntry("Right Triangle", RIGHT_TRIANGLE);
    glutAddMenuEntry("Equilateral Triangle", EQUILATERAL_TRIANGLE);
    
    int oval_id = glutCreateMenu(menu);
    glutAddMenuEntry("Circle", CIRCLE);
    glutAddMenuEntry("Elippse", ELIPPSE);
    
    int quadrilateral_id = glutCreateMenu(menu);
    glutAddMenuEntry("Square", SQUARE);
    glutAddMenuEntry("Rectangle", RECTANGLE);
    
    int color_id = glutCreateMenu(menu);
    glutAddMenuEntry("Red", RED);
    glutAddMenuEntry("Green", GREEN);
    glutAddMenuEntry("Blue", BLUE);
    
    int polygon_id = glutCreateMenu(menu);
    glutAddMenuEntry("Pentagon", PENTAGON);
    glutAddMenuEntry("Hexagon", HEXAGON);
    
    int menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Clear", CLEAR);
    glutAddMenuEntry("Pencil", PENCIL);
    glutAddMenuEntry("Free Style", FREESTYLE);
    glutAddMenuEntry("Line", LINE);
    glutAddSubMenu("Triangle", triangle_id);
    glutAddSubMenu("Quadrilateral", quadrilateral_id);
    glutAddSubMenu("Oval", oval_id);
    glutAddSubMenu("Polygon", polygon_id);
    glutAddSubMenu("Color", color_id);
    glutAddMenuEntry("Quit", QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
