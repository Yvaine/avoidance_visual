#ifndef VFH_H
#define VFH_H

class VFH
{
    public:
        VFH();
        ~VFH();

        void calcHistogramH();

    private:
        unsigned int histogramH[SECTOR_NUM];
        gridmap *p_map;





}



#endif
