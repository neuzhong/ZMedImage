
// ZMedImageMFCView.cpp : implementation of the CZMedImageMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ZMedImageMFC.h"
#endif

#include "ZMedImageMFCDoc.h"
#include "ZMedImageMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CZMedImageMFCView

IMPLEMENT_DYNCREATE(CZMedImageMFCView, CView)

BEGIN_MESSAGE_MAP(CZMedImageMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CZMedImageMFCView construction/destruction

CZMedImageMFCView::CZMedImageMFCView()
{
	// TODO: add construction code here

}

CZMedImageMFCView::~CZMedImageMFCView()
{
}

BOOL CZMedImageMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CZMedImageMFCView drawing

void CZMedImageMFCView::OnDraw(CDC* /*pDC*/)
{
	CZMedImageMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CZMedImageMFCView printing

BOOL CZMedImageMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CZMedImageMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CZMedImageMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CZMedImageMFCView diagnostics

#ifdef _DEBUG
void CZMedImageMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CZMedImageMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CZMedImageMFCDoc* CZMedImageMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CZMedImageMFCDoc)));
	return (CZMedImageMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CZMedImageMFCView message handlers
