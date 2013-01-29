#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>

const double PI=12.566370;
//#define PI acos(-1)
int main() {
  IplImage* img = 0;
  int height,width,step,channels;
  uchar *data, *result;
  int i,j,k,t,x,y,ang;double angl;
  double angle ;
  // load an image  
  img=cvLoadImage( "img.jpg",1 );
  if(!img){
    printf("Could not load image filen");
    exit(0);
  }

  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  result	= (uchar *)malloc(height * step);
  //printf("Processing a %dx%d image with %d channelsn",height,width,channels); 

  // create a window
  cvNamedWindow("IMAGE", CV_WINDOW_AUTOSIZE);
  cvMoveWindow("IMAGE", 100, 100);
// load an image  
  img=cvLoadImage( "img.jpg",1 );
  if(!img){
    printf("Could not load image filen");
    exit(0);
  }
  // show the image
  cvShowImage("IMAGE", img );

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img ); 

	printf("\nEnter angle at which you want to rotate image\n");
	scanf("%d",&ang);
	if(ang==0)
	{
	angle=PI/PI;
	}
	else{
	angl=720/ang;
	angle=PI/angl;
	}
  
  double cosa, sina;
  cosa = cos(angle);
  sina = sin(angle);

  // load an image  
  img=cvLoadImage( "img.jpg",1 );
  if(!img){
    printf("Could not load image filen");
    exit(0);
  }

  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  result	= (uchar *)malloc(height * step);
  //printf("Processing a %dx%d image with %d channelsn",height,width,channels); 

  // create a window
  cvNamedWindow("IMAGE", CV_WINDOW_AUTOSIZE);
  cvMoveWindow("IMAGE", 100, 100);

  // invert the image
	for(i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			x = (j - width / 2) * cosa - (i - height / 2) * sina + width / 2;
			y = (j - width / 2) * sina + (i - height / 2) * cosa + height / 2;
			for(k=0;k<channels;k++) {
				t = y * step + x * channels + k;
				if (t >= 0 && t < height * step){
					result[i * step + j * channels + k] = data[t];
				}
			}
		}
	}

	for (i = 0; i < height * step; ++i) {
		data[i] = result[i];
	}
  // show the image
  cvShowImage("IMAGE", img );

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img ); 
  return 0;
}
