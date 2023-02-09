#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#ifdef _DEBUG
#pragma comment(lib, "Core\\Debug\\Core.lib")
#else
#pragma comment(lib, "Core\\Release\\Core.lib")
#endif

#include "CorePch.h"