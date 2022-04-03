//
//  Canvas.hpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifndef Canvas_hpp
#define Canvas_hpp

#include "Point.hpp"
#include <vector>
using namespace std;

class Canvas {
private:
    vector<pair<int, vector<Point> > > objects;
    int width, height;
public:
    Canvas();
    
    void clearScreen();
    void putPixel(double x, double y);
    void add(double x, double y);
    void add(const Canvas& src);
    void drawScreen();
    
    void initNewObj(int type);
    
    Point pivot(int id = -1);
    
    void generateLine(Point a, Point b);
    void generateCircle(Point a, Point b);
    void generateElippse(Point a, Point b);
    
    vector<Point> generateRightTriangle(Point a, Point b);
    vector<Point> generateEquilateralTriangle(Point a, Point b);
    
    vector<Point> generateRectangle(Point a, Point b);
    vector<Point> generateSquare(Point a, Point b);
    
    void moveUp(int id = -1);
    void moveDown(int id = -1);
    void moveLeft(int id = -1);
    void moveRight(int id = -1);
    
    void scaleUp(int id = -1);
    void scaleDown(int id = -1);
    
    void rotateLeft(int id = -1);
    void rotateRight(int id = -1);
    
    void clear();
};

#endif /* Canvas_hpp */

