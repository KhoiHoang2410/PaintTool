//
//  Canvas.hpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifndef Canvas_hpp
#define Canvas_hpp

#include "Point.hpp"
#include "RBGColor.hpp"
#include <vector>
using namespace std;

class Canvas {
private:
    //vector<vector<pair<Point, RGBColor> > > points;
    vector<vector<Point> > points;
    vector<vector<RGBColor> > screen;
    int width, height;
public:
    Canvas();
    
    void clearScreen();
    
    RGBColor getPixel(int x, int y);
    void putPixel(int x, int y, RGBColor color = RGBColor());
    void add(int x, int y, RGBColor color = RGBColor());
    
    void fillColor(int x, int y, RGBColor color);
    
    void add(const Canvas& src);
    void drawScreen();
    
    void generateLine(Point a, Point b);
    void generateCircle(Point a, Point b);
    void generateElippse(Point a, Point b);
    
    void generateRightTriangle(Point a, Point b);
    void generateEquilateralTriangle(Point a, Point b);
    
    void generateRectangle(Point a, Point b);
    void generateSquare(Point a, Point b);
    
    void initNewObj();
    
    void clear();
};

#endif /* Canvas_hpp */

