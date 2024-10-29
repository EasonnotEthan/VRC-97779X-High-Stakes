/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\EasonnotEthan                                       */
/*    Created:      Fri Jun 21 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RightB               motor         13                  
// RightM               motor         12              
// RightF               motor         11              
// LeftF                motor         18              
// LeftM                motor         19              
// LeftB                motor         20              
// Controller1          controller                    
// mobile               digital_out   A               
// Arm                  motor         10              
// intake               motor         9               
// Iner                 inertial      3              
// Opticaldown          optical       2               
// intakeup             digital_out   B               
// hang                 digital_out   C               
// Opticaltop           optical       1               
// top                  digital_out   D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
competition Competition;


//


int x,y;
int intakeflag=0;
int takein = 0;
  int colornum=0;/////Red team:colornum=1   Blue team:colornum=2
  int bc=0;
  int team=0;
  int upcolornum=0;


void instart(){

  mobile.set(false);
  hang.set(false);
  intakeup.set(false);
  top.set(false);
}


void motorbreak(){
  LeftF.setStopping(coast);
  LeftM.setStopping(coast);
  LeftB.setStopping(coast);
  RightF.setStopping(coast);
  RightM.setStopping(coast);
  RightB.setStopping(coast);
  intake.setStopping(coast);
  Arm.setStopping(hold);
}
void motorshache(){
  LeftF.setStopping(brake);
  LeftM.setStopping(brake);
  LeftB.setStopping(brake);
  RightF.setStopping(brake);
  RightM.setStopping(brake);
  RightB.setStopping(brake);
  intake.setStopping(coast);
  Arm.setStopping(hold);
}

void intaking(int speed)
{
  intake.setVelocity(speed,percent);
  intake.spin(forward);
}
  
//task one strat
int taskone(){
  motorbreak();

  while(1){
    y=Controller1.Axis1.position(percent)*0.7;
    x=Controller1.Axis3.position(percent);
    if(abs(x)<=5){
      x=0;
    }    
    if(abs(y)<=5){
      y=0;
    }
    RightF.setVelocity(x-y,percent);
    RightM.setVelocity(x-y,percent);
    RightB.setVelocity(x-y,percent);
    LeftF.setVelocity(x+y,percent);
    LeftM.setVelocity(x+y,percent);
    LeftB.setVelocity(x+y,percent);
    RightF.spin(forward);
    RightM.spin(forward);
    RightB.spin(forward);
    LeftF.spin(forward);
    LeftM.spin(forward);
    LeftB.spin(forward);
  
    if(Controller1.ButtonR1.pressing()){
      mobile.set(true);
    }
    else if(Controller1.ButtonR2.pressing()){
      mobile.set(false);
    }
    //intake start
    if(Controller1.ButtonL1.pressing()){
      if(takein == 100){
        takein=0;
        bc=0;
        }
      else{
        takein=100;
        bc=0;
        }
      while (Controller1.ButtonL1.pressing()){}
    }
   else if (Controller1.ButtonL2.pressing()){
      if(takein == -100){takein=0;bc=0;}
      else{takein=-100;bc=0;}
      while (Controller1.ButtonL2.pressing()){}
    }
    intaking(takein);
    //intake end
    //arm start
  if(Arm.position(degrees)<200 && Arm.current()>2.4){
    Arm.spinFor(forward,5,degrees);
  }
  else if(Arm.position(degrees)>850  && Arm.current()>2.4){
    Arm.spinFor(reverse,5,degrees);
  }
    else if(Controller1.ButtonX.pressing()){
    Arm.spin(forward,100,percent);
    }
    else if(Controller1.ButtonB.pressing()){
      //       Arm.setVelocity(70, pct);
      // Arm.spinToPosition(0, degrees);
    Arm.spin(reverse,100,percent);    
    }
    else{Arm.stop();}

    //arm end
    if(Controller1.ButtonUp.pressing()){
      hang.set(true);
    }
    else if(Controller1.ButtonDown.pressing()){
      hang.set(false);
    }
    
    if(Controller1.ButtonY.pressing()){
      intakeup.set(true);
    }
    else if(Controller1.ButtonA.pressing()){
      intakeup.set(false);
    }
      
    
    
    

  }
return 0;
}
//task one end


int tasktwo(){
  while(1){
      if((0<Opticaltop.hue() && Opticaltop.hue()<30) || (320<Opticaltop.hue() && Opticaltop.hue()<359)){
          upcolornum=1;
          }
      else if((210<Opticaltop.hue() && Opticaltop.hue()<260)){
          upcolornum=2;
          }
      else{
          upcolornum=0;}

       if((0<Opticaldown.hue() && Opticaldown.hue()<30) || (320<Opticaldown.hue() && Opticaldown.hue()<359)){
       colornum=1;
          }
       else if((210<Opticaldown.hue() && Opticaldown.hue()<260)){
          colornum=2;
          }
         else{
          colornum=0;}

       
        
        if(Controller1.ButtonLeft.pressing()||(Controller1.ButtonRight.pressing())){
          if(bc==0){
          bc=1;
          }
          else{
            bc=0;
          }while(Controller1.ButtonLeft.pressing()||(Controller1.ButtonRight.pressing())){}
        }
        
        if(bc==1){
          takein=50;
          if(upcolornum!=0){
          takein=-60;
          } 
        }
        
        if((upcolornum!=team)&&(upcolornum>0) &&(takein!=0)){
          top.set(true);
          wait(500,msec);
        }
          else{
           top.set(false); 
          }
          
    
             
     
      
  }
    return 0;
}

int task3(){

    while(1){
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("DTdis:");
    Controller1.Screen.setCursor(1,7);
    Controller1.Screen.print(LeftF.position(degrees));
    Controller1.Screen.setCursor(2,1);
    Controller1.Screen.print("Gyro:");
    Controller1.Screen.setCursor(2,7);
    Controller1.Screen.print(Iner.angle());
    // Controller1.Screen.setCursor(3,1);
    // Controller1.Screen.print("bc:");
    // Controller1.Screen.setCursor(3,7);
    // Controller1.Screen.print(bc);
    // Controller1.Screen.setCursor(3,10);
    // Controller1.Screen.print(team);
    Controller1.Screen.setCursor(3,1);
    // Controller1.Screen.print(Arm.current());  // current>2.4A
    Controller1.Screen.print(Arm.position(degrees));  // 200rpm 947du
    Controller1.Screen.clearScreen();   
  }
  return 0;
     
}  

int task4(){
  while(1){
        if(Controller1.ButtonLeft.pressing()||(Controller1.ButtonRight.pressing())){
          if(bc==0){
          bc=1;
          }
          else{
            bc=0;
          }while(Controller1.ButtonLeft.pressing()||(Controller1.ButtonRight.pressing())){}
        }    
        if(bc==1){
          takein=30;
          if(Distance1.objectDistance(mm)<40){
          // wait(50,msec);
          takein=-60;
          wait(700,msec);
          } 
        }
    //arm end
  }
}


int current_auton_selection = 0;
bool auto_started = false;


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  instart();
    /*while(!auto_started){
      Brain.Screen.clearScreen();
      Controller1.Screen.clearScreen();
      Brain.Screen.setFillColor(orange);
      Brain.Screen.printAt(5, 20, "Cephalopod Crusaders 99788A");
      Brain.Screen.printAt(5, 40, "Battery Percentage:");
      Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
      Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
      Brain.Screen.printAt(5, 100, "%f", Iner.rotation());
      Brain.Screen.printAt(200, 120, "%d", current_auton_selection);
      Brain.Screen.printAt(300, 150, "%f", Arm.position(degrees));
      Controller1.Screen.setCursor(1,0);
      Controller1.Screen.print("选择自动：");
      switch(current_auton_selection){
        case 0:
          team=2;
          Controller1.Screen.print("Blue5ringright");
        case 1:
          team=2;
          Controller1.Screen.print("BlueLeft2");
          break;
        case 2:
          team=2;
          Controller1.Screen.print("BlueRight");
          break;
        case 3:
          team=1;
          Controller1.Screen.print("RedLeft");
          break;
        case 4:
          team=1;
          Controller1.Screen.print("RedRight1");
          break;
        case 5:
          team=1;
          Controller1.Screen.print("RedRight2");
          break;
        case 6:
          team=2;
          Controller1.Screen.print("Red5ringleft");
          break;
    }
    
    if(Brain.Screen.pressing()){
      while(Brain.Screen.pressing()) {}
      current_auton_selection ++;
    } else if (current_auton_selection == 7){
      current_auton_selection = 0;
    }
    task::sleep(200);
  }*/
}



void autonomous(void) {
motorshache();

auto_started = true;
  switch(current_auton_selection){ 
    case 0:
      team=2;
      bluefivering();
      motorbreak();
      break;
    case 1:
    team=2;
      blueleft2();
      motorbreak();
      break;
    case 2: 
    team=2;        
      blueright();
      motorbreak();
      break;
    case 3:
    team=1;
      redleft();
      motorbreak();
      break;
    case 4:
    team=1;
      redright1();
      motorbreak();
      break;
    case 5:
    team=1;
      redright2();
      motorbreak();
      break;
    case 6:
    team=2;
      redfivering();
      motorbreak();
      break;
 }  


}


void usercontrol(void) {
  // User control code here, inside the loop                     /////team=1:红队 team2：蓝队
  motorbreak();
  task myTask1 = task(taskone);
  // task myTask2 = task(tasktwo);
  task myTask3 = task(task3);
  task myTask4 = task(task4);
  wait(20, msec);
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  // Opticaltop.setLightPower(20,percent);
  // Opticaldown.setLightPower(20,percent);
  Iner.calibrate();
  wait(50, msec);
  Arm.setPosition(0, degrees);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  while (true) {
    wait(100, msec);
  }

  // Prevent main from exiting with an infinite loop.

}


//

