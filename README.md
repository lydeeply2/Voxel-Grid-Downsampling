# Voxel-Grid-Downsampling
pcd to pcd

通过cloudcompare由stl文件得到pcd文件之后，再通过这个代码对pcd文件执行一次体素网格下采样 ，使点云分布更加均匀
执行完这个程序之后得到最终的pcd文件

### 如何制作一个用于自主探索的pcd地图？
对于一些仿真器如MARSIM等，需要的地图场景需要pcd点云文件作为地图输入，除了开源的地图场景外，如何得到一个自己想要的场景进行仿真实验
制作pcd文件步骤如下：

1.利用Blender等3D建模软件对场景进行建模，然后场景模型文件，如stl格式，其余格式也行
- Blender官网免费下载，Ubuntun下通过tar -xf进行解压，解压文件夹下可直接打开软件

2.利用CloudCompare采样初步得到pcd文件
- 通过snap安装
~~~
sudo apt-get update
sudo apt install snap
sudo snap install cloudcompare
~~~

3.利用Voxel-Grid-Downsampling进行体素网格下采样，得到点云均匀分布的pcd文件
