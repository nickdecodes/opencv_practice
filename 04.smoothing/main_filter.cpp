/**
@Author  : zhengdongqi
@Email   :
@Usage   :
@Filename: main_filter.cpp
@DateTime: 2022/11/20 11:59
@Software: CLion
**/

//
// Created by 郑东琦 on 2022/11/20.
//

#include <opencv2/opencv.hpp>
using namespace cv;
#include <iostream>
using namespace std;

int main() {
    // 读取图片
    Mat srcImg = imread("../house.jpg");
    // 创建卷积核 掩码 如果是在滤波当中使用，一般都是3 5 7
    Mat kernel = (Mat_<double>(3,3) <<
    -2,0,2,
    -2,0,2,
    -2,0,2);
    // 进行卷积化处理
    Mat resultImg;
    // OpenCV提供了一个卷积处理函数filter2D
    filter2D(srcImg, resultImg, srcImg.depth(), kernel);

    imshow("srcImg", srcImg);
    imshow("result", resultImg);

    waitKey(0);
    return 0;
}