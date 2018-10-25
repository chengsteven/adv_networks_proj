//
// Generated file, do not edit! Created by nedtool 5.4 from inet/networklayer/common/EchoPacket.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_ECHOPACKET_M_H
#define __INET_ECHOPACKET_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif

// cplusplus {{
#include "inet/common/INETDefs.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/networklayer/common/EchoPacket.msg:28</tt> by nedtool.
 * <pre>
 * //
 * // Determines the packet type.
 * //
 * enum EchoProtocolType
 * {
 *     ECHO_PROTOCOL_REQUEST = 0;
 *     ECHO_PROTOCOL_REPLY = 1;
 * }
 * </pre>
 */
enum EchoProtocolType {
    ECHO_PROTOCOL_REQUEST = 0,
    ECHO_PROTOCOL_REPLY = 1
};

/**
 * Class generated from <tt>inet/networklayer/common/EchoPacket.msg:37</tt> by nedtool.
 * <pre>
 * //
 * // Generic network protocol packet for testing network connectivity.
 * //
 * packet EchoPacket
 * {
 *     int type \@enum(EchoProtocolType);
 * }
 * </pre>
 */
class INET_API EchoPacket : public ::omnetpp::cPacket
{
  protected:
    int type;

  private:
    void copy(const EchoPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const EchoPacket&);

  public:
    EchoPacket(const char *name=nullptr, short kind=0);
    EchoPacket(const EchoPacket& other);
    virtual ~EchoPacket();
    EchoPacket& operator=(const EchoPacket& other);
    virtual EchoPacket *dup() const override {return new EchoPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getType() const;
    virtual void setType(int type);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const EchoPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, EchoPacket& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_ECHOPACKET_M_H

