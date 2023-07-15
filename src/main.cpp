#include <vector>
#include <iostream>
#include <string>
#include  <opencv2/opencv.hpp>
#include "depixelizing.h"

int main(int argc, char** argv)
{
    if(argc < 4)
    {
        printf ("Usage: %s image_in image_out scale", argv[0]);
        return 0;
    }

    cv::Mat img = cv::imread(argv[1], cv::IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "ERROR: failed to load image" << std::endl;
        return -1;
    }
    std::string outname = (std::string) argv[2];
    float scale = atof(argv[3]);
    if (scale < 2.f)
    {
        scale = 2.f;
    }
    Depixelizing pix;
    pix.depixelize(img, scale, outname);

    return 0;
}
