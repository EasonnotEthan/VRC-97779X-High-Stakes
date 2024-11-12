//// THIS EXPLAINS THE CODE BELOW
//// rundis= go forward (velocity, setpoint (just error), distance, Kp ) you can find this in the pid section
//// mobile = pistoncontrol 
//// intak is intake
//// turnaround is turnaround ALSO FOUND IN pid
//// wait is wait
//// intakeup  digital_out   B               


#include "vex.h"
#include "movepid.h"


void intak(int speed)
{
  intake.setVelocity(speed,percent);
  intake.spin(forward);
}


int Armthread(){
  Arm.spinFor(forward,370,degrees);
return 0;
}

int Armdown(){
   Arm.spinFor(reverse, 300, degrees);
   return 0;
  
}
int armtop(){
  Arm.spinFor(forward, 500, degrees);
  return 0;
}


/////Autonomus start

/////////////
//RED AUTON//
/////////////
void redfivering(){ //red

rundis(-40,  0, 1220, 0.7);
mobile.set(true);
turnaround(145, 30);
intak(85);
rundis(60,145,950, 0.7);   //950
turnaround(95,40);
wait(100, msec);
rundis(40, 95, 700, 0.7);  //
wait(100,msec);
rundis(-40, 120, 400, 0.7);
turnaround(38,40);
task arms(Armthread);   //
wait(100, msec);
rundis(40,38, 550, 0.7);
turnaround(-25, 40);
intakeup.set(true);
rundis(40, -25, 550, 0.7);
turnaround(-65,40);
rundis(40, -65, 1800, 0.7);
rundis(20, -65, 400, 0.7);
wait(100, msec);
intakeup.set(false);
rundis(-20, -65, 200,0.7);  //
task armt(armtop);
rundis(-40, -65, 200,0.7);

wait(100, msec);


//150
turnaround(-200, 40);
rundis(40, -200, 1200, 0.7);
mobile.set(false);
turnaround(-135,30);
rundis(40, -135, 270, 0.7);
intak(0); 
}

void redright2(){ ////3rings 2stake

rundis(-40,  0, 1200, 0.7);
mobile.set(true);
intak(125);
  turnaround(175, 30);
  rundis(-40,  175, 300, 0.7);
   mobile.set(false); 
   wait(80,msec);  
    turnaround(248, 30);                         
  rundis(60, 248, 1200, 0.7);
  wait(0.2,sec);
  intak(0);
  task arms(Armthread);
  turnaround(365, 30);  
  rundis(-30, 360, 800, 0.7);
  mobile.set(true);
  rundis(30, 360, 300, 0.7);
  rundis(-30, 360, 100, 0.7);
  intak(80);
  wait(0.3,sec);
  turnaround(405,40);
  
 intakeup.set(true);
  rundis(60,405, 2700, 0.7);
  intakeup.set(false);
  task armt(armtop);
  rundis(-40, 405, 500, 0.7);
  wait(800,msec);
  rundis(-30, 405, 500, 0.7);
  mobile.set(false);
  intak(0);
  turnaround(495,80);
  rundis(60, 495,320, 0.7);

}
//////////////
//BLUE AUTON//
//////////////
void bluefivering(){  //blue
rundis(-40,  0, 1200, 0.7);
mobile.set(true);
intak(85);
turnaround(-145, 30);
rundis(60,-145,950, 0.7);
turnaround(-90,40);
wait(100, msec);
rundis(40, -90, 600, 0.7);
wait(100,msec);
rundis(-40, -120, 500, 0.7);
turnaround(-28,40);
wait(100, msec);
rundis(40,-28, 400, 0.7);
turnaround(0, 40);
task arms(Armthread);
intakeup.set(true);
wait(500, msec);

rundis(40, 0, 550, 0.7); //uncomment later
turnaround(60,40);
rundis(40, 60, 2150, 0.7);
wait(100, msec);
intakeup.set(false);
task armt(armtop);
wait(500,msec);
rundis(-40, 60, 200,0.7);

wait(100, msec);


//150
turnaround(210, 40);
rundis(40, 210, 1500, 0.7);
mobile.set(false);
turnaround(135,30);
rundis(40, 135, 220, 0.7);
intak(0); 
}

void blueleft2(){  ////3rings 2stake
rundis(-40,  0, 1200, 0.7);
mobile.set(true);
intak(100);
  turnaround(-175, 30);
  rundis(-40,  -175, 300, 0.7);
   mobile.set(false); 
   wait(80,msec);  
    turnaround(-250, 30);                            
  rundis(60, -250, 1100, 0.7);
  wait(0.2,sec);
  intak(0);
  task arms(Armthread);
  turnaround(-365, 30);  
  rundis(-30, -360, 790, 0.7);
  mobile.set(true);
  rundis(30, -360, 300, 0.7);
  rundis(-30, -360, 100, 0.7);
  intak(80);
  wait(0.3,sec);
  turnaround(-408,40);

   intakeup.set(true);
  rundis(60,-405, 2700, 0.7);
  intakeup.set(false);
  task armt(armtop);
  rundis(-40, -405, 500, 0.7);
  wait(800,msec);
  rundis(-30, -405, 500, 0.7);
  mobile.set(false);
  intak(0);

  turnaround(-495,80);
  
  rundis(60, -495, 320, 0.7);
}

/////Autonomus end