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
    vector<pair<int, vector<Point> > > points;
    int width, height;
public:
    Canvas();
    
    void clearScreen();
    
    void putPixel(int x, int y);
    
    void add(int x, int y);
    void add(const Canvas& src);
    void drawScreen();
    
    Point pivot(int id = -1);
    
    void generateLine(Point a, Point b);
    void generateCircle(Point a, Point b);
    void generateElippse(Point a, Point b);
    
    void generateRightTriangle(Point a, Point b);
    void generateEquilateralTriangle(Point a, Point b);
    
    void generateRectangle(Point a, Point b);
    void generateSquare(Point a, Point b);
    
    void initNewObj(int type);
    
    void clear();
};

#endif /* Canvas_hpp */

