//
// Generated file, do not edit! Created by nedtool 4.6 from package/packet/packet.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "packet_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}



namespace wsn_energy {

// Template rule for outputting std::vector<T> types
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

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::IP_PACKET_NEXT_HEADER");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::IP_PACKET_NEXT_HEADER"));
    e->insert(NEXT_HEADER_UDP, "NEXT_HEADER_UDP");
    e->insert(NEXT_HEADER_TCP, "NEXT_HEADER_TCP");
    e->insert(NEXT_HEADER_ICMP, "NEXT_HEADER_ICMP");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::ICMP_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::ICMP_TYPE"));
    e->insert(ICMP_RPL, "ICMP_RPL");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::ICMP_CODE");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::ICMP_CODE"));
    e->insert(RPL_DIO_CODE, "RPL_DIO_CODE");
    e->insert(RPL_DIS_CODE, "RPL_DIS_CODE");
);

Register_Class(IpPacketInterface);

IpPacketInterface::IpPacketInterface(const char *name, int kind) : ::cPacket(name,kind)
{
    this->time_var = 0;
    this->headerLength_var = 0;
}

IpPacketInterface::IpPacketInterface(const IpPacketInterface& other) : ::cPacket(other)
{
    copy(other);
}

IpPacketInterface::~IpPacketInterface()
{
}

IpPacketInterface& IpPacketInterface::operator=(const IpPacketInterface& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IpPacketInterface::copy(const IpPacketInterface& other)
{
    this->time_var = other.time_var;
    this->headerLength_var = other.headerLength_var;
}

void IpPacketInterface::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->time_var);
    doPacking(b,this->headerLength_var);
}

void IpPacketInterface::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->time_var);
    doUnpacking(b,this->headerLength_var);
}

double IpPacketInterface::getTime() const
{
    return time_var;
}

void IpPacketInterface::setTime(double time)
{
    this->time_var = time;
}

int IpPacketInterface::getHeaderLength() const
{
    return headerLength_var;
}

void IpPacketInterface::setHeaderLength(int headerLength)
{
    this->headerLength_var = headerLength;
}

class IpPacketInterfaceDescriptor : public cClassDescriptor
{
  public:
    IpPacketInterfaceDescriptor();
    virtual ~IpPacketInterfaceDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IpPacketInterfaceDescriptor);

IpPacketInterfaceDescriptor::IpPacketInterfaceDescriptor() : cClassDescriptor("wsn_energy::IpPacketInterface", "cPacket")
{
}

IpPacketInterfaceDescriptor::~IpPacketInterfaceDescriptor()
{
}

bool IpPacketInterfaceDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IpPacketInterface *>(obj)!=NULL;
}

const char *IpPacketInterfaceDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IpPacketInterfaceDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int IpPacketInterfaceDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *IpPacketInterfaceDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "time",
        "headerLength",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int IpPacketInterfaceDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IpPacketInterfaceDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *IpPacketInterfaceDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IpPacketInterfaceDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketInterface *pp = (IpPacketInterface *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IpPacketInterfaceDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketInterface *pp = (IpPacketInterface *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getTime());
        case 1: return long2string(pp->getHeaderLength());
        default: return "";
    }
}

bool IpPacketInterfaceDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketInterface *pp = (IpPacketInterface *)object; (void)pp;
    switch (field) {
        case 0: pp->setTime(string2double(value)); return true;
        case 1: pp->setHeaderLength(string2long(value)); return true;
        default: return false;
    }
}

const char *IpPacketInterfaceDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *IpPacketInterfaceDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketInterface *pp = (IpPacketInterface *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(IpPacketStandard);

IpPacketStandard::IpPacketStandard(const char *name, int kind) : ::wsn_energy::IpPacketInterface(name,kind)
{
    this->setHeaderLength(40);

    this->version_var = 0;
    this->trafficClass_var = 0;
    this->flowLabel_var = 0;
    this->payloadLength_var = 0;
    this->nextHeader_var = 0;
    this->hopLimit_var = 0;
    this->sourceIpAddress_var = 0;
    this->destinationIpAddress_var = 0;
}

IpPacketStandard::IpPacketStandard(const IpPacketStandard& other) : ::wsn_energy::IpPacketInterface(other)
{
    copy(other);
}

IpPacketStandard::~IpPacketStandard()
{
}

IpPacketStandard& IpPacketStandard::operator=(const IpPacketStandard& other)
{
    if (this==&other) return *this;
    ::wsn_energy::IpPacketInterface::operator=(other);
    copy(other);
    return *this;
}

void IpPacketStandard::copy(const IpPacketStandard& other)
{
    this->version_var = other.version_var;
    this->trafficClass_var = other.trafficClass_var;
    this->flowLabel_var = other.flowLabel_var;
    this->payloadLength_var = other.payloadLength_var;
    this->nextHeader_var = other.nextHeader_var;
    this->hopLimit_var = other.hopLimit_var;
    this->sourceIpAddressV6_var = other.sourceIpAddressV6_var;
    this->destinationIpAddressV6_var = other.destinationIpAddressV6_var;
    this->sourceIpAddress_var = other.sourceIpAddress_var;
    this->destinationIpAddress_var = other.destinationIpAddress_var;
}

void IpPacketStandard::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::IpPacketInterface::parsimPack(b);
    doPacking(b,this->version_var);
    doPacking(b,this->trafficClass_var);
    doPacking(b,this->flowLabel_var);
    doPacking(b,this->payloadLength_var);
    doPacking(b,this->nextHeader_var);
    doPacking(b,this->hopLimit_var);
    doPacking(b,this->sourceIpAddressV6_var);
    doPacking(b,this->destinationIpAddressV6_var);
    doPacking(b,this->sourceIpAddress_var);
    doPacking(b,this->destinationIpAddress_var);
}

void IpPacketStandard::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::IpPacketInterface::parsimUnpack(b);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->trafficClass_var);
    doUnpacking(b,this->flowLabel_var);
    doUnpacking(b,this->payloadLength_var);
    doUnpacking(b,this->nextHeader_var);
    doUnpacking(b,this->hopLimit_var);
    doUnpacking(b,this->sourceIpAddressV6_var);
    doUnpacking(b,this->destinationIpAddressV6_var);
    doUnpacking(b,this->sourceIpAddress_var);
    doUnpacking(b,this->destinationIpAddress_var);
}

int IpPacketStandard::getVersion() const
{
    return version_var;
}

void IpPacketStandard::setVersion(int version)
{
    this->version_var = version;
}

int IpPacketStandard::getTrafficClass() const
{
    return trafficClass_var;
}

void IpPacketStandard::setTrafficClass(int trafficClass)
{
    this->trafficClass_var = trafficClass;
}

int IpPacketStandard::getFlowLabel() const
{
    return flowLabel_var;
}

void IpPacketStandard::setFlowLabel(int flowLabel)
{
    this->flowLabel_var = flowLabel;
}

int IpPacketStandard::getPayloadLength() const
{
    return payloadLength_var;
}

void IpPacketStandard::setPayloadLength(int payloadLength)
{
    this->payloadLength_var = payloadLength;
}

int IpPacketStandard::getNextHeader() const
{
    return nextHeader_var;
}

void IpPacketStandard::setNextHeader(int nextHeader)
{
    this->nextHeader_var = nextHeader;
}

int IpPacketStandard::getHopLimit() const
{
    return hopLimit_var;
}

void IpPacketStandard::setHopLimit(int hopLimit)
{
    this->hopLimit_var = hopLimit;
}

IpAddress& IpPacketStandard::getSourceIpAddressV6()
{
    return sourceIpAddressV6_var;
}

void IpPacketStandard::setSourceIpAddressV6(const IpAddress& sourceIpAddressV6)
{
    this->sourceIpAddressV6_var = sourceIpAddressV6;
}

IpAddress& IpPacketStandard::getDestinationIpAddressV6()
{
    return destinationIpAddressV6_var;
}

void IpPacketStandard::setDestinationIpAddressV6(const IpAddress& destinationIpAddressV6)
{
    this->destinationIpAddressV6_var = destinationIpAddressV6;
}

int IpPacketStandard::getSourceIpAddress() const
{
    return sourceIpAddress_var;
}

void IpPacketStandard::setSourceIpAddress(int sourceIpAddress)
{
    this->sourceIpAddress_var = sourceIpAddress;
}

int IpPacketStandard::getDestinationIpAddress() const
{
    return destinationIpAddress_var;
}

void IpPacketStandard::setDestinationIpAddress(int destinationIpAddress)
{
    this->destinationIpAddress_var = destinationIpAddress;
}

class IpPacketStandardDescriptor : public cClassDescriptor
{
  public:
    IpPacketStandardDescriptor();
    virtual ~IpPacketStandardDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IpPacketStandardDescriptor);

IpPacketStandardDescriptor::IpPacketStandardDescriptor() : cClassDescriptor("wsn_energy::IpPacketStandard", "wsn_energy::IpPacketInterface")
{
}

IpPacketStandardDescriptor::~IpPacketStandardDescriptor()
{
}

bool IpPacketStandardDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IpPacketStandard *>(obj)!=NULL;
}

const char *IpPacketStandardDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IpPacketStandardDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int IpPacketStandardDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *IpPacketStandardDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "version",
        "trafficClass",
        "flowLabel",
        "payloadLength",
        "nextHeader",
        "hopLimit",
        "sourceIpAddressV6",
        "destinationIpAddressV6",
        "sourceIpAddress",
        "destinationIpAddress",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int IpPacketStandardDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "trafficClass")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "flowLabel")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLength")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHeader")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopLimit")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceIpAddressV6")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationIpAddressV6")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceIpAddress")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationIpAddress")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IpPacketStandardDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "IpAddress",
        "IpAddress",
        "int",
        "int",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *IpPacketStandardDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IpPacketStandardDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketStandard *pp = (IpPacketStandard *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IpPacketStandardDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketStandard *pp = (IpPacketStandard *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVersion());
        case 1: return long2string(pp->getTrafficClass());
        case 2: return long2string(pp->getFlowLabel());
        case 3: return long2string(pp->getPayloadLength());
        case 4: return long2string(pp->getNextHeader());
        case 5: return long2string(pp->getHopLimit());
        case 6: {std::stringstream out; out << pp->getSourceIpAddressV6(); return out.str();}
        case 7: {std::stringstream out; out << pp->getDestinationIpAddressV6(); return out.str();}
        case 8: return long2string(pp->getSourceIpAddress());
        case 9: return long2string(pp->getDestinationIpAddress());
        default: return "";
    }
}

bool IpPacketStandardDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketStandard *pp = (IpPacketStandard *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2long(value)); return true;
        case 1: pp->setTrafficClass(string2long(value)); return true;
        case 2: pp->setFlowLabel(string2long(value)); return true;
        case 3: pp->setPayloadLength(string2long(value)); return true;
        case 4: pp->setNextHeader(string2long(value)); return true;
        case 5: pp->setHopLimit(string2long(value)); return true;
        case 8: pp->setSourceIpAddress(string2long(value)); return true;
        case 9: pp->setDestinationIpAddress(string2long(value)); return true;
        default: return false;
    }
}

const char *IpPacketStandardDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 6: return opp_typename(typeid(IpAddress));
        case 7: return opp_typename(typeid(IpAddress));
        default: return NULL;
    };
}

void *IpPacketStandardDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketStandard *pp = (IpPacketStandard *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getSourceIpAddressV6()); break;
        case 7: return (void *)(&pp->getDestinationIpAddressV6()); break;
        default: return NULL;
    }
}

Register_Class(IpPacketCompressed);

IpPacketCompressed::IpPacketCompressed(const char *name, int kind) : ::wsn_energy::IpPacketInterface(name,kind)
{
    this->setHeaderLength(2);

    this->sourceIpAddress_var = 0;
    this->destinationIpAddress_var = 0;
    this->trafficClassAndFlowLabel_var = 0;
    this->nextHeader_var = 0;
    this->hc2encoding_var = 0;
    this->hopLimit_var = 0;
    this->metaHopLimit_var = 0;
    this->metaSourceIpAddress_var = 0;
    this->metaDestinationIpAddress_var = 0;
}

IpPacketCompressed::IpPacketCompressed(const IpPacketCompressed& other) : ::wsn_energy::IpPacketInterface(other)
{
    copy(other);
}

IpPacketCompressed::~IpPacketCompressed()
{
}

IpPacketCompressed& IpPacketCompressed::operator=(const IpPacketCompressed& other)
{
    if (this==&other) return *this;
    ::wsn_energy::IpPacketInterface::operator=(other);
    copy(other);
    return *this;
}

void IpPacketCompressed::copy(const IpPacketCompressed& other)
{
    this->sourceIpAddress_var = other.sourceIpAddress_var;
    this->destinationIpAddress_var = other.destinationIpAddress_var;
    this->trafficClassAndFlowLabel_var = other.trafficClassAndFlowLabel_var;
    this->nextHeader_var = other.nextHeader_var;
    this->hc2encoding_var = other.hc2encoding_var;
    this->hopLimit_var = other.hopLimit_var;
    this->metaHopLimit_var = other.metaHopLimit_var;
    this->metaSourceIpAddressV6_var = other.metaSourceIpAddressV6_var;
    this->metaDestinationIpAddressV6_var = other.metaDestinationIpAddressV6_var;
    this->metaSourceIpAddress_var = other.metaSourceIpAddress_var;
    this->metaDestinationIpAddress_var = other.metaDestinationIpAddress_var;
}

void IpPacketCompressed::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::IpPacketInterface::parsimPack(b);
    doPacking(b,this->sourceIpAddress_var);
    doPacking(b,this->destinationIpAddress_var);
    doPacking(b,this->trafficClassAndFlowLabel_var);
    doPacking(b,this->nextHeader_var);
    doPacking(b,this->hc2encoding_var);
    doPacking(b,this->hopLimit_var);
    doPacking(b,this->metaHopLimit_var);
    doPacking(b,this->metaSourceIpAddressV6_var);
    doPacking(b,this->metaDestinationIpAddressV6_var);
    doPacking(b,this->metaSourceIpAddress_var);
    doPacking(b,this->metaDestinationIpAddress_var);
}

void IpPacketCompressed::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::IpPacketInterface::parsimUnpack(b);
    doUnpacking(b,this->sourceIpAddress_var);
    doUnpacking(b,this->destinationIpAddress_var);
    doUnpacking(b,this->trafficClassAndFlowLabel_var);
    doUnpacking(b,this->nextHeader_var);
    doUnpacking(b,this->hc2encoding_var);
    doUnpacking(b,this->hopLimit_var);
    doUnpacking(b,this->metaHopLimit_var);
    doUnpacking(b,this->metaSourceIpAddressV6_var);
    doUnpacking(b,this->metaDestinationIpAddressV6_var);
    doUnpacking(b,this->metaSourceIpAddress_var);
    doUnpacking(b,this->metaDestinationIpAddress_var);
}

int IpPacketCompressed::getSourceIpAddress() const
{
    return sourceIpAddress_var;
}

void IpPacketCompressed::setSourceIpAddress(int sourceIpAddress)
{
    this->sourceIpAddress_var = sourceIpAddress;
}

int IpPacketCompressed::getDestinationIpAddress() const
{
    return destinationIpAddress_var;
}

void IpPacketCompressed::setDestinationIpAddress(int destinationIpAddress)
{
    this->destinationIpAddress_var = destinationIpAddress;
}

int IpPacketCompressed::getTrafficClassAndFlowLabel() const
{
    return trafficClassAndFlowLabel_var;
}

void IpPacketCompressed::setTrafficClassAndFlowLabel(int trafficClassAndFlowLabel)
{
    this->trafficClassAndFlowLabel_var = trafficClassAndFlowLabel;
}

int IpPacketCompressed::getNextHeader() const
{
    return nextHeader_var;
}

void IpPacketCompressed::setNextHeader(int nextHeader)
{
    this->nextHeader_var = nextHeader;
}

int IpPacketCompressed::getHc2encoding() const
{
    return hc2encoding_var;
}

void IpPacketCompressed::setHc2encoding(int hc2encoding)
{
    this->hc2encoding_var = hc2encoding;
}

int IpPacketCompressed::getHopLimit() const
{
    return hopLimit_var;
}

void IpPacketCompressed::setHopLimit(int hopLimit)
{
    this->hopLimit_var = hopLimit;
}

int IpPacketCompressed::getMetaHopLimit() const
{
    return metaHopLimit_var;
}

void IpPacketCompressed::setMetaHopLimit(int metaHopLimit)
{
    this->metaHopLimit_var = metaHopLimit;
}

IpAddress& IpPacketCompressed::getMetaSourceIpAddressV6()
{
    return metaSourceIpAddressV6_var;
}

void IpPacketCompressed::setMetaSourceIpAddressV6(const IpAddress& metaSourceIpAddressV6)
{
    this->metaSourceIpAddressV6_var = metaSourceIpAddressV6;
}

IpAddress& IpPacketCompressed::getMetaDestinationIpAddressV6()
{
    return metaDestinationIpAddressV6_var;
}

void IpPacketCompressed::setMetaDestinationIpAddressV6(const IpAddress& metaDestinationIpAddressV6)
{
    this->metaDestinationIpAddressV6_var = metaDestinationIpAddressV6;
}

int IpPacketCompressed::getMetaSourceIpAddress() const
{
    return metaSourceIpAddress_var;
}

void IpPacketCompressed::setMetaSourceIpAddress(int metaSourceIpAddress)
{
    this->metaSourceIpAddress_var = metaSourceIpAddress;
}

int IpPacketCompressed::getMetaDestinationIpAddress() const
{
    return metaDestinationIpAddress_var;
}

void IpPacketCompressed::setMetaDestinationIpAddress(int metaDestinationIpAddress)
{
    this->metaDestinationIpAddress_var = metaDestinationIpAddress;
}

class IpPacketCompressedDescriptor : public cClassDescriptor
{
  public:
    IpPacketCompressedDescriptor();
    virtual ~IpPacketCompressedDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IpPacketCompressedDescriptor);

IpPacketCompressedDescriptor::IpPacketCompressedDescriptor() : cClassDescriptor("wsn_energy::IpPacketCompressed", "wsn_energy::IpPacketInterface")
{
}

IpPacketCompressedDescriptor::~IpPacketCompressedDescriptor()
{
}

bool IpPacketCompressedDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IpPacketCompressed *>(obj)!=NULL;
}

const char *IpPacketCompressedDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IpPacketCompressedDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int IpPacketCompressedDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *IpPacketCompressedDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sourceIpAddress",
        "destinationIpAddress",
        "trafficClassAndFlowLabel",
        "nextHeader",
        "hc2encoding",
        "hopLimit",
        "metaHopLimit",
        "metaSourceIpAddressV6",
        "metaDestinationIpAddressV6",
        "metaSourceIpAddress",
        "metaDestinationIpAddress",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int IpPacketCompressedDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceIpAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationIpAddress")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "trafficClassAndFlowLabel")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHeader")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hc2encoding")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopLimit")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "metaHopLimit")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "metaSourceIpAddressV6")==0) return base+7;
    if (fieldName[0]=='m' && strcmp(fieldName, "metaDestinationIpAddressV6")==0) return base+8;
    if (fieldName[0]=='m' && strcmp(fieldName, "metaSourceIpAddress")==0) return base+9;
    if (fieldName[0]=='m' && strcmp(fieldName, "metaDestinationIpAddress")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IpPacketCompressedDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "IpAddress",
        "IpAddress",
        "int",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *IpPacketCompressedDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IpPacketCompressedDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketCompressed *pp = (IpPacketCompressed *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IpPacketCompressedDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketCompressed *pp = (IpPacketCompressed *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSourceIpAddress());
        case 1: return long2string(pp->getDestinationIpAddress());
        case 2: return long2string(pp->getTrafficClassAndFlowLabel());
        case 3: return long2string(pp->getNextHeader());
        case 4: return long2string(pp->getHc2encoding());
        case 5: return long2string(pp->getHopLimit());
        case 6: return long2string(pp->getMetaHopLimit());
        case 7: {std::stringstream out; out << pp->getMetaSourceIpAddressV6(); return out.str();}
        case 8: {std::stringstream out; out << pp->getMetaDestinationIpAddressV6(); return out.str();}
        case 9: return long2string(pp->getMetaSourceIpAddress());
        case 10: return long2string(pp->getMetaDestinationIpAddress());
        default: return "";
    }
}

bool IpPacketCompressedDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketCompressed *pp = (IpPacketCompressed *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourceIpAddress(string2long(value)); return true;
        case 1: pp->setDestinationIpAddress(string2long(value)); return true;
        case 2: pp->setTrafficClassAndFlowLabel(string2long(value)); return true;
        case 3: pp->setNextHeader(string2long(value)); return true;
        case 4: pp->setHc2encoding(string2long(value)); return true;
        case 5: pp->setHopLimit(string2long(value)); return true;
        case 6: pp->setMetaHopLimit(string2long(value)); return true;
        case 9: pp->setMetaSourceIpAddress(string2long(value)); return true;
        case 10: pp->setMetaDestinationIpAddress(string2long(value)); return true;
        default: return false;
    }
}

const char *IpPacketCompressedDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 7: return opp_typename(typeid(IpAddress));
        case 8: return opp_typename(typeid(IpAddress));
        default: return NULL;
    };
}

void *IpPacketCompressedDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IpPacketCompressed *pp = (IpPacketCompressed *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getMetaSourceIpAddressV6()); break;
        case 8: return (void *)(&pp->getMetaDestinationIpAddressV6()); break;
        default: return NULL;
    }
}

Register_Class(IcmpPacket);

IcmpPacket::IcmpPacket(const char *name, int kind) : ::cPacket(name,kind)
{
    this->headerLength_var = 8;
    this->type_var = 0;
    this->code_var = 0;
    this->checksum_var = 0;
    this->others_var = 0;
}

IcmpPacket::IcmpPacket(const IcmpPacket& other) : ::cPacket(other)
{
    copy(other);
}

IcmpPacket::~IcmpPacket()
{
}

IcmpPacket& IcmpPacket::operator=(const IcmpPacket& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IcmpPacket::copy(const IcmpPacket& other)
{
    this->headerLength_var = other.headerLength_var;
    this->type_var = other.type_var;
    this->code_var = other.code_var;
    this->checksum_var = other.checksum_var;
    this->others_var = other.others_var;
}

void IcmpPacket::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->headerLength_var);
    doPacking(b,this->type_var);
    doPacking(b,this->code_var);
    doPacking(b,this->checksum_var);
    doPacking(b,this->others_var);
}

void IcmpPacket::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->headerLength_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->code_var);
    doUnpacking(b,this->checksum_var);
    doUnpacking(b,this->others_var);
}

int IcmpPacket::getHeaderLength() const
{
    return headerLength_var;
}

void IcmpPacket::setHeaderLength(int headerLength)
{
    this->headerLength_var = headerLength;
}

int IcmpPacket::getType() const
{
    return type_var;
}

void IcmpPacket::setType(int type)
{
    this->type_var = type;
}

int IcmpPacket::getCode() const
{
    return code_var;
}

void IcmpPacket::setCode(int code)
{
    this->code_var = code;
}

int IcmpPacket::getChecksum() const
{
    return checksum_var;
}

void IcmpPacket::setChecksum(int checksum)
{
    this->checksum_var = checksum;
}

int IcmpPacket::getOthers() const
{
    return others_var;
}

void IcmpPacket::setOthers(int others)
{
    this->others_var = others;
}

class IcmpPacketDescriptor : public cClassDescriptor
{
  public:
    IcmpPacketDescriptor();
    virtual ~IcmpPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(IcmpPacketDescriptor);

IcmpPacketDescriptor::IcmpPacketDescriptor() : cClassDescriptor("wsn_energy::IcmpPacket", "cPacket")
{
}

IcmpPacketDescriptor::~IcmpPacketDescriptor()
{
}

bool IcmpPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IcmpPacket *>(obj)!=NULL;
}

const char *IcmpPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IcmpPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int IcmpPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *IcmpPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "headerLength",
        "type",
        "code",
        "checksum",
        "others",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int IcmpPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksum")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "others")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IcmpPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *IcmpPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int IcmpPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IcmpPacket *pp = (IcmpPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IcmpPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IcmpPacket *pp = (IcmpPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getHeaderLength());
        case 1: return long2string(pp->getType());
        case 2: return long2string(pp->getCode());
        case 3: return long2string(pp->getChecksum());
        case 4: return long2string(pp->getOthers());
        default: return "";
    }
}

bool IcmpPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IcmpPacket *pp = (IcmpPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setHeaderLength(string2long(value)); return true;
        case 1: pp->setType(string2long(value)); return true;
        case 2: pp->setCode(string2long(value)); return true;
        case 3: pp->setChecksum(string2long(value)); return true;
        case 4: pp->setOthers(string2long(value)); return true;
        default: return false;
    }
}

const char *IcmpPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *IcmpPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IcmpPacket *pp = (IcmpPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DIO);

DIO::DIO(const char *name, int kind) : ::cPacket(name,kind)
{
    this->senderID_var = 0;
    this->payloadLength_var = 24;
    this->instanceID_var = 0;
    this->version_var = 0;
    this->rank_var = 0;
    this->grounded_var = 0;
    this->o_var = 0;
    this->modeOfOperation_var = 0;
    this->preference_var = 0;
    this->dstn_var = 0;
    this->flags_var = 0;
    this->reserved_var = 0;
    this->dodagID_var = 0;
}

DIO::DIO(const DIO& other) : ::cPacket(other)
{
    copy(other);
}

DIO::~DIO()
{
}

DIO& DIO::operator=(const DIO& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DIO::copy(const DIO& other)
{
    this->senderID_var = other.senderID_var;
    this->payloadLength_var = other.payloadLength_var;
    this->instanceID_var = other.instanceID_var;
    this->version_var = other.version_var;
    this->rank_var = other.rank_var;
    this->grounded_var = other.grounded_var;
    this->o_var = other.o_var;
    this->modeOfOperation_var = other.modeOfOperation_var;
    this->preference_var = other.preference_var;
    this->dstn_var = other.dstn_var;
    this->flags_var = other.flags_var;
    this->reserved_var = other.reserved_var;
    this->dodagID_var = other.dodagID_var;
}

void DIO::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->senderID_var);
    doPacking(b,this->payloadLength_var);
    doPacking(b,this->instanceID_var);
    doPacking(b,this->version_var);
    doPacking(b,this->rank_var);
    doPacking(b,this->grounded_var);
    doPacking(b,this->o_var);
    doPacking(b,this->modeOfOperation_var);
    doPacking(b,this->preference_var);
    doPacking(b,this->dstn_var);
    doPacking(b,this->flags_var);
    doPacking(b,this->reserved_var);
    doPacking(b,this->dodagID_var);
}

void DIO::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->senderID_var);
    doUnpacking(b,this->payloadLength_var);
    doUnpacking(b,this->instanceID_var);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->rank_var);
    doUnpacking(b,this->grounded_var);
    doUnpacking(b,this->o_var);
    doUnpacking(b,this->modeOfOperation_var);
    doUnpacking(b,this->preference_var);
    doUnpacking(b,this->dstn_var);
    doUnpacking(b,this->flags_var);
    doUnpacking(b,this->reserved_var);
    doUnpacking(b,this->dodagID_var);
}

int DIO::getSenderID() const
{
    return senderID_var;
}

void DIO::setSenderID(int senderID)
{
    this->senderID_var = senderID;
}

int DIO::getPayloadLength() const
{
    return payloadLength_var;
}

void DIO::setPayloadLength(int payloadLength)
{
    this->payloadLength_var = payloadLength;
}

int DIO::getInstanceID() const
{
    return instanceID_var;
}

void DIO::setInstanceID(int instanceID)
{
    this->instanceID_var = instanceID;
}

int DIO::getVersion() const
{
    return version_var;
}

void DIO::setVersion(int version)
{
    this->version_var = version;
}

unsigned long DIO::getRank() const
{
    return rank_var;
}

void DIO::setRank(unsigned long rank)
{
    this->rank_var = rank;
}

bool DIO::getGrounded() const
{
    return grounded_var;
}

void DIO::setGrounded(bool grounded)
{
    this->grounded_var = grounded;
}

bool DIO::getO() const
{
    return o_var;
}

void DIO::setO(bool o)
{
    this->o_var = o;
}

int DIO::getModeOfOperation() const
{
    return modeOfOperation_var;
}

void DIO::setModeOfOperation(int modeOfOperation)
{
    this->modeOfOperation_var = modeOfOperation;
}

int DIO::getPreference() const
{
    return preference_var;
}

void DIO::setPreference(int preference)
{
    this->preference_var = preference;
}

int DIO::getDstn() const
{
    return dstn_var;
}

void DIO::setDstn(int dstn)
{
    this->dstn_var = dstn;
}

int DIO::getFlags() const
{
    return flags_var;
}

void DIO::setFlags(int flags)
{
    this->flags_var = flags;
}

int DIO::getReserved() const
{
    return reserved_var;
}

void DIO::setReserved(int reserved)
{
    this->reserved_var = reserved;
}

int DIO::getDodagID() const
{
    return dodagID_var;
}

void DIO::setDodagID(int dodagID)
{
    this->dodagID_var = dodagID;
}

class DIODescriptor : public cClassDescriptor
{
  public:
    DIODescriptor();
    virtual ~DIODescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DIODescriptor);

DIODescriptor::DIODescriptor() : cClassDescriptor("wsn_energy::DIO", "cPacket")
{
}

DIODescriptor::~DIODescriptor()
{
}

bool DIODescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DIO *>(obj)!=NULL;
}

const char *DIODescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DIODescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount(object) : 13;
}

unsigned int DIODescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *DIODescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "senderID",
        "payloadLength",
        "instanceID",
        "version",
        "rank",
        "grounded",
        "o",
        "modeOfOperation",
        "preference",
        "dstn",
        "flags",
        "reserved",
        "dodagID",
    };
    return (field>=0 && field<13) ? fieldNames[field] : NULL;
}

int DIODescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderID")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLength")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "instanceID")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "rank")==0) return base+4;
    if (fieldName[0]=='g' && strcmp(fieldName, "grounded")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "o")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "modeOfOperation")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "preference")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "dstn")==0) return base+9;
    if (fieldName[0]=='f' && strcmp(fieldName, "flags")==0) return base+10;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+11;
    if (fieldName[0]=='d' && strcmp(fieldName, "dodagID")==0) return base+12;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DIODescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "unsigned long",
        "bool",
        "bool",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : NULL;
}

const char *DIODescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DIODescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DIO *pp = (DIO *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DIODescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DIO *pp = (DIO *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSenderID());
        case 1: return long2string(pp->getPayloadLength());
        case 2: return long2string(pp->getInstanceID());
        case 3: return long2string(pp->getVersion());
        case 4: return ulong2string(pp->getRank());
        case 5: return bool2string(pp->getGrounded());
        case 6: return bool2string(pp->getO());
        case 7: return long2string(pp->getModeOfOperation());
        case 8: return long2string(pp->getPreference());
        case 9: return long2string(pp->getDstn());
        case 10: return long2string(pp->getFlags());
        case 11: return long2string(pp->getReserved());
        case 12: return long2string(pp->getDodagID());
        default: return "";
    }
}

bool DIODescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DIO *pp = (DIO *)object; (void)pp;
    switch (field) {
        case 0: pp->setSenderID(string2long(value)); return true;
        case 1: pp->setPayloadLength(string2long(value)); return true;
        case 2: pp->setInstanceID(string2long(value)); return true;
        case 3: pp->setVersion(string2long(value)); return true;
        case 4: pp->setRank(string2ulong(value)); return true;
        case 5: pp->setGrounded(string2bool(value)); return true;
        case 6: pp->setO(string2bool(value)); return true;
        case 7: pp->setModeOfOperation(string2long(value)); return true;
        case 8: pp->setPreference(string2long(value)); return true;
        case 9: pp->setDstn(string2long(value)); return true;
        case 10: pp->setFlags(string2long(value)); return true;
        case 11: pp->setReserved(string2long(value)); return true;
        case 12: pp->setDodagID(string2long(value)); return true;
        default: return false;
    }
}

const char *DIODescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DIODescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DIO *pp = (DIO *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DIS);

DIS::DIS(const char *name, int kind) : ::cPacket(name,kind)
{
    this->payloadLength_var = 2;
    this->flag_var = 0;
    this->reserved_var = 0;
}

DIS::DIS(const DIS& other) : ::cPacket(other)
{
    copy(other);
}

DIS::~DIS()
{
}

DIS& DIS::operator=(const DIS& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DIS::copy(const DIS& other)
{
    this->payloadLength_var = other.payloadLength_var;
    this->flag_var = other.flag_var;
    this->reserved_var = other.reserved_var;
}

void DIS::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->payloadLength_var);
    doPacking(b,this->flag_var);
    doPacking(b,this->reserved_var);
}

void DIS::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->payloadLength_var);
    doUnpacking(b,this->flag_var);
    doUnpacking(b,this->reserved_var);
}

int DIS::getPayloadLength() const
{
    return payloadLength_var;
}

void DIS::setPayloadLength(int payloadLength)
{
    this->payloadLength_var = payloadLength;
}

int DIS::getFlag() const
{
    return flag_var;
}

void DIS::setFlag(int flag)
{
    this->flag_var = flag;
}

int DIS::getReserved() const
{
    return reserved_var;
}

void DIS::setReserved(int reserved)
{
    this->reserved_var = reserved;
}

class DISDescriptor : public cClassDescriptor
{
  public:
    DISDescriptor();
    virtual ~DISDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DISDescriptor);

DISDescriptor::DISDescriptor() : cClassDescriptor("wsn_energy::DIS", "cPacket")
{
}

DISDescriptor::~DISDescriptor()
{
}

bool DISDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DIS *>(obj)!=NULL;
}

const char *DISDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DISDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int DISDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *DISDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "payloadLength",
        "flag",
        "reserved",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int DISDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLength")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flag")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DISDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *DISDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DISDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DIS *pp = (DIS *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DISDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DIS *pp = (DIS *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadLength());
        case 1: return long2string(pp->getFlag());
        case 2: return long2string(pp->getReserved());
        default: return "";
    }
}

bool DISDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DIS *pp = (DIS *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadLength(string2long(value)); return true;
        case 1: pp->setFlag(string2long(value)); return true;
        case 2: pp->setReserved(string2long(value)); return true;
        default: return false;
    }
}

const char *DISDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DISDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DIS *pp = (DIS *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace wsn_energy

