#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/MultiArrayDimension.h"

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


uint32_t lidar1;
uint32_t lidar2;
uint32_t lidar3;
uint32_t state=0;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

void lidarCallback(const std_msgs::Float32MultiArray msg)
{
  lidar1=msg.data[0];
  lidar2=msg.data[1];
  lidar3=msg.data[2];

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "/lidar_data");
  ros::NodeHandle node_handle;
  ros::Subscriber sub = node_handle.subscribe("/lidar_data", 1000, lidarCallback);

  ros::init(argc, argv, "hexapod_move");
  ros::AsyncSpinner spinner(1);
  spinner.start();

  sleep(3.0);

  moveit::planning_interface::MoveGroupInterface lb_leg("lb_leg");
  moveit::planning_interface::MoveGroupInterface lf_leg("lf_leg");
  moveit::planning_interface::MoveGroupInterface lm_leg("lm_leg");

  moveit::planning_interface::MoveGroupInterface rb_leg("rb_leg");
  moveit::planning_interface::MoveGroupInterface rf_leg("rf_leg");
  moveit::planning_interface::MoveGroupInterface rm_leg("rm_leg");

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
  //Up_forward position declarations
  geometry_msgs::Pose lb_toe_up_forward;
  geometry_msgs::Pose lf_toe_up_forward;
  geometry_msgs::Pose lm_toe_up_forward;

  geometry_msgs::Pose rb_toe_up_forward;
  geometry_msgs::Pose rf_toe_up_forward;
  geometry_msgs::Pose rm_toe_up_forward;

  //--------------------------------------------------------------------------------
  //Target pose declarations 
  //Down_forward position declarations
  geometry_msgs::Pose lb_toe_down_forward;
  geometry_msgs::Pose lf_toe_down_forward;
  geometry_msgs::Pose lm_toe_down_forward;

  geometry_msgs::Pose rb_toe_down_forward;
  geometry_msgs::Pose rf_toe_down_forward;
  geometry_msgs::Pose rm_toe_down_forward;

  //--------------------------------------------------------------------------------
  //Target pose declarations
  //Up_home position declarations
  geometry_msgs::Pose lb_toe_up_home;
  geometry_msgs::Pose lf_toe_up_home;
  geometry_msgs::Pose lm_toe_up_home;

  geometry_msgs::Pose rb_toe_up_home;
  geometry_msgs::Pose rf_toe_up_home;
  geometry_msgs::Pose rm_toe_up_home;

  //--------------------------------------------------------------------------------
  //Target pose declarations 
  geometry_msgs::Pose lb_toe_down_backward;
  geometry_msgs::Pose lf_toe_down_backward;
  geometry_msgs::Pose lm_toe_down_backward;

  geometry_msgs::Pose rb_toe_down_backward;
  geometry_msgs::Pose rf_toe_down_backward;
  geometry_msgs::Pose rm_toe_down_backward;

  //--------------------------------------------------------------------------------
  //Target pose declarations 
  geometry_msgs::Pose lb_toe_up_backward;
  geometry_msgs::Pose lf_toe_up_backward;
  geometry_msgs::Pose lm_toe_up_backward;

  geometry_msgs::Pose rb_toe_up_backward;
  geometry_msgs::Pose rf_toe_up_backward;
  geometry_msgs::Pose rm_toe_up_backward;

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

  //Right up and forward defitions
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

  lb_toe_down_forward.position.x = -0.0953619;
  lb_toe_down_forward.position.y = 0.138947;
  lb_toe_down_forward.position.z = -0.117145;

  lf_toe_down_forward.position.x = 0.209946;
  lf_toe_down_forward.position.y = 0.141048;
  lf_toe_down_forward.position.z = -0.114861;

  lm_toe_down_forward.position.x = 0.0588517;
  lm_toe_down_forward.position.y = 0.141638;
  lm_toe_down_forward.position.z = -0.115452;
  //--------------------------------------------------------------------------------

  //Right up and foward defitions
  rb_toe_down_forward.position.x = -0.0954773;
  rb_toe_down_forward.position.y = -0.1389;
  rb_toe_down_forward.position.z = -0.11546;

  rf_toe_down_forward.position.x =  0.208273;
  rf_toe_down_forward.position.y = -0.139224;
  rf_toe_down_forward.position.z = -0.11626;

  rm_toe_down_forward.position.x = 0.0563553;
  rm_toe_down_forward.position.y = -0.138944;
  rm_toe_down_forward.position.z = -0.115839;

  //--------------------------------------------------------------------------------
  //Left down and forward defintion

  lb_toe_up_home.position.x = -0.0520047;
  lb_toe_up_home.position.y = 0.185305;
  lb_toe_up_home.position.z = -0.0428311;

  lf_toe_up_home.position.x = 0.25078;
  lf_toe_up_home.position.y = 0.184788;
  lf_toe_up_home.position.z = -0.0429786;

  lm_toe_up_home.position.x = 0.0998278;
  lm_toe_up_home.position.y = 0.185476;
  lm_toe_up_home.position.z = -0.0428002;

  //--------------------------------------------------------------------------------

  //Right up and foward defitions
  rb_toe_up_home.position.x = -0.0533545;
  rb_toe_up_home.position.y = -0.183999;
  rb_toe_up_home.position.z = -0.0435861;

  rf_toe_up_home.position.x =  0.250694;
  rf_toe_up_home.position.y = -0.184644;
  rf_toe_up_home.position.z = -0.0438348;

  rm_toe_up_home.position.x = 0.098666;
  rm_toe_up_home.position.y = -0.184195;
  rm_toe_up_home.position.z = -0.0437799;

  //--------------------------------------------------------------------------------


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

  ros::Publisher js_publisher = node_handle.advertise<sensor_msgs::JointState>("/joint_states", 1, true);

  lb_leg.setNamedTarget("default");
  lf_leg.setNamedTarget("default");
  lm_leg.setNamedTarget("default");

  rb_leg.setNamedTarget("default");
  rf_leg.setNamedTarget("default");
  rm_leg.setNamedTarget("default");

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
  sleep(20.0);

  sensor_msgs::JointState home1;
  home1.name.push_back("rm_hip");
  home1.name.push_back("rm_toe");
  home1.name.push_back("rm_knee");
  
  home1.name.push_back("lf_hip");
  home1.name.push_back("lf_knee");
  home1.name.push_back("lf_toe");
  
  home1.name.push_back("lb_hip");
  home1.name.push_back("lb_knee");
  home1.name.push_back("lb_toe");
  
  home1.position.push_back(0.00036366274877781607);
  home1.position.push_back(0.0014642818616096864);
  home1.position.push_back(1.5742249193273423);
  
  home1.position.push_back(0.0001195254564282332);
  home1.position.push_back(-0.0013927852805418845);
  home1.position.push_back(1.5696556967893192);
  
  home1.position.push_back(-0.03041695415859095);
  home1.position.push_back(0.028544208166492172);
  home1.position.push_back(-1.570191581062994);
  
  
  sensor_msgs::JointState home2;

  home2.name.push_back("rf_hip");
  home2.name.push_back("rf_knee");
  home2.name.push_back("rf_toe");
  
  home2.name.push_back("rb_hip");
  home2.name.push_back("rb_knee");
  home2.name.push_back("rb_toe");
  
  home2.name.push_back("lm_hip");
  home2.name.push_back("lm_knee");
  home2.name.push_back("lm_toe");
  
  home2.position.push_back(0.0005494598920195385);
  home2.position.push_back(0.00033841381185778464);
  home2.position.push_back(1.5745533198544903);
  
  home2.position.push_back(-0.00013365282215757284);
  home2.position.push_back(-0.0015704057142507306);
  home2.position.push_back(1.5694978101688597);
  
  home2.position.push_back(0.0001626035399991959);
  home2.position.push_back(-0.0013168479862824926);
  home2.position.push_back(-1.5703153291811438);  


  while(1)
  {
    state = 0;
    switch(state)
    {
      case 0: // Walk / Check
      {
        if(lidar1>200 && lidar2>200)
        {
          state = 0;
          printf("Walking State");

          lb_leg.setPositionTarget(lb_toe_up_forward.position.x, lb_toe_up_forward.position.y, lb_toe_up_forward.position.z, "lb_toe_end");
          lf_leg.setPositionTarget(lf_toe_up_forward.position.x, lf_toe_up_forward.position.y, lf_toe_up_forward.position.z, "lf_toe_end");
          rm_leg.setPositionTarget(rm_toe_up_forward.position.x, rm_toe_up_forward.position.y, rm_toe_up_forward.position.z, "rm_toe_end");

          success = (bool)(lb_leg.plan(lb_leg_plan));
          ROS_INFO("Visualizing plan 2 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lb_leg.execute(lb_leg_plan);
          sleep(0.5);

          success = (bool)(lf_leg.plan(lf_leg_plan));
          ROS_INFO("Visualizing plan 3 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lf_leg.execute(lf_leg_plan);
          sleep(0.5);

          success = (bool)(rm_leg.plan(rm_leg_plan));
          ROS_INFO("Visualizing plan 4 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rm_leg.execute(rm_leg_plan);
          sleep(0.5);

          //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          // Set 1 Down and Forward

          lb_leg.setPositionTarget(lb_toe_down_forward.position.x, lb_toe_down_forward.position.y, lb_toe_down_forward.position.z, "lb_toe_end");
          lf_leg.setPositionTarget(lf_toe_down_forward.position.x, lf_toe_down_forward.position.y, lf_toe_down_forward.position.z, "lf_toe_end");
          rm_leg.setPositionTarget(rm_toe_down_forward.position.x, rm_toe_down_forward.position.y, rm_toe_down_forward.position.z, "rm_toe_end");

          success = (bool)(lb_leg.plan(lb_leg_plan));
          ROS_INFO("Visualizing plan 5 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lb_leg.execute(lb_leg_plan);
          sleep(0.5);

          success = (bool)(lf_leg.plan(lf_leg_plan));
          ROS_INFO("Visualizing plan 6 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lf_leg.execute(lf_leg_plan);
          sleep(0.5);

          success = (bool)(rm_leg.plan(rm_leg_plan));
          ROS_INFO("Visualizing plan 7 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rm_leg.execute(rm_leg_plan);
          sleep(0.5);

          //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          // Set 2 Up and Center

          lm_leg.setPositionTarget(lm_toe_up_home.position.x, lm_toe_up_home.position.y, lm_toe_up_home.position.z, "lm_toe_end");
          rb_leg.setPositionTarget(rb_toe_up_home.position.x, rb_toe_up_home.position.y, rb_toe_up_home.position.z, "rb_toe_end");
          rf_leg.setPositionTarget(rf_toe_up_home.position.x, rf_toe_up_home.position.y, rf_toe_up_home.position.z, "rf_toe_end");

          success = (bool)(lm_leg.plan(lm_leg_plan));
          ROS_INFO("Visualizing plan 8 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lb_leg.execute(lm_leg_plan);
          sleep(0.5);

          success = (bool)(rb_leg.plan(rb_leg_plan));
          ROS_INFO("Visualizing plan 9 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rb_leg.execute(rb_leg_plan);
          sleep(0.5);

          success = (bool)(rf_leg.plan(rf_leg_plan));
          ROS_INFO("Visualizing plan 10 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rf_leg.execute(rf_leg_plan);
          sleep(0.5);


          // Center 1
          js_publisher.publish(home1);
          sleep(0.5);






          lm_leg.setPositionTarget(lm_toe_up_forward.position.x, lm_toe_up_forward.position.y, lm_toe_up_forward.position.z, "lm_toe_end");
          rb_leg.setPositionTarget(rb_toe_up_forward.position.x, rb_toe_up_forward.position.y, rb_toe_up_forward.position.z, "rb_toe_end");
          rf_leg.setPositionTarget(rf_toe_up_forward.position.x, rf_toe_up_forward.position.y, rf_toe_up_forward.position.z, "rf_toe_end");

          success = (bool)(lm_leg.plan(lm_leg_plan));
          ROS_INFO("Visualizing plan 11 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lb_leg.execute(lm_leg_plan);
          sleep(0.5);

          success = (bool)(rb_leg.plan(rb_leg_plan));
          ROS_INFO("Visualizing plan 12 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rb_leg.execute(rb_leg_plan);
          sleep(0.5);

          success = (bool)(rf_leg.plan(rf_leg_plan));
          ROS_INFO("Visualizing plan 13 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rf_leg.execute(rf_leg_plan);
          sleep(0.5);

          //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          // Set 2 Down and Forward

          lm_leg.setPositionTarget(lm_toe_down_forward.position.x, lm_toe_down_forward.position.y, lm_toe_down_forward.position.z, "lm_toe_end");
          rb_leg.setPositionTarget(rb_toe_down_forward.position.x, rb_toe_down_forward.position.y, rb_toe_down_forward.position.z, "rb_toe_end");
          rf_leg.setPositionTarget(rf_toe_down_forward.position.x, rf_toe_down_forward.position.y, rf_toe_down_forward.position.z, "rf_toe_end");

          success = (bool)(lm_leg.plan(lm_leg_plan));
          ROS_INFO("Visualizing plan 14 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lb_leg.execute(lm_leg_plan);
          sleep(0.5);

          success = (bool)(rb_leg.plan(rb_leg_plan));
          ROS_INFO("Visualizing plan 15 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rb_leg.execute(rb_leg_plan);
          sleep(0.5);

          success = (bool)(rf_leg.plan(rf_leg_plan));
          ROS_INFO("Visualizing plan 16 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rf_leg.execute(rf_leg_plan);
          sleep(0.5);

          //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
          // Set 1 Up and Center

          lb_leg.setPositionTarget(lb_toe_up_home.position.x, lb_toe_up_home.position.y, lb_toe_up_home.position.z, "lb_toe_end");
          lf_leg.setPositionTarget(lf_toe_up_home.position.x, lf_toe_up_home.position.y, lf_toe_up_home.position.z, "lf_toe_end");
          rm_leg.setPositionTarget(rm_toe_up_home.position.x, rm_toe_up_home.position.y, rm_toe_up_home.position.z, "rm_toe_end");

          success = (bool)(lb_leg.plan(lb_leg_plan));
          ROS_INFO("Visualizing plan 17 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lb_leg.execute(lb_leg_plan);
          sleep(0.5);

          success = (bool)(lf_leg.plan(lf_leg_plan));
          ROS_INFO("Visualizing plan 18 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          lf_leg.execute(lf_leg_plan);
          sleep(0.5);

          success = (bool)(rm_leg.plan(rm_leg_plan));
          ROS_INFO("Visualizing plan 19 (pose goal) %s",success?"":"FAILED");
          sleep(0.5);
          rm_leg.execute(rm_leg_plan);
          sleep(0.5);


          // Center 2
          js_publisher.publish(home2);
          sleep(0.5);

        }
        else
        {
          state = 1;
          printf("Detect State");
        }
        break;
      }

      case 1: // Check if stair / wall
      {
        if(lidar3 > 5000)
        {
          state = 2;
          printf("May be a stair");
        }
        else if(lidar3 < 5000)
        {
          state = 3;
          printf("May be a wall");
        }
        break;
      }

      case 2: // Adjust to get close to stairs
      {
        if(lidar1>100 && lidar2<100)
        {
          printf("Shuffle left");
          break;
        }
        else if(lidar1<100 && lidar2>100)
        {
          printf("Shuffle right");
          break;
        }
        else if(lidar1>100 && lidar2>100)
        {
          printf("Move Closer");
          break;
        }
        else if(lidar1<100 && lidar2<100)
        {
          printf("Stair within climbing distance");
          state = 4;
          break;
        }
      }

      case 3: // Evade the wall
      {
        //EVADE THE WALL
        printf("Evade the wall");
        break;
      }

      case 4: //Align robot
      {
        if(abs(lidar1-lidar2) < 10)
        {
          printf("Aligned for climbing");
          state = 5;
          break;
        }
        if(lidar1-lidar2 < 0)
        {
          printf("Slight turn right");
          break;
        }
        else if(lidar1-lidar2 >0)
        {
          printf("Slight turn left");
          break;
        }
        break;
      }

      case 5: //Climb
      {
          //Climb...
        break;
      }

      default:
        break;

    }
  }
  

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}