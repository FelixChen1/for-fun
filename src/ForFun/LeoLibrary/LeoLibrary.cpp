// This is the main DLL file.

#include "LeoLibrary.h"

namespace LeoLibrary{

	int ObjTwo::getCount(){
		return m_iCount;
	}

	char ObjTwo::getSymbol(){
		return m_cSymbol;
	}
}