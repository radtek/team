// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeePoint2D;
class CPen1;

/////////////////////////////////////////////////////////////////////////////
// CDrawLine wrapper class

class CDrawLine : public COleDispatchDriver
{
public:
	CDrawLine() {}		// Calls COleDispatchDriver default constructor
	CDrawLine(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDrawLine(const CDrawLine& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CTeePoint2D GetEndPos();
	CTeePoint2D GetStartPos();
	CPen1 GetPen();
	void DrawHandles();
	// method 'EndHandle' not emitted because of invalid return type or parameter type
	// method 'StartHandle' not emitted because of invalid return type or parameter type
	long GetStyle();
	void SetStyle(long nNewValue);
};
