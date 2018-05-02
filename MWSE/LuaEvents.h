#pragma once

#include "LuaUnifiedHeader.h"

namespace mwse {
	namespace lua {
		class BaseEvent {
		public:
			virtual sol::table createEventTable() { return sol::nil; };
			virtual const char* getEventName() { return NULL; };
		};

		// ---------------------------------------------------------------------------- //

		class GenericEvent : public BaseEvent {
		public:
			GenericEvent(const char* name);
			const char* getEventName();

		protected:
			const char* m_EventName;
		};

		// ---------------------------------------------------------------------------- //

		class EquipEvent : public GenericEvent {
		public:
			EquipEvent(TES3::Reference* reference, TES3::BaseObject* item, TES3::ItemData* itemData);
			sol::table createEventTable();

		protected:
			TES3::Reference* m_Reference;
			TES3::BaseObject* m_Item;
			TES3::ItemData* m_ItemData;
		};

		// ---------------------------------------------------------------------------- //

		class EquippedEvent : public GenericEvent {
		public:
			EquippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id);
			sol::table createEventTable();

		protected:
			TES3::Actor* m_Actor;
			TES3::MobileActor* m_MobileActor;
			TES3::BaseObject* m_Item;
			TES3::ItemData* m_ItemData;
		};

		// ---------------------------------------------------------------------------- //

		class UnequippedEvent : public EquippedEvent {
		public:
			UnequippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id);
		};

		// ---------------------------------------------------------------------------- //

		class SimulateEvent : public GenericEvent {
		public:
			SimulateEvent(float delta);
			sol::table createEventTable();

		protected:
			float m_Delta;
		};

		// ---------------------------------------------------------------------------- //

		class FrameEvent : public SimulateEvent {
		public:
			FrameEvent(float delta, bool menuMode);
			sol::table createEventTable();

		protected:
			bool m_MenuMode;
		};

		// ---------------------------------------------------------------------------- //

		class ButtonPressedEvent : public GenericEvent {
		public:
			ButtonPressedEvent(int buttonId);
			sol::table createEventTable();

		protected:
			int m_ButtonId;
		};

		// ---------------------------------------------------------------------------- //

		class ActivateEvent : public GenericEvent {
		public:
			ActivateEvent(TES3::Reference* activator, TES3::Reference* target);
			sol::table createEventTable();

		protected:
			TES3::Reference* m_Activator;
			TES3::Reference* m_Target;
		};

		// ---------------------------------------------------------------------------- //

		class SaveGameEvent : public GenericEvent {
		public:
			SaveGameEvent(const char* saveName, const char* fileName);
			sol::table createEventTable();

		protected:
			const char* m_SaveName;
			const char* m_FileName;
		};

		// ---------------------------------------------------------------------------- //

		class SavedGameEvent : public SaveGameEvent {
		public:
			SavedGameEvent(const char* saveName, const char* fileName);
		};

		// ---------------------------------------------------------------------------- //

		class LoadGameEvent : public GenericEvent {
		public:
			LoadGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
			sol::table createEventTable();

		protected:
			const char* m_FileName;
			bool m_QuickLoad;
			bool m_NewGame;
		};

		// ---------------------------------------------------------------------------- //

		class LoadedGameEvent : public LoadGameEvent {
		public:
			LoadedGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
		};

		// ---------------------------------------------------------------------------- //

		class CellChangedEvent : public GenericEvent {
		public:
			CellChangedEvent(TES3::Cell* cell, float x, float y, float z);
			sol::table createEventTable();

		protected:
			TES3::Cell* m_Cell;
			float m_X;
			float m_Y;
			float m_Z;
		};

		// ---------------------------------------------------------------------------- //

		class CombatStartEvent : public GenericEvent {
		public:
			CombatStartEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target);
			sol::table createEventTable();

		protected:
			TES3::MobileActor* m_MobileActor;
			TES3::MobileActor* m_Target;
		};

		// ---------------------------------------------------------------------------- //

		class CombatStartedEvent : public GenericEvent {
		public:
			CombatStartedEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target);
			sol::table createEventTable();

		protected:
			TES3::MobileActor* m_MobileActor;
			TES3::MobileActor* m_Target;
		};

		// ---------------------------------------------------------------------------- //

		class CombatStopEvent : public GenericEvent {
		public:
			CombatStopEvent(TES3::MobileActor* mobileActor);
			sol::table createEventTable();

		protected:
			TES3::MobileActor* m_MobileActor;
		};

		// ---------------------------------------------------------------------------- //

		class CombatStoppedEvent : public GenericEvent {
		public:
			CombatStoppedEvent(TES3::MobileActor* mobileActor);
			sol::table createEventTable();

		protected:
			TES3::MobileActor* m_MobileActor;
		};

		// ---------------------------------------------------------------------------- //

		class AttackEvent : public GenericEvent {
		public:
			AttackEvent(TES3::ActorAnimationData* animData);
			sol::table createEventTable();

		protected:
			TES3::ActorAnimationData* m_AnimationData;
		};

		// ---------------------------------------------------------------------------- //

		class ProjectileHitEvent : public GenericEvent {
		public:
			ProjectileHitEvent(TES3::MobileProjectile* projectile);
			sol::table createEventTable();

		protected:
			TES3::MobileProjectile* m_MobileProjectile;
		};

	}
}
