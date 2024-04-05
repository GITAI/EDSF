#include <iostream>

#include"EDLib.h"
#include "CED.h"
#include <opencv2/core/utils/logger.hpp>

int main(int argc, char *argv[]) {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);
    if (argc == 1)
    {
       throw std::runtime_error("Usage: ./esdf [image file path]");
    }
    std::string imgPath(argv[1]);
    cv::Mat img = cv::imread(imgPath);
    CED ced = CED(img);
    ced.run_CED();

    cv::Mat ellArcSeg = ced.drawEdgeSegmentsAfterSplit();
    cv::imshow("ellArcSeg", ellArcSeg);
    cv::waitKey();

    cv::Mat ellArc = ced.drawEllArc();
    cv::imshow("ellArc", ellArc);
    cv::waitKey();

    cv::Mat ellMap = ced.drawEllipses(img);
    cv::imshow("ellMap", ellMap);
    cv::waitKey();

    cv::Mat ellMapCluster = ced.drawEllipsesAfterCluster(img);
    cv::imshow("ellMapCluster", ellMapCluster);
    cv::waitKey();
    return 0;
}
