#include "stdafx.h"
#include "Tab.h"
#include "Vector2D.h"
#include "Graphics.h"
#include "Input.h"
#include "Intersection2D.h"
#include "GameObject.h"
#include "Transform.h"
#include "Sprite.h"
#include "Physics.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
#include "Space.h"
#include "Menu.h"
#include "MenuController.h"

Tab::Tab() : Button()
{
}

Component * Tab::Clone() const
{
    return new Tab(*this);
}

void Tab::Clicked()
{
    Menu* m = menu->GetComponent<Menu>();

    if (m->IsShown())
    {
        //toggle
        m->GetMenuController()->GetComponent<MenuController>()->ShowMenu(GetMenu());
        GetMenu()->GetComponent<Sprite>()->SetAlpha(0.0f);

        m->GetMenuController()->GetComponent<MenuController>()->ToggleMenus();
    }
    else
    {
        //show self
        m->GetMenuController()->GetComponent<MenuController>()->ShowMenu(GetMenu());
    }
}

void Tab::SetMenu(GameObject * menu_)
{
    menu = menu_;
}

GameObject * Tab::GetMenu()
{
    return menu;
}