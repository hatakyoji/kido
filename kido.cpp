//---------------------------------------------------------
// 概要      : 明度の確認
// File Name : kido.cpp
// Library   : OpenCV 2.0
//---------------------------------------------------------

#include <stdio.h>
#include <highgui.h>
#include <cv.h>

#pragma comment (lib,"cv200d.lib")
#pragma comment (lib,"cxcore200d.lib")
#pragma comment (lib,"highgui200d.lib")

#define WIDTH	640	//	キャプチャ画像の横幅
#define HEIGHT	480	//	キャプチャ画像の縦幅


uchar v[1000],s[1000],h[1000];

int main( int argc, char** argv ){ 
	int key;					//	キー入力用の変数
	CvCapture *capture;				//	カメラキャプチャ用の構造体
	IplImage *frameImage;				//	キャプチャ画像用IplImage
	char windowNameCapture[] = "Capture";			//キャプチャした画像を表示するウィンドウの名前
	IplImage *hsvImage = cvCreateImage( cvSize(WIDTH,HEIGHT), IPL_DEPTH_8U, 3 );			//	HSV画像用IplImage
	int x, y;
	FILE *fp;
	int i,j,k,l;
	uchar h0,s0,v0,h1,s1,v1,h2,s2,v2,h3,s3,v3;

	//	カメラを初期化する
	if ( ( capture = cvCreateCameraCapture( 0 ) ) == NULL ) {
		//	カメラが見つからなかった場合
		printf( "カメラが見つかりません\n" );
		key = cvWaitKey( 10 );
	}


	//	ウィンドウを生成する
    cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );
	i = 0;
	j = 0;
	k = 0;

	//	メインループ
	while ( k<1000 ) {
		//	カメラからの入力画像フレームをframeImageに格納する
		printf("in");
		frameImage = cvQueryFrame( capture );
		printf("out");
		//frameImageをBGRからHSVに変換
		cvCvtColor(frameImage,hsvImage,CV_BGR2HSV);

      /* 画素値を直接操作する*/   
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


		//	画像を表示する
		cvShowImage( windowNameCapture, frameImage );
	    cvWaitKey( 1 );

	}	


	//	キャプチャを解放する
	cvReleaseCapture( &capture );
	//	ウィンドウを破棄する
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

