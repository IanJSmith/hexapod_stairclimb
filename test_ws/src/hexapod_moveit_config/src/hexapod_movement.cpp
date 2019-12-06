/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, SRI International
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of SRI International nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Darebear */

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_model/robot_model.h>
#include <moveit/robot_state/robot_state.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "hexapod_move");
  ros::NodeHandle node_handle;  
  ros::AsyncSpinner spinner(1);
  spinner.start();

  /* This sleep is ONLY to allow Rviz to come up */
  sleep(3.0);
  
  // BEGIN_TUTORIAL
  // 
  // Setup
  // ^^^^^
  // 
  // The :move_group_interface:`MoveGroupInterface` class can be easily 
  // setup using just the name
  // of the group you would like to control and plan for.
  
  //------moveit::planning_interface::MoveGroupInterface group("arm_group");

  moveit::planning_interface::MoveGroupInterface lb_leg("lb_leg");
  moveit::planning_interface::MoveGroupInterface lf_leg("lf_leg");
  moveit::planning_interface::MoveGroupInterface lm_leg("lm_leg");

  moveit::planning_interface::MoveGroupInterface rb_leg("rb_leg");
  moveit::planning_interface::MoveGroupInterface rf_leg("rf_leg");
  moveit::planning_interface::MoveGroupInterface rm_leg("rm_leg");

  //Home position points
/*  
  lb_toe  Home  -0.154184 0.16404 -0.11567
  lf_toe  Home  0.149208  0.163343  -0.115189
  lm_toe  Home  -0.0024832  0.1642  -0.115785
  rb_toe  Home  -0.15417  -0.161672 -0.115145
  rf_toe  Home  0.149266  -0.162118 -0.115942
  rm_toe  Home  -0.00239747 -0.161778 -0.115523
*/

  //--------------------------------------------------------------------------------
  //Target pose declarations 
  geometry_msgs::Pose target_pose_lb_toe;
  geometry_msgs::Pose target_pose_lf_toe;
  geometry_msgs::Pose target_pose_lm_toe;

  geometry_msgs::Pose target_pose_rb_toe;
  geometry_msgs::Pose target_pose_rf_toe;
  geometry_msgs::Pose target_pose_rm_toe;

  //--------------------------------------------------------------------------------
  //Current pose declarations
  geometry_msgs::Pose current_pose_lb_toe;
  geometry_msgs::Pose current_pose_lf_toe;
  geometry_msgs::Pose current_pose_lm_toe;

  geometry_msgs::Pose current_pose_rb_toe;
  geometry_msgs::Pose current_pose_rf_toe;
  geometry_msgs::Pose current_pose_rm_toe;

  //--------------------------------------------------------------------------------
  //Home position declarations
  geometry_msgs::Pose lb_toe_home;
  geometry_msgs::Pose lf_toe_home;
  geometry_msgs::Pose lm_toe_home;

  geometry_msgs::Pose rb_toe_home;
  geometry_msgs::Pose rf_toe_home;
  geometry_msgs::Pose rm_toe_home;

  //--------------------------------------------------------------------------------
  //Target pose declarations 
  geometry_msgs::Pose lb_toe_up_forward;
  geometry_msgs::Pose lf_toe_up_forward;
  geometry_msgs::Pose lm_toe_up_forward;

  geometry_msgs::Pose rb_toe_up_forward;
  geometry_msgs::Pose rf_toe_up_forward;
  geometry_msgs::Pose rm_toe_up_forward;

  //--------------------------------------------------------------------------------
  //Left home defitions
  lb_toe_home.position.x = -0.154184;
  lb_toe_home.position.y = 0.16404 ;
  lb_toe_home.position.z = -0.11567;

  lf_toe_home.position.x = 0.149208;
  lf_toe_home.position.y = 0.163343;
  lf_toe_home.position.z = -0.115189;

  lm_toe_home.position.x = -0.0024832;
  lm_toe_home.position.y = 0.1642;
  lm_toe_home.position.z = -0.115785;

  //--------------------------------------------------------------------------------
  //Right home definions
  rb_toe_home.position.x = -0.15417;
  rb_toe_home.position.y = -0.161672;
  rb_toe_home.position.z = -0.115145;

  rf_toe_home.position.x = 0.149266;
  rf_toe_home.position.y = -0.162118;
  rf_toe_home.position.z = -0.115942;

  rm_toe_home.position.x = -0.00239747;
  rm_toe_home.position.y = -0.161778;
  rm_toe_home.position.z = -0.115523;

  //--------------------------------------------------------------------------------
  //Left up and foward defitions

/*-0.0520047  0.185305  -0.0428311
  0.25078 0.184788  -0.0429786
  0.0998278 0.185476  -0.0428002
  -0.0533545  -0.183999 -0.0435861
  0.250694  -0.184644 -0.0438348
  0.098666  -0.184195 -0.0437799
*/

  lb_toe_up_forward.position.x = -0.0520047;
  lb_toe_up_forward.position.y = 0.185305;
  lb_toe_up_forward.position.z = -0.0428311;

  lf_toe_up_forward.position.x = 0.25078;
  lf_toe_up_forward.position.y = 0.184788;
  lf_toe_up_forward.position.z = -0.0429786;

  lm_toe_up_forward.position.x = 0.0998278;
  lm_toe_up_forward.position.y = 0.185476;
  lm_toe_up_forward.position.z = -0.0428002;
  //--------------------------------------------------------------------------------

  //Right up and foward defitions
  rb_toe_up_forward.position.x = -0.0533545;
  rb_toe_up_forward.position.y = -0.183999;
  rb_toe_up_forward.position.z = -0.0435861;

  rf_toe_up_forward.position.x =  0.250694;
  rf_toe_up_forward.position.y = -0.184644;
  rf_toe_up_forward.position.z = -0.0438348;

  rm_toe_up_forward.position.x = 0.098666;
  rm_toe_up_forward.position.y = -0.184195;
  rm_toe_up_forward.position.z = -0.0437799;

  //--------------------------------------------------------------------------------
  //Left down and forward defintion

/*
  lb_toe  Down and Forward  -0.0953619  0.138947  -0.117145
  lf_toe  Down and Forward  0.209946  0.141048  -0.114861
  lm_toe  Down and Forward  0.0588517 0.141638  -0.1p15452
  rb_toe  Down and Forward  -0.0954773  -0.1389 -0.11546
  rf_toe  Down and Forward  0.208273  -0.139224 -0.11626
  rm_toe  Down and Forward  0.0563553 -0.138944 -0.115839
*/

  lb_toe_down_forward.position.x = -0.0520047;
  lb_toe_down_forward.position.y = 0.185305;
  lb_toe_down_forward.position.z = -0.0428311;

  lf_toe_down_forward.position.x = 0.25078;
  lf_toe_down_forward.position.y = 0.184788;
  lf_toe_down_forward.position.z = -0.0429786;

  lm_toe_down_forward.position.x = 0.0998278;
  lm_toe_down_forward.position.y = 0.185476;
  lm_toe_down_forward.position.z = -0.0428002;
  //--------------------------------------------------------------------------------

  //Right up and foward defitions
  rb_toe_down_forward.position.x = -0.0533545;
  rb_toe_down_forward.position.y = -0.183999;
  rb_toe_down_forward.position.z = -0.0435861;

  rf_toe_down_forward.position.x =  0.250694;
  rf_toe_down_forward.position.y = -0.184644;
  rf_toe_down_forward.position.z = -0.0438348;

  rm_toe_down_forward.position.x = 0.098666;
  rm_toe_down_forward.position.y = -0.184195;
  rm_toe_down_forward.position.z = -0.0437799;

  //--------------------------------------------------------------------------------

  


  // We will use the :planning_scene_interface:`PlanningSceneInterface`
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

	//Without a specified planner, the group will use the default planner. If the default works fine, this line isn't needed.
  //WHAT FUCKING PLANNER SHOULD WE USE
  lb_leg.setPlannerId("RRTConnectkConfigDefault");
  lf_leg.setPlannerId("RRTConnectkConfigDefault");
  lm_leg.setPlannerId("RRTConnectkConfigDefault");

  rb_leg.setPlannerId("RRTConnectkConfigDefault");
  rf_leg.setPlannerId("RRTConnectkConfigDefault");
  rm_leg.setPlannerId("RRTConnectkConfigDefault");

  //WHAT IS THE POINT OF THIS
  ros::Publisher lb_leg_publisher = node_handle.advertise<trajectory_msgs::JointTrajectory>("/lb_leg_group/command", 1, true);
  ros::Publisher lf_leg_publisher = node_handle.advertise<trajectory_msgs::JointTrajectory>("/lf_leg_group/command", 1, true);
  ros::Publisher lm_leg_publisher = node_handle.advertise<trajectory_msgs::JointTrajectory>("/lm_leg_group/command", 1, true);

  ros::Publisher rb_leg_publisher = node_handle.advertise<trajectory_msgs::JointTrajectory>("/rb_leg_group/command", 1, true);
  ros::Publisher rf_leg_publisher = node_handle.advertise<trajectory_msgs::JointTrajectory>("/rf_leg_group/command", 1, true);
  ros::Publisher rm_leg_publisher = node_handle.advertise<trajectory_msgs::JointTrajectory>("/rm_leg_group/command", 1, true);

  // Getting Basic Information
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // We can print the name of the reference frame for this robot.
  
  //ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  lb_leg.setNamedTarget("default");
  lf_leg.setNamedTarget("default");
  lm_leg.setNamedTarget("default");

  rb_leg.setNamedTarget("default");
  rf_leg.setNamedTarget("default");
  rm_leg.setNamedTarget("default");

  // We can also print the name of the end-effector link for this group.
  //ROS_INFO("End effector link: %s", group.getEndEffectorLink().c_str());

	// Set the arm to the default pose created in the setup assistant

  // Try to plan to move to the target
  //--------------------------------------------------------------------------------

  moveit::planning_interface::MoveGroupInterface::Plan lb_leg_plan;
  moveit::planning_interface::MoveGroupInterface::Plan lf_leg_plan;
  moveit::planning_interface::MoveGroupInterface::Plan lm_leg_plan;

  moveit::planning_interface::MoveGroupInterface::Plan rb_leg_plan;
  moveit::planning_interface::MoveGroupInterface::Plan rf_leg_plan;
  moveit::planning_interface::MoveGroupInterface::Plan rm_leg_plan;

  //--------------------------------------------------------------------------------
  bool success = (bool)(lb_leg.plan(lb_leg_plan));
  ROS_INFO("Visualizing plan to default pose %s",success?"":"FAILED");
  lb_leg.execute(lb_leg_plan);
  sleep(0.1);

  success = (bool)(lf_leg.plan(lf_leg_plan));
  ROS_INFO("Visualizing plan to default pose %s",success?"":"FAILED");
  lf_leg.execute(lf_leg_plan);
  sleep(0.1);

  success = (bool)(lm_leg.plan(lm_leg_plan));
  ROS_INFO("Visualizing plan to default pose %s",success?"":"FAILED");
  lm_leg.execute(lm_leg_plan);
  sleep(0.1);

  //--------------------------------------------------------------------------------
  
  success = (bool)(rb_leg.plan(rb_leg_plan));
  ROS_INFO("Visualizing plan to default pose %s",success?"":"FAILED");
  rb_leg.execute(rb_leg_plan);
  sleep(0.1);

  success = (bool)(rf_leg.plan(rf_leg_plan));
  ROS_INFO("Visualizing plan to default pose %s",success?"":"FAILED");
  rf_leg.execute(rf_leg_plan);
  sleep(0.1);

  success = (bool)(rm_leg.plan(rm_leg_plan));
  ROS_INFO("Visualizing plan to default pose %s",success?"":"FAILED");
  rm_leg.execute(rm_leg_plan);
  sleep(0.1);

	//servo_publisher.publish(my_plan.trajectory_.joint_trajectory);    

  // Planning to a Pose goal
  // ^^^^^^^^^^^^^^^^^^^^^^^
  // We can plan a motion for this group to a desired pose for the 
  // end-effector.

  //Left side with respect to base y's are z's, x's are x's, z's are negative y's

  lb_leg.setPositionTarget(lb_toe_home.position.x, lb_toe_home.position.y, lb_toe_home.position.z, "lb_toe_end");
  lf_leg.setPositionTarget(lf_toe_home.position.x, lf_toe_home.position.y, lf_toe_home.position.z, "lf_toe_end");
  lm_leg.setPositionTarget(lm_toe_home.position.x, lm_toe_home.position.y, lm_toe_home.position.z, "lm_toe_end");

  rb_leg.setPositionTarget(rb_toe_home.position.x, rb_toe_home.position.y, rb_toe_home.position.z, "rb_toe_end");
  rf_leg.setPositionTarget(rf_toe_home.position.x, rf_toe_home.position.y, rf_toe_home.position.z, "rf_toe_end");
  rm_leg.setPositionTarget(rm_toe_home.position.x, rm_toe_home.position.y, rm_toe_home.position.z, "rm_toe_end");

/*
	group.setApproximateJointValueTarget(target_pose1);
*/

 /*geometry_msgs::Point exact_pose = target_pose1.position;
  geometry_msgs::Quaternion exact_orientation = target_pose1.orientation;
  
  
  std::cout<<"Robot position : "<<exact_pose.x<<"\t"<<exact_pose.y<<"\t"<<exact_pose.z<<std::endl;
  std::cout<<"Robot Orientation : "<<exact_orientation.x<<"\t"<<exact_orientation.y<<"\t"<<exact_orientation.z<<"\t"<<exact_orientation.w<<std::endl;*/


  // Now, we call the planner to compute the plan
  // and visualize it.
  // Note that we are just planning, not asking move_group 
  // to actually move the robot.

  success = (bool)(lb_leg.plan(lb_leg_plan));
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan.
  sleep(0.1);
  lb_leg.execute(lb_leg_plan);
  sleep(0.1);

  success = (bool)(lf_leg.plan(lf_leg_plan));
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan.
  sleep(0.1);
  lf_leg.execute(lf_leg_plan);
  sleep(0.1);

  success = (bool)(lm_leg.plan(lm_leg_plan));
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan.
  sleep(0.1);
  lb_leg.execute(lm_leg_plan);
  sleep(0.1);

  //--------------------------------------------------------------------------------

  success = (bool)(rb_leg.plan(rb_leg_plan));
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan.
  sleep(0.1);
  rb_leg.execute(rb_leg_plan);
  sleep(0.1);

  success = (bool)(rf_leg.plan(rf_leg_plan));
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan.
  sleep(0.1);
  rf_leg.execute(rf_leg_plan);
  sleep(0.1);

  success = (bool)(rm_leg.plan(rm_leg_plan));
  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"":"FAILED");    
  // Sleep to give Rviz time to visualize the plan.
  sleep(0.1);
  rm_leg.execute(rm_leg_plan);
  sleep(0.1);

	//servo_publisher.publish(my_plan.trajectory_.joint_trajectory);

	// Instead of giving an absolute position, a relative change can be given too.

/*	target_pose1.position.z+=.1;
	group.setApproximateJointValueTarget(target_pose1);
	success = bool(group.plan(my_plan));
  ROS_INFO("Visualizing plan 1 (relative pose goal) %s",success?"":"FAILED");    
  sleep(1.0);
	group.execute(my_plan);
*/

	//servo_publisher.publish(my_plan.trajectory_.joint_trajectory);

  
  // Moving to a pose goal
  // ^^^^^^^^^^^^^^^^^^^^^
  //
  // Moving to a pose goal is similar to the step above
  // except we now use the move() function. Note that
  // the pose goal we had set earlier is still active 
  // and so the robot will try to move to that goal. We will
  // not use that function in this tutorial since it is 
  // a blocking function and requires a controller to be active
  // and report success on execution of a trajectory.

	// If you already used plan(my_plan), then it's sufficient to just use
	// execute(my_plan). move() is a combination of plan(my_plan) and execute(my_plan).
	// But in this case, we're publishing to the ssc32_node instead of 
	// using the move/execute functions.
 
  // Uncomment below line when working with a real robot
  // group.move() 

  // Planning to a joint-space goal 
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // Let's set a joint space goal and move towards it.  This will replace the
  // pose target we set above.
  //
  // First get the current set of joint values for the group.

/*  std::vector<double> group_variable_values;
  group.getCurrentState()->copyJointGroupPositions(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()), group_variable_values);
  
  // Now, let's modify one of the joints, plan to the new joint
  // space goal and visualize the plan.
  group_variable_values[0] = -1.0;  
  group.setJointValueTarget(group_variable_values);
  success = bool(group.plan(my_plan));

  ROS_INFO("Visualizing plan 2 (joint space goal) %s",success?"":"FAILED");
  // Sleep to give Rviz time to visualize the plan.
  sleep(5.0);
	//servo_publisher.publish(my_plan.trajectory_.joint_trajectory);

	target_pose1.position.z-=.1;
	group.setApproximateJointValueTarget(target_pose1);
	success = bool(group.plan(my_plan));
  ROS_INFO("Visualizing plan 1 (relative pose goal) %s",success?"":"FAILED");    
  sleep(1.0);
	group.execute(my_plan);
*/	//servo_publisher.publish(my_plan.trajectory_.joint_trajectory);



	//How to get current joint values and pose
/*
  robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
  robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
	robot_state::RobotStatePtr kinematic_state(group.getCurrentState());
  const robot_state::JointModelGroup *joint_model_group = kinematic_model->getJointModelGroup("arm_group");

  const std::vector<std::string> &joint_names = joint_model_group->getVariableNames();

  // Get Joint Values
  // ^^^^^^^^^^^^^^^^
  // We can retreive the current set of joint values stored in the state for the arm.
  std::vector<double> joint_values;
  kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
  for (std::size_t i = 0; i < joint_names.size(); ++i)
  {
    ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
  }

  const Eigen::Affine3d &end_effector_state = kinematic_state->getGlobalLinkTransform("gripper_link");

  // Print end-effector pose. Remember that this is in the model frame 
  ROS_INFO_STREAM("Translation: " << end_effector_state.translation());
  ROS_INFO_STREAM("Rotation: " << end_effector_state.rotation());
*/
// END_TUTORIAL

  ros::shutdown();  
  return 0;
}

