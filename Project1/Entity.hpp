#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include "ComponentManager.hpp"
#include "constants.hpp"
#include "SDL.h"

#include <iostream>
#include <memory>
#include <bitset>
#include <array>
#include <vector>

class Component;
class ComponentManager;

class Entity : public std::enable_shared_from_this<Entity>
{
public:
	Entity(const std::weak_ptr<ComponentManager>& manager);
	~Entity();

	void update();
	void draw();
	void handle_events(const SDL_Event& event);
	bool is_active() const;
	void destroy();
	void onCollision(Entity& e);
	
	template <typename T>
	bool has_component() const;

	template <typename T, typename ...TArgs>
	T& add_component(TArgs&& ...mArgs);

	template <typename T>
	T& get_component() const;

	bool has_group(Group group);
	void add_group(Group group);
	void remove_group(Group group);

	std::string tag = "";

	std::weak_ptr<ComponentManager> manager;
private:
	bool active = true;

	std::vector<std::shared_ptr<Component>> components;
	std::array<std::weak_ptr<Component>, maxComponents> componentArray;
	std::bitset<maxComponents> componentBitset;

	std::bitset<maxGroups> groupBitset;
};

#include "Entity.tcc"

#endif