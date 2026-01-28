#pragma once
#include <opencv2/opencv.hpp>

void grayscale(cv::Mat& frame);
void sepia(cv::Mat& frame);
void invertColors(cv::Mat& frame);
void blur(cv::Mat& frame);
void cartoon(cv::Mat& frame);
void rgb(cv::Mat& frame);
void hsv(cv::Mat& frame);
void pencilSketch(cv::Mat& frame);
