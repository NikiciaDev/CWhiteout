#include "DrawableSetting.h"

DrawableSetting::DrawableSetting(const sf::Vector2f pos, Whiteout& whiteout) : pos(pos), whiteout(whiteout) { }

DrawableSetting::~DrawableSetting() {}

float DrawableSetting::draw() { return 0; }

bool DrawableSetting::on_event(const Key key) { return false; }