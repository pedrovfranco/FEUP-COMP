#include <stdio.h>
#include <stdlib.h>
/********************************
Author: Sravanthi Kota Venkata
********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
I2D * convertF2DtoI2D(F2D *in);
F2D * convertI2DtoF2D(I2D *in);
/** New functions **/

void photonPrintTiming(unsigned int *elapsed);
unsigned int * photonReportTiming(unsigned int *startCycles, unsigned int *endCycles);
unsigned int * photonStartTiming();
unsigned int * photonEndTiming();
/** Timing functions **/

void fWriteMatrix(F2D *input, char *inpath, char *fileName);
void writeMatrix(I2D *input, char *inpath, char *fileName);
int fSelfCheck(F2D *in1, char *path, float tol);
int selfCheck(I2D *in1, char *path, int tol);
/** Checking functions **/

F2D * randWrapper(int m, int n);
F2D * randnWrapper(int m, int n);
I2D * fSortIndices(F2D *input, int dim);
I2D * iSortIndices(I2D *in, int dim);
F2D * fSort(F2D *in, int dim);
I2D * iSort(I2D *in, int dim);
F2D * fSum(F2D *inMat);
F2D * fSum2(F2D *inMat, int dir);
F2D * fFind3(F2D *in);
/** Support functions **/

F2D * imageBlur(I2D *imageIn);
F2D * imageResize(F2D *imageIn);
/** Image Transformations - resize, integration etc **/

I2D * iiConv2(I2D *a, I2D *b);
F2D * ffiConv2(F2D *a, I2D *b);
F2D * ffConv2_dY(F2D *a, F2D *b);
F2D * fiConv2(I2D *a, F2D *b);
F2D * ffConv2(F2D *a, F2D *b);
F2D * calcSobel_dY(F2D *imageIn);
F2D * calcSobel_dX(F2D *imageIn);
/** Filtering operations **/

I2D * isPlus(I2D *a, int b);
F2D * fPlus(F2D *a, F2D *b);
I2D * isMinus(I2D *a, int b);
I2D * iMinus(I2D *a, I2D *b);
F2D * fMinus(F2D *a, F2D *b);
F2D * ifMtimes(I2D *a, F2D *b);
F2D * fMtimes(F2D *a, F2D *b);
I2D * iTimes(I2D *a, I2D *b);
F2D * fTimes(F2D *a, F2D *b);
F2D * ffTimes(F2D *a, float b);
F2D * ffDivide(F2D *a, F2D *b);
F2D * fMdivide(F2D *a, F2D *b);
F2D * fDivide(F2D *a, float b);
/** Binary Operations **/

I2D * iReshape(I2D *in, int rows, int cols);
F2D * fReshape(F2D *in, int rows, int cols);
I2D * iTranspose(I2D *a);
F2D * fTranspose(F2D *a);
F2D * horzcat(F2D *a, F2D *b, F2D *c);
I2D * iHorzcat(I2D *a, I2D *b);
F2D * fHorzcat(F2D *a, F2D *b);
I2D * iVertcat(I2D *matrix1, I2D *matrix2);
F2D * ffVertcat(F2D *matrix1, F2D *matrix2);
/** Matrix operations - concatenation, reshape **/

I2D * ifDeepCopy(F2D *in);
F2D * fiDeepCopy(I2D *in);
F2D * fDeepCopyRange(F2D *in, int startRow, int numberRows, int startCol, int numberCols);
I2D * iDeepCopyRange(I2D *in, int startRow, int numberRows, int startCol, int numberCols);
F2D * fDeepCopy(F2D *in);
I2D * iDeepCopy(I2D *in);
F2D * fSetArray(int rows, int cols, float val);
I2D * iSetArray(int rows, int cols, int val);
/** Memory copy/set function **/

void uiFreeHandle(UI2D *out);
void fFreeHandle(F2D *out);
void iFreeHandle(I2D *out);
UI2D * uiMallocHandle(int rows, int cols);
F2D * fMallocHandle(int rows, int cols);
I2D * iMallocHandle(int rows, int cols);
/** Memory allocation functions **/

F2D * readFile(char *fileName);

I2D * readImage(char const *pathName);
/** Image read and write **/

typedef struct anon_sdvbs_common_h_26 F2D;

struct anon_sdvbs_common_h_26 {
   int width;
   int height;
   float data[];
};

typedef struct anon_sdvbs_common_h_19 UI2D;

struct anon_sdvbs_common_h_19 {
   int width;
   int height;
   unsigned int data[];
};

typedef struct anon_sdvbs_common_h_12 I2D;

struct anon_sdvbs_common_h_12 {
   int width;
   int height;
   int data[];
};

/********************************
Author: Sravanthi Kota Venkata
********************************/

void padarray4(I2D *inMat, I2D *borderMat, int dir, I2D *paddedArray) {
   int rows, cols, bRows, bCols, newRows, newCols;
   int i, j;
   int adir;
   adir = abs(dir);
   rows = inMat->height;
   cols = inMat->width;
   bRows = borderMat->data[0];
   bCols = borderMat->data[1];
   newRows = rows + bRows;
   newCols = cols + bCols;
   if(dir == 1) {
      for(i = 0; i < rows; i++) for(j = 0; j < cols; j++) paddedArray->data[(i) * paddedArray->width + (j)] = inMat->data[(i) * inMat->width + (j)];
   }
   else {
      for(i = 0; i < rows - bRows; i++) for(j = 0; j < cols - bCols; j++) paddedArray->data[((bRows + i)) * paddedArray->width + ((bCols + j))] = inMat->data[(i) * inMat->width + (j)];
   }
   
   return;
}

/********************************
Author: Sravanthi Kota Venkata
********************************/

void integralImage2D2D(F2D *SAD, F2D *integralImg) {
   int nr, nc, i, j;
   nr = SAD->height;
   nc = SAD->width;
   for(i = 0; i < nc; i++) integralImg->data[(0) * integralImg->width + (i)] = SAD->data[(0) * SAD->width + (i)];
   for(i = 1; i < nr; i++) for(j = 0; j < nc; j++) {
      integralImg->data[(i) * integralImg->width + (j)] = integralImg->data[((i - 1)) * integralImg->width + (j)] + SAD->data[(i) * SAD->width + (j)];
   }
   for(i = 0; i < nr; i++) for(j = 1; j < nc; j++) integralImg->data[(i) * integralImg->width + (j)] = integralImg->data[(i) * integralImg->width + ((j - 1))] + integralImg->data[(i) * integralImg->width + (j)];
   
   return;
}

/********************************
Author: Sravanthi Kota Venkata
********************************/

void findDisparity(F2D *retSAD, F2D *minSAD, I2D *retDisp, int level, int nr, int nc) {
   int i, j, a, b;
   for(i = 0; i < nr; i++) {
      for(j = 0; j < nc; j++) {
         a = retSAD->data[(i) * retSAD->width + (j)];
         b = minSAD->data[(i) * minSAD->width + (j)];
         if(a < b) {
            minSAD->data[(i) * minSAD->width + (j)] = a;
            retDisp->data[(i) * retDisp->width + (j)] = level;
         }
      }
   }
   
   return;
}

/********************************
Author: Sravanthi Kota Venkata
********************************/

void padarray4(I2D *inMat, I2D *borderMat, int dir, I2D *paddedArray);
I2D * padarray2(I2D *inMat, I2D *borderMat);
void correlateSAD_2D(I2D *Ileft, I2D *Iright, I2D *Iright_moved, int win_sz, int disparity, F2D *SAD, F2D *integralImg, F2D *retSAD);
void integralImage2D2D(F2D *SAD, F2D *integralImg);
void findDisparity(F2D *retSAD, F2D *minSAD, I2D *retDisp, int level, int nr, int nc);
void finalSAD(F2D *integralImg, int win_sz, F2D *retSAD);
I2D * getDisparity(I2D *Ileft, I2D *Iright, int win_sz, int max_shift);
void computeSAD(I2D *Ileft, I2D *Iright_moved, F2D *SAD);
/********************************
Author: Sravanthi Kota Venkata
********************************/

void computeSAD(I2D *Ileft, I2D *Iright_moved, F2D *SAD) {
   int rows, cols, i, j, diff;
   rows = Ileft->height;
   cols = Ileft->width;
   for(i = 0; i < rows; i++) {
      for(j = 0; j < cols; j++) {
         diff = Ileft->data[(i) * Ileft->width + (j)] - Iright_moved->data[(i) * Iright_moved->width + (j)];
         SAD->data[(i) * SAD->width + (j)] = diff * diff;
      }
   }
   
   return;
}

/********************************
Author: Sravanthi Kota Venkata
********************************/

int originalMain(int argc, char *argv[]) {
   int rows = 32;
   int cols = 32;
   I2D *imleft, *imright, *retDisparity;
   unsigned int *start, *endC, *elapsed;
   int i, j;
   char im1[100];
   char im2[100];
   char timFile[100];
   int WIN_SZ = 8, SHIFT = 64;
   FILE *fp;
   sprintf(im1, "%s/1.bmp", "../test_images");
   sprintf(im2, "%s/2.bmp", "../test_images");
   imleft = readImage(im1);
   imright = readImage(im2);
   rows = imleft->height;
   cols = imleft->width;
   start = photonStartTiming();
   retDisparity = getDisparity(imleft, imright, WIN_SZ, SHIFT);
   endC = photonEndTiming();
   printf("Input size\t\t- (%dx%d)\n", rows, cols);
   /** Self checking - use expected.txt from data directory  **/
   /** Self checking done **/
   elapsed = photonReportTiming(start, endC);
   photonPrintTiming(elapsed);
   iFreeHandle(imleft);
   iFreeHandle(imright);
   iFreeHandle(retDisparity);
   free(start);
   free(endC);
   free(elapsed);
   
   return 0;
}
