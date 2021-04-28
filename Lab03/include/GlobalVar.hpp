//
//  GlobalVar.hpp
//  Lab03_1
//
//  Created by Nguyen-Khoi Hoang on 20/04/2021.
//

#ifndef GlobalVar_hpp
#define GlobalVar_hpp

#include <string>
#include "Point.hpp"
using namespace std;

enum MENU {CLEAR, QUIT, LINE, CIRCLE, ELIPPSE,
    RIGHT_TRIANGLE, EQUILATERAL_TRIANGLE,
    SQUARE, RECTANGLE,
    FREESTYLE
};

class GlobalVar {
private:
    inline static int width = 640, height = 480;
    inline static string windowName = "HNKhoi-18125038";
    inline static string testFileName = "test.txt";
    inline static bool isFirstTimeFreeStyle = 1;
public:
    inline static bool isHoldLeft = 0, isFinishHoldLeft = 0, isFinishHoldRight = 0;
    inline static Point Ppre, Pcur;
    inline static int idTitle;

    static void setWidth(int w);
    static void setHeight(int h);
    static void setResolution(int w, int h);
    static void setWindowName(string name);
    
    static bool checkWidth(int center, int range);
    static bool checkHeight(int center, int range);
    static bool checkWidth(int center);
    static bool checkHeight(int center);
    
    static int getWidth();
    static int getHeight();
    static string getWindowName();
    static string getTestFileName();
    
    static double getPi();
    
    static Point getMiddle();
    
    static void mouseFunc(int button, int state, int x, int y);
    static void motionFunc (int x, int y);
    
    static void menu(int num);

    static void createMenu();
};

#endif /* GlobalVar_hpp */
