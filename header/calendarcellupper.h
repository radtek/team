// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeeFont;
class CGradient;
class CTeeRect;
class CTeeShadow;
class CPen1;
class CBackImage;
class CTeeEmboss;

/////////////////////////////////////////////////////////////////////////////
// CCalendarCellUpper wrapper class

class CCalendarCellUpper : public COleDispatchDriver
{
public:
	CCalendarCellUpper() {}		// Calls COleDispatchDriver default constructor
	CCalendarCellUpper(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCalendarCellUpper(const CCalendarCellUpper& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	unsigned long GetColor();
	void SetColor(unsigned long newValue);
	CTeeFont GetFont();
	CGradient GetGradient();
	long GetShadowSize();
	void SetShadowSize(long nNewValue);
	unsigned long GetShadowColor();
	void SetShadowColor(unsigned long newValue);
	BOOL GetTransparent();
	void SetTransparent(BOOL bNewValue);
	long GetShapeStyle();
	void SetShapeStyle(long nNewValue);
	long GetTransparency();
	void SetTransparency(long nNewValue);
	CTeeRect GetShapeBounds();
	long GetBevel();
	void SetBevel(long nNewValue);
	long GetBevelWidth();
	void SetBevelWidth(long nNewValue);
	void ShowEditorShape(BOOL HideTexts, LPCTSTR Caption);
	CTeeShadow GetShadow();
	long GetRoundSize();
	void SetRoundSize(long nNewValue);
	CPen1 GetPen();
	CBackImage GetPicture();
	void Show();
	void Hide();
	long GetTextFormat();
	void SetTextFormat(long nNewValue);
	CTeeEmboss GetEmboss();
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	CPen1 GetFrame();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CString GetFormat();
	void SetFormat(LPCTSTR lpszNewValue);
	BOOL GetUpperCase();
	void SetUpperCase(BOOL bNewValue);
};