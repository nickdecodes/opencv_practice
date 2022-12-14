# OpenCV图像处理

## 介绍

OpenCV是一个基于[BSD](https://baike.baidu.com/item/BSD/3794498)许可（开源）发行的跨平台[计算机视觉](https://baike.baidu.com/item/计算机视觉/2803351)和[机器学习](https://baike.baidu.com/item/机器学习/217599)软件库，可以运行在[Linux](https://baike.baidu.com/item/Linux/27050)、[Windows](https://baike.baidu.com/item/Windows/165458)、[Android](https://baike.baidu.com/item/Android/60243)和[Mac OS](https://baike.baidu.com/item/Mac OS/2840867)操作系统上。 [1] 它轻量级而且高效——由一系列 C 函数和少量 C++ 类构成，同时提供了Python、Ruby、MATLAB等语言的接口，实现了[图像处理](https://baike.baidu.com/item/图像处理/294902)和计算机视觉方面的很多通用算法。

OpenCV用C++语言编写，它具有C ++，[Python](https://baike.baidu.com/item/Python/407313)，[Java](https://baike.baidu.com/item/Java/85979)和[MATLAB](https://baike.baidu.com/item/MATLAB/263035)接口，并支持Windows，Linux，Android和Mac OS，OpenCV主要倾向于实时视觉应用，并在可用时利用MMX和SSE指令， 如今也提供对于C#、Ch、Ruby，GO的支持。 [2] 

## 文档

[中文官方](http://www.woshicver.com)

## 环境配置

1. 库+命令行编程`cmake g++ opnecv库`
2. 库+IDE`Qtcreator opencv`

### linux

```bash
# 安装编译依赖工具
sudo apt-get install build-esssential
# 安装基本辅助工具及库
sudo apt-get install cmake git pkg-config libgtk2.0-dev libavcodec-dev libabformat-dev libswscale-dev qt5-default
# 安装相关关联库
sudo apt-get install python-dev python-opencv python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
# 安装opencv库
sudo apt-get install libopencv-dev
# 或者源码安装
https://opencv.org/releases/
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig

# g++编译
g++ -I/usr/local/include/opencv4/ main.cpp -o demo -lopencv_core -lopencv_imgproc -lopencv_imgcodecs -lopencv_highgui
# cmake编译
cmake_minimum_required(VERSION 3.2)
project(demo)
find_package(OpenCV REQUIRED)
add_executable(demo main.cpp)
target_link_libraries(demo $(OpenCV_LIBS))
```

### mac

```bash
# 使用brew
brew install opencv
# 使用源码
brew install gcc, openblas, suite-sparse, tbb, ceres-solver, numpy, gl2ps, glew, libaec, hdf5, jsoncpp, netcdf, pugixml, qt@5, pyqt@5, utf8cpp and vtk
https://opencv.org/releases/
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..
make -j4
sudo make install
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
```

