#include <conio.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;

int getRandomNumber(int min, int max)
{
    int num = min + rand() % (max - min + 1);
    return num;
}

class dotPosition
{
    private: int _X;
    int _Y;
    int _pathLenght;
    int _width;
    vector<vector<int>> _path;

    public: dotPosition(int X = 0, int Y = 0, int width = 10, int pathLenght = 0)
    {
        _X = X;
        _Y = Y;
        _pathLenght = pathLenght;
        _width = width;
    }

    void addToX(int X)
    {
        _X = _X + X;
        _pathLenght += abs(X);
    }

    void addToY(int Y)
    {
        _Y = _Y + Y;
        _pathLenght += abs(Y);
    }

    void setX(int X)
    {
        _X = X;
    }

    void setY(int Y)
    {
        _Y = Y;
    }

    int getX()
    {
        return(_X);
    }

    int getY()
    {
        return(_Y);
    }

    int getPathLenght()
    {
        return(_pathLenght);
    }

    void randomWalk()
    {
        int shiftX = getRandomNumber(-1, 1);
        if (_X + shiftX >= 0 && _X + shiftX < _width)
        {
            addToX(shiftX);
        }

        int shiftY = getRandomNumber(-1, 1);
        if (_Y + shiftY >= 0 && _Y + shiftY < _width)
        {
            addToY(shiftY);
        }
    }

    void move(int moveType, int amountOfMoves)
    {
        switch(moveType)
        {
            case 1:
            for (int i = 0; i < amountOfMoves; i++)
            {
                system("cls");
                randomWalk();
                safeState();
                printMatrix();
                cout << "distance to 0 0:    " << distance(0, 0) << endl << "pathLenght:         " << _pathLenght << endl << "cords of dot (X/Y): " << _X << "/" << _Y;
                Sleep(100);
            }

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;
        }
    }

    void printMatrix()
    {
        for (int i = _width-1; i >= 0; i--)
        {
            if (i == _Y)
            {
                for (int j = 0; j < _width; j++)
                {
                    if (j == _X)
                    {
                        cout << "* ";
                    }
                    else
                    {
                        cout << "- ";
                    }
                }
            }
            else
            {
                for (int j = 0; j < _width; j++)
                {
                    cout << "- ";
                }
            }

            cout << endl;
        }

        cout << endl;
    }

    double distance(double goalX, double goalY)
    {
        double X = abs(_X - goalX);
        double Y = abs(_Y - goalY);
        return sqrt(X *X + Y *Y);
    }

    void safeState()
    {
        vector<int> pos;
        pos.resize(2);
        pos[0] = _X;
        pos[1] = _Y;
        _path.push_back(pos);
    }
};


