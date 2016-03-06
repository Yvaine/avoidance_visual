#include "Common.hpp"

VFH::VFH(gridmap *map))
{
    p_map = map;


}
// step 1
void VFH::calcHistogramH()
{
    float belta;
    Position2f ObstaclePos;
    float distance;
    uchar *count = map.getCount();
    for (int i = 0; i < p_map->getCellY(); i++)
    {
        for (int j = 0; j < p_map->getCellX(); j++)
        {
            int index = map.getIndexN(i,j);
            p_map->getPositionFromIndex(j, i, ObstaclePos);
            calcHeading(ObstaclePos, belta);
            beta = beta < 0 ? (2 * pi + belta) : beta;
            calcSector(belta, k);
            float distancePow = getDistancePow(ObstaclePos);
            float distance = powf(distancePow, 0.5);
            float m = pow(count[index], 2)(a - b * distance);
            histogramH[k] += m;
        }
    }
}

void VFF::calcSector(float belta, unsigned int &k)
{
    k = floor(belta / alpha);
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
// step 2 :  calculate Valley
void VFH::calcValley(float *POD, std::map<int,float> &valley)
{
    for(int i = 0 ; i < SECTOR_NUM; i++)
    {
         if( POD[i] < SECTOR_THREASHOLD)
         {
             valley.insert(std::make_pair(i, POD[i]));
         }
    }
}

//step3 : calcOptimal direction
void VFH::calcOptimal(std::map<int, float> &valley, vector<int> &candidate_sector)
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

//Step4 : calcOptimalK()
void VFH::calcOptimalK(vector<int> &candidate_sector, int &K)
{
    for(int i = 0; i < candidate_sector.size(); i++)
    {
        if(abs(candidate_sector[i]))

    }
}


