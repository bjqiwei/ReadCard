// ReadCardATL.h : Declaration of the CReadCard
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "ReadCard_i.h"
#include "_IReadCardEvents_CP.h"
#include <string>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

extern TCHAR szPath[MAX_PATH];
using namespace ATL;

// CReadCard
class ATL_NO_VTABLE CReadCard :
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IReadCard, &IID_IReadCard, &LIBID_ReadCardLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IPersistStreamInitImpl<CReadCard>,
	public IOleControlImpl<CReadCard>,
	public IOleObjectImpl<CReadCard>,
	public IOleInPlaceActiveObjectImpl<CReadCard>,
	public IViewObjectExImpl<CReadCard>,
	public IOleInPlaceObjectWindowlessImpl<CReadCard>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CReadCard>,
	public CProxy_IReadCardEvents<CReadCard>,
	public IPersistStorageImpl<CReadCard>,
	public ISpecifyPropertyPagesImpl<CReadCard>,
	public IQuickActivateImpl<CReadCard>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<CReadCard>,
#endif
	public IProvideClassInfo2Impl<&CLSID_ReadCard, &__uuidof(_IReadCardEvents), &LIBID_ReadCardLib>,
	public IObjectSafetyImpl<CReadCard, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public CComCoClass<CReadCard, &CLSID_ReadCard>,
	public CComCompositeControl<CReadCard>
{
public:

	CReadCard()
	{
		m_bWindowOnly = TRUE;
		CalcExtent(m_sizeExtent);

	}
	~CReadCard()
	{
	}
DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_READCARD1)


BEGIN_COM_MAP(CReadCard)
	COM_INTERFACE_ENTRY(IReadCard)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CReadCard)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	// Example entries
	// PROP_ENTRY_TYPE("Property Name", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CReadCard)
	CONNECTION_POINT_ENTRY(__uuidof(_IReadCardEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CReadCard)
	CHAIN_MSG_MAP(CComCompositeControl<CReadCard>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

BEGIN_SINK_MAP(CReadCard)
	//Make sure the Event Handlers have __stdcall calling convention
END_SINK_MAP()

	STDMETHOD(OnAmbientPropertyChange)(DISPID dispid)
	{
		if (dispid == DISPID_AMBIENT_BACKCOLOR)
		{
			SetBackgroundColorFromAmbient();
			FireViewChange();
		}
		return IOleControlImpl<CReadCard>::OnAmbientPropertyChange(dispid);
	}
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* const arr[] =
		{
			&IID_IReadCard,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IReadCard

	enum { IDD = IDD_READCARD };

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}
	STDMETHOD(readyktcard)(LONG port, BSTR* result);
};

OBJECT_ENTRY_AUTO(__uuidof(ReadCard), CReadCard)
