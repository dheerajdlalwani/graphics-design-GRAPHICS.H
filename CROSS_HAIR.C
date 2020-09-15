#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void circ(int xc, int yc, int r);
void display(int x, int y, int xc, int yc);
void main()
{
    int gd = DETECT, gm, r, xc, yc, i;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(BLACK);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    printf("Enter the co-ordinates of the centre: ");
    scanf("%d%d", &xc, &yc);
    line(320, 0, 320, 480);
    line(0, 240, 640, 240);

    for (i = 0; i < r; i = i + 20)
    {
        circ(xc, yc, i);
    }

    getch();
}
void circ(int xc, int yc, int r)
{
    int x, y;
    float dp;
    x = 0;
    y = r;
    dp = (5 / 4) - r;
    do
    {
        display(x, y, xc, yc);
        if (dp < 0)
        {
            x = x + 1; //y remains same
            dp = dp + 2 * x + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dp = dp + 2 * (x - y) + 1;
        }
    } while (x < y);
}
void display(int x, int y, int xc, int yc)
{
    putpixel(320 + (x + xc), 240 - (y + yc), 2);
    putpixel(320 + (y + xc), 240 - (x + yc), 2);
    putpixel(320 + (-x + xc), 240 - (y + yc), 2);
    putpixel(320 + (-y + xc), 240 - (x + yc), 2);
    putpixel(320 + (x + xc), 240 - (-y + yc), 2);
    putpixel(320 + (y + xc), 240 - (-x + yc), 2);
    putpixel(320 + (-x + xc), 240 - (-y + yc), 2);
    putpixel(320 + (-y + xc), 240 - (-x + yc), 2);
}
