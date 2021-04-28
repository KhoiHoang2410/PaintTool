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
#include <GLUT/GLUT.h>
#include <queue>

using namespace std;

Canvas::Canvas() {
    clear();
    this->width = GlobalVar::getWidth();
    this->height = GlobalVar::getHeight();
}

void Canvas::add(int x, int y) {
    if (GlobalVar::checkWidth(x) && GlobalVar::checkHeight(y)){
        points.back().push_back(Point(x, y));
    }
}

void Canvas::initNewObj() {
    points.push_back(vector<Point>());
}

void Canvas::clear() {
    for (int i=0;i<points.size();++i)
    points[i].clear();
    points.clear();
}

void Canvas::add(const Canvas& src) {
    if (src.points.size() == 0) return;
    
    points.push_back(src.points.back());
}

void Canvas::putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void Canvas::drawScreen() {
    for (int i=0; i < points.size(); ++i) {
        for (int j=0; j< points[i].size(); ++j) {
            putPixel(points[i][j].getX(), points[i][j].getY());
        }
    }
}

void Canvas::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}
