#include "Texture_Manager.h"

Texture_Manager::Texture_Manager()
{
	addResource(Texture_Name::Player, "Res/Textures/player.png");
	addResource(Texture_Name::Coin, "Res/Textures/coin_gold.png");
	addResource(Texture_Name::Block, "Res/Textures/block.png");
}