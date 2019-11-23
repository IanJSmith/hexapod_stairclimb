# Install script for directory: /home/darian/test_ws/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/darian/test_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/darian/test_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/darian/test_ws/install" TYPE PROGRAM FILES "/home/darian/test_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/darian/test_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/darian/test_ws/install" TYPE PROGRAM FILES "/home/darian/test_ws/build/catkin_generated/installspace/env.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/darian/test_ws/install/setup.bash;/home/darian/test_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/darian/test_ws/install" TYPE FILE FILES
    "/home/darian/test_ws/build/catkin_generated/installspace/setup.bash"
    "/home/darian/test_ws/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/darian/test_ws/install/setup.sh;/home/darian/test_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/darian/test_ws/install" TYPE FILE FILES
    "/home/darian/test_ws/build/catkin_generated/installspace/setup.sh"
    "/home/darian/test_ws/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/darian/test_ws/install/setup.zsh;/home/darian/test_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/darian/test_ws/install" TYPE FILE FILES
    "/home/darian/test_ws/build/catkin_generated/installspace/setup.zsh"
    "/home/darian/test_ws/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/darian/test_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/darian/test_ws/install" TYPE FILE FILES "/home/darian/test_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/darian/test_ws/build/gtest/cmake_install.cmake")
  include("/home/darian/test_ws/build/hexapod_gazebo/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_experimental/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_planners/moveit_planners/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_plugins/moveit_plugins/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/moveit_ros/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_runtime/cmake_install.cmake")
  include("/home/darian/test_ws/build/lynxmotion_ssc32/cmake_install.cmake")
  include("/home/darian/test_ws/build/hexapod_control/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_commander/cmake_install.cmake")
  include("/home/darian/test_ws/build/hexapodV2/cmake_install.cmake")
  include("/home/darian/test_ws/build/hexapod_moveit_config/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_core/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_planners/chomp/chomp_motion_planner/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_planners/chomp/chomp_optimizer_adapter/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_plugins/moveit_controller_manager_example/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/perception/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/planning/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_plugins/moveit_fake_controller_manager/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_kinematics/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_planners/ompl/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/move_group/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/manipulation/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/robot_interaction/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_plugins/moveit_simple_controller_manager/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_plugins/moveit_ros_control_interface/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/warehouse/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/benchmarks/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/planning_interface/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_planners/chomp/chomp_interface/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_ros/visualization/cmake_install.cmake")
  include("/home/darian/test_ws/build/moveit/moveit_setup_assistant/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/darian/test_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
