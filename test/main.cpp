#include <opencv2/opencv.hpp>
#include <iostream>

#include "GridMap.hpp"
#include "Common.hpp"
#include "BasicVFF.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    //GridMap map(1, 1, 400, 400);
    Resolution2f r(0.1, 0.1);
    Cell2i m(50,30);
    float res = 0.1;

    GridMap map(res, m);
#if 1
    cout << "Map size " << map.getMapSize().x << " " << map.getMapSize().y << endl;

    Cell2i index(49,29), index2;
    Position2f position;
    cout << "index = " << index.x << " " << index.y << endl;

    map.getPositionFromIndex(index.x, index.y, position);
    cout << "position " << position.x << " " << position.y << endl;

    map.getIndexFromPosition(position, index2);

    cout << "index2 = " << index2.x << " " << index2.y << endl;

    float heading;
    Position2f pos(2,-4);
    map.calcHeading(pos, heading);
    cout << "heading is " <<  heading * 180 / 3.1415926<<" degree" << endl;
#endif



    BasicVFF basicVFF;
#if 0
    basicVFF.calcDistanceVecArray(map);

    distance2f distanceVec(10, 10);
    float distancePow = basicVFF.getDistancePow(distanceVec);
    cout <<"distancePow = "  << distancePow << endl;

    float distance = basicVFF.getDistance(distanceVec);
    cout <<"distance = "  << distance << endl;
    //basicVFF.calcRepulsiveForceArray(map);
    basicVFF.calcRepulsiveForceSum(map);
    basicVFF.calcDirection();
    basicVFF.calcAngle();
    basicVFF.calcSteerRate();
#endif
#if 0
    for(int i = 0; i < 2; i++)
    {
        map.updateMap(i);
        map.showMap();
        basicVFF.run(map);
        basicVFF.update();
    }
#endif
    cout << "end" << endl;
    return 0;
}
