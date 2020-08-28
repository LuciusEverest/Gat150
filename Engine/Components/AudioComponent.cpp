#include "pch.h"
#include "AudioComponent.h"
#include "Audio/Sound.h"
#include "Audio/AudioSystem.h"

namespace bleh
{
	void AudioComponent::Create(void* data)
	{
		m_owner = static_cast<GameObject*>(data);
	}

	void AudioComponent::Destroy()
	{
		m_channel.Stop();
	}

	void AudioComponent::Read(const rapidjson::Value& value)
	{
		json::Get(value, "sound", m_soundName);
		json::Get(value, "loop", m_loop);
		json::Get(value, "playOnAwake", m_playOnAwake);

		if (m_playOnAwake)
		{
			Play();
		}
	}

	void AudioComponent::Update()
	{
	}

	void AudioComponent::Play()
	{
		m_channel.Stop();

		Sound* sound = m_owner->m_engine->GetSystem<bleh::ResourceManger>()->Get<bleh::Sound>(m_soundName, m_owner->m_engine->GetSystem<bleh::AudioSystem>());
		ASSERT_MSG((sound), "Could not find sound: " + m_soundName);
		m_channel = sound->Play(m_loop);
	}

	void AudioComponent::Stop()
	{
		m_channel.Stop();
	}
}
