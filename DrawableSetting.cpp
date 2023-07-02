#include "DrawableSetting.h"

DrawableSetting::DrawableSetting(const sf::Vector2f pos, const setting::Type type, Whiteout& whiteout) : pos(pos), type(type), whiteout(whiteout) {}

DrawableSetting::~DrawableSetting() {}

void DrawableSetting::draw(float& height, sf::Vector2f outline_r_w) { }

bool DrawableSetting::on_event(const Key key) { return false; }