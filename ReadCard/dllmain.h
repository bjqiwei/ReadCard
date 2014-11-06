// dllmain.h : Declaration of module class.

class CReadCardModule : public ATL::CAtlDllModuleT< CReadCardModule >
{
public :
	DECLARE_LIBID(LIBID_ReadCardLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_READCARD, "{05C58191-FF61-43A2-8B03-84CD204C64A4}")
};

extern class CReadCardModule _AtlModule;
