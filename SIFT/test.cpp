//
// Created by 16337 on 2021/5/22 0022.
//
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

    Mat imageL = imread("..\\left.jfif");
    Mat imageR = imread("..\\right.jfif");


    Ptr<SIFT> sift = SIFT::create();

    //特征点
    std::vector<KeyPoint> keyPointL, keyPointR;
    //单独提取特征点
    sift->detect(imageL, keyPointL);
    sift->detect(imageR, keyPointR);

    //画特征点
    Mat keyPointImageL;
    Mat keyPointImageR;
    drawKeypoints(imageL, keyPointL, keyPointImageL, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    drawKeypoints(imageR, keyPointR, keyPointImageR, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

    //显示窗口
    namedWindow("KeyPoints of imageL");
    namedWindow("KeyPoints of imageR");

    //显示特征点
    imshow("KeyPoints of imageL", keyPointImageL);
    imshow("KeyPoints of imageR", keyPointImageR);

    //特征点匹配
    Mat despL, despR;
    //提取特征点并计算特征描述子
    sift->detectAndCompute(imageL, Mat(), keyPointL, despL);
    sift->detectAndCompute(imageR, Mat(), keyPointR, despR);

    std::vector<cv::DMatch> matches;

    if (despL.type() != CV_32F || despR.type() != CV_32F)
    {
        despL.convertTo(despL, CV_32F);
        despR.convertTo(despR, CV_32F);
    }

    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("FlannBased");
    matcher->match(despL, despR, matches);

    //计算特征点距离的最大值
    double maxDist = 0;
    for (int i = 0; i < despL.rows; i++)
    {
        double dist = matches[i].distance;
        if (dist > maxDist)
            maxDist = dist;
    }

    //挑选好的匹配点
    std::vector<DMatch> good_matches;
    for (int i = 0; i < despL.rows; i++)
    {
        if (matches[i].distance < 0.5 * maxDist)
        {
            good_matches.push_back(matches[i]);
        }
    }

    Mat imageOutput;
    drawMatches(imageL, keyPointL, imageR, keyPointR, good_matches, imageOutput);
    namedWindow("picture of matching");
    imshow("picture of matching", imageOutput);
    waitKey(0);
    return 0;
}


