#include <cv.h>
#include <highgui.h>
#include <string>
#include <fstream>
#include <direct.h>

using namespace std;

int main()
{
	ifstream fin;
	string filename = "C://Users//ZBY//Desktop//list.txt";//the directory of video files' path and name
	string videoname = "";
	fin.open(filename);
	char videoname2[60];
	int count = 1;
	IplImage* img = NULL;
	cvNamedWindow("image");
	CvCapture* pCapture = NULL;
	char picname[100];

	while (fin.good())
	{

		fin >> videoname;
		strcpy(videoname2, videoname.c_str());



		if (!(pCapture = cvCaptureFromFile(videoname2)))
		{
			fprintf(stderr, "Can not open the file");
			return -2;
		}

		int frameH = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_HEIGHT);
		int frameW = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_WIDTH);
		int fps = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FPS);
		int numFrames = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_COUNT);

		char foldername[100];
		sprintf(foldername, "C://Users//ZBY//Desktop//video%d", count);
		_mkdir(foldername);
		int pframe = 1;
		while (img = cvQueryFrame(pCapture))
		{
			if (1)//pframe % 20 == 0)
			{
				sprintf(picname, "C://Users//ZBY//Desktop//video%d//%d.jpg", count, pframe);
				cvSaveImage(picname, img);
			}
			pframe++;
			cvShowImage("image", img);
			cvWaitKey(2);
		}
		count = count + 1;
	}
	cvReleaseImage(&img);
	cvReleaseCapture(&pCapture);
	cvDestroyWindow("image");
}