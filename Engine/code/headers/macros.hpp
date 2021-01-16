
// comentario de encabezado

#pragma once

#if defined (NDEBUG) || defined(_OPTIMIZE)

	#define ENGINE_RELEASE

#else 
	
	#define ENGINE_DEBUG

#endif