#include <time.h>
#include <string.h>
#include <omnetpp.h>
#include <unistd.h>


using namespace omnetpp;

/*
 * incast_burst.cpp
 *
 *  Created on: Oct 4, 2018
 *      Author: stevencheng
 */

class sender_node : public omnetpp::cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
};

class receiver_node : public omnetpp::cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void handleMessage(cMessage *msg) override;
};

// The module class needs to be registered with OMNeT++
Define_Module(receiver_node);
Define_Module(sender_node);

void sender_node::initialize()
{
    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message. Let this be `tic'.
    cMessage *msg = new cMessage(getName());
    usleep(5);
    send(msg, "out");
}

void receiver_node::handleMessage(cMessage *msg)
{
    // The handleMessage() method is called whenever a message arrives
    // at the module. Here, we just send it to the other module, through
    // gate `out'. Because both `tic' and `toc' does the same, the message
    // will bounce between the two.
}
