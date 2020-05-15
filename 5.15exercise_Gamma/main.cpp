#include<opencv2/opencv.hpp>


//定义Gamma函数
void Gamma(cv::Mat& src, cv::Mat& dst, float K)
{
	uchar LUT[256];
	src.copyTo(dst);
	for (int i = 0; i < 256; i++) 
	{
		float f = i / 255.0;
		f = pow(f, K);
		LUT[i] = cv::saturate_cast<uchar>(f*255.0);
	}

	if (dst.channels() == 1)
	{
		cv::MatIterator_<uchar> it = dst.begin<uchar>();
		cv::MatIterator_<uchar> it_end = dst.end<uchar>();
		for (; it != it_end; ++it) 
		{
			*it = LUT[(*it)];
		}
	}
	else
	{
		cv::MatIterator_<cv::Vec3b> it = dst.begin<cv::Vec3b>();
		cv::MatIterator_<cv::Vec3b> it_end = dst.end<cv::Vec3b>();
		for (; it != it_end; ++it) 
		{
			(*it)[0] = LUT[(*it)[0]];
			(*it)[1] = LUT[(*it)[1]];
			(*it)[2] = LUT[(*it)[2]];
		}
	}

}

int main() {

	cv::Mat src = cv::imread("E:\\PIC\\gtest.jpg");
	cv::Mat dst;

	Gamma(src, dst,0.5); //进行Gamma变换

	imshow("src", src);
	imshow("dst", dst);
    waitKey(0);
}
   
