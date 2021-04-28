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

int window_id, preMenu;
Canvas base, newObj;
bool isFirstTime = 1;
Point ptmp1, ptmp2;

void Render();
void keyboardUpFunc(unsigned char key, int x, int y);
void ProcessDraw(int type);

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
    
    preMenu = GlobalVar::idTitle;
    
    glutMainLoop();
        
    return 0;
}

void Render() {
    if (preMenu == PENCIL && preMenu != GlobalVar::idTitle) {
        isFirstTime = 1;
        GlobalVar::isFinishHoldLeft = 0;
    }
    
    preMenu = GlobalVar::idTitle;

    if (GlobalVar::isFinishHoldLeft && GlobalVar::idTitle != FREESTYLE && GlobalVar::idTitle != PENCIL) {
        GlobalVar::isFinishHoldLeft = 0;
        base.add(newObj);
    }
        
    switch (GlobalVar::idTitle) {
        case FREESTYLE:
            if (GlobalVar::isFinishHoldRight) {
                GlobalVar::isFinishHoldRight = 0;
                GlobalVar::createMenu();
                isFirstTime = 1;
                base.generateLine(ptmp1, ptmp2);
                break;
            }
    
            if (GlobalVar::isFinishHoldLeft) {
                GlobalVar::isFinishHoldLeft = 0;
                if (isFirstTime) {
                    base.initNewObj(FREESTYLE);
                    isFirstTime = 0;
                    glutDetachMenu(GLUT_RIGHT_BUTTON);
                    ptmp1 = GlobalVar::Pcur;
                }
                ptmp2 = GlobalVar::Pcur;
                base.generateLine(GlobalVar::Ppre, GlobalVar::Pcur);
                base.add(GlobalVar::Pcur.getX(), GlobalVar::Pcur.getY());
            }
            
            break;
        case PENCIL:
            if (GlobalVar::isHoldLeft) {
                if (isFirstTime) {
                    isFirstTime = 0;
                    base.initNewObj(PENCIL);
                }
                
                base.add(GlobalVar::Pcur.getX(), GlobalVar::Pcur.getY());
                base.putPixel(GlobalVar::Pcur.getX(), GlobalVar::Pcur.getY());
            }
            break;
        case LINE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(LINE);
            }

            break;
        case CIRCLE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(CIRCLE);
            }

            break;
        case ELIPPSE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(ELIPPSE);
            }

            break;
        case RIGHT_TRIANGLE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(RIGHT_TRIANGLE);
            }
            
            break;
        case EQUILATERAL_TRIANGLE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(EQUILATERAL_TRIANGLE);
            }
            
            break;
        case RECTANGLE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(RECTANGLE);
            }

            break;
        case SQUARE:
            if (GlobalVar::isHoldLeft) {
                ProcessDraw(SQUARE);
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

void ProcessDraw(int type) {
    newObj.clear();
    newObj.initNewObj(type);
    newObj.add(GlobalVar::Ppre.getX(), GlobalVar::Ppre.getY());
    newObj.add(GlobalVar::Pcur.getX(), GlobalVar::Pcur.getY());

    base.clearScreen();
    base.drawScreen();
    newObj.drawScreen();
}

void keyboardUpFunc(unsigned char key, int x, int y) {
    
}
