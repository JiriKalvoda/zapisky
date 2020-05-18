#include <stdio.h>
#include <opencv2/opencv.hpp>
int main(int argc, char *argv[])
{
	if(argc<2) return 10;
    
    std::cout << "Testovaci program pro OpenCV"<<std::endl;
    // nacteni obrazku
    cv::Mat image = cv::imread(argv[1], 1);
    // tisk matice
    std::cout << image<< std::endl;
	
	//ukončení konzolové aplikace
    return 0;
}
