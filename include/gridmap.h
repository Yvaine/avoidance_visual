#ifndef GRID_MAP_H
#define GRID_MAP_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "Common.hpp"
using namespace cv;

class GridMap {
    public:
        GridMap();
        GridMap(float resolution, Cell2i &cell);
        GridMap(float resolutionx, float resolutiony,
                float mapx, float mapy);
        void updateMap(int i);
        ~GridMap();

        void showMap();

        void getPositionFromIndex(int x, int y, Position2f &pos) const;
        void getIndexFromPosition(const Position2f &pos, Cell2i &index) const;

        void setObstacle(const Cell2i &index_topleft, const Cell2i &index_rightbottom);
        void setObstaclePosition(const Position2f &position_topleft, const Position2f &position_rightbottom);

       Map2f getMapSize() const;

        Mat getOccupancyGridMap() const;

        void calcHeading(Position2f &pos, float &heading);


    private:

        float resolutionX;
        float resolutionY;


        unsigned int CellX;
        unsigned int CellY;

       float resolution;
        Cell2i cell;

        Mat occupancyGirdMap;

        int currentIndexX;
        int currentIndexY;

        int mapPositionX;
        int mapPositionY;

        offset2f offset_;

        float width;
        float height;

        int row;
        int col;

        Map2f mapSize;





};




















#endif
