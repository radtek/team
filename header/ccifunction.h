// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CCCIFunction wrapper class

class CCCIFunction : public COleDispatchDriver
{
public:
	CCCIFunction() {}		// Calls COleDispatchDriver default constructor
	CCCIFunction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CCCIFunction(const CCCIFunction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetConstant();
	void SetConstant(double newValue);
};
