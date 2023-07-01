#include "DrawableSetting.h"

DrawableSetting::DrawableSetting(const sf::Vector2f pos) : pos(pos) { }

DrawableSetting::~DrawableSetting() {}

float DrawableSetting::draw() { return 0; }

bool DrawableSetting::on_event(const Key key) { return false; }