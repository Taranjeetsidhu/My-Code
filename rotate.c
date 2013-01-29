#include <cv.h>
#include <highgui.h>
#include <math.h>
int main( int argc, char** argv )
{
    IplImage* src = cvLoadImage("imag.jpg", 1);    
    IplImage* Welcome = cvCloneImage( src );

    int delta = 1;
    int angle = 0;
    int opt;
	printf("\nEnter 1 to Zoom & Rotate 0 to rotate only\n");
	scanf("%d",&opt);  						// 1： rotate & zoom
               						// 0:  rotate only
    double factor;

    for(;;)
    {
    float m[6];
    CvMat M = cvMat(2, 3, CV_32F, m);
    int w = src->width;
    int h = src->height;

    if(opt)  
        factor = (cos(angle*CV_PI/180.) + 1.05) * 2;
    else 
        factor = 1;
    m[0] = (float)(factor*cos(-angle*2*CV_PI/180.));
    m[1] = (float)(factor*sin(-angle*2*CV_PI/180.));
    m[3] = -m[1];
    m[4] = m[0];
    m[2] = w*0.5f;  
    m[5] = h*0.5f;  

    cvGetQuadrangleSubPix( src, Welcome, &M);
    cvNamedWindow("Welcome", 1);
    cvShowImage("Welcome", Welcome);
    if( cvWaitKey(1) == 27 )
        break;
    angle =(int)(angle + delta) % 360;
    }     
    return 0;
}
