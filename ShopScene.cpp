#include "Enemy.hpp"
#include "ShopScene.h"
#include "Globals.h"
#include "room.h"
#include "MenuObjects.hpp"
#include "AnimationSystem.hpp"
#include "Structs.hpp"
#include "TileMapping.hpp"
#include <iostream>



void shopScene() {
	float scale = 2.0f;
	animation_update(&ShopAnimation);
	walkableArea = false;
	float scaledWidth = battleScreen.width * scale;
	float scaledHeight = battleScreen.height * scale;
	float centerX = GetScreenWidth() / 2.0f;
	float rightThirdX = GetScreenWidth() * 1 / 5;
	float leftThirdX = GetScreenWidth() * 4 / 5;
	float lowerThirdY = GetScreenHeight() * 7 / 8;


	Button exitButton{
		400,
		60,
		exit_button_texture,
		2,
		2,
		exitButtonAnimation,
		79,
		48
	};

	Button Scissor(rightThirdX,
		lowerThirdY,
		Scissor_Texture,
		scale, 1, ScissorAnimation, 32, 32);
	Button Rock(GetScreenWidth() / 2,
		lowerThirdY,
		Rock_Texture,
		scale, 1, RockAnimation, 32, 32);
	Button Paper(leftThirdX,
		lowerThirdY,
		Paper_Texture,
		scale, 1, PaperAnimation, 32, 32);

	animation_update(&exitButtonAnimation);
	animation_update(&CursorAnimation);
	Shop.Animate();
	Player_cursor.Update();
	
	exitButton.HitBox();
	Paper.Draw();
	Rock.Draw();
	Scissor.Draw();
	Player_cursor.Draw();
	if (isButtonHover(exitButton)) {
		exitButton.Animate();
		Player_cursor.Animate();

		if (isButtonClicked(exitButton)) {
			inShop = false;
			walkableArea = true;
		}
	}
	else {
		exitButton.Draw();
	}

	if (isButtonHover(Scissor)) {
		DrawTextBox(tileTexture, 0, 0, 5, 2, "scissor upgrade");
		Player_cursor.Animate();	
	}
	if (isButtonHover(Rock)) {
		Player_cursor.Animate();
		DrawTextBox(tileTexture, 0, 0, 5, 2, "Rock upgrade");
	}
	if (isButtonHover(Paper)) {
		Player_cursor.Animate();
		DrawTextBox(tileTexture, 0, 0, 5, 2, "Paper upgrade");
	}
	
}