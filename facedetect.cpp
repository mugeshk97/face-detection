#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/objdetect.hpp>
#include <iostream>

int main(){
    cv::VideoCapture cap(0);
    cv::Mat img;
    cv::Mat fliped, grayimg, resized;
    cv::CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_default.xml");
    while (true)
    {
        cap.read(img);
        std::vector<cv::Rect> faces;
        cv::flip(img, fliped, 1);
        faceCascade.detectMultiScale(fliped, faces, 1.1, 10);
        for (int i = 0; i < faces.size(); i++)
        {
            cv::rectangle(fliped, faces[i].tl(), faces[i].br(), cv::Scalar(255,0,255), 3);
        }
        cv::imshow("Frame", fliped);
        int key = cv::waitKey(1);
        
        if (key ==27)
        {
            break;
            cv::destroyWindow("Frame");
        }
        
    }
    
}
