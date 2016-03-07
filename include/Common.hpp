#ifndef COMMON_H
#define COMMON_H

template<class T>
class array
{
public:
    T x;
    T y;

    int row;
    int col;

    array(void)
    {
        x = 0;
        y = 0;
    }

    array(T x, T y){ this->x = x; this->y = y; }

    array(const array<T> &a)
    {
        this->x = a.x;
        this->y = a.y;
    }

    array &operator=(const array<T> &other)
    {
        x = other.x;
        y = other.y;
    }

    array &operator+=(const array<T> &other)
    {
        x += other.x;
        y += other.y;
    }

    friend array operator/(const array<T> &numerator, const array<T> &denominator)
    {
        array<T> remainder;
        remainder.x = numerator.x / denominator.x;
        remainder.y = numerator.y / denominator.y;
        return remainder;
    }
    friend array operator/(const array<T> &numerator, const T denominator)
    {
        array<T> remainder;
        remainder.x = numerator.x / denominator;
        remainder.y = numerator.y / denominator;
        return remainder;
    }
    friend array operator*(const array<T> &numerator, const array<T> &denominator)
    {
        array<T> remainder;
        remainder.x = numerator.x * denominator.x;
        remainder.y = numerator.y * denominator.y;
        return remainder;
    }
    friend array operator*(const T value, const array<T> &denominator)
    {
        array<T> mulply;
        mulply.x = value * denominator.x;
        mulply.y = value * denominator.y;
        return mulply;
    }
    friend array operator+(const array<T> &numerator, const array<T> &denominator)
    {
        array<T> remainder;
        remainder.x = numerator.x + denominator.x;
        remainder.y = numerator.y + denominator.y;
        return remainder;
    }
    friend array operator-(const array<T> &numerator, const array<T> &denominator)
    {
        array<T> remainder;
        remainder.x = numerator.x - denominator.x;
        remainder.y = numerator.y - denominator.y;
        return remainder;
    }

};


typedef array<float> Position2f;
typedef array<float> Map2f;
typedef array<float> Resolution2f;
typedef array<int> Cell2i;
typedef array<int> Index2i;
typedef array<float> offset2f;
typedef array<float> distance2f;
typedef array<float> force2f;



#define PI 3.1415926
#define VFH

#ifdef VFH
const float ALPHA  = static_cast<const float>(5 * PI / 180);// 5 degree
const int SECTOR_NUM = static_cast<const int>(2 * PI / ALPHA);
const int S_MAX = 18;
const int A = 1;
const int B = 1;
const int C = 1;
#endif





#endif
