#ifndef BasicVFH_H
#define BasicVFH_H
#include "Common.hpp"
#include "gridmap.h"

class BasicVFH
{
    public:
        BasicVFH();
        BasicVFH(GridMap *map);
        ~BasicVFH();

        void calcHistogramH();
        void smoothPOD(float *histogramH, float *POD);
        void calcValley(float *POD, std::map<int,float> &valley);
        void calcCandidate(std::map<int, float> &valley, vector<int> &candidate_sector);
        void calcOptimalK(int cmd_w, vector<int> &candidate_sector, int &K);
        void calcHeadingFromPosition(Position2f &pos, float &heading);
        void calcSectorFromPosition(Position2f &pos, uint &sector);
        void calcSectorFromHeading(const float heading, uint &sector);
        void calcHeadingFromSector(const uint sector, float &heading);

    private:
        unsigned int histogramH[SECTOR_NUM];
        GridMap *p_map;


};



#endif
