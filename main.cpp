#include "filereader.hpp"
#include "visualizer.hpp"

int main()
{
    FileReader* pointCloudReader = new FileReader("Jiangtailgong.pcd");
    Visualizer* visualizer = new Visualizer(pointCloudReader->getPointCloud());
    visualizer->visualize();

    return 0;
}
