#include "GridMap.hpp"
//#include "Common.hpp"
using namespace std;
using namespace cv;

GridMap::GridMap()
{
    cell_ = Cell2i(0,0);

}
#if 0
GridMap::GridMap(float resolutionx, float resolutiony,
                 float mapx, float mapy)
{
    resolutionX = resolutionx;
    resolutionY = resolutiony;
    mapX = mapx;
    mapY = mapy;
    CellX = mapX / resolutionX;
    CellY = mapY / resolutionY;

    cout << CellX  << " " << CellY << endl;
    occupancyGirdMap = cv::Mat(CellX, CellY, CV_8UC1);

}
#else
GridMap::GridMap(Resolution2f &resolution, Map2f &map)
{
#if 0
    resolutionX = resolution.x;
    resolutionY = resolution.y;
    mapX = map.x;
    mapY = map.y;
    CellX = map.x / resolutionX;
    CellY = map.y / resolutionY;

    cout << CellX  << " " << CellY << endl;
    occupancyGirdMap = cv::Mat(CellX, CellY, CV_8UC1);
#else
    resolution_ = resolution;
    map_ = map;
    array<float> cellf = map_ / resolution_;

    //cout << cellf.x << " " << cellf.y << endl;

    cell_.x = int(cellf.x);
    cell_.y = int(cellf.y);

    offset_.x = -map_.x / 2;
    offset_.y = map_.y / 2;

    occupancyGirdMap = cv::Mat(cell_.x, cell_.y, CV_8UC1, Scalar::all(0));




#endif

}
#endif
GridMap::~GridMap()
{

}

void GridMap::showMap()
{
    cv::namedWindow("occupancyGridMap", CV_WINDOW_KEEPRATIO);
    cv::imshow("occupancyGridMap", occupancyGirdMap);
    cv::waitKey(0);

    cv::imwrite("../bin/occupancyGridMap.jpg", occupancyGirdMap);
}

void GridMap::updateMap(int i)
{
    memset(occupancyGirdMap.data, 0, sizeof(occupancyGirdMap.data));
    Cell2i obstacle_lefttop(0, 0);
    Cell2i obstacle_rightbottom(2, 2);
    if(i == 0){
        setObstacle(obstacle_lefttop, obstacle_rightbottom);
    }
    else
    {
        Position2f pos_lefttop, pos_rightbottom;
        getPositionFromIndex(obstacle_lefttop, pos_lefttop);
        getPositionFromIndex(obstacle_rightbottom, pos_rightbottom);

        setObstaclePosition(pos_lefttop, pos_rightbottom);
    }
}

void GridMap::getPositionFromIndex(const Cell2i &index, Position2f &pos) const
{
    pos = array<float>((float)index.x, -(float)index.y) * resolution_ + offset_;

}

void GridMap::getIndexFromPosition(const Position2f &pos, Cell2i &index) const
{
    array<float> index_tmp = (pos - offset_ ) / resolution_;
    index = Cell2i(static_cast<int>(index_tmp.x), static_cast<int>(-index_tmp.y));
}

void GridMap::setObstacle(const Cell2i &index_topleft, const Cell2i &index_rightbottom)
{
    for(int i = index_topleft.y; i < index_rightbottom.y; i++)
    {

        for(int j = index_topleft.x; j < index_rightbottom.x; j++)
        {
            occupancyGirdMap.at<uchar>(i,j) = 255;

        }
    }
}

void GridMap::setObstaclePosition(const Position2f &position_topleft, const Position2f &position_rightbottom)
{
    Cell2i index_topleft, index_rightbottom;
    getIndexFromPosition(position_topleft, index_topleft);
    getIndexFromPosition(position_rightbottom, index_rightbottom);
    setObstacle(index_topleft, index_rightbottom);


}

Cell2i GridMap::getMapSize() const
{
     return cell_;
}

Mat GridMap::getOccupancyGridMap() const
{
    return occupancyGirdMap;
}
