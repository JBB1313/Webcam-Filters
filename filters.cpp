#include "filters.h"

void grayscale(cv::Mat& frame) {
	cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
}

void sepia(cv::Mat& frame) {
    cv::Mat temp = frame.clone();
    cv::transform(temp, frame, cv::Matx33f(
        0.272, 0.534, 0.131,
        0.349, 0.686, 0.168,
        0.393, 0.769, 0.189)
    );
}

void invertColors(cv::Mat& frame) {
    cv::bitwise_not(frame, frame);
}

void blur(cv::Mat& frame) {
    cv::GaussianBlur(frame, frame, cv::Size(5, 5), 10);
}

void cartoon(cv::Mat& frame) {
    cv::Mat res;
    cv::Mat mask;

    cv::GaussianBlur(frame, frame, cv::Size(3, 3), 1, 1);
    cv::cvtColor(frame, mask, cv::COLOR_BGR2GRAY);
    cv::Laplacian(mask, mask, CV_8U, 5);
    cv::threshold(mask, mask, 75, 255, cv::THRESH_BINARY_INV);

    frame.copyTo(res, mask);
    res.copyTo(frame);
}

void rgb(cv::Mat& frame) {
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
}

void hsv(cv::Mat& frame) {
    cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
}

void pencilSketch(cv::Mat& frame) {
    cv::Mat res;
    GaussianBlur(frame, res, cv::Size(3, 3), 1, 1);
    cv::cvtColor(res, res, cv::COLOR_BGR2GRAY);
    cv::Laplacian(res, res, CV_8U, 5);
    cv::threshold(res, res, 75, 255, cv::THRESH_BINARY_INV);
    cv::cvtColor(res, frame, cv::COLOR_GRAY2BGR);
}