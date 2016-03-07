#ifndef BASIC_VFF_H
#define BASIC_VFF_H

#include "Common.hpp"
#include "gridmap.h"
#include "vector"

using namespace std;

class BasicVFF
{
    public:
        BasicVFF();
        ~BasicVFF();

        void calcDistanceVecArray(const GridMap &map) ;

        void calcRepulsiveForceArray(const GridMap &map) ;
        void calcRepulsiveForceSum(const GridMap &map) ;

        float getDistancePow(distance2f distance_vec) const;
        float getDistance(distance2f distance_vec) const;

        void calcDirection();
        void calcAngle();

        float rad2degree(float rad);

        void calcSteerRate();

        void run(const GridMap & map);
        void update();

    private:
        distance2f distance_vec;
        float distance;

        vector<distance2f>distance_vec_array;

        vector<force2f>force_vec_array;

        force2f forceSum;

        force2f direction;

        force2f cur_direction;

        float angle;//degree
        float cur_angle;

        float Ks;
        float steer_rate;

	float delta_time;

};



























#endif
