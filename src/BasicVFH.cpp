#include "BasicVFH.h"

BasicVFH::BasicVFH()
{
}
BasicVFH::BasicVFH(GridMap *map)
{
    p_map = map;
}
// step 1
void BasicVFH::calcHistogramH()
{
    float belta;
    Position2f ObstaclePos;
    float distance;
    int k = 0;
    for (int i = 0; i < p_map->getCellY(); i++)
    {
        for (int j = 0; j < p_map->getCellX(); j++)
        {
            int index = p_map->getIndexN(i,j);
            p_map->getPositionFromIndex(j, i, ObstaclePos);
            calcSectorFromPosition(ObstaclePos, k);
            float distancePow = getDistancePow(ObstaclePos);
            float distance = powf(distancePow, 0.5);
            float m = C * (A - B * distance);
            histogramH[k] += m;
        }
    }
}

// step 2 : smoothPOD, convolution kernel is [1 2 5 2 1]
void VFF::smoothPOD(float *histogramH, float *POD)
{
    float kernel[5] = {1.0f 2.0f 5.0f 2.0f 1.0f};
    for(int i = 2; i < SECTOR_NUM - 2; i++)
    {
        for(int k = 0; k < 5; k++)
        {
            POD[i] += histogramH[k] * kernel[k];
        }
    }
}
// step 3 :  calculate Valley
void BasicVFH::calcValley(float *POD, std::map<int,float> &valley)
{
    for(int i = 0 ; i < SECTOR_NUM; i++)
    {
         if( POD[i] < SECTOR_THREASHOLD)
         {
             valley.insert(std::make_pair(i, POD[i]));
         }
    }
}

//step4 : calcOptimal direction
void BasicVFH::calcCandidate(std::map<int, float> &valley, vector<int> &candidate_sector)
{
    std::map<int, float>::iterator it;
    for(it = Valley.begin(); it != valley.end(); it++)
    {
        int it_cur = it->first;
        int it_tmp = (it+1)->first;
        if( (it_cur + 1) == it_tmp)
        {
            s_count++;
            static int it_start = it_cur;
            it_cur = it_tmp;
        }
        else{
            if(s_count > S_MAX)
            {
                int middle = (it_start + it_cur) / 2;
                candidate_sector.push_back(middle);
            }
            s_count = 0;
            it_start = it_tmp;
        }
    }
}

//Step5 : calcOptimalK()
void BasicVFH::calcOptimalK(int cmd_w, vector<int> &candidate_sector, int &K)
{
    float heading;
    float minAngle = 2 * PI;
    int optimalK;
    for(int i = 0; i < candidate_sector.size(); i++)
    {
        calcHeadingFromSector(candidate_sector[i], heading);
        float heading_sub = abs(heading-cmd_w);
        if(minAngle > heading_sub)
        {
            minAngle = heading_sub;
            optimalK = i;
        }
    }
    K = optimalK;
}

void BasicVFH::calcHeadingFromPosition(Position2f &pos, float &heading)
{
    float angle_rad = atan2(pos.y, pos.x);
    cout << angle_rad << endl;
    heading = angle_rad - 3.1415926 / 2;
#if 1
    if(heading < -PI)
        heading += 2 * PI;
    if(heading > PI)
        heading -= 2 * PI;
#endif
}

void BasicVFH::calcSectorFromPosition(Position2f &pos, uint &sector)
{
    float heading;
    calcHeadingFromPosition(pos, heading);
    calcSectorFromHeading(heading, sector);
}

void BasicVFH::calcSectorFromHeading(const float heading, uint &sector)
{
    float beta = heading < 0 ? (2 * PI + heading) : beta;
    sector = floor(belta / ALPHA);
}

void BasicVFH::calcHeadingFromSector(const uint sector, float &heading)
{
    float beta = sector * ALPHA + 0.5 * ALPHA;
    heading = beta >  PI ? (beta - 2 * PI) : beta;
}


