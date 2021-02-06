/*第四章课后练习1

建立一个500x500大小的单通道图像,每个像素值都为0
1.创建一个ASCII数字打字机,你可以在自己的电脑上输入数字,并在一个20像素高、10像素宽的方格中显示数字。当你键入时，数字从左到右显示，知道到达图像末尾才停止。
2.允许键入回车和退格。
3.允许使用箭头来编辑每个数字。
4.创建一个键来将输出图像转化为彩色图像，每个不同的数字由不同的颜色显示。*/
#include "opencv2/opencv.hpp"

//实现a的部分
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

const int display_height = 500;
const int display_weight = 500;
vector<cv::Mat1b> numbers;

void init_numbers(void);
void help(void);

int main(int argc, char **argv) {

	cv::Mat1b  cursorMat(1,10);
	cursorMat.zeros(1, 10);
	for (int i = 0; i < 10; i++)
		cursorMat.at<uchar>(0, i) = 255;



	init_numbers();
	help();
	cv::Mat1b display = cv::Mat1b::zeros(display_height,display_weight);
	int count = 0;
	unsigned hang = 0;//行
	unsigned lie = 0;//列

	//show the empty image
	cv::namedWindow("Typewriter",cv::WINDOW_AUTOSIZE);
	//cv::imshow("TYpewriter",display);
	
	//loop for input
	int c= cv::waitKey(0);
	do {
		
		if ((char)c==13)
		{
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 0;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * (lie ), 10 + 10 * (lie )));
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			hang++;
			lie = 0;
			c = 0;
		}
		else if ((char)c == 8)
		{
			
			count--;
			if (count < 0)
			{
				count = 0;
				c = 0;
				continue;
			}
			int tmp = lie;
			if (tmp > 0)
				lie--;
			else if (tmp==0)
			{
				hang--;
				lie = (display_weight / 10);
			}
			cout << "hang:" << hang << "lie:" << lie << endl;
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 0;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * (lie+1), 10 + 10 * (lie+1)));

			numbers[10].copyTo(display.rowRange(0+20*hang,20+20*hang).colRange(0 + 10 * lie, 10 + 10 * lie));
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//光标显示
	
		}
		else if((char)c>='0' && (char)c<='9'){
			cout << "number input" << endl;
			numbers[c - '0'].copyTo(display.rowRange(0 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
	
			count++;
			lie++;
			if (lie == (display_weight/10)) {
				lie = 0; 
				hang++;
			}
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
		}
		
		cout << (char)c << endl;
		cv::imshow("Typewriter", display);
		c = cv::waitKey(0);
	} while (1);

	cv::waitKey(0);
	return 0;
}

void init_numbers() {
	//init numbers
	for (int i = 0; i < 11; i++) {
		numbers.push_back(cv::Mat1b::zeros(20, 10));
	}
	//0
	for (int i = 2; i < 8; i++)
	{
		numbers[0].at<unsigned char>(2, i) = 255;
		numbers[0].at<unsigned char>(17, i) = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers[0].at<unsigned char>(i, 2) = 255;
		numbers[0].at<unsigned char>(i, 7) = 255;
	}

	//1
	for (int i = 2; i < 8; i++)
	{
		numbers[1].at<uchar>(17, i) = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers[1].at<uchar>(i, 5) = 255;
	}
	numbers[1].at<uchar>(5, 2) = 255;
	numbers[1].at<uchar>(4, 3) = 255;
	numbers[1].at<uchar>(3, 4) = 255;
	numbers[1].at<uchar>(2, 5) = 255;

	//2:
	for (int i = 2; i < 8; i++)
	{
		numbers[2].at<uchar>(2, i) = 255;
		numbers[2].at<uchar>(9, i) = 255;
		numbers[2].at<uchar>(17, i) = 255;
	}
	for (int i = 3; i < 9; i++)
	{
		numbers[2].at<uchar>(i, 7) = 255;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers[2].at<uchar>(i, 2) = 255;
	}

	//3:
	for (int i = 2; i < 8; i++)
	{
		numbers[3].at<unsigned char>(2, i) = 255;
		numbers[3].at<unsigned char>(9, i) = 255;
		numbers[3].at<unsigned char>(17, i) = 255;
	}
	for (int i = 3; i < 9; i++)
	{
		numbers[3].at<unsigned char>(i, 7) = 255;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers[3].at<unsigned char>(i, 7) = 255;
	}
	//4:
	for (int i = 2; i < 8; i++)
	{
		numbers[4].at<unsigned char>(10, i) = 255;
	}
	for (int i = 2; i < 18; i++)
	{
		numbers[4].at<unsigned char>(i, 5) = 255;
	}
	numbers[4].at<unsigned char>(4, 4) = 255;
	numbers[4].at<unsigned char>(5, 4) = 255;
	numbers[4].at<unsigned char>(6, 3) = 255;
	numbers[4].at<unsigned char>(7, 3) = 255;
	numbers[4].at<unsigned char>(8, 3) = 255;
	numbers[4].at<unsigned char>(9, 2) = 255;
	numbers[4].at<unsigned char>(10, 2) = 255;
	//5:
	for (int i = 2; i < 8; i++)
	{
		numbers[5].at<unsigned char>(2, i) = 255;
		numbers[5].at<unsigned char>(9, i) = 255;
		numbers[5].at<unsigned char>(17, i) = 255;
	}
	for (int i = 3; i < 9; i++)
	{
		numbers[5].at<unsigned char>(i, 2) = 255;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers[5].at<unsigned char>(i, 7) = 255;
	}
	//6:
	for (int i = 2; i < 8; i++)
	{
		numbers[6].at<unsigned char>(2, i) = 255;
		numbers[6].at<unsigned char>(9, i) = 255;
		numbers[6].at<unsigned char>(17, i) = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers[6].at<unsigned char>(i, 2) = 255;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers[6].at<unsigned char>(i, 7) = 255;
	}
	//7:
	for (int i = 2; i < 8; i++)
	{
		numbers[7].at<unsigned char>(2, i) = 255;
	}
	for (int i = 3; i < 6; i++)
	{
		numbers[7].at<unsigned char>(i, 7) = 255;
	}
	for (int i = 6; i < 10; i++)
	{
		numbers[7].at<unsigned char>(i, 6) = 255;
	}
	for (int i = 10; i < 14; i++)
	{
		numbers[7].at<unsigned char>(i, 5) = 255;
	}
	for (int i = 14; i < 18; i++)
	{
		numbers[7].at<unsigned char>(i, 4) = 255;
	}
	//8:
	for (int i = 2; i < 8; i++)
	{
		numbers[8].at<unsigned char>(2, i) = 255;
		numbers[8].at<unsigned char>(9, i) = 255;
		numbers[8].at<unsigned char>(17, i) = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers[8].at<unsigned char>(i, 2) = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers[8].at<unsigned char>(i, 7) = 255;
	}
	//9:
	for (int i = 2; i < 8; i++)
	{
		numbers[9].at<unsigned char>(2, i) = 255;
		numbers[9].at<unsigned char>(9, i) = 255;
		numbers[9].at<unsigned char>(17, i) = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers[9].at<unsigned char>(i, 7) = 255;
	}
	for (int i = 3; i < 10; i++)
	{
		numbers[9].at<unsigned char>(i, 2) = 255;
	}


	//10 空白符号用于清空

}
void help() {
	std::cout << "Please Input number '0'-'9',and other keys will quit" << std::endl;
}