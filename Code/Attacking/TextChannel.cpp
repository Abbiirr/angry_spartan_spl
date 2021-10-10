#include "TextChannel.h"

TextChannel::TextChannel()
{
	font.loadFromFile("Fonts/TYPEWR__.TTF");
	text.setFont(font);
	text.setCharacterSize(22);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);
}

TextChannel::~TextChannel()
{

}

void TextChannel::updateText(string text)
{
	this->text.setString(text);
}

void TextChannel::draw(RenderTarget & target, Vector2f pos)
{
	this->text.setPosition(pos.x - 50.f, pos.y + 200.f);
	target.draw(this->text);
}
