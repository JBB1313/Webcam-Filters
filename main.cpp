#include <opencv2/opencv.hpp>
#include "filters.h"
#include <iostream>

int main() {
  
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Couldnt open the camera." << std::endl;
        return -1;
    }
    
    std::cout << "Select which filter to use:\n";
    std::cout << "0: None\n";
    std::cout << "1: Grayscale\n";
    std::cout << "2: RGB\n";
    std::cout << "3: HSV (Hue Saturation)\n";
    std::cout << "4: Uncanny\n";
    std::cout << "5: Invert Colors\n";
    std::cout << "6: Sepia\n";
    std::cout << "7. Blur\n";
    std::cout << "8: Cartoon\n";
    std::cout << "9: Sketch\n";

    char filterChoice = '0';

    while (true) {
        cv::Mat frame;
        cap >> frame;

        if (frame.empty()) break;
        
        cv::Mat output;
        switch (filterChoice) {
        case '0':
            output = frame.clone();
            break;
        case '1':
            output = frame.clone();
            grayscale(output);
            break;
        case '2':
            output = frame.clone();
            rgb(output);
            break;
        case '3':
            output = frame.clone();
            hsv(output);
            break;
        case '4':
            Canny(frame, output, 50, 150);
            break;
        case '5':
            output = frame.clone();
            invertColors(output);
            break;
        case '6':
            output = frame.clone();
            sepia(output);
            break;
        case '7':
            output = frame.clone();
            blur(output);
            break;
        case '8':
            output = frame.clone();
            cartoon(output);
            break;
        case '9':
            output = frame.clone();
            pencilSketch(output);
            break;
        default:
            output = frame.clone();
            break;
        }
   

        cv::imshow("No Filter", frame);
        cv::imshow("Webcam Filter", output);

        char key = (char)cv::waitKey(1);
        if (key == 27) break;
        else if (key == '0' || key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9')
            filterChoice = key;
        
    }
        cap.release();
        cv::destroyAllWindows();
        return 0;
    }
