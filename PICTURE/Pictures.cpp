#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

#define DIM 1024
#define DM1 (DIM-1)
#define _sq(x) ((x)*(x)) //square
#define _cb(x) abs((x)*(x)*(x)) //absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) //cube root

unsigned char RD(int, int);
unsigned char GR(int, int);
unsigned char BL(int, int);

//255、153、204粉

unsigned char RD(int i,int j){
	//return (char)(i*log(j+1))%255;
	//return (char)(i*j*log((i>j)?i:j+1))%255;
	return (char)(i*j*log10(i+j+1))%255;
	//return 255;
}

unsigned char GR(int i,int j){
	//return (char)(j*log(i+1))%255;
	//return 0;//(char)(i*log(j+1))%255;
	return (char)(0*((int)(i*j*log10(i+j+1))%255));
	//return 153;
}

unsigned char BL(int i,int j){
	//return (char)(i*j*log(i+j+1))%255;
	//return 0;//(char)(j*log(i+1))%255;
	return (char)(0.5*((int)(i*j*log10(i+j+1))%255));
	//return 204;
}

void pixel_write(int, int);
FILE *fp;


int main()
{
	fp = fopen("MathPic"".ppm","wb");
	fprintf(fp, "P6\n%d %d\n255\n",1024 ,1024);
	for(int j = 0; j < 1024; j++)
		for(int i = 0; i < 1024; i++)
			pixel_write(i, j);
	fclose(fp);
	cout<<"制作完成。"<<endl;
	return 0;
}

void pixel_write(int i, int j)
{
	static unsigned char color[3];
	color[0] = RD(i, j)&255;
	color[1] = GR(i, j)&255;
	color[2] = BL(i, j)&255;
	fwrite(color, 1, 3, fp);
}