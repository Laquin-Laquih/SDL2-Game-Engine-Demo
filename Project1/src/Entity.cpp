#include "Entity.hpp"
#include "Component.hpp"
#include "Scene.hpp"
#include "SDL.h"
#include <memory>

Entity::Entity(const std::weak_ptr<Scene>& scene) :
	scene(scene)
{
}

Entity::~Entity()
{
}

void Entity::update()
{
	for (auto& c : components)
	{
		c->update();
	}
}

void Entity::draw()
{
	for (auto& c : components) c->draw();
}

void Entity::handle_events(const SDL_Event& event)
{
	for (auto& c : components) c->handle_events(event);
}

bool Entity::is_active() const
{
	return active;
}

void Entity::destroy()
{
	active = false;
	for (auto& c : components) c->destroy();
	if (auto s = scene.lock())
	{
		s->refresh();
	}
}

void Entity::onCollision(Entity& e)
{
	for (auto& c : components) c->onCollision(e);
}

bool Entity::has_group(Group group)
{
	return groupBitset[group];
}

void Entity::add_group(Group group)
{
	groupBitset[group] = true;
	scene.lock()->add_to_group(shared_from_this(), group);
}

void Entity::remove_group(Group group)
{
	groupBitset[group] = false;
}
