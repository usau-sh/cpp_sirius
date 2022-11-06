#ifndef SRC1_H_
#define SRC1_H_
#include <iostream>
#include <vector>

struct Coords {
  int64_t x;
  int64_t y;
};

enum class Orientations { up, down, right, left };
enum class Actions { forward, backward, turn_left, turn_right };

class Robot {
 private:
  Orientations cur_orient;
  Coords cur_position;
  void move(Actions act);
  void forward();
  void backward();
  void turn_left();
  void turn_right();

 public:
  Robot(Orientations orient, Coords start_coords);
  void run_actions(const std::vector<Actions>& act_vector);
  Orientations get_orientation();
  Coords get_coords();
};

std::istream& operator>>(std::istream& s, Actions& act);
std::ostream& operator<<(std::ostream& s, Coords coords);
std::ostream& operator<<(std::ostream& s, Orientations orient);

Orientations strtoorient(const char* stuff);

#endif