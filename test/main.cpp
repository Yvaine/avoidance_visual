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
    Map2f m(400,400);

    GridMap map(r, m);
#if 0
    cout << "Map size " << map.getMapSize().x << " " << map.getMapSize().y << endl;

    Cell2i index(70,60), index2;
    Position2f position;
    map.getPositionFromIndex(index, position);

    map.getIndexFromPosition(position, index2);

    cout << "index = " << index.x << " " << index.y << ", position = " << position.x << ", " << position.y << endl;
    cout << "index2 = " << index2.x << " " << index2.y << endl;
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
#if 1
	string windowname = "occupancyGridMap";
	cv::namedWindow(windowname.c_str(), CV_WINDOW_KEEPRATIO);
    for(int i = 0; i < 2; i++)
    {
        map.updateMap(i);
        map.showMap(windowname.c_str());
        basicVFF.run(map);
        basicVFF.update();
    }
#endif
	cv::waitKey(0);
    cout << "end" << endl;
    return 0;
}
