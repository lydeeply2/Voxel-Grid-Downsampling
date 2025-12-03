#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <iostream>
#include <string>

int main()
{
    // ———— 在这里指定你的输入/输出路径和叶子尺寸 ————
    const std::string input_file  = "/home/xdu/UAV/experiment/work_first/map/pcd/wa_with_floor.pcd";
    const std::string output_file = "/home/xdu/UAV/experiment/work_first/map/Downsampling/map_with_floor.pcd";
    const float leaf_size = 0.005f;  // 体素格边长，单位为米

    // 1. 读取原始点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile(input_file, *cloud) == -1) {
        PCL_ERROR("无法读取文件 %s\n", input_file.c_str());
        return -1;
    }
    std::cout << "原始点数: " << cloud->size() << std::endl;

    // 2. VoxelGrid 下采样
    pcl::VoxelGrid<pcl::PointXYZ> vg;
    vg.setInputCloud(cloud);
    vg.setLeafSize(leaf_size, leaf_size, leaf_size);

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    vg.filter(*cloud_filtered);
    std::cout << "下采样后点数: " << cloud_filtered->size() << std::endl;

    // 3. 保存下采样后的点云
    if (pcl::io::savePCDFileASCII(output_file, *cloud_filtered) == -1) {
        PCL_ERROR("无法写入文件 %s\n", output_file.c_str());
        return -1;
    }
    std::cout << "已保存下采样点云到: " << output_file << std::endl;

    return 0;
}
