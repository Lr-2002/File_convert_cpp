//
// Created by lr-2002 on 2021/4/30.
//
#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/opencv.hpp"
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/imgcodecs.hpp"
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
using namespace cv;
int morph_elem = 0 ;

bool dis(int x1,int y1,int x2,int y2,int r)
{
    if (pow(x1-x2,2)+pow(y1-y2,2)>pow(r,2))
    {
        return true;
    }
    else return false;
}

bool cmp(Point a, Point b)
{
    return a.x < b.x;
}

void show(Mat & temp)
{

    imshow("temp",temp);
    waitKey(0);
}

void get_range_image(Mat &img,int x1,int x2,int y1,int y2) {

    //<editor-fold desc="change the image and get concrete contours info">
    Mat temp = img(Rect(x1, y1, x2, y2));
    show(temp);
    Mat kernel = Mat::ones(Size(3,3),CV_8UC1);
    morphologyEx(temp,temp,MORPH_CLOSE,kernel);
    cvtColor(temp,temp,COLOR_BGR2GRAY); // convert temp into a gray image
    GaussianBlur(temp,temp,Size(1,1),0);
    Mat dst;
    threshold(temp,dst,0,255,THRESH_BINARY|THRESH_OTSU);
//    Mat cannypic = Canny()
    Mat canny;
    Canny(dst,canny,1,200);
//    Mat contours,hierarchy;
    vector<vector<Point>> contours(1000);
    vector<Vec4i>hierarchy;
    findContours(canny,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_NONE);
    drawContours(img,contours,-1,(0,0,255),1);
    show(img);
    //</editor-fold>

    //------------------------------------------------------------------------------------------
    //

    // point --x / y
    vector<int> x,r,y;

    for (int i =0;i<contours.size();i++)
    {
//        cout << i<<endl;
        int maxn = 0;
        int mx = 0;
        int mi = 10000;
        int minn = 10000;
        for (int j=0;j<contours.size();j++)
        {
           maxn = max(contours[i][j].y,maxn);
           mx = max (contours[i][j].x , mx );
           mi  =  min (contours[i][j].x , mi);
           minn = min  (contours[i][j].y,minn);
           cout << contours[i][j] << endl;
        }
        int leng = maxn - minn;
        int lenn = mx- mi;
        if (leng <= 35 && lenn <=35 &&leng>=2 && lenn>=2) // 35 is a contours set by me
        {
            if(x.size()==0)
            {
                x.push_back(mx/2 + mi /2);
                y.push_back(maxn/2 + minn/2 );
                int rr =max(leng/2, lenn/2);
                r.push_back(rr);

            }
            else{
                bool flag =false;
                for(int j = 0;j<x.size();j++)
                {
                    if(dis(mx/2+mi/2,maxn/2+minn/2 , x[j],y[j],r[j]))
                    {
                        flag = true;
                    }
                    flag = false;
                }
                if (flag)
                {
                    x.push_back(mx/2+mi/2);
                    y.push_back(maxn/2 + minn/2);
                    int rr = max(leng/2, lenn/2);
                    r. push_back(rr);
                }
            }
        }
    }


    vector<int> cnt, high;
    for (int i=0;i<x.size();i++)
    {
        if (!high.empty())
        {
            bool flag =1;
            for(int j=0;j<=high.size();j++)
            {
                if (y[i]>high[j]-20 && y[i]<high[j] +20)
                {
                    cnt[j] +=1;
                    flag =0;
                    break;
                }
            }
        }
        else{
            high.push_back(y[i]);
            cnt.push_back(1);
        }
    }
    int mnum = 0;
    int mnui = 0;
    for(int i=0;i<cnt.size();i++)
    {
        if (cnt[i]>mnum)
        {
            mnum = cnt[i];
            mnui = i;
        }
    }
    vector<int > res,rex,rey;
    vector<Point>retu;
    for (int i=0;i<x.size();i++)
    {
        res.push_back(i);
        rex.push_back(x[i]);
        rey.push_back(y[i]);
        retu.push_back(Point(x[i],y[i]));
    }
    sort(retu.begin(),retu.end(),cmp);
    cout<<"after sorted:"<<retu.size();
    for(int i=0;i<retu.size();i++)
    {
        cout<<retu[i].x<<" "<<retu[i].y<<endl;
    }
}

int main()
{
    Mat img;
    img = imread("/home/lr-2002/code/File_convert_cpp/test.jpg");

    Point pt1(899,924);
    Point pt2(240,89); // infact the pic of the rect
    cout << pt1.x<<endl;
    get_range_image(img ,pt1.x,pt2.x,pt1.y,pt2.y);
    return 0;
}