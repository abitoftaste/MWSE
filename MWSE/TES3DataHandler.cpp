#include "TES3DataHandler.h"

#define TES3_NonDynamicData_resolveObject 0x4B8B60
#define TES3_NonDynamicData_findTemplate2 0x4BA8D0
#define TES3_NonDynamicData_findFirstCloneOfActor 0x4B8F50
#define TES3_NonDynamicData_findScriptByName 0x4BA700
#define TES3_NonDynamicData_findGlobalVariable 0x4BA820
#define TES3_NonDynamicData_addNewObject 0x4B8980
#define TES3_NonDynamicData_deleteObject 0x4B8B20

#define TES3_DataHandler_getSoundPlaying 0x48BBD0

namespace TES3 {
	//
	// NonDynamicData
	//

	BaseObject* NonDynamicData::resolveObject(const char* id) {
		return reinterpret_cast<BaseObject*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_resolveObject)(this, id);
	}

	Reference* NonDynamicData::findFirstCloneOfActor(const char* baseId) {
		return reinterpret_cast<Reference*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findFirstCloneOfActor)(this, baseId);
	}

	Script* NonDynamicData::findScriptByName(const char* name) {
		return reinterpret_cast<Script*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findScriptByName)(this, name);
	}

	GlobalVariable* NonDynamicData::findGlobalVariable(const char* name) {
		return reinterpret_cast<GlobalVariable*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findGlobalVariable)(this, name);
	}

	bool NonDynamicData::addNewObject(BaseObject* object) {
		return reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_addNewObject)(this, object);
	}

	void NonDynamicData::deleteObject(BaseObject* object) {
		reinterpret_cast<void(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_deleteObject)(this, object);
	}

	//
	// DataHandler
	//

	bool DataHandler::getSoundPlaying(Sound* sound, Reference* reference) {
		return reinterpret_cast<Sound*(__thiscall *)(DataHandler*, Sound*, Reference*)>(TES3_DataHandler_getSoundPlaying)(this, sound, reference);
	}
}
