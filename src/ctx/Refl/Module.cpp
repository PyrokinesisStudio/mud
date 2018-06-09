#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module mud.ctx;
#else
#include <ctx/Refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <ctx/Refl/Convert.h>
#endif
#define MUD_CTX_REFLECTION_IMPL
#include <ctx/Refl/Meta.h>

namespace mud
{
	mudctx::mudctx()
		: Module("mud::ctx")
	{
        // ensure dependencies are instantiated
        mudobj::m();
        mudmath::m();

        // setup reflection meta data
		mudctx_meta(*this);
	}
}

#ifdef MUD_CTX_MODULE
extern "C"
Module& getModule()
{
	return mudctx::m();
}
#endif