// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CExpandAnimation wrapper class

class CExpandAnimation : public COleDispatchDriver
{
public:
	CExpandAnimation() {}		// Calls COleDispatchDriver default constructor
	CExpandAnimation(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CExpandAnimation(const CExpandAnimation& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetSpeed();
	void SetSpeed(long nNewValue);
	long GetTarget();
	void SetTarget(long nNewValue);
	long GetTrigger();
	void SetTrigger(long nNewValue);
	long GetSizeBy();
	void SetSizeBy(long nNewValue);
};