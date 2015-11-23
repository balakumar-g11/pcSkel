#ifndef FILEREADER_H
#define FILEREADER_H

#include <pcl/io/pcd_io.h>
#include <pcl/common/common_headers.h>

class FileReader
{
public:
    explicit FileReader(const std::string& fileName);

    const pcl::PointCloud<pcl::PointXYZRGBA>::Ptr getPointCloud() const;

private:
    bool readPointCloud();

    void moveToCenter();

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr pointCloud;

    std::string fileName;
};

#endif // FILEREADER_H
