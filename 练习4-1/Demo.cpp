/*�����¿κ���ϰ1

����һ��500x500��С�ĵ�ͨ��ͼ��,ÿ������ֵ��Ϊ0
1.����һ��ASCII���ִ��ֻ�,��������Լ��ĵ�������������,����һ��20���ظߡ�10���ؿ�ķ�������ʾ���֡��������ʱ�����ִ�������ʾ��֪������ͼ��ĩβ��ֹͣ��
2.�������س����˸�
3.����ʹ�ü�ͷ���༭ÿ�����֡�
4.����һ�����������ͼ��ת��Ϊ��ɫͼ��ÿ����ͬ�������ɲ�ͬ����ɫ��ʾ��*/

//ʵ��a�Ĳ���
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
	unsigned hang = 0;//��
	unsigned lie = 0; //��


	cv::Mat3b displayMat3 = cv::Mat3b::zeros(display_height, display_weight);
	for (size_t i = 0; i < display_height; i++)
		for (size_t j= 0; j < display_weight; j++)
	{
			displayMat3.at<cv::Vec3b>(j, i)[0] = rand() * 255;
			displayMat3.at<cv::Vec3b>(j, i)[1] = rand() * 255;
			displayMat3.at<cv::Vec3b>(j, i)[2] = rand() * 255;
	}
	//show the empty image
	cv::namedWindow("Typewriter",cv::WINDOW_AUTOSIZE);
	//cv::imshow("TYpewriter", display);
	
	//loop for input
	int c= cv::waitKeyEx(0);
	do {
		if (c == 2490368) {//���ϼ�ͷ
			
	
			if (hang > 0) {//���ǵ�һ��
				//���ع��
				for (int i = 0; i < 10; i++)
					cursorMat.at<uchar>(0, i) = 0;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie , 10 + 10 * lie ));
				hang--;
			}
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//��ʾ���
				count = hang * 50+lie;
		}
		else if(c == 2621440){//���¼�ͷ
			if (hang < ((display_height / 20) - 1))//�������һ��
			{
				//���ع��
				for (int i = 0; i < 10; i++)
					cursorMat.at<uchar>(0, i) = 0;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
				hang++;
			}
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//��ʾ���
			count = hang * 50 + lie;
		}
		else if (c == 2424832) {//����ļ�ͷ
			if (lie > 0) {
				//���ع��
				for (int i = 0; i < 10; i++)
					cursorMat.at<uchar>(0, i) = 0;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
				lie--;
			}
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//��ʾ���
			count = hang * 50 + lie;
		}
		else if (c == 2555904) {//���ҵļ�ͷ
			if (lie < (display_weight / 10) - 1) {
				//���ع��
				for (int i = 0; i < 10; i++)
					cursorMat.at<uchar>(0, i) = 0;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
				lie++;
			}
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//��ʾ���
			count = hang * 50 + lie;
		}
		else if ((char)c==13)//����
		{
			//ɾ�����Ĺ��
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 0;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * (lie ), 10 + 10 * (lie )));
			if (hang < ((display_height / 20) - 1))//�������һ��
				hang++;

	
			count = hang*50;
			lie = 0;
			c = 0;
			//��ʾ���
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * (lie), 10 + 10 * (lie)));
		}
		else if ((char)c == 8)//backspace ɾ����
		{
			count--;
			if (count < 0)
			{
				count = 0;
				c = 0;
				continue;
			}
			int tmp = lie;
			if (tmp > 0) {
				lie--;
				//���ع��
				for (int i = 0; i < 10; i++)
					cursorMat.at<uchar>(0, i) = 0;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * (lie + 1), 10 + 10 * (lie + 1)));
			
			}
			else if (tmp==0)
			{
				for (int i = 0; i < 10; i++)
					cursorMat.at<uchar>(0, i) = 0;
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie , 10 + 10 * lie ));
				hang--;
				lie = (display_weight / 10)-1;
			}
			cout << "hang:" << hang << "lie:" << lie << endl;
					numbers[10].copyTo(display.rowRange(0+20*hang,20+20*hang).colRange(0 + 10 * lie, 10 + 10 * lie));
			for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//�����ʾ
	
		}
		else if((char)c>='0' && (char)c<='9'){
			cout << "number input" << endl;
			//���ָ��Ƶ���ʾ�����Ӧ��λ��
			numbers[c - '0'].copyTo(display.rowRange(0 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
			if (hang< display_weight / 10 - 1)
			{

				count++;
				lie++;
				if (lie == (display_weight/10)) {
					if (hang < ((display_height / 20) - 1)) {
						lie = 0;
						hang++;
					}
					else {//��λ�����һ�к��� 
						lie = (display_weight / 10) - 1;
					}
				}
				cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//��ʾ���
			}
		}
		
		cout << (char)c << endl;
		cv::imshow("Typewriter", display);
		c = cv::waitKeyEx(0);
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


	//10 �հ׷����������

}
void help() {
	std::cout << "Please Input number '0'-'9',and other keys will quit" << std::endl;
}