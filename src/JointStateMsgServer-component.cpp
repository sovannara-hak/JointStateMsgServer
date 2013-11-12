#include "JointStateMsgServer-component.hpp"
#include <rtt/Component.hpp>
#include <iostream>

JointStateMsgServer::JointStateMsgServer(std::string const& name) : TaskContext(name){
  std::cout << "JointStateMsgServer constructed !" <<std::endl;
}

bool JointStateMsgServer::configureHook(){
  std::cout << "JointStateMsgServer configured !" <<std::endl;
  return true;
}

bool JointStateMsgServer::startHook(){
  std::cout << "JointStateMsgServer started !" <<std::endl;
  return true;
}

void JointStateMsgServer::updateHook(){
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
