/**
@Author  : zhengdongqi
@Email   :
@Usage   :
@Filename: main.cpp
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

int main(int argc, char const *argv[]) {
    Mat srcImg = imread("../test/kai.png", IMREAD_UNCHANGED);
    Mat srcImg1 = imread("../test/kai.png", 0);
    Mat srcImg2 = imread("../test/kai.png", 1);

    cout << srcImg.channels() << endl;
    cout << srcImg1.channels() << endl;
    cout << srcImg2.channels() << endl;

    imshow("-1", srcImg);
    imshow("0", srcImg1);
    imshow("1", srcImg2);

    // 颜色有空间 RGB （1） RGBA(-1) 透明度  灰色空间(0)

    // 存储阶段的颜色值
    vector<Vec3d> colors;
    unsigned long index = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                colors.emplace_back();
                colors[index][0] = i / 5.0 * 255;
                colors[index][1] = j / 5.0 * 255;
                colors[index][2] = k / 5.0 * 255; 
                index++;  
            }
        }
    }
    // 更改对应的颜色值
    index = 0;
    Mat temp = srcImg.clone();
    while (index < colors.size()) {
        for (int r = 0; r < srcImg.rows; r++) {
            for (int c = 0; c < srcImg.cols; c++) {
                // 获取像素点的颜色值
                // Vec4b &pixel = srcImg.at<Vec4b>(r, c);
                auto &pixel_temp = temp.at<Vec4b>(r, c);
                // 如果当前点的透明度为0
                if (pixel_temp[3] == 0) {
                    continue;
                } else {
                    for (int i = 0; i < 3; i++) {
                        pixel_temp[i] = colors[index][i];
                    }
                }
            }
        }

        char outImagePath[64] = {};
        snprintf(outImagePath, sizeof("../out_img/out_img_%.0f_%.0f_%.0f.png"), "../out_img/out_img_%.0f_%.0f_%.0f.png", colors[index][0], colors[index][1], colors[index][2]);
        imwrite(outImagePath, temp);
        index++;
    }
    // 保存需要的图片

    // waitKey(0);
    return 0;
}
