#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

using namespace std;
using namespace cv;

Mat src, dst, warpMat;
vector<Point2f> srcCorners(4), dstCorners(4);
int clickNums;

void trans()
{
    dstCorners[0] = Point2f(0, 0);
    dstCorners[1] = Point2f(100, 0);
    dstCorners[2] = Point2f(100, 200);
    dstCorners[3] = Point2f(0, 200);
    printf("dst %d", dstCorners.size());
    warpMat = getPerspectiveTransform(srcCorners, dstCorners);
    warpPerspective(src, dst, warpMat, dst.size());
    imshow("dst", dst);
    waitKey(0);
}

void mouseHandle(int event, int x, int y, int flags, void* param)
{
    if (event == EVENT_LBUTTONUP)
    {
        circle(src, Point2f(x, y), 1, Scalar(0, 255, 0), -1);
        imshow("src", src);
        srcCorners[clickNums] = Point2f(x, y);
        clickNums++;
        printf("%d\n", clickNums);
        printf("%d", srcCorners.size());
    }
    if (event == EVENT_LBUTTONUP && clickNums == 4)
    {
        printf("over\n");
        trans();
    }
}


int main()
{
    src = imread("../card.png");
    if (src.empty())
    {
        printf("image read: Failed.");
        getchar();
        return -1;
    }
    imshow("src", src);
    setMouseCallback("src", mouseHandle);
    waitKey(0);
    return 0;
}

