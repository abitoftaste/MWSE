#include "TES3AudioController.h"
#include "TES3Sound.h"
#include "TES3Util.h"
#include "TES3WorldController.h"

#include "LuaUtil.h"

#include "LuaSoundObjectPlayEvent.h"

#include "LuaManager.h"

namespace TES3 {
	char* Sound::getObjectID() {
		return id;
	}

	bool Sound::play(int playbackFlags, unsigned char volume, float pitch, bool isNot3D) {
		unsigned int master = TES3::WorldController::get()->audioController->volumeMaster;
		unsigned int finalVolume = master * volume / 250;
		return playRaw(playbackFlags, finalVolume, pitch, isNot3D);
	}

	const auto TES3_Sound_play = reinterpret_cast<bool(__thiscall*)(Sound*, int, unsigned char, float, bool)>(0x510A40);
	bool Sound::playRaw(int playbackFlags, unsigned char volume, float pitch, bool isNot3D) {
		Sound* sound = this;

		if (mwse::lua::event::SoundObjectPlayEvent::getEventEnabled()) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::SoundObjectPlayEvent(sound, playbackFlags, volume, pitch, isNot3D));
			if (eventData.valid()) {
				if (eventData.get_or("block", false)) {
					return false;
				}

				// Override event data.
				Sound* sound = eventData["sound"];
				playbackFlags = eventData["flags"];
				volume = eventData["volume"];
				pitch = eventData["pitch"];
				isNot3D = eventData["isNot3D"];

				// If it's not a sound, forward as if we were playing that sound, raising a new event.
				if (sound != this) {
					return sound->playRaw(playbackFlags, volume, pitch, isNot3D);
				} else if (sound == nullptr) {
					return false;
				}
			}
		}

		return TES3_Sound_play(sound, playbackFlags, volume, pitch, isNot3D);
	}

	const auto TES3_Sound_stop = reinterpret_cast<void(__thiscall *)(Sound*)>(0x510BC0);
	void Sound::stop() {
		TES3_Sound_stop(this);
	}

	const auto TES3_Sound_setVolumeRaw = reinterpret_cast<void(__thiscall*)(Sound*, unsigned char)>(0x510C30);
	void Sound::setVolumeRaw(unsigned char volume) {
		TES3_Sound_setVolumeRaw(this, volume);
	}

	const auto TES3_Sound_isPlaying = reinterpret_cast<bool(__thiscall *)(Sound*)>(0x510B80);
	bool Sound::isPlaying() {
		return TES3_Sound_isPlaying(this);
	}
	
	const char* Sound::getFilename() const {
		return filename;
	}

	float Sound::getVolume() {
		return (float)volume / 250.0f;
	}

	void Sound::setVolume(float volume) {
		float currentScale = 1.0f;
		if (soundBuffer && soundBuffer->lpSoundBuffer) {
			if (this->volume == 0) {
				currentScale = 0.0f;
			}
			else {
				currentScale = (float)soundBuffer->volume / (float)this->volume;
			}
		}

		this->volume = volume * 250;

		setVolumeRaw(currentScale);
	}

	std::string Sound::toJson() const {
		std::ostringstream ss;
		ss << "\"tes3sound:" << id << "\"";
		return std::move(ss.str());
	}

	bool Sound::play_lua(sol::optional<sol::table> params) {
		bool loop = mwse::lua::getOptionalParam<bool>(params, "loop", false);
		unsigned char volume = mwse::lua::getOptionalParam<double>(params, "volume", 1.0) * 250;
		float pitch = mwse::lua::getOptionalParam<double>(params, "pitch", 1.0);
		return play(loop ? TES3::SoundPlayFlags::Loop : 0, volume, pitch, true);
	}

}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Sound)
