#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
	    m_level += levels; 
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::addItems(const std::vector<Item*>& items)
{
    if (items.empty())
    {
        m_items = items;
    }
    else
    {
        for (int i = 0; i < items.size(); i++)
        {
            m_items.push_back(items[i]);
        }
    }
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;
}

void Munchkin::addModifiers(const std::vector<Modifier*>& modifiers)
{
    if (modifiers.empty())
    {
        m_modifiers = modifiers;
    }
    else
    {
        for (int i = 0; i < modifiers.size(); i++)
        {
            m_modifiers.push_back(modifiers[i]);
        }
    }
}

void Munchkin::removeModifierFromHand()
{
    if (!m_modifiers.empty())
    {
        int choice = std::rand() % m_modifiers.size();
        m_modifiers.erase(m_modifiers.begin() + choice);
    }
}

void Munchkin::removeItemEquipped()
{
    if (!m_items.empty())
    {
        int choice = std::rand() % m_items.size();
        m_items.erase(m_items.begin() + choice);
    }
}

void Munchkin::removeBiggestBasePowerItem()
{
    if (!m_items.empty())
    {
        int maxBasePower = m_items[0]->getBasePower();
        int choice = 0;
        for (int i = 0; i < m_items.size(); i++)
        {
            if (maxBasePower < m_items[i]->getBasePower())
            {
                maxBasePower = m_items[i]->getBasePower();
                choice = i;
            }
        }
        m_items.erase(m_items.begin() + choice);
    }
}

