//  Copyright (c) 2018 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#include <infra/Cpp20.h>

#ifdef MUD_MODULES
module mud.proto;
#else
#include <obj/Indexer.h>
#include <proto/Complex.h>
#include <proto/Proto.h>
#endif

namespace mud
{
	Complex::Complex(Id id, Type& type, Prototype& prototype)
		: m_id(index(type, id, Ref(this, type)))
		, m_type(type)
		, m_prototype(prototype)
		, m_parts(prototype.m_parts.size())
	{}

	Complex::~Complex()
	{
		unindex(m_type, m_id);
	}
}
