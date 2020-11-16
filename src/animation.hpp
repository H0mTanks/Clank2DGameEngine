#ifndef ANIMATION_HPP
#define ANIMATION_HPP

class Animation {
public:
  unsigned int index;
  unsigned int num_frames;
  unsigned int animation_speed;
  Animation();
  Animation(unsigned int index, unsigned int num_frames, unsigned int animation_speed);
};



#endif
