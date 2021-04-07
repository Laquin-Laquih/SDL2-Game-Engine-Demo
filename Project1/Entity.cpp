#include "Entity.hpp"
#include <memory>

Entity::Entity(const std::weak_ptr<ComponentManager>& manager) :
	manager(manager)
{
	std::cout << "Entity created\n";
}

Entity::~Entity()
{
	std::cout << "Entity destroyed\n";
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

bool Entity::is_active() const
{
	return active;
}

void Entity::destroy()
{
	active = false;
}

bool Entity::has_group(Group group)
{
	return groupBitset[group];
}

void Entity::add_group(Group group)
{
	groupBitset[group] = true;
	manager.lock()->add_to_group(shared_from_this(), group);
}

void Entity::remove_group(Group group)
{
	groupBitset[group] = false;
}
