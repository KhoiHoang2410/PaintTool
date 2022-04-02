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

Point GlobalVar::getMiddle() {
    return Point(width / 2., height / 2.);
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
        if (state == GLUT_DOWN) {
            isRelease = 0;
        }
        
        if (button == GLUT_LEFT_BUTTON and state == GLUT_UP) {
            isRelease = 1;
            
            if (isFirstTimeFreeStyle) {
                Pcur = Ppre = Point(x, GlobalVar::height - y);
                isFirstTimeFreeStyle = 0;
            }
            else {
                Ppre = Pcur;
                Pcur = Point(x, GlobalVar::height - y);
            }
            isFinishHoldLeft = 1;
        }
        
        if (button == GLUT_RIGHT_BUTTON and state == GLUT_UP) {
            isFinishHoldRight = 1;
            isFirstTimeFreeStyle = 1;
            isRelease = 1;
        }
    }
    else {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            isHoldLeft = 1;
            Ppre = Pcur = Point(x, GlobalVar::height - y);
            isRelease = 0;
        }

        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            if (idTitle != PENCIL)
                isFinishHoldLeft = 1;
            
            isHoldLeft = 0;
            Pcur = Point(x, GlobalVar::height - y);
            isRelease = 1;
        }
    }
    
    glutPostRedisplay();
}

void GlobalVar::motionFunc(int x, int y) {
    if (idTitle == FREESTYLE) return;
    Pcur = Point(x, GlobalVar::height - y);
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
    
    glutCreateMenu(menu);
    glutAddMenuEntry("Clear", CLEAR);
    glutAddMenuEntry("Pencil", PENCIL);
    glutAddMenuEntry("Free Style", FREESTYLE);
    glutAddMenuEntry("Line", LINE);
    glutAddSubMenu("Triangle", triangle_id);
    glutAddSubMenu("Quadrilateral", quadrilateral_id);
    glutAddSubMenu("Oval", oval_id);
    glutAddMenuEntry("Quit", QUIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void GlobalVar::Render() {
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
            if (isRelease) {
                base.initNewObj(PENCIL);
            }
            
            if (GlobalVar::isHoldLeft) {
                base.add(GlobalVar::Pcur.getX(), GlobalVar::Pcur.getY());
                base.drawScreen();
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
            glutDestroyMenu(windowID);
            exit(0);
        default:
            break;
    }
    glFlush();
}

void GlobalVar::ProcessDraw(int type) {
    newObj.clear();
    newObj.initNewObj(type);
    newObj.add(GlobalVar::Ppre.getX(), GlobalVar::Ppre.getY());
    newObj.add(GlobalVar::Pcur.getX(), GlobalVar::Pcur.getY());

    base.clearScreen();
    base.drawScreen();
    newObj.drawScreen();
}

void GlobalVar::keyboardFunc(unsigned char key, int x, int y) {
    if ('A' <= key && key <= 'Z') key -= 'A' - 'a';
    
    switch (key) {
        case '+':
            base.scaleUp();
            break;
        case '-':
            base.scaleDown();
            break;
        case 'l':
            base.rotateLeft();
            break;
        case 'r':
            base.rotateRight();
            break;
        default:
            return;
    }
    
    base.clearScreen();
    base.drawScreen();
    glFlush();
}

void GlobalVar::specialFunc(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            base.moveUp();
            break;
        case GLUT_KEY_DOWN:
            base.moveDown();
            break;
        case GLUT_KEY_LEFT:
            base.moveLeft();
            break;
        case GLUT_KEY_RIGHT:
            base.moveRight();
            break;
        default:
            return;
    }
    
    base.clearScreen();
    base.drawScreen();
    
    glFlush();
}
