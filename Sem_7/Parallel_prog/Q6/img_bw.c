#include<stdio.h>
#include<gd.h>
#include<string.h>
#include<omp.h>

int main(){

	char *input_file = "test.jpg";
	char *output_file = "test_bw.jpg";
	
	
	int num_threads = 2;
	
	int color, x,y,i;
	int r,g,b;
	FILE *fp;
	
	
	
	if((fp = fopen(input_file, "r")) == NULL){
		printf("error opening");
		return 1;
	}


	gdImagePtr img = gdImageCreateFromJpeg(fp);
	int width = gdImageSX(img);
	int height = gdImageSY(img);
	int combined;
	
	double t1 = omp_get_wtime();
	
	
	#pragma omp parallel for private(y, color, r, g, b, combined)
	for(x = 0; x<width;x++){
		#pragma omp critical
		{
			for(y = 0;y<height;y++){
				color = gdImageGetPixel(img,x,y);
				r = gdImageRed(img,color);
				g = gdImageGreen(img,color);
				b = gdImageBlue(img,color);
				
				combined = 0.3*r + 0.59*g + 0.11*b;
				
				color = gdImageColorAllocate(img, combined,combined,combined);
				
				gdImageSetPixel(img,x,y,color);
			}
		}
	}
	
	double t2 = omp_get_wtime();
	
	
	if((fp = fopen(output_file, "w")) == NULL){
		printf("Error opening output");
		return 1;
	}
	
	
	gdImageJpeg(img,fp,-1);
	gdImageDestroy(img);
	fclose(fp);
	
	printf("File Size: %dx%d \n",width,height);
	printf("Time Taken: %.3lfms\n",(t2-t1)*1000);
	
	return 0;
}

	
	
	
