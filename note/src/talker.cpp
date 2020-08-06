/**
 * 该例程将发布chatter话题，消息类型String
*/
#include <math.h>
#include "ros/ros.h"
#include "note/test.h"

int main(int argc, char **argv)
{
  // ROS节点初始化
  ros::init(argc, argv, "shiyan_talker");
  
  // 创建节点句柄
  ros::NodeHandle n;
  
  // 创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::String
  ros::Publisher self_pub = n.advertise<note::test>("self_date", 1000);

  int pi = 3.1415926;

  // 设置循环的频率
  ros::Rate loop_rate(10);

  double count = 0;
  while (ros::ok())
  {
    // 初始化std_msgs::String类型的消息
    note::test self_msg;
    self_msg.x = sin(pi*count/8);
    self_msg.y = cos(pi*count/8);
    self_msg.z = 1 + (pow(-1,count))/2;

    // 发布消息
    ROS_INFO("%.5f %.5f %.5f",self_msg.x,self_msg.y,self_msg.z);
    self_pub.publish(self_msg);
	  // 循环等待回调函数
    ros::spinOnce();

    // 按照循环频率延时
    loop_rate.sleep();

    ++count;
  }

  return 0;
}
