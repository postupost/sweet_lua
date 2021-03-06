//
// LuaAllocator.cpp
// Copyright (c) 2007 - 2010 Charles Baker.  All rights reserved.
//

#include "LuaAllocator.hpp"
#if defined(BUILD_OS_WINDOWS)
#include <malloc.h>
#elif defined(BUILD_OS_MACOSX)
#include <stdlib.h>
#endif

using namespace sweet::lua;

/**
// An implementation of the lua_Alloc function.
//
// @param context
// 
// @param ptr
// 
// @param osize
// 
// @param nsize
// 
// @return
//  A pointer to the newly allocated memory.
*/
void* LuaAllocator::allocate( void* context, void* ptr, size_t osize, size_t nsize )
{
    if ( nsize == 0 ) 
    {
        free( ptr );
        return 0;
    }
    else
    {
        return realloc( ptr, nsize );
    }
}
