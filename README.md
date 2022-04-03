This is an Paint Tool written by C++

Main feature
- Pencil: draw freeway
- Free style: application connect every dots by left click. Using right click to end the action, it will connect the first and last dot together
- Line: Press to draw a line
- Triange: Support to draw `Right triangle` and `Equilateral triangle`
- Quadrilateral: Support to draw `Square` and `Rectangle`
- Oval: Support to draw `circle` and `Elipse`

After draw an object
- User can press `L` or `R` to rotate the object
- Press `-` or `+` to zoom the object

Programme OS
- MacOS

To execute the program
- Run `g++ -std=c++17 -framework GLUT -framework OpenGL lib/*.cpp main.cpp && ./a.out`
