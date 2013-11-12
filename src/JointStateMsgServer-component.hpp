#ifndef OROCOS_JOINTSTATEMSGSERVER_COMPONENT_HPP
#define OROCOS_JOINTSTATEMSGSERVER_COMPONENT_HPP

#include <rtt/RTT.hpp>

class JointStateMsgServer : public RTT::TaskContext{
  public:
    JointStateMsgServer(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};
#endif
