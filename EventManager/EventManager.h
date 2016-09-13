#pragma once

using Events = std::vector<std::pair<EventType, EventInfo>;

enum class EventType
{
	KeyDown = sf::Event::KeyPressed,
	KeyUp = sf::Event::KeyReleased,
	MButtonDown = sf::Event::MouseButtonPressed,
	MButtonUp = sf::Event::MouseButtonReleased,
	MouseWheel = sf::Event::MouseWheelMoved,
	WindowResized = sf::Event::Resized,
	GainedFocus = sf::Event::GainedFocus,
	LostFocus = sf::Event::LostFocus,
	MouseEntered = sf::Event::MouseEntered,
	MouseLeft = sf::Event::MouseLeft,
	Closed = sf::Event::Closed,
	TextEntered = sf::Event::TextEntered,
	Keyboard = sf::Event::Count + 1, Mouse, Joystick
};

struct EventInfo
{
	EventInfo() { code = 0; }
	EventInfo(int event) { code = event; }
	union 
	{
		int code;
	}
}

struct EventDetails
{
	EventDetails(const std::string& bindName)
		: name(bindName)
	{
		clear();
	}
	std::string name;
	sf::Vector2i size;
	sf::Vector2i textEntered;
	sf::Vector2i mouse;
	int mouseWheelDelta;
	int keyCode; //Single key code
	
	void clear()
	{
		size = sf::Vector2i(0,0);
		textEntered = 0;
		mouse = sf::Vector2i(0,0);
		mouseWheelDelta = 0;
		keyCode = -1;
	}
}