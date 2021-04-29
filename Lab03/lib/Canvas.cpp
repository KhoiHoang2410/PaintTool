//
//  Canvas.cpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif

#define fi first
#define se second

#include "Canvas.hpp"
#include "GlobalVar.hpp"
#include "Matrix.hpp"
#include <GLUT/GLUT.h>
#include <queue>

using namespace std;

Canvas::Canvas() {
    clear();
    this->width = GlobalVar::getWidth();
    this->height = GlobalVar::getHeight();
}

void Canvas::initNewObj(int type) {
    objects.push_back(make_pair(type, vector<Point>()));
}

void Canvas::clear() {
    for (int i=0;i<objects.size();++i)
        objects[i].se.clear();
    objects.clear();
}

void Canvas::add(double x, double y) {
    objects.back().se.push_back(Point(x, y));
}

void Canvas::add(const Canvas& src) {
    if (src.objects.size() == 0) return;
    
    objects.push_back(src.objects.back());
}

void Canvas::putPixel(double x, double y) {
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

void Canvas::drawScreen() {
    for (int i=0; i<objects.size(); ++i) {
        switch (objects[i].fi) {
            case FREESTYLE:
                for (int j=1; j<objects[i].se.size(); ++j)
                    generateLine(objects[i].se[j-1], objects[i].se[j]);
                
                generateLine(objects[i].se[0], objects[i].se.back());
                break;
            case PENCIL:
                for (int j=0; j<objects[i].se.size(); ++j)
                    putPixel(objects[i].se[j].getX(), objects[i].se[j].getY());
                break;
            case LINE:
                generateLine(objects[i].se[0], objects[i].se[1]);
                break;
                
            case CIRCLE:
                generateCircle(objects[i].se[0], objects[i].se[1]);
                break;
          
            case ELIPPSE:
                generateElippse(objects[i].se[0], objects[i].se[1]);
                break;
                
            case RIGHT_TRIANGLE:
                generateRightTriangle(objects[i].se[0], objects[i].se[1]);
                break;
                
            case EQUILATERAL_TRIANGLE:
                generateEquilateralTriangle(objects[i].se[0], objects[i].se[1]);
                break;
                
            case RECTANGLE:
                generateRectangle(objects[i].se[0], objects[i].se[1]);
                break;
                
            case SQUARE:
                generateSquare(objects[i].se[0], objects[i].se[1]);
                break;
                
            default:
                break;
        }
    }
}

void Canvas::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}

Point Canvas::pivot(int id) {
    if (id == -1) {
        if (objects.empty()) {
            exit(0);
        }
        id = (int) objects.size() - 1;
    }
    
    Point res = Point(0, 0);
    for (int i=0;i<objects[id].se.size();++i)
        res = res + objects[id].se[i];
    
    return res / (double) objects[id].se.size();
}

void Canvas::moveUp(int id) {
    if (id == -1) {
        if (objects.empty()) return;
        id = (int) objects.size() - 1;
    }
    
    for (int i=0; i < objects[id].se.size(); ++i) {
        objects[id].se[i] += Point(0, 5);
    }
}

void Canvas::moveDown(int id) {
    if (id == -1) {
        if (objects.empty()) return;
        id = (int) objects.size() - 1;
    }
    
    for (int i=0; i < objects[id].se.size(); ++i) {
        objects[id].se[i] += Point(0, -5);
    }
}

void Canvas::moveLeft(int id) {
    if (id == -1) {
        if (objects.empty()) return;
        id = (int) objects.size() - 1;
    }
    
    for (int i=0; i < objects[id].se.size(); ++i) {
        objects[id].se[i] += Point(-5, 0);
    }
}

void Canvas::moveRight(int id) {
    if (id == -1) {
        if (objects.empty()) return;
        id = (int) objects.size() - 1;
    }
    
    for (int i=0; i < objects[id].se.size(); ++i) {
        objects[id].se[i] += Point(5, 0);
    }
}

void Canvas::scaleUp(int id) {
    if (id == -1) {
        if (objects.empty()) return;
        id = (int) objects.size() - 1;
    }
    
    Matrix pv = pivot(id);
    for (int i=0; i < objects[id].se.size(); ++i) {
        Matrix tmp = Matrix(objects[id].se[i]) * Matrix(vector<double>{1.1, 0, 0, 1.1}, 2, 2) + pv * Matrix(vector<double>{1 - 1.1, 0, 0, 1 - 1.1}, 2, 2);;
        //objects[id].se[i] =
        //
    }
}

void Canvas::scaleDown(int id) {
    if (id == -1) {
        if (objects.empty()) return;
        id = (int) objects.size() - 1;
    }
}



