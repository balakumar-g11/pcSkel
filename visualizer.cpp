#include "visualizer.hpp"

Visualizer::Visualizer(const pcl::PointCloud<pcl::PointXYZRGBA>::Ptr pointCloud) : pointCloud(pointCloud)
{
    visualizer = boost::shared_ptr<pcl::visualization::PCLVisualizer>(new pcl::visualization::PCLVisualizer("PC Skel Viewer"));
    visualizer->setBackgroundColor(0, 0, 0);
    pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGBA> handler(pointCloud);
    visualizer->addPointCloud<pcl::PointXYZRGBA>(pointCloud, handler, "JiangTai Cloud");
    visualizer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "JiangTai Cloud");
    visualizer->addCoordinateSystem(1.0);
    visualizer->initCameraParameters();
}

void Visualizer::visualize()
{
    while(!visualizer->wasStopped())
    {
        visualizer->spinOnce(100);
        boost::this_thread::sleep(boost::posix_time::microseconds(100000));
    }
}

