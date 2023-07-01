#include "DrawableSetting.h"

DrawableSetting::DrawableSetting(const sf::Vector2f pos) : pos(pos) { }

DrawableSetting::~DrawableSetting() {}

void DrawableSetting::draw() { }

bool DrawableSetting::on_event(const Key key) { return false; }