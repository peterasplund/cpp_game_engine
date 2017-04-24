#pragma once

#include "Animation.h"

void Animation::addFrame(const sf::IntRect & rect, float timeToNextFrame)
{
	m_frames.emplace_back(rect, timeToNextFrame);
}

void Animation::stop()
{
	active = false;
}

void Animation::play()
{
	active = true;
	// m_timer.restart();
}

sf::IntRect Animation::getFrame()
{
	if (m_timer.getElapsedTime().asSeconds() >= m_frames.at(m_currentFrame).timeToNextFrame)
	{
		if (!active) {
			return m_frames.at(0).rect;
		}
		m_currentFrame++;
		m_timer.restart();

		if (m_currentFrame == m_frames.size()) {
			m_currentFrame = 0;
		}
	}
	return m_frames.at(m_currentFrame).rect;
}
