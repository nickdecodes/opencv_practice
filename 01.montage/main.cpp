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
#include <iostream>
#include <vector>
#include <cstdio>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[]) {
    int image_count = 39;

    // 想要生成的图片
    Mat srcImage = imread("../test/xihu1.jpg");
    cout << srcImage.size() << endl;

    // 通过resize方法，进行尺寸设置
    resize(srcImage, srcImage, Size(1920, 1080));
    cout << srcImage.size() << endl;

    // 存放资源文件
    vector<Mat> source_images;
    char filenames[20];
    for (int i = 1; i <= 39; i++) {
        Mat src_img;
        snprintf(filenames, sizeof("../data/cat%d.jpg"), "../data/cat%d.jpg", i);

        // 根据路径读取文件
        src_img = imread(filenames);
        resize(src_img, src_img, Size(30,30) , 0, 0, INTER_NEAREST);
        source_images.push_back(src_img);
    }

    // cout << source_images.size() << endl;
    // imshow("first", source_images[1]);

    // 制作相关的步骤
    int width = 1920; // srcImage.cols
    int height = srcImage.rows;

    // 根据宽高 去计算横纵需要的图片个数

    // 根据颜色进行匹配

    // 生成对应的图片

    Mat montageImage;
    resize(srcImage, montageImage, Size(1920, 1080));
    /*
        直方图
            （1）根据图片的信息统计出直方图信息
            （2）根据直方图信息进行匹配
            （3）替换对应位置的图片
    */
    int bins = 128;
    int hist_sizes[] = {bins, bins, bins};
    float range[] = {0,255};
    const float *ranges[] = {range, range, range};
    int channels[] = {0, 1, 2};

    vector<MatND> hist_list;

    for (int i = 0; i < image_count; i++) {
        MatND hist_RGB;
        Mat frame;
        source_images[i].copyTo(frame);

        // 计算直方图信息
        calcHist(&frame, 1, channels, Mat(), hist_RGB, 3, hist_sizes, ranges, true, false);

        hist_list.push_back(hist_RGB);
    }

    int number_order = 0;
    for (int y = 0; y < height; y = y + 30) {
        for (int x = 0; x < width; x = x + 30) {
            Mat roiImage = montageImage(Rect(x, y, 30, 30));

            MatND hist_roi;

            double match_max = 0.0;
            calcHist(&roiImage, 1, channels, Mat(), hist_roi, 3, hist_sizes, ranges, true, false);

            for (int i = 0; i < image_count; i++) {
                double match = 0;
                match = compareHist(hist_roi, hist_list[i], HISTCMP_CORREL);

                if (match > match_max) {
                    // 将匹配度最高的值算出来
                    number_order = i;
                    match_max = match;
                }

            }
            source_images[number_order].copyTo(roiImage);

            printf("正在生成中：\033[01;32m %.2f%% \r", (y / (double)1080 + x / (double)1920 / 100 ) * 100);
            fflush(stdout);
        }
    }

    Mat dstImage;
    addWeighted(montageImage, 0.2, srcImage, 0.8, 3, dstImage);
    imwrite("../test/dstImage.jpg", dstImage);

    imshow("montage", dstImage);


	waitKey(0);

    return 0;
}
