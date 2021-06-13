//
// Created by 16337 on 2021/6/9 0009.
//
// MySAD.cpp : 定义控制台应用程序的入口点。
//

#include "Sad.h"
#include <iostream>

int main()
{
    Mat Img_L=imread("../Aloe0.jpg",0);
    Mat Img_R=imread("../Aloe1.jpg",0);
    Mat Disparity;    //视差图

    //Sad mySAD;
    Sad mySAD(7,30);
    Disparity= mySAD.compute(Img_L, Img_R);

    imshow("Img_L",Img_L);
    imshow("Img_R",Img_R);
    imshow("Disparity",Disparity);
    waitKey();
    return 0;
}
