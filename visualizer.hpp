#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <boost/shared_ptr.hpp>
#include <pcl/io/pcd_io.h>
#include <pcl/common/common_headers.h>
#include <pcl/visualization/pcl_visualizer.h>

class Visualizer
{
public:
    explicit Visualizer(const pcl::PointCloud<pcl::PointXYZRGBA>::Ptr pointCloud);

    void visualize();
private:
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr pointCloud;

    boost::shared_ptr<pcl::visualization::PCLVisualizer> visualizer;
};

#endif // VISUALIZER_H
