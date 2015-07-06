

#if _WIN64 
// 64 bit build
	typedef unsigned int	INT32
	typedef unsigned short	INT16
	
#else
// 32 bit build
	typedef char				INT8;
	typedef short				INT16;
	typedef int					INT32;
	typedef long long			INT64;
	typedef unsigned char		UINT8;
	typedef unsigned short		UINT16;
	typedef unsigned int		UINT32;
	typedef unsigned long long  UINT64;	
	
#endif

#define PI		3.14159265f 


typedef struct IMAGE_INFOR{

	int nVer;
	int nInverted;

	int nAllocBit;
	int nUsingBit;
	int nWidth;
	int nHeight;
	int nWindow;
	int nLevel;

	int nDICOMStatus; //0:others; 1:DICOM image

	int	ImageUID;
	double dPixelSpace[2];
	double dImgPosition[3];
	double dSliceLocation;
	double dThickness;	

	//$$rect
	double CollimSx;
	double CollimEx;
	double CollimSy;
	double CollimEy;

	char DirectChar;//R or L 
	char DirectPos;// 0,1,2,3,4 -->CW //0 : 
	short ssDummy;
	long  slDummy;
	double Dummy2;
	double Dummy3;
	double Dummy4;

	int  AquisitionMode;
	int  MethodImgPrc; //

	int  ImgCount;
	int  Dummy5;
	IMAGE_INFOR(){
	
	}
}