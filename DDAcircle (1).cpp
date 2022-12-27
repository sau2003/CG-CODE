#include <iostream>
#include <math.h>
#include <graphics.h>
 
// Function to put pixels
// at subsequence points

void DDA(int x1, int y1, int x2, int y2)
{
    // calculate dx & dy
    int dx = x2 - x1;
    int dy = y2 - y1;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float xinc = dx / (float) steps;
    float yinc = dy / (float) steps;
 
    // Put pixel for each step
    float x=x1;
    float y=y1;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (round(x),round(y),RED);  // put pixel at (X,Y)
        x += xinc;           // increment in x at each step
        y += yinc;           // increment in y at each step
               // for visualization of line-
                             // generation step by step
    }
     delay(500);
}
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}
 
// Function for circle-generation
// using Bresenham's algorithm
void circleBres(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (y >= x)
    {
        // for each pixel we will
        // draw all eight pixels
         
        x++;
 
        // check for decision parameter
        // and correspondingly
        // update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
            d = d + 4 * x + 6;
        drawCircle(xc, yc, x, y);
        delay(200);
    }
}
 
 
// Driver code
int main()
{
    int xc, yc, r;
    
  
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm,NULL);  // initialize graph
    circleBres(250,200,828);
    
        // function call
    int x1,y1,x2,y2;
    DDA(100,100,400,100);
    DDA(100,100,100,300);
    DDA(100,300,400,300);
    DDA(400,100,400,300);
    
    DDA(250,100,100,200);
    DDA(100,200,250,300);
    DDA(250,300,400,200);
    DDA(400,200,250,100);
    
    
    
    
    //DDA(
    closegraph();
    return 0;
    
}
