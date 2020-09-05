#include "PID.h"
#include "math.h"

PID::PID(float sample_time, float p_factor, float i_factor, float d_factor) :
          sample_time(sample_time),
          p_factor(p_factor), i_factor(i_factor), d_factor(d_factor){

}

float PID::Read(){
  return 0.0F;
}

void PID::Update(int measurement){

}

void PID::Set(float velocity){
  this->target_velocity = velocity;
}
