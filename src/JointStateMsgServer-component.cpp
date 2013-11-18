#include "JointStateMsgServer-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

JointStateMsgServer::JointStateMsgServer(std::string const& name) : TaskContext(name){
  this->addPort("JointState", port_joint_state);
  this->addPort("doublePort", port_double);
  std::cout << "JointStateMsgServer constructed !" <<std::endl;
}

bool JointStateMsgServer::configureHook(){
  joint_states.name.resize(7);
  for(unsigned int i = 0; i < 7; i++){
    std::ostringstream ss;
    ss << "body_" << i;
    joint_states.name[i] = ss.str();
  }
  joint_states.position.resize(7);
  joint_states.header.frame_id = "dummy_frame_id";
  delta = 0.0;
  std::cout << "JointStateMsgServer configured !" <<std::endl;
  return true;
}

bool JointStateMsgServer::startHook(){
  std::cout << "JointStateMsgServer started !" <<std::endl;
  return true;
}

void JointStateMsgServer::updateHook(){
  for(unsigned int i = 0; i<7; i++){
      joint_states.position[i] = i + delta;
  }
  delta += 0.05;
  joint_states.header.stamp.fromNSec ( RTT::os::TimeService::Instance()->getNSecs() );
  port_joint_state.write(joint_states);
  port_double.write(delta);
  std::cout << "JointStateMsgServer executes updateHook !" <<std::endl;
}

void JointStateMsgServer::stopHook() {
  std::cout << "JointStateMsgServer executes stopping !" <<std::endl;
}

void JointStateMsgServer::cleanupHook() {
  std::cout << "JointStateMsgServer cleaning up !" <<std::endl;
}

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(JointStateMsgServer)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
ORO_CREATE_COMPONENT(JointStateMsgServer)
