
/** Image display window class. 
	To display images.

	@author Yi Zhong, 2012 
*/
#pragma once
#include "afxwin.h"
#pragma once
#include "ZImage.h"

#define COLOR_TITILE RGB(255, 255, 200)

enum WHICH_CROP_NOBE{
	LT,
	RT,
	RB,
	LB,
	TM,
	BM,
	LM,
	RM
};

enum MODE_WND_IMAGE{
	PAN,
	ZOOM,
	WINDOW_LEVEL,
	CROP,	
	MAGIC,
	ANNO,
	ROI,
	MANUAL_MODIFY,
	MANUAL_PEN,
	MANUAL_PICKUP,
    MANUAL_BRUSH,
	DRAWROI,	
	SLICE_SLIDE,
};

class ZWndImage : public CWnd
{

	// Operations
public:
	ZWndImage(void);
	virtual ~ZWndImage();

public:	
	void SetMouseAction(UINT uMouseAction);
	void SetZoomFactor(int nZoomFactor);
	void GetZoomFactor(int& nZoomFactor);
	void GetWidLev(int& nWid, int& nLev);
	int  GetPosMouseonImage(CPoint& pt,int& nIntensity);
	int  GetCurrentSlice();
	void SetCurrentSlice(int nSlice);
	void SetPan(int xOff, int yOff);
	void GetPan(int &xOff, int &yOff);

	void SetClientRect(CRect rtClient);
	void SetWndMode(MODE_WND_IMAGE mode);
	void ShowImage(int nIndex);
	void ShowMask(bool bShow);
	void UpdateDisplay();
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWndImageBase)
public:
	//}}AFX_VIRTUAL

	// Implementation
public:
	virtual void InitialShown();
	virtual void SetWidLev(int nWid, int nLev);
	virtual void AlterPanVal(int dCox, int dCoy);
	virtual void AlterWidLev(int dWid, int dLev);
	virtual void AlterZoomFac(int dVal);	
	virtual void DrawImageETC(BOOL bPostMessage = FALSE);


protected:
	virtual void OnDraw(CDC* pDC);
	virtual BOOL DrawImageETC(CDC* pDC);	
	void DrawCollimate(CDC* pDC);
	void DrawMagicGlass(CDC* pdc);
	void DrawCircle(CDC* pDC, CPoint pt,int nRadius);
	void DrawContour(CDC* pDC);

	BOOL	ManipudateImage(UINT nFlags);
	int		WhichCropNobe();
	void	CropImage();


protected:

	CRect m_rtClient;
	UINT m_uMouseAction;
	int m_nZoomFactor;
	int m_nDisWid;
	int m_nDisHei;
	int m_wWidth;
	int m_wLevel;
	int m_xOff;
	int m_yOff;
	int m_nSx;
	int m_nSy;
	int m_nCx;
	int m_nCy;
	bool m_bSelected;
	int m_nContColimate;
	int m_nCurrentSlice;
	int m_nCurrentTimepoint;
	int m_nLastSlice;

	int m_nLastTimepoint;
	double	m_dZoomMax;
	double	m_dZoomMin;

	CPoint m_ptCurMouse;
	CPoint m_ptOldMouse;
	MODE_WND_IMAGE			m_Mwi;	
	MODE_WND_IMAGE			m_OldMwi;	
	//VIEW_IMAGE_INFO			m_Vii;

	double	m_dZoomRatio;
	double	m_dWLRatio;	
	double	m_dMagicRatio;
	double	m_dMagicWndSize;

	bool m_bPrsLBtn;
	CPoint m_ptMagicGlass;
	int m_nCollimateNobeSize;
	bool m_bSyncWL;
	bool m_bFittoScreen;
    bool m_bHideMask;
    int  m_nBrushRadius;

	// Generated message map functions
protected:
	LRESULT NotifyParent(UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT NotifyParent(UINT lParam);

protected:
	CWnd* m_pParentWnd;
	CPoint m_PrePoint;
	//{{AFX_MSG(CWndImageBase)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	bool CreateCtrl(CWnd* pWnd);
	void SetImage(ZImage* pImage);
	void IsFittoScreen(bool bFit);
	void SetImages(short* pImage,int width,int height,int slices,int times);
	void SetImages(short* pImage,int width,int height,int slices,int times, int bitsAllocated, int bitsStored, int highBit, bool isSigned);
	void RemoveImages();
	//bool SetMaskContainer(CRegMaskContainer& pRegMasker);
	void SyncWith(ZWndImage* pWndImage);
	//void SetViewCondition(VIEW_IMAGE_INFO vi, int nwindow, int nlevel, int ncurslice);
	void DrawROI();
	void SetROIRadius(int iRadius);
	void SetSyncWL(bool bSyncWL);
    void SetHideMask(bool bHide);

private:
	ZImage* m_pImage;
	CPtrArray m_ImageArray;
	//CRegMaskContainer* m_pRegMasker;
	ZWndImage*  m_pSyncWndImage;
	int m_iROIRadius;

	//. From ZImageWnd

	//CList<int,&int> m_ImageArray;
public:
	virtual afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	virtual afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	virtual afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	virtual afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);	
};
