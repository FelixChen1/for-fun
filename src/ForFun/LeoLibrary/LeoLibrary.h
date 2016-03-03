#ifdef LEOLIBRARY_EXPORTS
#define LEOLIBRARY_API __declspec(dllexport)
#else
#define LEOLIBRARY_API __declspec(dllimport)
#endif

namespace  LeoLibrary {

	class LEOLIBRARY_API ObjTwo
	{
		// TODO: Add your methods for this class here.
	public:
		int m_iCount;
		char m_cSymbol;
		int getCount();
		char getSymbol();
	};
}

