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

void Canvas::initNewObj(int type) {
    points.push_back(make_pair(type, vector<Point>()));
}

void Canvas::clear() {
    for (int i=0;i<points.size();++i)
        points[i].se.clear();
    points.clear();
}

void Canvas::add(int x, int y) {
    points.back().se.push_back(Point(x, y));
    putPixel(x, y);
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
    for (int i=0; i<points.size(); ++i) {
        switch (points[i].fi) {
            case FREESTYLE:
                for (int )
                break;
                
            default:
                break;
        }
    }
}

void Canvas::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}
