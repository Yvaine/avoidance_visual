#include "BasicVFF.hpp"
#include <math.h>

BasicVFF::BasicVFF()
{
    distance_vec_array.clear();
    forceSum = force2f(0, 0);
    cur_direction = force2f(0,0);
    direction = force2f(0, 0);
    angle = 0;
    cur_angle = 0;
    Ks = 0.1;

}

BasicVFF::~BasicVFF()
{

}


void BasicVFF::calcDistanceVecArray(const GridMap &map)
{
    for(int i = 0; i < map.getMapSize().y; i++)
    {
        for(int j = 0; j < map.getMapSize().x; j++)
        {
            if(map.getOccupancyGridMap().at<uchar>(i,j) > 0)
            {
                Position2f ObstaclePos;
                map.getPositionFromIndex(Cell2i(i,j), ObstaclePos);
                cout << i << " " << j << endl;
                cout << ObstaclePos.x << " " << ObstaclePos.y << endl;
                distance_vec_array.push_back(ObstaclePos);
                cout << distance_vec_array.size() << endl;

            }

        }
    }
}

void BasicVFF::calcRepulsiveForceArray(const GridMap &map)
{
    for(int i = 0; i < map.getMapSize().y; i++)
    {
        for(int j = 0; j < map.getMapSize().x; j++)
        {
            uchar occupancyData = map.getOccupancyGridMap().at<uchar>(i,j);
            if(occupancyData > 0)
            {
                Position2f ObstaclePos;
                map.getPositionFromIndex(Cell2i(i,j), ObstaclePos);
                cout << i << " " << j << endl;
                cout << ObstaclePos.x << " " << ObstaclePos.y << endl;
                float distancePow = getDistancePow(ObstaclePos);
                float distance = powf(distancePow, 0.5);
                force2f force = force2f((0 - ObstaclePos.x) / distance , (0 - ObstaclePos.y) / distance);
                float coeff = (float)occupancyData / distancePow;
                cout << (float)occupancyData << " "<< distancePow << " " << coeff<< endl;

                force2f force1 = coeff * force;

                //cout << force.x << " " << force.y << endl;
                //cout << force1.x << " " << force1.y << endl;

            }

        }
    }
}

void BasicVFF::calcRepulsiveForceSum(const GridMap &map)
{
    for(int i = 0; i < map.getMapSize().y; i++)
    {
        for(int j = 0; j < map.getMapSize().x; j++)
        {
            uchar occupancyData = map.getOccupancyGridMap().at<uchar>(i,j);
            if(occupancyData > 0)
            {
                Position2f ObstaclePos;
                map.getPositionFromIndex(Cell2i(i,j), ObstaclePos);
                //cout << i << " " << j << endl;
                //cout << ObstaclePos.x << " " << ObstaclePos.y << endl;
                float distancePow = getDistancePow(ObstaclePos);
                float distance = powf(distancePow, 0.5);
                force2f force = force2f((0 - ObstaclePos.x) / distance , (0 - ObstaclePos.y) / distance);
                float coeff = (float)occupancyData / distancePow;
                //cout << (float)occupancyData << " "<< distancePow << " " << coeff<< endl;

                force2f force1 = coeff * force;
                forceSum += force1;
                //cout << force.x << " " << force.y << endl;
                //cout << force1.x << " " << force1.y << endl;
            }
        }
    }

    cout << "ForceSum = " << forceSum.x << " "<< forceSum.y << endl;
}

float BasicVFF::getDistancePow(distance2f distance_vec) const
{
    return powf(abs(distance_vec.x),2) + powf(abs(distance_vec.y),2);
}

float BasicVFF::getDistance(distance2f distance_vec) const
{
    return powf(powf(abs(distance_vec.x),2) + powf(abs(distance_vec.y),2), 0.5);
}

float BasicVFF::rad2degree(float rad)
{
    return 180 * rad / CV_PI;
}

void BasicVFF::calcDirection()
{
    direction = forceSum / getDistance(forceSum);
    cout << direction.x << " " << direction.y << endl;
}

void BasicVFF::calcAngle()
{
    float angle_rad = atan2(direction.y, direction.x);

    if(angle_rad < -CV_PI)
        angle_rad += 2 * CV_PI;
    if(angle_rad > CV_PI)
        angle_rad -= 2 * CV_PI;

    angle = rad2degree(angle_rad) - 90;
    cout << "angle = " << angle << endl;
}

void BasicVFF::calcSteerRate()
{
    steer_rate = Ks * (angle - cur_angle);
    cout << "steer_rate = " << steer_rate << endl;
}

void BasicVFF::run(const GridMap & map)
{
    calcRepulsiveForceSum(map);
    calcDirection();
    calcAngle();
    calcSteerRate();
}

void BasicVFF::update()
{
    //cur_angle = angle;
    forceSum = force2f(0,0);
}

