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
//��Ų�ɫ����
vector<cv::Mat3b> numbers3b;
void init_numbers(void);
//��ʼ����ɫ�����0~1
void init_numbers3b(void);
void help(void);

int main(int argc, char **argv) {

	cv::Mat1b  cursorMat(1,10);
	cursorMat.zeros(1, 10);
	for (int i = 0; i < 10; i++)
		cursorMat.at<uchar>(0, i) = 255;

	init_numbers();
	init_numbers3b();
	help();
	cv::Mat1b display = cv::Mat1b::zeros(display_height,display_weight);
	int count = 0;
	unsigned hang = 0;//��
	unsigned lie = 0; //��


	cv::Mat3b displayMat3 = cv::Mat3b::zeros(display_height, display_weight);
	/*for (size_t i = 0; i < display_height; i++)
		for (size_t j= 0; j < display_weight; j++)
	{
			displayMat3.at<cv::Vec3b>(j, i)[0] = rand() * 255;
			displayMat3.at<cv::Vec3b>(j, i)[1] = rand() * 255;
			displayMat3.at<cv::Vec3b>(j, i)[2] = rand() * 255;
	}*/
	//show the empty image 
	cv::namedWindow("Typewriter",cv::WINDOW_AUTOSIZE);
	//cv::imshow("TYpewriter", display);
	
	//loop for input
	int c= cv::waitKeyEx(0);
	do {
		if (c=='s')//���һ�Ų�ɫͼƬ
		{
			//��ʾ��ɫͼƬ
			cv::imshow("��ɫͼƬ", displayMat3);
		}else if (c == 2490368) {//���ϼ�ͷ
		
			
	
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
					numbers3b[10].copyTo(displayMat3.rowRange(0 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
					for (int i = 0; i < 10; i++)
				cursorMat.at<uchar>(0, i) = 255;
			cursorMat.copyTo(display.rowRange(19 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));//�����ʾ
	
		}
		else if((char)c>='0' && (char)c<='9'){
			cout << "number input" << endl;
			//���ָ��Ƶ���ʾ�����Ӧ��λ��
			numbers[c - '0'].copyTo(display.rowRange(0 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
			//��ɫͼƬ
			numbers3b[c - '0'].copyTo(displayMat3.rowRange(0 + 20 * hang, 20 + 20 * hang).colRange(0 + 10 * lie, 10 + 10 * lie));
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

void init_numbers3b() {
	//init numbers
	for (int i = 0; i < 11; i++) {
		numbers3b.push_back(cv::Mat3b::zeros(20, 10));
	}
	//0
	for (int i = 2; i < 8; i++)
	{
		numbers3b[0].at<cv::Vec3b>(2, i)[0] = 125;
		numbers3b[0].at<cv::Vec3b>(2, i)[1] = 0;
		numbers3b[0].at<cv::Vec3b>(2, i)[2] = 0;
		numbers3b[0].at<cv::Vec3b>(17, i)[0] = 125;
		numbers3b[0].at<cv::Vec3b>(17, i)[1] = 0;
		numbers3b[0].at<cv::Vec3b>(17, i)[2] = 0;

	}
	for (int i = 3; i < 17; i++)
	{	
		numbers3b[0].at<cv::Vec3b>(i, 2)[0] = 125;
		numbers3b[0].at<cv::Vec3b>(i, 2)[1] = 0;
		numbers3b[0].at<cv::Vec3b>(i, 2)[2] = 0;
		numbers3b[0].at<cv::Vec3b>(i, 7)[0] = 125;
		numbers3b[0].at<cv::Vec3b>(i, 7)[1] = 0;
		numbers3b[0].at<cv::Vec3b>(i, 7)[2] = 0;
	}

	//1
	for (int i = 2; i < 8; i++)
	{
		numbers3b[1].at<cv::Vec3b>(17, i)[0] = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers3b[1].at<cv::Vec3b>(i, 5)[0] = 255;
	}
	numbers3b[1].at<cv::Vec3b>(5, 2)[0] = 255;
	numbers3b[1].at<cv::Vec3b>(4, 3)[0] = 255;
	numbers3b[1].at<cv::Vec3b>(3, 4)[0] = 255;
	numbers3b[1].at<cv::Vec3b>(2, 5)[0] = 255;

	//2:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[2].at<cv::Vec3b>(2, i)[1]= 125;
		numbers3b[2].at<cv::Vec3b>(9, i)[1]= 125;
		numbers3b[2].at<cv::Vec3b>(17, i)[1] = 125;
	}
	for (int i = 3; i < 9; i++)
	{
		numbers3b[2].at<cv::Vec3b>(i, 7)[1] = 125;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers3b[2].at<cv::Vec3b>(i, 2)[1] = 125;
	}

	//3:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[3].at<cv::Vec3b>(2, i)[1] = 255;
		numbers3b[3].at<cv::Vec3b>(9, i)[1] = 255;
		numbers3b[3].at<cv::Vec3b>(17, i)[1] = 255;
	}
	for (int i = 3; i < 9; i++)
	{
		numbers3b[3].at<cv::Vec3b>(i, 7)[1] = 255;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers3b[3].at<cv::Vec3b>(i, 7)[1] = 255;
	}
	//4:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[4].at<cv::Vec3b>(10, i)[2] = 125;
	}
	for (int i = 2; i < 18; i++)
	{
		numbers3b[4].at<cv::Vec3b>(i, 5)[2] = 125;
	}
	numbers3b[4].at<cv::Vec3b>(4, 4)[2] = 125;
	numbers3b[4].at<cv::Vec3b>(5, 4)[2] = 125;
	numbers3b[4].at<cv::Vec3b>(6, 3)[2] = 125;
	numbers3b[4].at<cv::Vec3b>(7, 3)[2] = 125;
	numbers3b[4].at<cv::Vec3b>(8, 3)[2] = 125;
	numbers3b[4].at<cv::Vec3b>(9, 2)[2] = 125;
	numbers3b[4].at<cv::Vec3b>(10, 2)[2] = 125;
	//5:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[5].at<cv::Vec3b>(2, i)[2] = 255;
		numbers3b[5].at<cv::Vec3b>(9, i)[2] = 255;
		numbers3b[5].at<cv::Vec3b>(17, i)[2] = 255;
	}
	for (int i = 3; i < 9; i++)
	{
		numbers3b[5].at<cv::Vec3b>(i, 2)[2] = 255;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers3b[5].at<cv::Vec3b>(i, 7)[2] = 255;
	}
	//6:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[6].at<cv::Vec3b>(2, i)[0] = 125;
		numbers3b[6].at<cv::Vec3b>(9, i)[0] = 125;
		numbers3b[6].at<cv::Vec3b>(17, i)[0] = 125;
		numbers3b[6].at<cv::Vec3b>(2, i)[1] = 125;
		numbers3b[6].at<cv::Vec3b>(9, i)[1] = 125;
		numbers3b[6].at<cv::Vec3b>(17, i)[1] = 125;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers3b[6].at<cv::Vec3b>(i, 2)[0] = 125;
		numbers3b[6].at<cv::Vec3b>(i, 2)[1] = 125;
	}
	for (int i = 10; i < 17; i++)
	{
		numbers3b[6].at<cv::Vec3b>(i, 7)[0] = 125;
		numbers3b[6].at<cv::Vec3b>(i, 2)[1] = 125;
	}
	//7:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[7].at<cv::Vec3b>(2, i)[0] = 255;
		numbers3b[7].at<cv::Vec3b>(2, i)[1] = 125;
	}
	for (int i = 3; i < 6; i++)
	{
		numbers3b[7].at<cv::Vec3b>(i, 7)[0] = 255;
		numbers3b[7].at<cv::Vec3b>(i, 7)[1] = 125;
	}
	for (int i = 6; i < 10; i++)
	{
		numbers3b[7].at<cv::Vec3b>(i, 6)[0] = 255;
		numbers3b[7].at<cv::Vec3b>(i, 6)[1] = 125;
	}
	for (int i = 10; i < 14; i++)
	{
		numbers3b[7].at<cv::Vec3b>(i, 5)[0] = 255;
		numbers3b[7].at<cv::Vec3b>(i, 6)[1] = 125;
	}
	for (int i = 14; i < 18; i++)
	{
		numbers3b[7].at<cv::Vec3b>(i, 4)[0] = 255;
		numbers3b[7].at<cv::Vec3b>(i, 6)[1] = 125;
	}
	//8:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[8].at<cv::Vec3b>(2, i)[1] = 255;
		numbers3b[8].at<cv::Vec3b>(9, i)[1] = 255;
		numbers3b[8].at<cv::Vec3b>(17, i)[1] = 255;
		numbers3b[8].at<cv::Vec3b>(2, i)[2] = 255;
		numbers3b[8].at<cv::Vec3b>(9, i)[2] = 255;
		numbers3b[8].at<cv::Vec3b>(17, i)[2] = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers3b[8].at<cv::Vec3b>(i, 2)[1] = 255;
		numbers3b[8].at<cv::Vec3b>(i, 2)[2] = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers3b[8].at<cv::Vec3b>(i, 7)[1] = 255;
		numbers3b[8].at<cv::Vec3b>(i, 7)[2] = 255;
	}
	//9:
	for (int i = 2; i < 8; i++)
	{
		numbers3b[9].at<cv::Vec3b>(2, i)[0] = 255;
		numbers3b[9].at<cv::Vec3b>(9, i)[0] = 255;
		numbers3b[9].at<cv::Vec3b>(17, i)[0] = 255;
		numbers3b[9].at<cv::Vec3b>(2, i)[2] = 255;
		numbers3b[9].at<cv::Vec3b>(9, i)[2] = 255;
		numbers3b[9].at<cv::Vec3b>(17, i)[2] = 255;
	}
	for (int i = 3; i < 17; i++)
	{
		numbers3b[9].at<cv::Vec3b>(i, 7)[0] = 255;
		numbers3b[9].at<cv::Vec3b>(i, 7)[2] = 255;
	}
	for (int i = 3; i < 10; i++)
	{
		numbers3b[9].at<cv::Vec3b>(i, 2)[0] = 255;
		numbers3b[9].at<cv::Vec3b>(i, 2)[2] = 255;
	}


	//10 �հ׷����������

}
void help() {
	std::cout << "Please Input number '0'-'9',and other keys will quit" << std::endl;
}