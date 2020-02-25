#pragma once

#include "TES3Defines.h"

#include "NIPointer.h"
#include "NINode.h"

namespace TES3 {
	struct BodyPartManager {
		struct AttachNode {
			enum class Index : int {
				Root,
				Head,
				Neck,
				Spine,
				Pelvis,
				RightHand,
				LeftHand,
				RightForearm1,
				LeftForearm1,
				RightForearm2,
				LeftForearm2,
				RightUpperArm,
				LeftUpperArm,
				RightFoot,
				LeftFoot,
				RightCalf1,
				LeftCalf1,
				RightCalf2,
				LeftCalf2,
				RightThigh,
				LeftThigh,
				RightClavicle,
				LeftClavicle,
				Weapon,
				Shield,
				COUNT,
			};
			NI::Pointer<NI::Node> node; // 0x0
			unsigned int flags; // 0x4
			Vector3 translation; // 0x8
			Matrix33 rotation; // 0x14
		};
		struct ActiveBodyPart {
			enum class Layer : int {
				Base,
				Clothing,
				Armor,
				COUNT,
			};
			enum class Index : int {
				Head,
				Hair,
				Neck,
				Chest,
				Groin,
				Skirt,
				RightHand,
				LeftHand,
				RightWrist,
				LeftWrist,
				Shield,
				RightForearm,
				LeftForearm,
				RightUpperArm,
				LeftUpperArm,
				RightFoot,
				LeftFoot,
				RightAnkle,
				LeftAnkle,
				RightKnee,
				LeftKnee,
				RightUpperLeg,
				LeftUpperLeg,
				RightPauldron,
				LeftPauldron,
				Weapon,
				Tail,
				COUNT,
			};
			Item* item; // 0x0
			BodyPart* bodyPart; // 0x4
			NI::Pointer<NI::Node> node; // 0x8
			unsigned int flags; // 0xC
		};
		AttachNode attachNodes[25]; // 0x0
		int unknown_0x578;
		ActiveBodyPart activeBodyParts[3][27]; // 0x57C
		float animationPhase; // 0xA8C
		Reference* reference; // 0xA90

		//
		// Related this-call functions.
		//

		ActiveBodyPart* getActiveBodyPartForItem(Item* item);
		NI::Node* getActiveBodyPartNode(ActiveBodyPart::Layer layer, ActiveBodyPart::Index index);

		void setActivePartData(ActiveBodyPart::Layer layer, ActiveBodyPart::Index index, bool overwriteData = true, NI::Node* node = nullptr);
		void setBodyPartForItem(Item* item, ActiveBodyPart::Index index, BodyPart* bodyPart, bool isFirstPerson = false);
		void setBodyPartByIdForItem(Item* item, ActiveBodyPart::Index index, const char* bodyPartId, bool isFirstPerson = false);

		void removeEquippedLayers();

		void updateForReference(Reference* reference);

	};
	static_assert(sizeof(BodyPartManager) == 0xA94, "TES3::BodyPartManager failed size validation");
	static_assert(sizeof(BodyPartManager::AttachNode) == 0x38, "TES3::BodyPartManager::AttachNode failed size validation");
	static_assert(sizeof(BodyPartManager::ActiveBodyPart) == 0x10, "TES3::BodyPartManager::ActiveBodyPart failed size validation");
}
