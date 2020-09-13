#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2)
{
    int i, length;
    double dx, dy, x = x1, y = y1;
    putpixel(x1, y1, WHITE);
    if (abs(x2 - x1) >= abs(y2 - y1))
    {
        length = abs(x2 - x1);
    }
    else
    {
        length = abs(y2 - y1);
    }
    dx = (double)(x2 - x1) / length;
    dy = (double)(y2 - y1) / length;

    for (i = 0; i <= length; i++)
    {
        x += dx;
        y += dy;
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
    }
}
void plot(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}
void drawCircle(int xc, int yc, int r)
{

    int x, y, p;
    x = 0;
    y = r;
    plot(xc, yc, x, y);
    p = 1 - r;
    while (x < y)
    {
        x = x + 1;
        if (p >= 0)
        {
            y = y - 1;
        }

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }

        else
        {
            p = p + 2 * (x - y) + 1;
        }

        plot(xc, yc, x, y);
    }
}

void plotTopLeftQuarter(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
}

void drawCircleTopLeftQuarter(int xc, int yc, int r)
{

    int x, y, p;
    x = 0;
    y = r;
    plot(xc, yc, x, y);
    p = 1 - r;
    while (x < y)
    {
        x = x + 1;
        if (p >= 0)
        {
            y = y - 1;
        }

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }

        else
        {
            p = p + 2 * (x - y) + 1;
        }

        plotTopLeftQuarter(xc, yc, x, y);
    }
}

void plotBottomLeftQuarter(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc + y, yc - x, WHITE);
}

void drawCircleBottomLeftQuarter(int xc, int yc, int r)
{

    int x, y, p;
    x = 0;
    y = r;
    plot(xc, yc, x, y);
    p = 1 - r;
    while (x < y)
    {
        x = x + 1;
        if (p >= 0)
        {
            y = y - 1;
        }

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }

        else
        {
            p = p + 2 * (x - y) + 1;
        }

        plotBottomLeftQuarter(xc, yc, x, y);
    }
}

void plotTopRightQuarter(int xc, int yc, int x, int y)
{
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - y, yc + x, WHITE);
}

void drawCircleTopRightQuarter(int xc, int yc, int r)
{

    int x, y, p;
    x = 0;
    y = r;
    plot(xc, yc, x, y);
    p = 1 - r;
    while (x < y)
    {
        x = x + 1;
        if (p >= 0)
        {
            y = y - 1;
        }

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }

        else
        {
            p = p + 2 * (x - y) + 1;
        }

        plotTopRightQuarter(xc, yc, x, y);
    }
}

void plotBottomRightQuarter(int xc, int yc, int x, int y)
{
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void drawCircleBottomRightQuarter(int xc, int yc, int r)
{

    int x, y, p;
    x = 0;
    y = r;
    plot(xc, yc, x, y);
    p = 1 - r;
    while (x < y)
    {
        x = x + 1;
        if (p >= 0)
        {
            y = y - 1;
        }

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }

        else
        {
            p = p + 2 * (x - y) + 1;
        }

        plotBottomRightQuarter(xc, yc, x, y);
    }
}

void main()
{
    int j, gd = VGA, gm = VGAHI, x1, y1, x2, y2, length;
    double dx, dy, x, y;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    drawLine(0, 0, 300, 300);
    drawLine(0, 300, 300, 0);
    drawLine(0, 300, 300, 300);
    drawLine(300, 0, 300, 300);
    drawLine(0, 0, 300, 0);
    drawLine(0, 0, 0, 300);
    for (j = 0; j <= 50; j++)
    {
        drawCircle(150, 150, j);
    }
    for (j = 0; j <= 100; j++)
    {
        drawCircleTopLeftQuarter(0, 0, j);
        drawCircleTopRightQuarter(300, 0, j);
        drawCircleBottomLeftQuarter(0, 300, j);
        drawCircleBottomRightQuarter(300, 300, j);
    }

    getch();
    closegraph();
}
