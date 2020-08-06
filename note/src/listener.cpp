#include "ros/ros.h"
#include "note/test.h"
#include <stdio.h>


void chatterCallback(const note::test::ConstPtr& msg)
{
  ROS_INFO("%f %f %f",msg->x,msg->y,msg->z);
}


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "shiyan_listener");
 
  ros::NodeHandle n;
 
  ros::Subscriber sub = n.subscribe("self_date", 1000, chatterCallback);

  ros::spin();

  return 0;
}

