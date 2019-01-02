// GlassDetectView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PyroSoftM.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "ResultView.h"
#include <time.h>

#define MAX_X_COUNT 60

#define WHITE_COLOR	-1


// CResultView

IMPLEMENT_DYNCREATE(CResultView, CView)

CResultView::CResultView()
{
	m_Dlg_H = 100;
	pDoc = NULL;

	m_XCount = 0;
	m_XCount_modeThr = 0;
	fTime = 0;

	for (int k = 0; k < 31; k++) {
		distPerZones[k] = 0;
	}
	isAlreadyChecked = false;
}

CResultView::~CResultView()
{
}

BEGIN_MESSAGE_MAP(CResultView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()	
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CResultView �����Դϴ�.

#ifdef _DEBUG
void CResultView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CResultView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CResultView �޽��� ó�����Դϴ�.
int CResultView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();
		
	if(m_ResultDlg.GetSafeHwnd() == 0)
	{		
		if(!m_ResultDlg.Create(IDD_RESULT, this))
			return FALSE;	
		
		m_ResultDlg.ModifyStyle(0,WS_VISIBLE, 0);

		AdjustLayout();
	}

	return 0;
}

void CResultView::AdjustLayout()
{	
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	int preScaleWidth = theApp.nScaleDlgWidth - theApp.nResultDlgWidth;

	CRect rectClient;
	GetClientRect(rectClient);

	int dlgH = 0;
	
	if (theApp.adjust_count > 4)
	{
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
		CChildFrame *pChild = (CChildFrame *)pFrame->GetActiveFrame();

		if (rectClient.Height() == 0) return;
		if (rectClient.Width() == 0) return;

		theApp.nResultDlgWidth = rectClient.Width();
		theApp.nScaleDlgWidth = theApp.nResultDlgWidth + preScaleWidth;

		int nLeft = theApp.m_childFrmWidth - theApp.nResultDlgWidth - 20;

		if (nLeft <= 0) return;

		pChild->m_wndSplitter.SetColumnInfo(0, nLeft, 100);
		pChild->m_wndSplitter.SetColumnInfo(1, theApp.nResultDlgWidth, 100);


		int nScaleLeft = theApp.m_childFrmWidth - theApp.nScaleDlgWidth - 20;

		if (nScaleLeft <= 0) return;

		pChild->m_ScaleSplitter.SetColumnInfo(0, nScaleLeft, 20);
		pChild->m_ScaleSplitter.SetColumnInfo(1, theApp.nScaleDlgWidth, 20);
		pChild->m_ScaleSplitter.RecalcLayout();
	}
	else if(theApp.adjust_count == 4)
		theApp.adjust_count++;

	m_ResultDlg.SetWindowPos(NULL, rectClient.left,
		rectClient.top + dlgH,
		rectClient.Width(),
		rectClient.Height() - dlgH,
		SWP_NOACTIVATE | SWP_NOZORDER);
	
	//m_ResultDlg.m_Result_Tap.SetWindowPos(NULL, 0, 0, rectClient.Width(), rectClient.Height()*0.9, SWP_NOZORDER);
	//m_ResultDlg.m_MaxTabDlg.SetWindowPos(NULL, 5, 25, rectClient.Width() - 12, rectClient.Height()*0.9 - 33, SWP_NOZORDER);
	//m_ResultDlg.m_MinTabDlg.SetWindowPos(NULL, 5, 25, rectClient.Width() - 12, rectClient.Height()*0.9 - 33, SWP_NOZORDER);
	//m_ResultDlg.m_AvgTabDlg.SetWindowPos(NULL, 5, 25, rectClient.Width() - 12, rectClient.Height()*0.9 - 33, SWP_NOZORDER);

	//m_ResultDlg.m_ZoneInf_btn.SetWindowPos(NULL, 5, rectClient.Height() - 35 - 10, 100, 35, SWP_NOZORDER);
	//m_ResultDlg.m_Coefficient_btn.SetWindowPos(NULL, 110, rectClient.Height() - 35 - 10, 100, 35, SWP_NOZORDER);
}

void CResultView::OnSize(UINT nType, int cx, int cy)
{
	if(GetSafeHwnd()==NULL) return;

	CView::OnSize(nType, cx, cy);

	AdjustLayout();
}


///////////////////////////////////////////////////////////////////////////////////////////
void CResultView::OnDraw(CDC* pDC)
{
	return;
}


void CResultView::CheckROICount(int ROI_count, int cROI_count)
{
	CString str;

	if (ROI_count < cROI_count)
	{
		for (int i = ROI_count; i < cROI_count; i++)
		{
			str.Format("%d", i + 1);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.AddSeries(0);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetTitle(str);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetLegendTitle(str);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetColor(ColorRef(i));

			/*m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.AddSeries(0);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetTitle(str);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetLegendTitle(str);
			m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).SetColor(ColorRef(i));*/
		}
		m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.AddSeries(0);
		m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(0).SetColor(ColorRef(WHITE_COLOR));
	}
	else if (ROI_count > cROI_count)
	{
		for (int i = ROI_count - 1; i >= cROI_count; i--)
		{
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).Clear();
			//m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.Series(i).Clear();
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.RemoveSeries(i);
			//m_ResultDlg.m_AvgTabDlg.m_Avg_Chart.RemoveSeries(i);
		}
		m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(0).Clear();
		m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.RemoveSeries(0);
	}
}

void CResultView::UpdateResult()		
{
	CString str;

	if (pDoc->m_bPreviousBtnClick) return;

	if (pDoc->m_ROI_check_flag)
	{
		CheckROICount(pDoc->m_comp_ROICount, pDoc->m_ROICount);

		pDoc->m_ROI_check_flag = false;
	}

	if (pDoc->m_OpenMode != 1)			// Online, Simulation �� ��쿡��
	{
		if (!(pDoc->m_ZoneInfoEnable)) {
			m_ResultDlg.m_ZoneInf_btn.EnableWindow(FALSE);
		}
		else
		{
			if (theApp.m_bLoggingRunning)
			{
				m_ResultDlg.m_ZoneInf_btn.EnableWindow(FALSE);
				m_ResultDlg.m_Coefficient_btn.EnableWindow(FALSE);
				m_ResultDlg.m_ClearGraph_btn.EnableWindow(FALSE);
				
				//float temp = pDoc->m_ZoneTemp[0];

				// ���� ���� �� drawing zone information temp
				m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(pDoc->m_ROICount).Clear();
				DrawZoneInformation();
			}
			else
			{
				m_ResultDlg.m_ZoneInf_btn.EnableWindow(TRUE);
				m_ResultDlg.m_Coefficient_btn.EnableWindow(TRUE);
				m_ResultDlg.m_ClearGraph_btn.EnableWindow(TRUE);
			}
		}
	}

	// �µ� Trend
	if (pDoc->m_ResultData.TMin[0] > 0.0f && theApp.m_bLoggingRunning  || pDoc->m_OpenMode == 1 )
	{
		if (pDoc->m_OpenMode == 3)
		{
			ProcessTime = theApp.m_systemTime;
			ProcessTime.Delete(ProcessTime.ReverseFind('.'), ProcessTime.GetLength() - ProcessTime.ReverseFind('.'));
		}
		else if (pDoc->m_OpenMode == 2)
		{
			ProcessTime = theApp.m_systemTime;
			ProcessTime.Delete(ProcessTime.ReverseFind('.'), ProcessTime.GetLength() - ProcessTime.ReverseFind('.'));
		}
		else
		{
			ProcessTime = theApp.m_systemTime;
			ProcessTime.Delete(ProcessTime.ReverseFind('.'), ProcessTime.GetLength() - ProcessTime.ReverseFind('.'));
		}

		if (pDoc->m_ChartFlag)
		{
			for (int i = 0; i < pDoc->m_ROICount; i++)
				m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).Clear();

			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(pDoc->m_ROICount).Clear();
			m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(0).Clear();

			pDoc->m_ChartFlag = false;
			m_XCount = 0;
			m_XCount_modeThr = 0;
		}
		else
		{
			if (!pDoc->m_bUpdateProperty)
			{
				// zone count ����üũ ���� �÷��� + Starting/Ending position ����
				if (isAlreadyChecked==false && pDoc->m_RHKZoneCount >= pDoc->m_StartingPos && pDoc->m_RHKZoneCount <= pDoc->m_EndingPos) {
					// starting position�϶��� ��ġ ����
					for (int k = 0; k < pDoc->m_StartingPos; k++) {
						zoneinfoCount += pDoc->m_ZoneDistance[k];
					}
					//zoneinfoCount = distPerZones[pDoc->m_RHKZoneCount - 1];
					isAlreadyChecked = true;
				}

				for (int i = 0; i < pDoc->m_ROICount; i++)
				{
					if (pDoc->m_ResultData.TMax[i] != 0.0f && isAlreadyChecked == true /*&& distPerZones[pDoc->m_EndingPos]<zoneinfoCount*/)
						m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).AddXY(zoneinfoCount, pDoc->m_ResultData.TMax[i], NULL, ColorRef(i));
				}
				if (isAlreadyChecked)	zoneinfoCount++;

				if (pDoc->m_bCheckSpread) 
				{
					m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(0).AddXY(m_XCount, pDoc->m_spreadTempr, ProcessTime, ColorRef(WHITE_COLOR));
					m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(1).AddXY(m_XCount, pDoc->m_spreadlimitTempr, ProcessTime, ColorRef(0));		// RED
					m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(2).AddXY(m_XCount, pDoc->m_spreadlimitTempr-0.01, ProcessTime, ColorRef(0));
					m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(3).AddXY(m_XCount, pDoc->m_spreadlimitTempr + 0.01, ProcessTime, ColorRef(0));
				}
				 
				if (pDoc->m_bSpreadCondition)
				{
					m_ResultDlg.m_SpreadTabDlg.spread_edit.SetWindowTextA("OK");
				}
				else
					m_ResultDlg.m_SpreadTabDlg.spread_edit.SetWindowTextA("NG");

				m_XCount++;
			}
		}
		theApp.m_TchartFlag = false;
	}
}

COLORREF CResultView::ColorRef(int series_idx)
{
	BYTE R = 0, G = 0, B = 0;

	switch (series_idx)
	{
	case WHITE_COLOR:
		R = 255;
		G = 255;
		B = 255;
		break;
	case 0:		// ��
		R = 255;
		break;
	case 1:		// ��
		R = 255;
		G = 153;
		break;
	case 2:		// ��
		R = 255;
		G = 255;
		break;
	case 3:		// ��
		G = 255;
		break;
	case 4:		// ��
		B = 255;
		break;
	case 5:		// ��
		B = 51;
		break;
	case 6:		// ��
		R = 102;
		B = 255;
		break;
	case 7:		// ����
		R = 255;
		G = 102;
		B = 102;
		break;
	case 8:		// �־�
		R = 255;
		G = 204;
		B = 102;
		break;
	case 9:		// ���
		R = 255;
		G = 225;
		B = 153;
		break;
	case 10:	// �ʾ�
		R = 153;
		G = 225;
		B = 204;
		break;
	default:
		srand((unsigned)time(NULL));
		R = rand() % 255;
		srand((unsigned)time(NULL));
		G = rand() % 255;
		srand((unsigned)time(NULL));
		B = rand() % 255;
		break;
	}
	return RGB(R, G, B);
}

void CResultView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if(lHint < 2 ) return;

	if(lHint < 4)	{
		//���� Updata�� ���۽�Ű�� �κ�
		UpdateResult();
	}

	switch (lHint)
	{
	case 7:
		CalAllResult();

		UpdateResult();

		m_ResultDlg.UpdateData(FALSE);
		break;
	}

}

void CResultView::CalAllResult()
{
	pDoc->CalMeasurement(pDoc->PPointArr.GetCount() , pDoc->sizeX, pDoc->sizeY, pDoc->pFrameBuffer);
}

void CResultView::OnMouseMove(UINT nFlags, CPoint point)
{
	CView::OnMouseMove(nFlags, point);
	return;
}


BOOL CResultView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	return CView::OnSetCursor(pWnd, nHitTest, message);
}

//ResultView�� �Ķ���� �� �ʱ�ȭ
void CResultView::InitROIData()			
{
	CString str;
	
	setFont();

	// Create the Max Tempurature Chart
	for (int i = 0; i < pDoc->m_ROICount; i++)
	{
		str.Format("%d", i+1);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.AddSeries(0);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetTitle(str);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetLegendTitle(str);
		m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(i).SetColor(ColorRef(i));

	}

	// Zone temperature add by DK, 181210
	m_ResultDlg.m_MaxTabDlg.m_Max_Chart.AddSeries(0);
	m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(pDoc->m_ROICount).SetColor(ColorRef(WHITE_COLOR));

	// Create the Spread Chart 
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.AddSeries(0);
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(0).SetColor(ColorRef(WHITE_COLOR));		

	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.AddSeries(0);
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(1).SetColor(ColorRef(0));
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.AddSeries(0);
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(2).SetColor(ColorRef(0));
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.AddSeries(0);
	m_ResultDlg.m_SpreadTabDlg.m_Spread_Chart.Series(3).SetColor(ColorRef(0));

	int k = m_ResultDlg.m_MaxTabDlg.m_Max_Chart.GetSeriesCount();

	// Init for IRDX file open
	if (pDoc->m_OpenMode == 1)
	{
		m_ResultDlg.m_ZoneInf_btn.EnableWindow(FALSE);
		m_ResultDlg.m_Coefficient_btn.EnableWindow(FALSE);
	}

	m_ResultDlg.UpdateData(FALSE);
}

void CResultView::setFont()
{
	m_bFont.CreateFontA(33, 13, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, _T("���ü"));
	m_mFont.CreateFontA(27, 9, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, _T("���ü"));
	m_sFont.CreateFontA(21, 7, 0, 0, FW_SEMIBOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH, _T("���ü"));
}

HBRUSH CResultView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CView::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  ���⼭ DC�� Ư���� �����մϴ�.

	// TODO:  �⺻���� �������� ������ �ٸ� �귯�ø� ��ȯ�մϴ�.
	return hbr;
}

void CResultView::DrawZoneInformation() {
	// total distance�� X������, �� zone �Ÿ��� ������ temperature line profile �׸���
	double zoneDistance = 0;
	for (int k = 0; k < 32; k++) {
		if (k == 0) {		// ù��ġ ���
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(pDoc->m_ROICount).AddXY(0, pDoc->m_ZoneTemp[0], 0, ColorRef(WHITE_COLOR));
		}
		else {
			CString xAxisMark = _T("");		// zone mark
			xAxisMark.Format(_T("%d"), k);
			m_ResultDlg.m_MaxTabDlg.m_Max_Chart.Series(pDoc->m_ROICount).AddXY(zoneDistance, pDoc->m_ZoneTemp[k], xAxisMark, ColorRef(WHITE_COLOR));
		}
		zoneDistance += pDoc->m_ZoneDistance[k];
		//distPerZones[k] = zoneDistance;
	}
}