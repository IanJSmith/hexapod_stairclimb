cmake_minimum_required(VERSION 2.8.3)
project(hexapod_moveit_config)

find_package(catkin REQUIRED
	COMPONENTS
		moveit_core
		moveit_ros_planning
		moveit_ros_planning_interface
		pluginlib
		geometric_shapes
		moveit_visual_tools
	)

add_compile_options(-std=c++11)

catkin_package()

include_directories(include
	${catkin_INCLUDE_DIRS}
)

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
	PATTERN "setup_assistant.launch" EXCLUDE)
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

add_executable(hexapod_movement src/hexapod_movement.cpp)
target_link_libraries(hexapod_movement ${catkin_LIBRARIES})
