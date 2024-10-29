#include "vex.h"


//---------turn------------------start
//turning 转弯
void turnaround(float aim, float maxspeed){
  float previouserror=0;
  float integral=0;
  int sts=1;
  float kp=0.6;
  float kd=0.00;
  float ki=0.00;
  float measured_value=Iner.rotation(degrees);
  float error=aim-measured_value;

  while(sts){
    float measured_value=Iner.rotation(degrees);
    error=aim-measured_value;
    integral=integral+error;
    float derivative=error-previouserror;
    if(abs(error)>15){
      integral=0;
      derivative=error-previouserror;
    }
    float output=kp*error+ki*integral+kd*derivative;
    if(abs(output)>maxspeed){
      output=abs(output)/output*maxspeed;
    }
    LeftF.spin(fwd, output,pct);
    LeftB.spin(fwd, output, pct);
    LeftM.spin(fwd, output,pct);
    RightF.spin(fwd,-output,pct);
    RightM.spin(fwd,-output,pct);
    RightB.spin(fwd,-output,pct);
    
    previouserror=error;
    wait(20,msec);
    Controller1.Screen.clearLine();
    if(abs(error)<10){
      sts=0;
  
    }
    
  LeftF.stop(brake);
  LeftM.stop(brake);
  LeftB.stop(brake);
  RightF.stop(brake);
  RightB.stop(brake);
  RightM.stop(brake); 
}
}

//distance 距离走直线
void rundis(float velo,  float setpoint, int dis, float kp){
  LeftF.setPosition(0,degrees);
  float leftencoder=LeftF.position(degrees);
  while(abs(leftencoder)<=dis){
    leftencoder=LeftF.position(degrees);
    float theta=Iner.rotation(degrees);
    float error=(setpoint-theta);
    float leftspeed=velo+error*kp;
    float rightspeed=velo-error*kp;
    LeftF.spin(fwd, leftspeed,pct);
    LeftB.spin(fwd, leftspeed, pct);
    LeftM.spin(fwd, leftspeed,pct);
    RightF.spin(fwd,rightspeed,pct);
    RightM.spin(fwd,rightspeed,pct);
    RightB.spin(fwd,rightspeed,pct);
  }

  LeftF.stop();
  LeftM.stop();
  LeftB.stop();
  RightF.stop();
  RightB.stop();
  RightM.stop(); 
}

//proportional correction 时间走直线
void runtime(float velo, float setpoint,int tt, float kp){
  Brain.Timer.reset();
  int st=1;
  while(st){
      float theta=Iner.rotation(degrees);
      float error=(setpoint-theta);
      float leftspeed=velo+error*kp;
      float rightspeed=velo-error*kp;
      LeftF.spin(fwd, leftspeed,pct);
      LeftB.spin(fwd, leftspeed, pct);
      LeftM.spin(fwd, leftspeed,pct);
      RightF.spin(fwd,rightspeed,pct);
      RightM.spin(fwd,rightspeed,pct);
      RightB.spin(fwd,rightspeed,pct);
      wait(tt, msec);
      st=0;
  }
  LeftF.stop();
  LeftM.stop();
  LeftB.stop();
  RightF.stop();
  RightB.stop();
  RightM.stop(); 
}