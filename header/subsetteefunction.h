// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CSubsetTeeFunction wrapper class

class CSubsetTeeFunction : public COleDispatchDriver
{
public:
	CSubsetTeeFunction() {}		// Calls COleDispatchDriver default constructor
	CSubsetTeeFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSubsetTeeFunction(const CSubsetTeeFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetStartValue();
	void SetStartValue(double newValue);
	double GetEndValue();
	void SetEndValue(double newValue);
};
