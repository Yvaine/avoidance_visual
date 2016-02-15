#include <opencv2/opencv.hpp>
#include <iostream>

#include "GridMap.hpp"
#include "Common.hpp"
#include "BasicVFF.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    //GridMap map(1, 1, 400, 400);
    Resolution2f r(1, 1);
    Map2f m(40,40);

    GridMap map(r, m);
#if 0
    cout << "Map size " << map.getMapSize().x << " " << map.getMapSize().y << endl;

    Cell2i index(20,20);
    Position2f position;
    map.getPositionFromIndex(index, position);

    cout << "index = " << index.x << "," << index.y << " position = " << position.x << ", " << position.y << endl;
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

    for(int i = 0; i < 3; i++)
    {
        map.updateMap();
        map.showMap();
        basicVFF.run(map);
        basicVFF.update();
    }

    cout << "end" << endl;
    return 0;
}