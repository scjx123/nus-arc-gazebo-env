#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>
#include <iostream>

using namespace std; 
int main(int argc, char **argv) {
//Initializes ROS, and sets up a node
ros::init(argc, argv, "random_husky_commands");
ros::NodeHandle nh;

//Ceates the publisher, and tells it to publish
//to the husky_velocity_controller/cmd_vel topic, with a queue size of 100
ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("robot_velocity_controller/cmd_vel", 100);

//Sets up the random number generator
srand(time(0));

//Sets the loop to publish at a rate of 10Hz
ros::Rate rate(60);

/*const char* msg = "(
Reading from the keyboard and Publishing to Twist!
---------------------------
Moving around:
w - straight
a - left
s - reverse
d - right
---------------------------
t : up (+z)
b : down (-z)
anything else : stop
q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%
CTRL-C to quit
)";
printf("%s",msg);*/

int speed=1;

  while(ros::ok()) {
    //Declares the message to be sent
    geometry_msgs::Twist msg;
    /*Random x value between -2 and 2
    msg.linear.x=4*double(rand())/double(RAND_MAX)-2;
    //Random y value between -3 and 3
    msg.angular.z=6*double(rand())/double(RAND_MAX)-3;
    //Publish the message
    pub.publish(msg);*/
    cout<<"Enter a key: ";
    system("stty raw");
    char key=getchar();
    system("stty cooked");
    
    if(key=='w') //straight
    {
    	msg.linear.x=10; 
    }
    else if (key=='s') //reverse 
    {
   	msg.linear.x=-10; 
    }
    else if (key=='a')//left turn 
    {
   	msg.linear.x=0.5;
    	msg.angular.z=0.5; 
    }
    else if (key=='d')//right turn 
    {
   	msg.linear.x=0.5;
    	msg.angular.z=-0.5; 
    }
    else if (key == '\x03')
    {
        printf("\n\n                 .     .\n              .  |\\-^-/|  .    \n             /| } O.=.O { |\\\n\n                 CH3EERS\n\n");
        break;
    }
    pub.publish(msg);
 
    //Delays until it is time to send another message
    rate.sleep();
    }
}
