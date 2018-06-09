#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module mud.geom;
#else
#include <geom/Refl/Module.h>
#endif

#ifndef MUD_MODULES
#include <geom/Refl/Convert.h>
#endif
#define MUD_GEOM_REFLECTION_IMPL
#include <geom/Refl/Meta.h>

namespace mud
{
	mudgeom::mudgeom()
		: Module("mud::geom")
	{
        // ensure dependencies are instantiated
        mudobj::m();
        mudmath::m();

        // setup reflection meta data
		mudgeom_meta(*this);
	}
}

#ifdef MUD_GEOM_MODULE
extern "C"
Module& getModule()
{
	return mudgeom::m();
}
#endif