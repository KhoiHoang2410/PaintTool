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
#include "Canvas.hpp"
using namespace std;

enum MENU {CLEAR, QUIT, LINE, CIRCLE, ELIPPSE,
    RIGHT_TRIANGLE, EQUILATERAL_TRIANGLE,
    SQUARE, RECTANGLE,
    FREESTYLE, PENCIL
};

class GlobalVar {
private:
    inline static bool isFirstTimeFreeStyle = 1;
public:
    inline static int width = 640, height = 480;
    inline static string windowName = "HNKhoi-18125038";
    
    inline static int window_id, idTitle;
    inline static Canvas base, newObj;
    inline static Point ptmp1, ptmp2, Ppre, Pcur;
    inline static bool isHoldLeft = 0, isFinishHoldLeft = 0, isFinishHoldRight = 0;
    inline static bool isRelease = 1, isFirstTime = 1;
    
    static bool checkWidth(int center, int range);
    static bool checkHeight(int center, int range);
    static bool checkWidth(int center);
    static bool checkHeight(int center);
        
    static double getPi();
    
    static Point getMiddle();
    
    static void mouseFunc(int button, int state, int x, int y);
    static void motionFunc (int x, int y);
    
    static void menu(int num);

    static void createMenu();
    
    static void Render();
    static void keyboardFunc(unsigned char key, int x, int y);
    static void specialFunc(int key, int x, int y);
    static void ProcessDraw(int type);
};

#endif /* GlobalVar_hpp */
