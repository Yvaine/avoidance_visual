#include "Common.hpp"

VFH::VFH(gridmap *map))
{
    p_map = map;


}

void VFH::calcHistogramH()
{
    float belta;
    Position2f ObstaclePos;
    float distance;
    for (int i = 0; i < p_map->getCellY(); i++)
    {
        for (int j = 0; j < p_map->getCellX(); j++)
        {
            p_map->getPositionFromIndex(j, i, ObstaclePos);
            calcHeading(ObstaclePos, belta);
            calcSector(belta, k);
            histogramH[k]++;





        }
    }
}

void VFF::calcSector(float belta, unsigned int &k)
{
    int tmp = floor(belta / alpha);
    k = (SECTOR_NUM - 1) / 2 - tmp;
}




