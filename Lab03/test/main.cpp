//
//  main.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#include "Canvas.hpp"
#include "GlobalVar.hpp"
#include <GLUT/GLUT.h>
#include <stdio.h>
using namespace std;

int window_id;
Canvas base, newObj;
bool isFirstTime = 1;
Point ptmp1, ptmp2;

void Render();
void keyboardUpFunc(unsigned char key, int x, int y);

int main(int argc, char** argv) {
    freopen("output.txt", "w", stdout);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(GlobalVar::getWidth(), GlobalVar::getHeight());
    glutInitWindowPosition(100, 100);
    window_id = glutCreateWindow(GlobalVar::getWindowName().c_str());
    GlobalVar::createMenu();
    
    gluOrtho2D(0.0, GlobalVar::getWidth(), 0.0, GlobalVar::getHeight());
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glutMouseFunc(GlobalVar::mouseFunc);
    glutMotionFunc(GlobalVar::motionFunc);
    
    glutKeyboardUpFunc(keyboardUpFunc);
    
    glutDisplayFunc(&Render);
    glutMainLoop();
        
    return 0;
}

void Render() {
    if (GlobalVar::isFinishHoldLeft && GlobalVar::idTitle != FREESTYLE) {
        GlobalVar::isFinishHoldLeft = 0;
        base.initNewObj();
        base.add(newObj);
    }
    
    newObj.clear();
    
    switch (GlobalVar::idTitle) {
        case FREESTYLE:
            if (GlobalVar::isFinishHoldRight) {
                GlobalVar::createMenu();
                GlobalVar::isFinishHoldRight = 0;
                isFirstTime = 1;
                base.generateLine(ptmp1, ptmp2);
                base.drawScreen();
                break;
            }
    
            if (GlobalVar::isFinishHoldLeft) {
                GlobalVar::isFinishHoldLeft = 0;
                if (isFirstTime) {
                    base.initNewObj();
                    isFirstTime = 0;
                    glutDetachMenu(GLUT_RIGHT_BUTTON);
                    ptmp1 = GlobalVar::Pcur;
                }
                ptmp2 = GlobalVar::Pcur;
                base.generateLine(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
            }
            
            break;
        case LINE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateLine(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }

            break;
        case CIRCLE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateCircle(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }

            break;
        case ELIPPSE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateElippse(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }

            break;
        case RIGHT_TRIANGLE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateRightTriangle(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }
            
            break;
        case EQUILATERAL_TRIANGLE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateEquilateralTriangle(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }
            
            break;
        case RECTANGLE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateRectangle(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }

            break;
        case SQUARE:
            if (GlobalVar::isHoldLeft) {
                base.clearScreen();
                newObj.initNewObj();
                newObj.generateSquare(GlobalVar::Ppre, GlobalVar::Pcur);
                base.drawScreen();
                newObj.drawScreen();
            }
            break;
        case CLEAR:
            base.clear();
            base.clearScreen();
            break;
        case QUIT:
            base.clear();
            glutDestroyMenu(window_id);
            exit(0);
        default:
            break;
    }
    glFlush();
}
