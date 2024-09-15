#include "stdafx.h"
#include "CImg.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace cimg_library;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp, *fp2;
	string input;
	int i, j, count = 0;
	cout << "intput the image name to compress:";
	cin >> input;
	CImg<unsigned char> src_image(input.c_str());//read in an image
	CImgDisplay main_disp(src_image, "Original");  //display the image of the input

	int width = src_image.width(); //get width of the image
	int height = src_image.height(); //get height of the image

	int *x = (int*)calloc(width*height, sizeof(int));
	int *y = (int*)calloc(height, sizeof(int));

	int numofsegment = 0;

	for (i = 0; i<height; i++)
	{
		int status = 0;
		int statusbefore = 0;
		for (j = 0; j<width; j++)
		{
			if (*src_image.data(j, i) == 0)
			{
				status = 1;
				if (status != statusbefore) //not equal then record it			   
				{
					x[count] = j;
					count++;
				}
			}
			else
			{
				status = 0;
				if (status != statusbefore)  //not equal then record it
				{
					x[count] = j - 1;
					count++;
					y[i]++;
					numofsegment++;
				}
			}
			statusbefore = status;
		}
	}

	errno_t err = fopen_s(&fp, "./compressed.txt", "w+");
	fprintf_s(fp, "%d ", width); //width of the image
	fprintf_s(fp, "%d ", height); //height of the image	
	for (i = 0; i<numofsegment * 2; i++)//first linefor x,secondline for y element
	{
		fprintf_s(fp, "%d ", x[i]);
	}
	fprintf_s(fp, "\n");
	for (i = 0; i<height; i++)
	{
		fprintf_s(fp, "%d\n ", y[i]);
	}
	fclose(fp);

	cout << "input the compressed file:"; //input the name of compressed file
	string output;
	cin >> output;

	CImg<unsigned char> image(width, height, 1, 1);  //create a empty image
	image.fill(255);

	err = fopen_s(&fp2, output.c_str(), "r+");
	fseek(fp2, 0L, SEEK_SET);
	fscanf_s(fp2, "%d", &width, sizeof(int));
	fscanf_s(fp2, "%d", &height, sizeof(int));
	int *x1 = (int*)calloc(width*height, sizeof(int));
	int *y1 = (int*)calloc(height, sizeof(int));
	for (i = 0; i < 2 * numofsegment; i++) //read the x array
	{
		fscanf_s(fp2, "%d", &x1[i]);
		cout << x1[i] << " ";
	}
	cout << endl;
	for (i = 0; i<height; i++) //read the y array
	{
		fscanf_s(fp2, "%d", &y1[i]);
		cout << y1[i] << " " << endl;
	}

	int pos = 0;
	for (i = 0; i<height; i++)//put x arrays element back to image
	{
		int j;
		for (j = 0; j < y1[i]; j++)  //segment for each line
		{
			int k;
			for (k = x1[pos]; k <= x1[pos + 1]; k++) //filling the block for each segment
			{
				*image.data(k, i) = 0;
			}
			pos = pos + 2;
		}
	}

	fclose(fp2);
	//int grayValue = *ptr;//get grayvalue of pixel @ 10,10
	//cout << width << "\n";
	//cout << height << "\n";
	//cout << grayValue << "\n";
	//save an image with file name:"output_image.bmp"
	image.save("output_image.bmp");
	//open a window to display an image on the screen with title : "Original"
	// wait until main window is closed
	//CImgDisplay main_disp(image, "output");
	//while (!main_disp.is_closed()) {
	//	main_disp.wait();
	//}
	delete[]x;
	delete[]y;
	delete[]x1;
	delete[]y1;
	system("pause");
	return 0;
}


