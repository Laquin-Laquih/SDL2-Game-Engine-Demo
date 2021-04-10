#include "KeyboardController.hpp"
#include "AnimationComponent.hpp"

KeyboardController& KeyboardController::init()
{
	transform = entity.lock()->get_component<TransformComponent>().shared_from_this();
	visible = entity.lock()->get_component<AnimationComponent>().shared_from_this();
	return *this;
}

KeyboardController& KeyboardController::handle_events()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			transform->velocity.y = -1;
			visible->play("walk");
			break;
		case SDLK_a:
			transform->velocity.x = -1;
			visible->play("walk");
			break;
		case SDLK_s:
			transform->velocity.y = 1;
			visible->play("walk");
			break;
		case SDLK_d:
			transform->velocity.x = 1;
			visible->play("walk");
			break;
		}
	}
	else if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_s:
			transform->velocity.y = 0;
			visible->play("idle");
			break;
		case SDLK_a:
		case SDLK_d:
			transform->velocity.x = 0;
			visible->play("idle");
			break;
		}
	}
	else if (Game::event.type == SDL_QUIT)
	{
		Game::isRunning = false;
	}
	return *this;
}
