// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CStrings;

/////////////////////////////////////////////////////////////////////////////
// CSeriesStatsTool wrapper class

class CSeriesStatsTool : public COleDispatchDriver
{
public:
	CSeriesStatsTool() {}		// Calls COleDispatchDriver default constructor
	CSeriesStatsTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSeriesStatsTool(const CSeriesStatsTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	VARIANT GetSeries();
	void SetSeries(const VARIANT& newValue);
	CStrings GetStatistics();
};