void rotationImg()
{
CvMat* rot_mat = cvCreateMat(2,3,CV_32FC1);

IplImage* src = cvLoadImage("img.jpg");
IplImage* dst = cvCreateImage(cvSize(src->width,src->height), src->depth, src->nChannels);
CvPoint2D32f center = cvPoint2D32f(
src->width/2,
src->height/2
);
double angle = -50.0;
double scale = 0.6;
cv2DRotationMatrix( center, angle, scale, rot_mat );

cvWarpAffine( src, dst, rot_mat );
cvNamedWindow( "Affine_Transform", 1 );
cvShowImage( "Affine_Transform", dst );
cvWaitKey();
cvSaveImage("D:/imgRotada.png",dst);
cvReleaseImage( &dst );
cvReleaseMat( &rot_mat ); 
}
