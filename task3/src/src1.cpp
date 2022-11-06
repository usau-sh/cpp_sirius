#include "src1.h"

#include <cstring>
#include <exception>

std::istream& operator>>(std::istream& s, Actions& act) {
  char c;
  s >> c;
  switch (c) {
    case 'b':
      act = Actions::backward;
      break;
    case 'l':
      act = Actions::turn_left;
      break;
    case 'r':
      act = Actions::turn_right;
      break;
    case 'f':
      act = Actions::forward;
      break;
  }
  return s;
}

std::ostream& operator<<(std::ostream& s, Coords coords) {
  s << '(' << coords.x << ", " << coords.y << ')' << std::endl;
  return s;
}

std::ostream& operator<<(std::ostream& s, Orientations orient) {
  switch (orient) {
    case Orientations::up:
      s << "up";
      break;
    case Orientations::down:
      s << "down";
      break;
    case Orientations::left:
      s << "left";
      break;
    case Orientations::right:
      s << "right";
      break;
  }
  return s;
}

Robot::Robot(Orientations orient, Coords start_coords)
    : cur_orient(orient), cur_position(start_coords) {}

void Robot::move(Actions act) {
  switch (act) {
    case Actions::forward:
      forward();
      break;
    case Actions::backward:
      backward();
      break;
    case Actions::turn_left:
      turn_left();
      break;
    case Actions::turn_right:
      turn_right();
      break;
  }
}

void Robot::forward() {
  switch (cur_orient) {
    case Orientations::up:
      ++cur_position.x;
      break;
    case Orientations::left:
      --cur_position.y;
      break;
    case Orientations::down:
      --cur_position.x;
      break;
    case Orientations::right:
      ++cur_position.y;
      break;
  }
}

void Robot::backward() {
  switch (cur_orient) {
    case Orientations::up:
      --cur_position.x;
      break;
    case Orientations::left:
      ++cur_position.y;
      break;
    case Orientations::down:
      ++cur_position.x;
      break;
    case Orientations::right:
      --cur_position.y;
      break;
  }
}

void Robot::turn_left() {
  switch (cur_orient) {
    case Orientations::up:
      cur_orient = Orientations::left;
      break;
    case Orientations::left:
      cur_orient = Orientations::down;
      break;
    case Orientations::down:
      cur_orient = Orientations::right;
      break;
    case Orientations::right:
      cur_orient = Orientations::up;
      break;
  }
}

void Robot::turn_right() {
  switch (cur_orient) {
    case Orientations::up:
      cur_orient = Orientations::right;
      break;
    case Orientations::left:
      cur_orient = Orientations::up;
      break;
    case Orientations::down:
      cur_orient = Orientations::left;
      break;
    case Orientations::right:
      cur_orient = Orientations::down;
      break;
  }
}

void Robot::run_actions(const std::vector<Actions>& act_vector) {
  for (Actions act : act_vector) {
    move(act);
  }
}

Orientations Robot::get_orientation() {
  return cur_orient;
}

Coords Robot::get_coords() {
  return cur_position;
}

Orientations strtoorient(const char* stuff) {
  if (0 == strcmp(stuff, "up")) {
    return Orientations::up;
  } else if (0 == strcmp(stuff, "left")) {
    return Orientations::left;
  } else if (0 == strcmp(stuff, "right")) {
    return Orientations::right;
  } else if (0 == strcmp(stuff, "down")) {
    return Orientations::down;
  } else {
    throw std::runtime_error("unknown orientation");
  }
}