//
// Generated file, do not edit! Created by nedtool 4.6 from package/segment/segment.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "segment_m.h"

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

Register_Class(UdpPacketInterface);

UdpPacketInterface::UdpPacketInterface(const char *name, int kind) : ::cPacket(name,kind)
{
    this->headerLength_var = 0;
}

UdpPacketInterface::UdpPacketInterface(const UdpPacketInterface& other) : ::cPacket(other)
{
    copy(other);
}

UdpPacketInterface::~UdpPacketInterface()
{
}

UdpPacketInterface& UdpPacketInterface::operator=(const UdpPacketInterface& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void UdpPacketInterface::copy(const UdpPacketInterface& other)
{
    this->headerLength_var = other.headerLength_var;
}

void UdpPacketInterface::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->headerLength_var);
}

void UdpPacketInterface::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->headerLength_var);
}

int UdpPacketInterface::getHeaderLength() const
{
    return headerLength_var;
}

void UdpPacketInterface::setHeaderLength(int headerLength)
{
    this->headerLength_var = headerLength;
}

class UdpPacketInterfaceDescriptor : public cClassDescriptor
{
  public:
    UdpPacketInterfaceDescriptor();
    virtual ~UdpPacketInterfaceDescriptor();

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

Register_ClassDescriptor(UdpPacketInterfaceDescriptor);

UdpPacketInterfaceDescriptor::UdpPacketInterfaceDescriptor() : cClassDescriptor("wsn_energy::UdpPacketInterface", "cPacket")
{
}

UdpPacketInterfaceDescriptor::~UdpPacketInterfaceDescriptor()
{
}

bool UdpPacketInterfaceDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UdpPacketInterface *>(obj)!=NULL;
}

const char *UdpPacketInterfaceDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UdpPacketInterfaceDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int UdpPacketInterfaceDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *UdpPacketInterfaceDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "headerLength",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int UdpPacketInterfaceDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UdpPacketInterfaceDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *UdpPacketInterfaceDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int UdpPacketInterfaceDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketInterface *pp = (UdpPacketInterface *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UdpPacketInterfaceDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketInterface *pp = (UdpPacketInterface *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getHeaderLength());
        default: return "";
    }
}

bool UdpPacketInterfaceDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketInterface *pp = (UdpPacketInterface *)object; (void)pp;
    switch (field) {
        case 0: pp->setHeaderLength(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpPacketInterfaceDescriptor::getFieldStructName(void *object, int field) const
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

void *UdpPacketInterfaceDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketInterface *pp = (UdpPacketInterface *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(UdpPacketStandard);

UdpPacketStandard::UdpPacketStandard(const char *name, int kind) : ::wsn_energy::UdpPacketInterface(name,kind)
{
    this->setHeaderLength(8);

    this->sourcePort_var = 0;
    this->length_var = 0;
    this->checksum_var = 0;
    this->destinationPort_var = 0;
}

UdpPacketStandard::UdpPacketStandard(const UdpPacketStandard& other) : ::wsn_energy::UdpPacketInterface(other)
{
    copy(other);
}

UdpPacketStandard::~UdpPacketStandard()
{
}

UdpPacketStandard& UdpPacketStandard::operator=(const UdpPacketStandard& other)
{
    if (this==&other) return *this;
    ::wsn_energy::UdpPacketInterface::operator=(other);
    copy(other);
    return *this;
}

void UdpPacketStandard::copy(const UdpPacketStandard& other)
{
    this->sourcePort_var = other.sourcePort_var;
    this->destinationPortV6_var = other.destinationPortV6_var;
    this->length_var = other.length_var;
    this->checksum_var = other.checksum_var;
    this->destinationPort_var = other.destinationPort_var;
}

void UdpPacketStandard::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::UdpPacketInterface::parsimPack(b);
    doPacking(b,this->sourcePort_var);
    doPacking(b,this->destinationPortV6_var);
    doPacking(b,this->length_var);
    doPacking(b,this->checksum_var);
    doPacking(b,this->destinationPort_var);
}

void UdpPacketStandard::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::UdpPacketInterface::parsimUnpack(b);
    doUnpacking(b,this->sourcePort_var);
    doUnpacking(b,this->destinationPortV6_var);
    doUnpacking(b,this->length_var);
    doUnpacking(b,this->checksum_var);
    doUnpacking(b,this->destinationPort_var);
}

short UdpPacketStandard::getSourcePort() const
{
    return sourcePort_var;
}

void UdpPacketStandard::setSourcePort(short sourcePort)
{
    this->sourcePort_var = sourcePort;
}

IpAddress& UdpPacketStandard::getDestinationPortV6()
{
    return destinationPortV6_var;
}

void UdpPacketStandard::setDestinationPortV6(const IpAddress& destinationPortV6)
{
    this->destinationPortV6_var = destinationPortV6;
}

short UdpPacketStandard::getLength() const
{
    return length_var;
}

void UdpPacketStandard::setLength(short length)
{
    this->length_var = length;
}

short UdpPacketStandard::getChecksum() const
{
    return checksum_var;
}

void UdpPacketStandard::setChecksum(short checksum)
{
    this->checksum_var = checksum;
}

int UdpPacketStandard::getDestinationPort() const
{
    return destinationPort_var;
}

void UdpPacketStandard::setDestinationPort(int destinationPort)
{
    this->destinationPort_var = destinationPort;
}

class UdpPacketStandardDescriptor : public cClassDescriptor
{
  public:
    UdpPacketStandardDescriptor();
    virtual ~UdpPacketStandardDescriptor();

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

Register_ClassDescriptor(UdpPacketStandardDescriptor);

UdpPacketStandardDescriptor::UdpPacketStandardDescriptor() : cClassDescriptor("wsn_energy::UdpPacketStandard", "wsn_energy::UdpPacketInterface")
{
}

UdpPacketStandardDescriptor::~UdpPacketStandardDescriptor()
{
}

bool UdpPacketStandardDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UdpPacketStandard *>(obj)!=NULL;
}

const char *UdpPacketStandardDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UdpPacketStandardDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int UdpPacketStandardDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *UdpPacketStandardDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sourcePort",
        "destinationPortV6",
        "length",
        "checksum",
        "destinationPort",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int UdpPacketStandardDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePort")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPortV6")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksum")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPort")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UdpPacketStandardDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IpAddress",
        "short",
        "short",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *UdpPacketStandardDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int UdpPacketStandardDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketStandard *pp = (UdpPacketStandard *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UdpPacketStandardDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketStandard *pp = (UdpPacketStandard *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSourcePort());
        case 1: {std::stringstream out; out << pp->getDestinationPortV6(); return out.str();}
        case 2: return long2string(pp->getLength());
        case 3: return long2string(pp->getChecksum());
        case 4: return long2string(pp->getDestinationPort());
        default: return "";
    }
}

bool UdpPacketStandardDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketStandard *pp = (UdpPacketStandard *)object; (void)pp;
    switch (field) {
        case 0: pp->setSourcePort(string2long(value)); return true;
        case 2: pp->setLength(string2long(value)); return true;
        case 3: pp->setChecksum(string2long(value)); return true;
        case 4: pp->setDestinationPort(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpPacketStandardDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1: return opp_typename(typeid(IpAddress));
        default: return NULL;
    };
}

void *UdpPacketStandardDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketStandard *pp = (UdpPacketStandard *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getDestinationPortV6()); break;
        default: return NULL;
    }
}

Register_Class(UdpPacketCompressed);

UdpPacketCompressed::UdpPacketCompressed(const char *name, int kind) : ::wsn_energy::UdpPacketInterface(name,kind)
{
    this->setHeaderLength(4);

    this->udpSourcePortCompressed_var = 0;
    this->udpDestinationPortCompressed_var = 0;
    this->lengthCompressed_var = 0;
    this->checksum_var = 0;
    this->inlineLength_var = 0;
    this->inlineUdpSourcePort_var = 0;
    this->inlineUdpDestinationPort_var = 0;
}

UdpPacketCompressed::UdpPacketCompressed(const UdpPacketCompressed& other) : ::wsn_energy::UdpPacketInterface(other)
{
    copy(other);
}

UdpPacketCompressed::~UdpPacketCompressed()
{
}

UdpPacketCompressed& UdpPacketCompressed::operator=(const UdpPacketCompressed& other)
{
    if (this==&other) return *this;
    ::wsn_energy::UdpPacketInterface::operator=(other);
    copy(other);
    return *this;
}

void UdpPacketCompressed::copy(const UdpPacketCompressed& other)
{
    this->udpSourcePortCompressed_var = other.udpSourcePortCompressed_var;
    this->udpDestinationPortCompressed_var = other.udpDestinationPortCompressed_var;
    this->lengthCompressed_var = other.lengthCompressed_var;
    this->checksum_var = other.checksum_var;
    this->inlineLength_var = other.inlineLength_var;
    this->inlineUdpSourcePort_var = other.inlineUdpSourcePort_var;
    this->inlineUdpDestinationPortV6_var = other.inlineUdpDestinationPortV6_var;
    this->inlineUdpDestinationPort_var = other.inlineUdpDestinationPort_var;
}

void UdpPacketCompressed::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::UdpPacketInterface::parsimPack(b);
    doPacking(b,this->udpSourcePortCompressed_var);
    doPacking(b,this->udpDestinationPortCompressed_var);
    doPacking(b,this->lengthCompressed_var);
    doPacking(b,this->checksum_var);
    doPacking(b,this->inlineLength_var);
    doPacking(b,this->inlineUdpSourcePort_var);
    doPacking(b,this->inlineUdpDestinationPortV6_var);
    doPacking(b,this->inlineUdpDestinationPort_var);
}

void UdpPacketCompressed::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::UdpPacketInterface::parsimUnpack(b);
    doUnpacking(b,this->udpSourcePortCompressed_var);
    doUnpacking(b,this->udpDestinationPortCompressed_var);
    doUnpacking(b,this->lengthCompressed_var);
    doUnpacking(b,this->checksum_var);
    doUnpacking(b,this->inlineLength_var);
    doUnpacking(b,this->inlineUdpSourcePort_var);
    doUnpacking(b,this->inlineUdpDestinationPortV6_var);
    doUnpacking(b,this->inlineUdpDestinationPort_var);
}

bool UdpPacketCompressed::getUdpSourcePortCompressed() const
{
    return udpSourcePortCompressed_var;
}

void UdpPacketCompressed::setUdpSourcePortCompressed(bool udpSourcePortCompressed)
{
    this->udpSourcePortCompressed_var = udpSourcePortCompressed;
}

bool UdpPacketCompressed::getUdpDestinationPortCompressed() const
{
    return udpDestinationPortCompressed_var;
}

void UdpPacketCompressed::setUdpDestinationPortCompressed(bool udpDestinationPortCompressed)
{
    this->udpDestinationPortCompressed_var = udpDestinationPortCompressed;
}

bool UdpPacketCompressed::getLengthCompressed() const
{
    return lengthCompressed_var;
}

void UdpPacketCompressed::setLengthCompressed(bool lengthCompressed)
{
    this->lengthCompressed_var = lengthCompressed;
}

short UdpPacketCompressed::getChecksum() const
{
    return checksum_var;
}

void UdpPacketCompressed::setChecksum(short checksum)
{
    this->checksum_var = checksum;
}

int UdpPacketCompressed::getInlineLength() const
{
    return inlineLength_var;
}

void UdpPacketCompressed::setInlineLength(int inlineLength)
{
    this->inlineLength_var = inlineLength;
}

int UdpPacketCompressed::getInlineUdpSourcePort() const
{
    return inlineUdpSourcePort_var;
}

void UdpPacketCompressed::setInlineUdpSourcePort(int inlineUdpSourcePort)
{
    this->inlineUdpSourcePort_var = inlineUdpSourcePort;
}

IpAddress& UdpPacketCompressed::getInlineUdpDestinationPortV6()
{
    return inlineUdpDestinationPortV6_var;
}

void UdpPacketCompressed::setInlineUdpDestinationPortV6(const IpAddress& inlineUdpDestinationPortV6)
{
    this->inlineUdpDestinationPortV6_var = inlineUdpDestinationPortV6;
}

int UdpPacketCompressed::getInlineUdpDestinationPort() const
{
    return inlineUdpDestinationPort_var;
}

void UdpPacketCompressed::setInlineUdpDestinationPort(int inlineUdpDestinationPort)
{
    this->inlineUdpDestinationPort_var = inlineUdpDestinationPort;
}

class UdpPacketCompressedDescriptor : public cClassDescriptor
{
  public:
    UdpPacketCompressedDescriptor();
    virtual ~UdpPacketCompressedDescriptor();

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

Register_ClassDescriptor(UdpPacketCompressedDescriptor);

UdpPacketCompressedDescriptor::UdpPacketCompressedDescriptor() : cClassDescriptor("wsn_energy::UdpPacketCompressed", "wsn_energy::UdpPacketInterface")
{
}

UdpPacketCompressedDescriptor::~UdpPacketCompressedDescriptor()
{
}

bool UdpPacketCompressedDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<UdpPacketCompressed *>(obj)!=NULL;
}

const char *UdpPacketCompressedDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int UdpPacketCompressedDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int UdpPacketCompressedDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *UdpPacketCompressedDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "udpSourcePortCompressed",
        "udpDestinationPortCompressed",
        "lengthCompressed",
        "checksum",
        "inlineLength",
        "inlineUdpSourcePort",
        "inlineUdpDestinationPortV6",
        "inlineUdpDestinationPort",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int UdpPacketCompressedDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='u' && strcmp(fieldName, "udpSourcePortCompressed")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "udpDestinationPortCompressed")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lengthCompressed")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksum")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "inlineLength")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "inlineUdpSourcePort")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "inlineUdpDestinationPortV6")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "inlineUdpDestinationPort")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *UdpPacketCompressedDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "short",
        "int",
        "int",
        "IpAddress",
        "int",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *UdpPacketCompressedDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int UdpPacketCompressedDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketCompressed *pp = (UdpPacketCompressed *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string UdpPacketCompressedDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketCompressed *pp = (UdpPacketCompressed *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getUdpSourcePortCompressed());
        case 1: return bool2string(pp->getUdpDestinationPortCompressed());
        case 2: return bool2string(pp->getLengthCompressed());
        case 3: return long2string(pp->getChecksum());
        case 4: return long2string(pp->getInlineLength());
        case 5: return long2string(pp->getInlineUdpSourcePort());
        case 6: {std::stringstream out; out << pp->getInlineUdpDestinationPortV6(); return out.str();}
        case 7: return long2string(pp->getInlineUdpDestinationPort());
        default: return "";
    }
}

bool UdpPacketCompressedDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketCompressed *pp = (UdpPacketCompressed *)object; (void)pp;
    switch (field) {
        case 0: pp->setUdpSourcePortCompressed(string2bool(value)); return true;
        case 1: pp->setUdpDestinationPortCompressed(string2bool(value)); return true;
        case 2: pp->setLengthCompressed(string2bool(value)); return true;
        case 3: pp->setChecksum(string2long(value)); return true;
        case 4: pp->setInlineLength(string2long(value)); return true;
        case 5: pp->setInlineUdpSourcePort(string2long(value)); return true;
        case 7: pp->setInlineUdpDestinationPort(string2long(value)); return true;
        default: return false;
    }
}

const char *UdpPacketCompressedDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 6: return opp_typename(typeid(IpAddress));
        default: return NULL;
    };
}

void *UdpPacketCompressedDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    UdpPacketCompressed *pp = (UdpPacketCompressed *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getInlineUdpDestinationPortV6()); break;
        default: return NULL;
    }
}

} // namespace wsn_energy

