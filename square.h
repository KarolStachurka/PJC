#ifndef SQUARE_H
#define SQUARE_H


class Square
{
public:
    Square();
    Square(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

private:
    int coordinateX;
    int coordinateY;
};


#endif // SQUARE_H
