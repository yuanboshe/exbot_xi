/*!
 * Author: Yuanbo She yuanboshe@126.com
 * Group: ExBot http://blog.exbot.net
 *
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2014, ExBot.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv)
{
  std::string topic = "/cmd_vel_mux/input/teleop"; // 发布的topic名，如果使用仿真机器人请改为"/cmd_vel"
  ros::init(argc, argv, "exbotxi_example_control");
  ros::NodeHandle node;
  ros::Publisher cmdVelPub = node.advertise<geometry_msgs::Twist>(topic, 1);
  ros::Rate loopRate(10);

  ROS_INFO("exbot_example_control cpp start...");
  geometry_msgs::Twist speed; // 控制信号载体 Twist message
  while (ros::ok())
  {
    speed.linear.x = 0.2; // 设置线速度为0.2m/s，正为前进，负为后退
    speed.angular.z = 0.5; // 设置角速度为0.5rad/s，正为左转，负为右转
    cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人

    loopRate.sleep();
  }

  return 0;
}
