// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CChartGridRows wrapper class

class CChartGridRows : public COleDispatchDriver
{
public:
	CChartGridRows() {}		// Calls COleDispatchDriver default constructor
	CChartGridRows(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CChartGridRows(const CChartGridRows& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetRow();
	void SetRow(long nNewValue);
	long GetCount();
	long GetHeights(long Index);
	void SetHeights(long Index, long nNewValue);
};