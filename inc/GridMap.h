#ifndef GRID_MAP_H
#define GRID_MAP_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Common.hpp"
using namespace cv;

class GridMap {
    public:
        GridMap();
        GridMap(float resolutionx, float resolutiony,
                float mapx, float mapy);
        GridMap(Resolution2f &resolution, Map2f &map);
        void updateMap();
        ~GridMap();

        void showMap();

        void getPositionFromIndex(const Cell2i &index, Position2f &pos) const;

        void setObstacle(const Cell2i &index_topleft, const Cell2i &index_rightbottom);

        Cell2i getMapSize() const;

        Mat getOccupancyGridMap() const;



    private:

        float resolutionX;
        float resolutionY;

        float mapX;
        float mapY;

        unsigned int CellX;
        unsigned int CellY;

        Resolution2f resolution_;
        Map2f map_;
        Cell2i cell_;

        Mat occupancyGirdMap;

        int currentIndexX;
        int currentIndexY;

        int mapPositionX;
        int mapPositionY;

        offset2f offset_;






};




















#endif
