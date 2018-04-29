#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    Square(int x, int y);
    void setX(int x);
    void setY(int y);
    void setCoordinates(int x, int y);
    int getX();
    int getY();

protected:
    int coordinateX;
    int coordinateY;
};


#endif // SQUARE_H
