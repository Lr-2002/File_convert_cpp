//
// Created by lr-2002 on 2021/4/30.
//

#include<iostream>
#include<vector>
#include"opencv2/core/core.hpp"
#include"opencv2/opencv.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;
void read_intrinsics(Mat &cameraMatrix,Mat &distCoeffs,Size &imageSize,char *IntrinsicsPath)
{
    bool FsFlag = false;
    FileStorage readfs;
    FsFlag = readfs.open(IntrinsicsPath,FileStorage::READ);
    if (FsFlag == false)
    {
        cout<<"Cannot read the file"<<endl;
    }
    readfs["camera_matrix"] >> cameraMatrix;
    readfs["distortion_coefficients"]>>distCoeffs;
    readfs["image_width"] >> imageSize.width;
    readfs["image_height"] >> imageSize.height;
    cout<< cameraMatrix << endl<< distCoeffs <<endl << imageSize <<endl;
    readfs.release();
}

void Undistort_image(const Mat &map1,const Mat &map2, char *path)
{
    Mat img1,img2;
    img1 = imread(path);
    if (img1.empty()) cout << "Cannot read the image"<<endl;
    remap(img1,img2,map1,map2,INTER_LINEAR);
    imshow("img1",img1);
    imshow("img2",img2);
    waitKey(0);
}


int main()
{
//    Mat img =imread("/home/lr-2002/code/File_convert_cpp/test.jpg");
//    namedWindow("Displayedimage");
    Mat cameraMatrix , distCoeffs , map1 , map2 ;
    Size imagesize;
    char *IntrinsicsPath = "out_camera_data.xml";
    read_intrinsics(cameraMatrix,distCoeffs, imagesize , IntrinsicsPath);
//   initUndistortRectifyMap(cameraMatrix,distCoeffs,Mat(),Mat(),
//                           imagesize,CV_16SC2,map1 ,map2 );
    initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(), Mat(),
                            imagesize, CV_16SC2, map1, map2);
   Undistort_image(map1,map2,"/home/lr-2002/code/File_convert_cpp/test.jpg");


//    imshow("CAT",img)/;

    return 0;




}