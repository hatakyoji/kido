//---------------------------------------------------------
// �T�v      : ���x�̊m�F
// File Name : kido.cpp
// Library   : OpenCV 2.0
//---------------------------------------------------------

#include <stdio.h>
#include <highgui.h>
#include <cv.h>

#pragma comment (lib,"cv200d.lib")
#pragma comment (lib,"cxcore200d.lib")
#pragma comment (lib,"highgui200d.lib")

#define WIDTH	640	//	�L���v�`���摜�̉���
#define HEIGHT	480	//	�L���v�`���摜�̏c��


uchar v[1000],s[1000],h[1000];

int main( int argc, char** argv ){ 
	int key;					//	�L�[���͗p�̕ϐ�
	CvCapture *capture;				//	�J�����L���v�`���p�̍\����
	IplImage *frameImage;				//	�L���v�`���摜�pIplImage
	char windowNameCapture[] = "Capture";			//�L���v�`�������摜��\������E�B���h�E�̖��O
	IplImage *hsvImage = cvCreateImage( cvSize(WIDTH,HEIGHT), IPL_DEPTH_8U, 3 );			//	HSV�摜�pIplImage
	int x, y;
	FILE *fp;
	int i,j,k,l;
	uchar h0,s0,v0,h1,s1,v1,h2,s2,v2,h3,s3,v3;

	//	�J����������������
	if ( ( capture = cvCreateCameraCapture( 0 ) ) == NULL ) {
		//	�J������������Ȃ������ꍇ
		printf( "�J������������܂���\n" );
		key = cvWaitKey( 10 );
	}


	//	�E�B���h�E�𐶐�����
    cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );
	i = 0;
	j = 0;
	k = 0;

	//	���C�����[�v
	while ( k<1000 ) {
		//	�J��������̓��͉摜�t���[����frameImage�Ɋi�[����
		printf("in");
		frameImage = cvQueryFrame( capture );
		printf("out");
		//frameImage��BGR����HSV�ɕϊ�
		cvCvtColor(frameImage,hsvImage,CV_BGR2HSV);

      /* ��f�l�𒼐ڑ��삷��*/   
		x = 160;
		y = 120;

		h0 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s0 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];    // G      
		v0 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

    	     frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 161;
		y = 120;
		h1 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s1 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];    // G      
		v1 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 160;
		y = 121;

		h2 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s2= hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];     // G      
		v2 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

       	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;


		x = 161;
		y = 121;
		h3 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3];        // B
		s3 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 1];    // G      
		v3 = hsvImage ->imageData[hsvImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
     	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		v[i]=(v0+v1+v2+v3)/4;
		s[j]=(s0+s1+s2+s3)/4;
		h[k]=(h0+h1+h2+h3)/4;

		i++;
		j++;
		k++;


		//	�摜��\������
		cvShowImage( windowNameCapture, frameImage );
	    cvWaitKey( 1 );

	}	


	//	�L���v�`�����������
	cvReleaseCapture( &capture );
	//	�E�B���h�E��j������
	cvDestroyWindow(windowNameCapture);

	i=0;
	j=0;
	k=0;

	fp=fopen("kido.csv","w");
	for(l=0;l< 1000;l++){
		fprintf(fp,"%d,%d,%d \n",v[i],s[j],h[k]);
		i++;
		j++;
		k++;
	}
	fclose(fp);

	return 0;
}

