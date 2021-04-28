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

void Canvas::add(int x, int y, RGBColor color) {
    if (GlobalVar::checkWidth(x) && GlobalVar::checkHeight(y)){
//        points.back().push_back(Point(x, y));
        points.back().push_back(make_pair(Point(x, y), color));
        screen[x][y] = color;
    }
}

RGBColor Canvas::getPixel(int x, int y) {
    return screen[x][y];
}

void Canvas::initNewObj() {
    points.push_back(vector<pair<Point, RGBColor> >());
//    points.push_back(vector<Point>());
}

void Canvas::clear() {
    for (int i=0;i<points.size();++i)
    points[i].clear();
    points.clear();
    
    for (int i=0;i<screen.size();++i)
    screen[i].clear();
    screen.clear();

    screen.resize(width, vector<RGBColor>(height, 0));
}

void Canvas::add(const Canvas& src) {
    if (src.points.size() == 0) return;
    
    points.push_back(src.points.back());
    for (int i=0; i<src.points.back().size(); ++i) {
        screen[src.points.back()[i].fi.getX()][src.points.back()[i].fi.getY()] = src.points.back()[i].se;
    }
}

void Canvas::putPixel(int x, int y, RGBColor color) {
//    glBegin(GL_POINTS);
//    glVertex2i(x, y);
//    glEnd();
    unsigned char * ptr = new unsigned char[3];
    ptr[0] = color.r;
    ptr[1] = color.g;
    ptr[2] = color.b;

    glRasterPos2i(x, y);
    glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);
    delete[] ptr;
}

void Canvas::fillColor(int x, int y, RGBColor color) {
    const RGBColor clicked = getPixel(x, y);
    if (clicked == color) return;

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    queue <pair<int, int> > q;
    pair<int, int> u, v;
    RGBColor cur;

    q.push(make_pair(x, y));

    while (q.size()) {
        u = q.front();
        q.pop();

        cur = getPixel(u.fi, u.se);

        if (cur == clicked && cur != color) {
            putPixel(u.fi, u.se, color);
            add(u.fi, u.se, color);

            for (int i=0;i<4;++i) {
                v = make_pair(u.fi + dx[i], u.se + dy[i]);

                if (GlobalVar::checkWidth(v.fi) && GlobalVar::checkHeight(v.se)) {
                    q.push(v);
                }
            }

        }
    }
}

void Canvas::drawScreen() {
    for (int i=0; i < points.size(); ++i) {
        for (int j=0; j< points[i].size(); ++j) {
            putPixel(points[i][j].fi.getX(), points[i][j].fi.getY(), points[i][j].se);
//            putPixel(points[i][j].getX(), points[i][j].getY());
        }
    }
}

void Canvas::clearScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
}
