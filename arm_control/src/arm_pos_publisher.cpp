#include "ros/ros.h"
#include "std_msgs/String.h"
#include "arm_control/arm_pos.h"
#include <sensor_msgs/Joy.h>

#include <sstream>

/**
 * Copied From ROS publisher Tutorial, check there for full comments
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher example_pub = n.advertise<arm_control::arm_pos>("/arm_position", 100);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    arm_control::arm_pos msg;

    msg.axis_1 = 90;
    msg.axis_2 = 90;
    msg.axis_3 = 90;
    msg.axis_4 = 90;
    msg.axis_5 = 90;
    msg.gripper = 90;

    ROS_INFO("%u, %u, %u, %u, %u, %u", msg.axis_1, msg.axis_2, msg.axis_3, msg.axis_4, msg.axis_5, msg.gripper);


    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    example_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
