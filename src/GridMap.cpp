#include "GridMap.hpp"
//#include "Common.hpp"
using namespace std;
using namespace cv;

GridMap::GridMap()
{
    cell = Cell2i(0,0);

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
GridMap::GridMap(float resolution, Cell2i &cell)
{
    this->resolution = resolution;

    cell = cell;
    width = cell.x * resolution;
    height = cell.y * resolution;

    mapSize = Map2f(width, height);

    //cout << cell.x << " " << cell.y << endl;

    row = cell.y;
    col = cell.x;

    occupancyGirdMap = cv::Mat(cell.x, cell.y, CV_8UC1, Scalar::all(0));

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
#if 0
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
#endif
#if 0
void GridMap::getPositionFromIndex(const Cell2i &index, Position2f &pos) const
{
    pos = array<float>((float)index.x, -(float)index.y) * resolution_ + offset_;

}
#endif

void GridMap::getPositionFromIndex(int x, int y, Position2f &pos) const
{
	pos.x = x * resolution - width / 2.0f + resolution / 2.0f;
	pos.y = height - (y + 1) * resolution + resolution / 2.0f;
}

void GridMap::getIndexFromPosition(const Position2f &pos, Cell2i &index) const
{
    index.x = floor(pos.x / resolution)  + col / 2.0f ;
	index.y = row - ceil(min(pos.y , height)/ resolution);
}

void GridMap::calcHeading(Position2f &pos, float &heading)
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

#if 0
void GridMap::getIndexFromPosition(const Position2f &pos, Cell2i &index) const
{
    array<float> index_tmp = (pos - offset_ ) / resolution_;
    index = Cell2i(static_cast<int>(index_tmp.x), static_cast<int>(-index_tmp.y));
}
#endif

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

Map2f GridMap::getMapSize() const
{
    return mapSize;
}

Mat GridMap::getOccupancyGridMap() const
{
    return occupancyGirdMap;
}
