//
// Generated file, do not edit! Created by nedtool 5.4 from inet/networklayer/ted/LinkStatePacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "LinkStatePacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(LinkStateMsg)

LinkStateMsg::LinkStateMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    linkInfo_arraysize = 0;
    this->linkInfo = 0;
    this->request = false;
    this->command = LINK_STATE_MESSAGE;
}

LinkStateMsg::LinkStateMsg(const LinkStateMsg& other) : ::omnetpp::cPacket(other)
{
    linkInfo_arraysize = 0;
    this->linkInfo = 0;
    copy(other);
}

LinkStateMsg::~LinkStateMsg()
{
    delete [] this->linkInfo;
}

LinkStateMsg& LinkStateMsg::operator=(const LinkStateMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LinkStateMsg::copy(const LinkStateMsg& other)
{
    delete [] this->linkInfo;
    this->linkInfo = (other.linkInfo_arraysize==0) ? nullptr : new TELinkStateInfo[other.linkInfo_arraysize];
    linkInfo_arraysize = other.linkInfo_arraysize;
    for (unsigned int i=0; i<linkInfo_arraysize; i++)
        this->linkInfo[i] = other.linkInfo[i];
    this->request = other.request;
    this->command = other.command;
}

void LinkStateMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    b->pack(linkInfo_arraysize);
    doParsimArrayPacking(b,this->linkInfo,linkInfo_arraysize);
    doParsimPacking(b,this->request);
    doParsimPacking(b,this->command);
}

void LinkStateMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    delete [] this->linkInfo;
    b->unpack(linkInfo_arraysize);
    if (linkInfo_arraysize==0) {
        this->linkInfo = 0;
    } else {
        this->linkInfo = new TELinkStateInfo[linkInfo_arraysize];
        doParsimArrayUnpacking(b,this->linkInfo,linkInfo_arraysize);
    }
    doParsimUnpacking(b,this->request);
    doParsimUnpacking(b,this->command);
}

void LinkStateMsg::setLinkInfoArraySize(unsigned int size)
{
    TELinkStateInfo *linkInfo2 = (size==0) ? nullptr : new TELinkStateInfo[size];
    unsigned int sz = linkInfo_arraysize < size ? linkInfo_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        linkInfo2[i] = this->linkInfo[i];
    linkInfo_arraysize = size;
    delete [] this->linkInfo;
    this->linkInfo = linkInfo2;
}

unsigned int LinkStateMsg::getLinkInfoArraySize() const
{
    return linkInfo_arraysize;
}

TELinkStateInfo& LinkStateMsg::getLinkInfo(unsigned int k)
{
    if (k>=linkInfo_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", linkInfo_arraysize, k);
    return this->linkInfo[k];
}

void LinkStateMsg::setLinkInfo(unsigned int k, const TELinkStateInfo& linkInfo)
{
    if (k>=linkInfo_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", linkInfo_arraysize, k);
    this->linkInfo[k] = linkInfo;
}

bool LinkStateMsg::getRequest() const
{
    return this->request;
}

void LinkStateMsg::setRequest(bool request)
{
    this->request = request;
}

int LinkStateMsg::getCommand() const
{
    return this->command;
}

void LinkStateMsg::setCommand(int command)
{
    this->command = command;
}

class LinkStateMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LinkStateMsgDescriptor();
    virtual ~LinkStateMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(LinkStateMsgDescriptor)

LinkStateMsgDescriptor::LinkStateMsgDescriptor() : omnetpp::cClassDescriptor("inet::LinkStateMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

LinkStateMsgDescriptor::~LinkStateMsgDescriptor()
{
    delete[] propertynames;
}

bool LinkStateMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LinkStateMsg *>(obj)!=nullptr;
}

const char **LinkStateMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkStateMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkStateMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LinkStateMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *LinkStateMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "linkInfo",
        "request",
        "command",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int LinkStateMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkInfo")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "request")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkStateMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "TELinkStateInfo",
        "bool",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **LinkStateMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LinkStateMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LinkStateMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LinkStateMsg *pp = (LinkStateMsg *)object; (void)pp;
    switch (field) {
        case 0: return pp->getLinkInfoArraySize();
        default: return 0;
    }
}

const char *LinkStateMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkStateMsg *pp = (LinkStateMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkStateMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LinkStateMsg *pp = (LinkStateMsg *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLinkInfo(i); return out.str();}
        case 1: return bool2string(pp->getRequest());
        case 2: return long2string(pp->getCommand());
        default: return "";
    }
}

bool LinkStateMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LinkStateMsg *pp = (LinkStateMsg *)object; (void)pp;
    switch (field) {
        case 1: pp->setRequest(string2bool(value)); return true;
        case 2: pp->setCommand(string2long(value)); return true;
        default: return false;
    }
}

const char *LinkStateMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(TELinkStateInfo));
        default: return nullptr;
    };
}

void *LinkStateMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LinkStateMsg *pp = (LinkStateMsg *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLinkInfo(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

