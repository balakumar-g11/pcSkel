#include "filereader.hpp"

#include <pcl/console/parse.h>
#include <pcl/common/centroid.h>
#include <pcl/common/transforms.h>
#include <Eigen/Eigen>

FileReader::FileReader(const std::string& fileName) : fileName(fileName), pointCloud(new pcl::PointCloud<pcl::PointXYZRGBA>())
{
    readPointCloud();
}

bool FileReader::readPointCloud()
{
    if(pcl::io::loadPCDFile<pcl::PointXYZRGBA>(fileName, *pointCloud) == -1)
        return false;

    moveToCenter();

    return true;
}

void FileReader::moveToCenter()
{
    Eigen::Vector4f centroid;

    pcl::compute3DCentroid(*pointCloud, centroid);

    Eigen::Matrix4f transform = Eigen::Matrix4f::Identity();
    transform(0,3) = -(centroid.x());
    transform(1,3) = -(centroid.y());
    transform(2,3) = -(centroid.z());

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tempCloud(new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::transformPointCloud(*pointCloud, *tempCloud, transform);

    pointCloud = tempCloud;
}

const pcl::PointCloud<pcl::PointXYZRGBA>::Ptr FileReader::getPointCloud() const
{
    return pointCloud;
}

