#ifndef LINE_RIDER_BRICK_HPP
#define LINE_RIDER_BRICK_HPP

#include <box2d/box2d.h>
#include <ftxui/dom/canvas.hpp>
#include <ftxui/screen/color.hpp>
#include <memory>

class BrickBase {
 public:
  BrickBase(b2World& world,
            int x,
            int y,
            int half_width,
            int half_height,
            int counter);
  ~BrickBase();

  void OnContact();
  void Step();
  void Draw(ftxui::Canvas& c) const;
  int counter() const { return counter_; }

  void MoveUp();
  int y() const { return y_; }

 private:
  b2World& world_;
  int x_;
  int y_;
  int half_width_;
  int half_height_;
  uint8_t color_hue_ = 0;
  uint8_t color_value_ = 0;
  int counter_;
  b2BodyDef bodyDef_;
  b2Body* body_ = nullptr;
  b2PolygonShape dynamicBox_;
  b2FixtureDef fixtureDef_;
};

using Brick = std::unique_ptr<BrickBase>;

#endif  // LINE_RIDER_BRICK_HPP
