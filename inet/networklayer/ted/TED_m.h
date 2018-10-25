//
// Generated file, do not edit! Created by nedtool 5.4 from inet/networklayer/ted/TED.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_TED_M_H
#define __INET_TED_M_H

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
#include "inet/networklayer/contract/ipv4/IPv4Address.h"
// }}


namespace inet {

// cplusplus {{
#define LINK_STATE_MESSAGE      1

typedef std::vector<struct TELinkStateInfo> TELinkStateInfoVector;
// }}

/**
 * Struct generated from inet/networklayer/ted/TED.msg:35 by nedtool.
 */
struct INET_API TELinkStateInfo
{
    TELinkStateInfo();
    IPv4Address advrouter;
    IPv4Address linkid;
    IPv4Address local;
    IPv4Address remote;
    double metric;
    double MaxBandwidth;
    double UnResvBandwidth[8];
    ::omnetpp::simtime_t timestamp;
    unsigned int sourceId;
    unsigned int messageId;
    bool state;
};

// helpers for local use
void INET_API __doPacking(omnetpp::cCommBuffer *b, const TELinkStateInfo& a);
void INET_API __doUnpacking(omnetpp::cCommBuffer *b, TELinkStateInfo& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TELinkStateInfo& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TELinkStateInfo& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>inet/networklayer/ted/TED.msg:57</tt> by nedtool.
 * <pre>
 * //
 * // Data structure supplied with NF_TED_CHANGE signal.
 * // This triggers the link state protocol to send out up-to-date link state info
 * // about the given links.
 * //
 * class TEDChangeInfo
 * {
 *     int tedLinkIndices[];
 * }
 * </pre>
 */
class INET_API TEDChangeInfo : public ::omnetpp::cObject
{
  protected:
    int *tedLinkIndices; // array ptr
    unsigned int tedLinkIndices_arraysize;

  private:
    void copy(const TEDChangeInfo& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TEDChangeInfo&);

  public:
    TEDChangeInfo();
    TEDChangeInfo(const TEDChangeInfo& other);
    virtual ~TEDChangeInfo();
    TEDChangeInfo& operator=(const TEDChangeInfo& other);
    virtual TEDChangeInfo *dup() const override {return new TEDChangeInfo(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setTedLinkIndicesArraySize(unsigned int size);
    virtual unsigned int getTedLinkIndicesArraySize() const;
    virtual int getTedLinkIndices(unsigned int k) const;
    virtual void setTedLinkIndices(unsigned int k, int tedLinkIndices);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TEDChangeInfo& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TEDChangeInfo& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_TED_M_H

