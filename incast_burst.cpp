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
    virtual void handleMessage(cMessage *msg) override;
};

class receiver_node : public omnetpp::cSimpleModule
{
  protected:
    // The following redefined virtual function holds the algorithm.
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

// The module class needs to be registered with OMNeT++
Define_Module(receiver_node);
Define_Module(sender_node);

void sender_node::initialize()
{

}

void sender_node::handleMessage(cMessage *msg)
{
    send(msg, "out");
}

void receiver_node::initialize()
{
    cMessage *msg1 = new cMessage(getName());
    send(msg1, "out1");
    cMessage *msg2 = new cMessage(getName());
    send(msg2, "out2");
    cMessage *msg3 = new cMessage(getName());
    send(msg3, "out3");
    cMessage *msg4 = new cMessage(getName());
    send(msg4, "out4");
}

void receiver_node::handleMessage(cMessage *msg)
{
    // The handleMessage() method is called whenever a message arrives
    // at the module. Here, we just send it to the other module, through
    // gate `out'. Because both `tic' and `toc' does the same, the message
    // will bounce between the two.
    if (strcmp(msg->getArrivalGate()->getName(), "in1") == 0) {
        send(msg, "out1");
    } else if (strcmp(msg->getArrivalGate()->getName(), "in2") == 0) {
        send(msg, "out2");
    } else if (strcmp(msg->getArrivalGate()->getName(), "in3") == 0) {
        send(msg, "out3");
    } else if (strcmp(msg->getArrivalGate()->getName(), "in4") == 0) {
        send(msg, "out4");
    }
}
