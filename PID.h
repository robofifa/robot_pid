#ifndef PID_H
#define PID_H


class PID{
public:
  PID(float sample_time, float p_factor, float i_factor, float d_factor);
  void Set(float velocity);
  void Update(int measurement);
  float Read();
private:
  float target_velocity;
  float sample_time;
  float p_factor;
  float i_factor;
  float d_factor;
};


#endif
