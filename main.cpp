#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <vector>
#include "coordinates.h"
#include "object.h"
using namespace std;



int main()
{
    srand(time(NULL));
    int width = 0;
    cout << "How big is your screen? XD" << endl;
    cin >> width;

    int amountOfMoves = 0;
    cout << "How many steps will we make? XD" << endl;
    cin >> amountOfMoves;

    int startX = 0, startY = 0;
    cout << "whats your starting cords? XD" << endl;
    cin >> startX >> startY;

    Coordinates dot1(startX, startY, width);
    dot1.move(1, amountOfMoves);
}
