#include "Renderer.h"
#include "VisualComponents.h"

Renderer::Renderer()
{
    
}

Renderer::~Renderer()
{
    
}

int Renderer::ShowWindow() { return 0; }
void Renderer::RenderObject(Rect* rect, Color* color) {}
bool Renderer::Render() { return false; }
void Renderer::HandleInput(const SDL_Event& event) {}

