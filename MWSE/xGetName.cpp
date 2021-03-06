/************************************************************************

	xGetName.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetName : mwse::InstructionInterface_t
	{
	public:
		xGetName();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetName xGetNameInstance;

	xGetName::xGetName() : mwse::InstructionInterface_t(OpCode::xGetName) {}

	void xGetName::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetName::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetName: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		char* name = NULL;

		// Get the base record.
		TES3::BaseObject* record = reference->baseObject;
		if (record) {
			name = reference->baseObject->vTable.object->getName(reference->baseObject);
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetName: Could not obtain record from reference." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushString(name);

		return 0.0f;
	}
}