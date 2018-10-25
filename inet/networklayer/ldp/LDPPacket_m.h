//
// Generated file, do not edit! Created by nedtool 5.4 from inet/networklayer/ldp/LDPPacket.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_LDPPACKET_M_H
#define __INET_LDPPACKET_M_H

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

// base header: version, length, LSR ID, Label space
#define LDP_BASEHEADER_BYTES  10

// FIXME: the length below is just a guess. TBD find lengths for individual TLVs
// making up different LDP packet types, and determine length for each packet type
#define LDP_HEADER_BYTES  (LDP_BASEHEADER_BYTES+20)
// }}


namespace inet {

/**
 * Enum generated from <tt>inet/networklayer/ldp/LDPPacket.msg:33</tt> by nedtool.
 * <pre>
 * //
 * // LDP message types
 * //
 * enum LDP_MESSAGE_TYPES
 * {
 *     NOTIFICATION = 10;
 *     HELLO = 11;
 *     INITIALIZATION = 12;
 *     KEEP_ALIVE = 13;
 *     ADDRESS = 14;
 *     ADDRESS_WITHDRAW = 15;
 *     LABEL_MAPPING = 16;
 *     LABEL_REQUEST = 17;
 *     LABEL_WITHDRAW = 18;
 *     LABEL_RELEASE = 19;
 *     UNKNOWN = 20;
 * }
 * </pre>
 */
enum LDP_MESSAGE_TYPES {
    NOTIFICATION = 10,
    HELLO = 11,
    INITIALIZATION = 12,
    KEEP_ALIVE = 13,
    ADDRESS = 14,
    ADDRESS_WITHDRAW = 15,
    LABEL_MAPPING = 16,
    LABEL_REQUEST = 17,
    LABEL_WITHDRAW = 18,
    LABEL_RELEASE = 19,
    UNKNOWN = 20
};

/**
 * Enum generated from <tt>inet/networklayer/ldp/LDPPacket.msg:49</tt> by nedtool.
 * <pre>
 * enum LDP_STATUS_TYPES
 * {
 *     NO_ROUTE = 13;
 * }
 * </pre>
 */
enum LDP_STATUS_TYPES {
    NO_ROUTE = 13
};

/**
 * Struct generated from inet/networklayer/ldp/LDPPacket.msg:55 by nedtool.
 */
struct INET_API FEC_TLV
{
    FEC_TLV();
    IPv4Address addr;
    int length;
};

// helpers for local use
void INET_API __doPacking(omnetpp::cCommBuffer *b, const FEC_TLV& a);
void INET_API __doUnpacking(omnetpp::cCommBuffer *b, FEC_TLV& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const FEC_TLV& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, FEC_TLV& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:64</tt> by nedtool.
 * <pre>
 * //
 * // Base class for LDP packets
 * //
 * packet LDPPacket
 * {
 *     int type;
 *     IPv4Address senderAddress;
 *     IPv4Address receiverAddress;
 * }
 * </pre>
 */
class INET_API LDPPacket : public ::omnetpp::cPacket
{
  protected:
    int type;
    IPv4Address senderAddress;
    IPv4Address receiverAddress;

  private:
    void copy(const LDPPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPPacket&);

  public:
    LDPPacket(const char *name=nullptr, short kind=0);
    LDPPacket(const LDPPacket& other);
    virtual ~LDPPacket();
    LDPPacket& operator=(const LDPPacket& other);
    virtual LDPPacket *dup() const override {return new LDPPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getType() const;
    virtual void setType(int type);
    virtual IPv4Address& getSenderAddress();
    virtual const IPv4Address& getSenderAddress() const {return const_cast<LDPPacket*>(this)->getSenderAddress();}
    virtual void setSenderAddress(const IPv4Address& senderAddress);
    virtual IPv4Address& getReceiverAddress();
    virtual const IPv4Address& getReceiverAddress() const {return const_cast<LDPPacket*>(this)->getReceiverAddress();}
    virtual void setReceiverAddress(const IPv4Address& receiverAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:75</tt> by nedtool.
 * <pre>
 * //
 * // LDP Label Mapping Message
 * //
 * packet LDPLabelMapping extends LDPPacket
 * {
 *     FEC_TLV fec;
 *     int label;
 * }
 * </pre>
 */
class INET_API LDPLabelMapping : public ::inet::LDPPacket
{
  protected:
    FEC_TLV fec;
    int label;

  private:
    void copy(const LDPLabelMapping& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPLabelMapping&);

  public:
    LDPLabelMapping(const char *name=nullptr, short kind=0);
    LDPLabelMapping(const LDPLabelMapping& other);
    virtual ~LDPLabelMapping();
    LDPLabelMapping& operator=(const LDPLabelMapping& other);
    virtual LDPLabelMapping *dup() const override {return new LDPLabelMapping(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual FEC_TLV& getFec();
    virtual const FEC_TLV& getFec() const {return const_cast<LDPLabelMapping*>(this)->getFec();}
    virtual void setFec(const FEC_TLV& fec);
    virtual int getLabel() const;
    virtual void setLabel(int label);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPLabelMapping& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPLabelMapping& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:84</tt> by nedtool.
 * <pre>
 * //
 * // LDP Label Request Message
 * //
 * packet LDPLabelRequest extends LDPPacket
 * {
 *     FEC_TLV fec;
 * }
 * </pre>
 */
class INET_API LDPLabelRequest : public ::inet::LDPPacket
{
  protected:
    FEC_TLV fec;

  private:
    void copy(const LDPLabelRequest& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPLabelRequest&);

  public:
    LDPLabelRequest(const char *name=nullptr, short kind=0);
    LDPLabelRequest(const LDPLabelRequest& other);
    virtual ~LDPLabelRequest();
    LDPLabelRequest& operator=(const LDPLabelRequest& other);
    virtual LDPLabelRequest *dup() const override {return new LDPLabelRequest(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual FEC_TLV& getFec();
    virtual const FEC_TLV& getFec() const {return const_cast<LDPLabelRequest*>(this)->getFec();}
    virtual void setFec(const FEC_TLV& fec);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPLabelRequest& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPLabelRequest& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:93</tt> by nedtool.
 * <pre>
 * //
 * // LDP Hello Message
 * //
 * packet LDPHello extends LDPPacket
 * {
 *     double holdTime;
 *     bool tbit;
 *     bool rbit;
 * }
 * </pre>
 */
class INET_API LDPHello : public ::inet::LDPPacket
{
  protected:
    double holdTime;
    bool tbit;
    bool rbit;

  private:
    void copy(const LDPHello& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPHello&);

  public:
    LDPHello(const char *name=nullptr, short kind=0);
    LDPHello(const LDPHello& other);
    virtual ~LDPHello();
    LDPHello& operator=(const LDPHello& other);
    virtual LDPHello *dup() const override {return new LDPHello(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getHoldTime() const;
    virtual void setHoldTime(double holdTime);
    virtual bool getTbit() const;
    virtual void setTbit(bool tbit);
    virtual bool getRbit() const;
    virtual void setRbit(bool rbit);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPHello& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPHello& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:103</tt> by nedtool.
 * <pre>
 * //
 * // LDP notification message
 * //
 * packet LDPNotify extends LDPPacket
 * {
 *     int status;
 *     FEC_TLV fec;
 * }
 * </pre>
 */
class INET_API LDPNotify : public ::inet::LDPPacket
{
  protected:
    int status;
    FEC_TLV fec;

  private:
    void copy(const LDPNotify& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPNotify&);

  public:
    LDPNotify(const char *name=nullptr, short kind=0);
    LDPNotify(const LDPNotify& other);
    virtual ~LDPNotify();
    LDPNotify& operator=(const LDPNotify& other);
    virtual LDPNotify *dup() const override {return new LDPNotify(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getStatus() const;
    virtual void setStatus(int status);
    virtual FEC_TLV& getFec();
    virtual const FEC_TLV& getFec() const {return const_cast<LDPNotify*>(this)->getFec();}
    virtual void setFec(const FEC_TLV& fec);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPNotify& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPNotify& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:113</tt> by nedtool.
 * <pre>
 * //
 * // LDP Ini Message
 * //
 * //# FIXME currently unused
 * packet LDPIni extends LDPPacket
 * {
 *     double keepAliveTime;
 *     bool abit;
 *     bool dbit;
 *     int pvLim;
 *     string receiverLDPIdentifier;
 * }
 * </pre>
 */
class INET_API LDPIni : public ::inet::LDPPacket
{
  protected:
    double keepAliveTime;
    bool abit;
    bool dbit;
    int pvLim;
    ::omnetpp::opp_string receiverLDPIdentifier;

  private:
    void copy(const LDPIni& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPIni&);

  public:
    LDPIni(const char *name=nullptr, short kind=0);
    LDPIni(const LDPIni& other);
    virtual ~LDPIni();
    LDPIni& operator=(const LDPIni& other);
    virtual LDPIni *dup() const override {return new LDPIni(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getKeepAliveTime() const;
    virtual void setKeepAliveTime(double keepAliveTime);
    virtual bool getAbit() const;
    virtual void setAbit(bool abit);
    virtual bool getDbit() const;
    virtual void setDbit(bool dbit);
    virtual int getPvLim() const;
    virtual void setPvLim(int pvLim);
    virtual const char * getReceiverLDPIdentifier() const;
    virtual void setReceiverLDPIdentifier(const char * receiverLDPIdentifier);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPIni& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPIni& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/ldp/LDPPacket.msg:126</tt> by nedtool.
 * <pre>
 * //
 * // LDP Address Message
 * //
 * //# FIXME currently unused
 * packet LDPAddress extends LDPPacket
 * {
 *     bool isWithdraw;
 *     string family;
 *     string addresses[];
 * }
 * </pre>
 */
class INET_API LDPAddress : public ::inet::LDPPacket
{
  protected:
    bool isWithdraw;
    ::omnetpp::opp_string family;
    ::omnetpp::opp_string *addresses; // array ptr
    unsigned int addresses_arraysize;

  private:
    void copy(const LDPAddress& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const LDPAddress&);

  public:
    LDPAddress(const char *name=nullptr, short kind=0);
    LDPAddress(const LDPAddress& other);
    virtual ~LDPAddress();
    LDPAddress& operator=(const LDPAddress& other);
    virtual LDPAddress *dup() const override {return new LDPAddress(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getIsWithdraw() const;
    virtual void setIsWithdraw(bool isWithdraw);
    virtual const char * getFamily() const;
    virtual void setFamily(const char * family);
    virtual void setAddressesArraySize(unsigned int size);
    virtual unsigned int getAddressesArraySize() const;
    virtual const char * getAddresses(unsigned int k) const;
    virtual void setAddresses(unsigned int k, const char * addresses);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const LDPAddress& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, LDPAddress& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_LDPPACKET_M_H

