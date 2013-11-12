#ifndef OROCOS_JOINTSTATEMSGSERVER_COMPONENT_HPP
#define OROCOS_JOINTSTATEMSGSERVER_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <sensor_msgs/typekit/Types.hpp>

class JointStateMsgServer : public RTT::TaskContext{
  public:
    JointStateMsgServer(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
    double delta;
	sensor_msgs::JointState joint_states;
	OutputPort<sensor_msgs::JointState> port_joint_state;
};
#endif
