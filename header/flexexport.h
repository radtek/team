// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CFlexExport wrapper class

class CFlexExport : public COleDispatchDriver
{
public:
	CFlexExport() {}		// Calls COleDispatchDriver default constructor
	CFlexExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFlexExport(const CFlexExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	void SaveToFile(LPCTSTR FileName);
	VARIANT SaveToStream();
	BOOL Compile(LPCTSTR TargetFile);
	void CompileDeleteShow(long AWidth, long AHeight, LPCTSTR TempDirectoryPath, LPCTSTR FileName, LPCTSTR FlexDirectory, BOOL DeleteTemp, BOOL EmbedImages, BOOL Show);
};
