/**
@Author  : zhengdongqi
@Email   :
@Usage   :
@Filename: montage.cpp
@DateTime: 2022/11/20 11:59
@Software: CLion
**/

//
// Created by 郑东琦 on 2022/11/20.
//

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char const *argv[]) {
    /*
        1、设置需要去除的颜色
        2、对整个图片进行颜色匹配
        3、展示效果
    */
    // 只有png是有透明度空间的，jpg是没有透明空间的
    Mat srcImg = imread("../test/lvbu.jpg", 1);
    cout << srcImg.channels() << endl;

    Vec3b color(0, 255, 0);
    int tempc = 0;
    // 先把图片放大，做完抠图后，再放小

    Mat temp;
    // 转换图片，增加透明区域
    cvtColor(srcImg, temp, COLOR_BGR2BGRA);
    for (int i = 0; i < srcImg.rows; i++) {
        for (int j = 0; j < srcImg.cols; j++) {
            Vec3b &pixel = srcImg.at<Vec3b>(i,j);
            Vec4b &pixel_temp = temp.at<Vec4b>(i,j);
            if (pixel[0] <= 30 && pixel[1] >= 210 && pixel[2] <= 30) {
                tempc = j + 1;
                pixel_temp[3] = 0;
            } else if (tempc == j - 1) {
                pixel_temp[3] = 0;
            }
        }
    }

    imshow("result", temp);
    imwrite("result.png", temp);
    waitKey(0);
    return 0;
}
