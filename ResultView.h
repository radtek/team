#pragma once

//#include "PyroSoftMDoc.h"

#include "ResultDlg.h"
#include "MinTapDlg.h"
#include "MaxTabDlg.h"
#include "AvgTabDlg.h"

class CPyroSoftMDoc;

// CResultView ���Դϴ�.

class CResultView : public CView
{
	DECLARE_DYNCREATE(CResultView)

protected:
	CResultView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CResultView();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

	double				fTime;
	CString				ProcessTime;

	void				CalAllResult();
	
	//Ư���Դϴ�.
public:
	CDC					memDC;
	CBitmap				bmpBuffer;

	CPyroSoftMDoc*		pDoc;

	CFont				m_bFont;
	CFont				m_mFont;
	CFont				m_sFont;

	CResultDlg			m_ResultDlg;
	CMaxTabDlg			m_MaxTabDlg;
	CMinTapDlg			m_SpreadTabDlg;
	//CAvgTabDlg			m_AvgTabDlg;

	int					m_Dlg_H;
	unsigned long		m_XCount;
	unsigned long		m_XCount_modeThr;

	// For Image 
	unsigned short		m_data_X, m_data_Y;
	float				m_zoomRate;

	int					m_bmp_size_x;	// drawing size
	int					m_bmp_size_y;
	int					m_bmp_ofs_x;	// drawing ofs
	int					m_bmp_ofs_y;
	
	int zoneinfoCount = 0;
	int distPerZones[31];
	bool isAlreadyChecked;

	//�۾��Դϴ�.
public:
	void AdjustLayout();
	void UpdateResult();
	void UpdataSetReadeOnly();
	void InitROIData();
	void setFont();
	void CheckROICount(int ROI_count, int cROI_count);
	void DrawZoneInformation();

	COLORREF ColorRef(int series_idx);
	
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);


	int Oldptr;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


