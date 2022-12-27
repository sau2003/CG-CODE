/*#include<iostream>
#include<graphics.h>
#include<stdlib.h>
using namespace std;

class walkingman
{
    int rhx,rhy;
    public:
    void draw(int,int);
    void draw(int);
};

void walkingman::draw(int i)
{
    line(20,380,580,380);
    if(i%2)
    {
        line(25+i,380,35+i,340);
        line(45+i,380,35+i,340);
        line(35+i,310,25+i,330);
        delay(20);
    }
    else
    {
    line(35+i,340,35+i,310);
    line(35+i,310,40+i,330);
    delay(20);
    }
    line(35+i,340,35+i,310);
    circle(35+i,300,10);
    line(35+i,310,50+i,330);
    line(50+i,330,50+i,280);
    line(15+i,280,85+i,280);
    arc(50+i,280,0,180,35);
    arc(55+i,330,180,360,5);
    
}

void walkingman::draw(int x,int y)
{
    int j;
    rhx=x;
    rhy=y;
    for(j=0;j<100;j++)
    {
        
        setcolor(WHITE);
    }
}

int main()
{
    int gd=DETECT,gm;
    int rhx,rhy,j,i;
    walkingman obj;
    initgraph(&gd,&gm,NULL);
    for(i=0;i<500;i++)
    {
        obj.draw(i);
        rhx=getmaxx();
        rhy=getmaxy();
        obj.draw(rhx,rhy);
        delay(150);
        cleardevice();
    }
    getch();
}

#include<iostream>
#include<graphics.h>
using namespace std;

using namespace std;
class walkingman
{
int rhx,rhy;
public:
void draw(int,int);
void draw(int);
};
void walkingman::draw(int i)
{
line(20,380,580,380);
if(i%2)
{
line(25+i,380,35+i,340);
line(45+i,380,35+i,340);
line(35+i,310,25+i,330);
delay(20);
}
else
{
line(35+i,340,35+i,310);
line(35+i,310,40+i,330);
delay(20);
}
line(35+i,340,35+i,310);
circle(35+i,300,10);
line(35+i,310,50+i,330);
line(50+i,330,50+i,280);
line(15+i,280,85+i,280);
arc(50+i,280,0,180,35);
arc(55+i,330,180,360,5);
}
void walkingman::draw(int x,int y)
{
int j;
rhx=x;
rhy=y;
for
(j=0;j<100;j++)
{
outtextxy(rand()%rhx,rand()%(rhy-50));
setcolor(WHITE);
}
}
int main()
{
int gd=DETECT,gm;
int rhx,rhy,j,i;
walkingman obj;
initgraph(&gd,&gm,NULL);
for(i=0;i<500;i++)
{
obj.draw(i);
rhx=getmaxx();
rhy=getmaxy();
obj.draw(rhx,rhy);
delay(150);
cleardevice();
}
getch();
}

#include<stdio.h>
#include<iostream>
#include<graphics.h>
using namespace std;

#define ScreenWidthgetmaxx()
#define ScreenHeightgetmaxy()
#define GroundYScreenHeight*0.74
//Use *1 for full screen

int ldisp=0;

void DrawManAndUmbrella(int x,int ldisp)
{
//head
circle(x,GroundY-90,10);
line(x,GroundY-80,x,GroundY-30);
//hand
line(x,GroundY-70,x+10,GroundY-60);
line(x,GroundY-65,x+10,GroundY-55);
line(x+10,GroundY-60,x+20,GroundY-70);
line(x+10,GroundY-55,x+20,GroundY-70);
//legs
line(x,GroundY-30,x+ldisp,GroundY);
line(x,GroundY-30,x-ldisp,GroundY);
//umbrella
pieslice(x+20,GroundY-120,0,180,40);
line(x+20,GroundY-120,x+20,GroundY-70);
}

void Rain(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
rx=rand() % ScreenWidth;
ry=rand() % ScreenHeight;
if(ry<GroundY-4)
{
if(ry<GroundY-120 || (ry>GroundY-120 && (rx<x-20 || rx>x+60)))
line(rx,ry,rx+0.5,ry+4);
}
}
}
void main()
{
int gd=DETECT,gm,x=0;
 //Change BGI directory according to yours
initgraph(&gd,&gm,NULL);
//If you fill here (0) then you will show like flashlight
while(!kbhit())

{
  //Draw Ground
line(1, GroundY , ScreenWidth , GroundY);
Rain(x);
  // Increase value of(ldisp+4) for Fast moving leg
ldisp=(ldisp+4)%20;
DrawManAndUmbrella(x,ldisp);
delay(75);
cleardevice();
 //If insted of(x+1) you use(x+5) or Decreasing the value moving Fast
x=(x+4)%ScreenWidth;
}
closegraph();
getch();
}

#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void man(int sx, int sy, int step)
{
	// body
	line(sx, sy, sx, sy + 45);
	rectangle(sx - 3, sy + 10, sx + 3, sy + 45);

	// head
	circle(sx, sy - 10, 10);

	// hand left
	if (step == 1)
	{
		line(sx, sy + 10, sx - 15, sy + 30);
	}
	else if (step == 2)
	{

		line(sx, sy + 10, sx + 10, sy + 30);
	}

	// hand right
	line(sx, sy + 10, sx + 15, sy + 25);

	// umbrella
	line(sx + 15, sy + 25, sx + 15, sy - 20);
	arc(sx + 13, sy + 25, 0, 180, 2);
	arc(sx + 15, sy - 20, 180, 0, 30);
	line(sx - 15, sy - 20, sx + 45, sy - 20);

	if (step == 1)
	{

		// leg left
		line(sx, sy + 45, sx - 5, sy + 75);

		// leg right
		line(sx, sy + 45, sx + 10, sy + 75);
	}
	else if (step == 2)
	{

		// leg left
		line(sx, sy + 45, sx - 10, sy + 75);

		// leg right
		line(sx, sy + 45, sx + 5, sy + 75);
	}
}
void rain(int x, int y, int intensity)
{
	int i, rx, ry;
	for (i = 0; i < intensity; i++)
	{
		rx = rand() % x;
		ry = rand() % y;
		if (ry < y - 4 and rx > 2)
		{
		line(rx, ry, rx - 1, ry + 4);
		}
	}
}


int main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, NULL);

	// man(300,100,2);
	int ground[4] = {20, 400, 600, 400};

	line(ground[0], ground[1], ground[2], ground[3]); // ground
	int step = 1;
	for (int i = ground[0]; i < ground[2]; i += 10)
	{
		line(ground[0], ground[1], ground[2], ground[3]); // ground

		man(i, ground[1] - 75, step);
		if (step == 1)
		{
			step = 2;
		}
		else
		{
			step = 1;
		}
		rain(ground[2],ground[3],100);
		delay(350);
		cleardevice();
	}

	// getch();
	closegraph();
	return 0;
}*/

#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

int main()
{   int x,y,t=0;
bool flag;
    int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

    line(0,450,500,450);    //base
    //  MAN
    for(int i=0; i<400;i++){
        line(0,450,getmaxx(),450);
        rectangle(20+i,360,40+i,420);   //body
        line(25+i,420,35+i,450);    //leg
        line(35+i,420,25+i,450);    //leg
        circle(30+i,345,15);      //head
        if (i%10==0){
            flag=false;
        }else if(i%5==0){
            flag=true;
        }
        if (flag){
            line(20+i,370,50+i,410);    //right hand
        }else{
            line(20+i,370,50+i-60,410);    //right hand
        }
        line(50+i,390,70+i,370);    //left hand
        
        
        line(70+i,370,70+i,315);    //umbrella handle
        arc(70+i,315,180,0,70);     //umbrella curve
        line(0+i,315,140+i,315);   //umbrella base
        for(int j=0;j<100;j+=80){
        x=rand()%getmaxx();
        y=rand()%getmaxy();
        line(x,y,x+2,y+4);
        delay(10);
        }
        delay(15);
        cleardevice();
        
    }
    delay(1500);
    closegraph();
    return 0;
}