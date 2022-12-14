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

#include <vector>
#include <iostream>
using namespace std;

int trackbarvalue;
Mat image;

void trackbarcallback(int value, void *data) {
    cout << value << endl;

    image &= 1;
    image *= value;

    imshow("window_name", image);
}

void mouseEventCallBack(int event, int x, int y, int flags, void *userdata) {
    cout << event << endl;
    cout << x << ":" << y << endl;
}

int main(int argc, char const *argv[]) {
    /* 图像存取相关函数 */
    // (1) 图片的绝对路径或相对路径 (2) 读入图片到Mat容器当中的存放方式
    Mat srcImage = imread("../logo.png", IMREAD_GRAYSCALE);
    image = srcImage;
    // autosize 在部分的环境下，可能无法改变窗口的大小 normal可以改变
    namedWindow("window_name", WINDOW_NORMAL);

    // 添加进度条，注意使用回调函数
    createTrackbar("trackbar","window_name", &trackbarvalue, 255, trackbarcallback);

    // 鼠标的操作
    setMouseCallback("window_name", mouseEventCallBack, (void *)&srcImage);

    // (1) 显示的图片名称 （2）图片的容器
    imshow("window_name", srcImage);

    /*
        1、保存的图片名称，注意需要带后缀名
        2、保存的源图片容器
        3、存储过程中的编码处理 比如压缩处理
    */
    vector<int> comparession;
    comparession.push_back(IMWRITE_PNG_COMPRESSION);
    comparession.push_back(9);
    imwrite("gray_logo1.png", srcImage, comparession);

    // 键盘组操作   等待一个任意字符，参数为延迟时间
    waitKey(0);
    return 0;
}
