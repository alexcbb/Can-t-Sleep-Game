#pragma once
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "./../Utils.h"

class Inventory
{
public:
	Inventory();
	void drawToolBar(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	bool addItem(Item* item);
	bool canAddItem();
	Item* dropItem(int id);
	Item* dropCurrentItem();
	bool useItem(int id);
	void deleteItem(int id);
	void deleteLastItem(int id);
	void craftItem(Item* item, std::map<Item*, int> recipe); // TODO: create this function
	Item* switchPosition(int firstId, int secondId);
	int getItemIndex(Item* item);
	int getItemIndexWithPos(int xPos, int yPos, sf::RenderWindow& window, bool mousePressed=true);
	int getQuantityOfItem(Item* item) const;
	inline bool changeSelectedItem(int index) { 
		if (0 < m_currentItemIndex < TOOLBAR_SIZE) {
			m_currentItemIndex = index;
			return true;
		}
		return false;
	}
	inline Item* getSelectedItem() { return m_items[m_currentItemIndex][0]; };
	inline int getLastClicked() { return m_lastClicked; };

private:
	std::vector< std::vector<Item* > > m_items;
	sf::Texture m_toolBarTexture;
	sf::Texture m_inventoryTexture;
	int m_nbItem;
	int m_currentItemIndex;
	sf::Font m_font;
	sf::Text m_inventoryText;
	int m_lastClicked;

	void drawItem(sf::RenderWindow& window, sf::Vector2f pos, int size);
};

