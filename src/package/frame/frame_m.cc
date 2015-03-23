//
// Generated file, do not edit! Created by nedtool 4.6 from package/frame/frame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "frame_m.h"

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
    cEnum *e = cEnum::find("wsn_energy::FRAME_TYPE");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::FRAME_TYPE"));
    e->insert(FRAME_BEACON, "FRAME_BEACON");
    e->insert(FRAME_COMMAND, "FRAME_COMMAND");
    e->insert(FRAME_DATA, "FRAME_DATA");
    e->insert(FRAME_ACK, "FRAME_ACK");
);

Register_Class(Frame);

Frame::Frame(const char *name, int kind) : ::cPacket(name,kind)
{
    this->numberTransmission_var = 0;
    this->headerLength_var = 0;
    this->frameType_var = 0;
    this->securityEnabled_var = 0;
    this->framePending_var = 0;
    this->ackRequired_var = 0;
    this->panIdCompression_var = 0;
    this->reserved_var = 0;
    this->destinationAddressMode_var = 0;
    this->frameVersion_var = 0;
    this->sourceAddressMode_var = 0;
    this->frameCheckSequence_var = 0;
}

Frame::Frame(const Frame& other) : ::cPacket(other)
{
    copy(other);
}

Frame::~Frame()
{
}

Frame& Frame::operator=(const Frame& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Frame::copy(const Frame& other)
{
    this->numberTransmission_var = other.numberTransmission_var;
    this->headerLength_var = other.headerLength_var;
    this->frameType_var = other.frameType_var;
    this->securityEnabled_var = other.securityEnabled_var;
    this->framePending_var = other.framePending_var;
    this->ackRequired_var = other.ackRequired_var;
    this->panIdCompression_var = other.panIdCompression_var;
    this->reserved_var = other.reserved_var;
    this->destinationAddressMode_var = other.destinationAddressMode_var;
    this->frameVersion_var = other.frameVersion_var;
    this->sourceAddressMode_var = other.sourceAddressMode_var;
    this->frameCheckSequence_var = other.frameCheckSequence_var;
}

void Frame::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->numberTransmission_var);
    doPacking(b,this->headerLength_var);
    doPacking(b,this->frameType_var);
    doPacking(b,this->securityEnabled_var);
    doPacking(b,this->framePending_var);
    doPacking(b,this->ackRequired_var);
    doPacking(b,this->panIdCompression_var);
    doPacking(b,this->reserved_var);
    doPacking(b,this->destinationAddressMode_var);
    doPacking(b,this->frameVersion_var);
    doPacking(b,this->sourceAddressMode_var);
    doPacking(b,this->frameCheckSequence_var);
}

void Frame::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->numberTransmission_var);
    doUnpacking(b,this->headerLength_var);
    doUnpacking(b,this->frameType_var);
    doUnpacking(b,this->securityEnabled_var);
    doUnpacking(b,this->framePending_var);
    doUnpacking(b,this->ackRequired_var);
    doUnpacking(b,this->panIdCompression_var);
    doUnpacking(b,this->reserved_var);
    doUnpacking(b,this->destinationAddressMode_var);
    doUnpacking(b,this->frameVersion_var);
    doUnpacking(b,this->sourceAddressMode_var);
    doUnpacking(b,this->frameCheckSequence_var);
}

int Frame::getNumberTransmission() const
{
    return numberTransmission_var;
}

void Frame::setNumberTransmission(int numberTransmission)
{
    this->numberTransmission_var = numberTransmission;
}

int Frame::getHeaderLength() const
{
    return headerLength_var;
}

void Frame::setHeaderLength(int headerLength)
{
    this->headerLength_var = headerLength;
}

int Frame::getFrameType() const
{
    return frameType_var;
}

void Frame::setFrameType(int frameType)
{
    this->frameType_var = frameType;
}

int Frame::getSecurityEnabled() const
{
    return securityEnabled_var;
}

void Frame::setSecurityEnabled(int securityEnabled)
{
    this->securityEnabled_var = securityEnabled;
}

int Frame::getFramePending() const
{
    return framePending_var;
}

void Frame::setFramePending(int framePending)
{
    this->framePending_var = framePending;
}

bool Frame::getAckRequired() const
{
    return ackRequired_var;
}

void Frame::setAckRequired(bool ackRequired)
{
    this->ackRequired_var = ackRequired;
}

bool Frame::getPanIdCompression() const
{
    return panIdCompression_var;
}

void Frame::setPanIdCompression(bool panIdCompression)
{
    this->panIdCompression_var = panIdCompression;
}

int Frame::getReserved() const
{
    return reserved_var;
}

void Frame::setReserved(int reserved)
{
    this->reserved_var = reserved;
}

int Frame::getDestinationAddressMode() const
{
    return destinationAddressMode_var;
}

void Frame::setDestinationAddressMode(int destinationAddressMode)
{
    this->destinationAddressMode_var = destinationAddressMode;
}

int Frame::getFrameVersion() const
{
    return frameVersion_var;
}

void Frame::setFrameVersion(int frameVersion)
{
    this->frameVersion_var = frameVersion;
}

int Frame::getSourceAddressMode() const
{
    return sourceAddressMode_var;
}

void Frame::setSourceAddressMode(int sourceAddressMode)
{
    this->sourceAddressMode_var = sourceAddressMode;
}

uint16_t Frame::getFrameCheckSequence() const
{
    return frameCheckSequence_var;
}

void Frame::setFrameCheckSequence(uint16_t frameCheckSequence)
{
    this->frameCheckSequence_var = frameCheckSequence;
}

class FrameDescriptor : public cClassDescriptor
{
  public:
    FrameDescriptor();
    virtual ~FrameDescriptor();

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

Register_ClassDescriptor(FrameDescriptor);

FrameDescriptor::FrameDescriptor() : cClassDescriptor("wsn_energy::Frame", "cPacket")
{
}

FrameDescriptor::~FrameDescriptor()
{
}

bool FrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Frame *>(obj)!=NULL;
}

const char *FrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount(object) : 12;
}

unsigned int FrameDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *FrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numberTransmission",
        "headerLength",
        "frameType",
        "securityEnabled",
        "framePending",
        "ackRequired",
        "panIdCompression",
        "reserved",
        "destinationAddressMode",
        "frameVersion",
        "sourceAddressMode",
        "frameCheckSequence",
    };
    return (field>=0 && field<12) ? fieldNames[field] : NULL;
}

int FrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberTransmission")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameType")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "securityEnabled")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "framePending")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackRequired")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "panIdCompression")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddressMode")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameVersion")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddressMode")==0) return base+10;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameCheckSequence")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FrameDescriptor::getFieldTypeString(void *object, int field) const
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
        "bool",
        "bool",
        "int",
        "int",
        "int",
        "int",
        "uint16_t",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : NULL;
}

const char *FrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Frame *pp = (Frame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Frame *pp = (Frame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNumberTransmission());
        case 1: return long2string(pp->getHeaderLength());
        case 2: return long2string(pp->getFrameType());
        case 3: return long2string(pp->getSecurityEnabled());
        case 4: return long2string(pp->getFramePending());
        case 5: return bool2string(pp->getAckRequired());
        case 6: return bool2string(pp->getPanIdCompression());
        case 7: return long2string(pp->getReserved());
        case 8: return long2string(pp->getDestinationAddressMode());
        case 9: return long2string(pp->getFrameVersion());
        case 10: return long2string(pp->getSourceAddressMode());
        case 11: return ulong2string(pp->getFrameCheckSequence());
        default: return "";
    }
}

bool FrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Frame *pp = (Frame *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumberTransmission(string2long(value)); return true;
        case 1: pp->setHeaderLength(string2long(value)); return true;
        case 2: pp->setFrameType(string2long(value)); return true;
        case 3: pp->setSecurityEnabled(string2long(value)); return true;
        case 4: pp->setFramePending(string2long(value)); return true;
        case 5: pp->setAckRequired(string2bool(value)); return true;
        case 6: pp->setPanIdCompression(string2bool(value)); return true;
        case 7: pp->setReserved(string2long(value)); return true;
        case 8: pp->setDestinationAddressMode(string2long(value)); return true;
        case 9: pp->setFrameVersion(string2long(value)); return true;
        case 10: pp->setSourceAddressMode(string2long(value)); return true;
        case 11: pp->setFrameCheckSequence(string2ulong(value)); return true;
        default: return false;
    }
}

const char *FrameDescriptor::getFieldStructName(void *object, int field) const
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

void *FrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Frame *pp = (Frame *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(FrameDataStandard);

FrameDataStandard::FrameDataStandard(const char *name, int kind) : ::wsn_energy::Frame(name,kind)
{
    this->setHeaderLength(25);

    this->dataSequenceNumber_var = 0;
    this->sourcePanID_var = 0;
    this->destinationPanID_var = 0;
    this->sourceMacAddress_var = 0;
    this->destinationMacAddress_var = 0;
}

FrameDataStandard::FrameDataStandard(const FrameDataStandard& other) : ::wsn_energy::Frame(other)
{
    copy(other);
}

FrameDataStandard::~FrameDataStandard()
{
}

FrameDataStandard& FrameDataStandard::operator=(const FrameDataStandard& other)
{
    if (this==&other) return *this;
    ::wsn_energy::Frame::operator=(other);
    copy(other);
    return *this;
}

void FrameDataStandard::copy(const FrameDataStandard& other)
{
    this->dataSequenceNumber_var = other.dataSequenceNumber_var;
    this->sourcePanID_var = other.sourcePanID_var;
    this->destinationPanID_var = other.destinationPanID_var;
    this->sourceMacAddressEUI64_var = other.sourceMacAddressEUI64_var;
    this->destinationMacAddressEUI64_var = other.destinationMacAddressEUI64_var;
    this->sourceMacAddress_var = other.sourceMacAddress_var;
    this->destinationMacAddress_var = other.destinationMacAddress_var;
}

void FrameDataStandard::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimPack(b);
    doPacking(b,this->dataSequenceNumber_var);
    doPacking(b,this->sourcePanID_var);
    doPacking(b,this->destinationPanID_var);
    doPacking(b,this->sourceMacAddressEUI64_var);
    doPacking(b,this->destinationMacAddressEUI64_var);
    doPacking(b,this->sourceMacAddress_var);
    doPacking(b,this->destinationMacAddress_var);
}

void FrameDataStandard::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimUnpack(b);
    doUnpacking(b,this->dataSequenceNumber_var);
    doUnpacking(b,this->sourcePanID_var);
    doUnpacking(b,this->destinationPanID_var);
    doUnpacking(b,this->sourceMacAddressEUI64_var);
    doUnpacking(b,this->destinationMacAddressEUI64_var);
    doUnpacking(b,this->sourceMacAddress_var);
    doUnpacking(b,this->destinationMacAddress_var);
}

int FrameDataStandard::getDataSequenceNumber() const
{
    return dataSequenceNumber_var;
}

void FrameDataStandard::setDataSequenceNumber(int dataSequenceNumber)
{
    this->dataSequenceNumber_var = dataSequenceNumber;
}

uint16_t FrameDataStandard::getSourcePanID() const
{
    return sourcePanID_var;
}

void FrameDataStandard::setSourcePanID(uint16_t sourcePanID)
{
    this->sourcePanID_var = sourcePanID;
}

uint16_t FrameDataStandard::getDestinationPanID() const
{
    return destinationPanID_var;
}

void FrameDataStandard::setDestinationPanID(uint16_t destinationPanID)
{
    this->destinationPanID_var = destinationPanID;
}

MacAddress& FrameDataStandard::getSourceMacAddressEUI64()
{
    return sourceMacAddressEUI64_var;
}

void FrameDataStandard::setSourceMacAddressEUI64(const MacAddress& sourceMacAddressEUI64)
{
    this->sourceMacAddressEUI64_var = sourceMacAddressEUI64;
}

MacAddress& FrameDataStandard::getDestinationMacAddressEUI64()
{
    return destinationMacAddressEUI64_var;
}

void FrameDataStandard::setDestinationMacAddressEUI64(const MacAddress& destinationMacAddressEUI64)
{
    this->destinationMacAddressEUI64_var = destinationMacAddressEUI64;
}

int FrameDataStandard::getSourceMacAddress() const
{
    return sourceMacAddress_var;
}

void FrameDataStandard::setSourceMacAddress(int sourceMacAddress)
{
    this->sourceMacAddress_var = sourceMacAddress;
}

int FrameDataStandard::getDestinationMacAddress() const
{
    return destinationMacAddress_var;
}

void FrameDataStandard::setDestinationMacAddress(int destinationMacAddress)
{
    this->destinationMacAddress_var = destinationMacAddress;
}

class FrameDataStandardDescriptor : public cClassDescriptor
{
  public:
    FrameDataStandardDescriptor();
    virtual ~FrameDataStandardDescriptor();

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

Register_ClassDescriptor(FrameDataStandardDescriptor);

FrameDataStandardDescriptor::FrameDataStandardDescriptor() : cClassDescriptor("wsn_energy::FrameDataStandard", "wsn_energy::Frame")
{
}

FrameDataStandardDescriptor::~FrameDataStandardDescriptor()
{
}

bool FrameDataStandardDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FrameDataStandard *>(obj)!=NULL;
}

const char *FrameDataStandardDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FrameDataStandardDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int FrameDataStandardDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *FrameDataStandardDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dataSequenceNumber",
        "sourcePanID",
        "destinationPanID",
        "sourceMacAddressEUI64",
        "destinationMacAddressEUI64",
        "sourceMacAddress",
        "destinationMacAddress",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int FrameDataStandardDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataSequenceNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePanID")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPanID")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceMacAddressEUI64")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationMacAddressEUI64")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceMacAddress")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationMacAddress")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FrameDataStandardDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "uint16_t",
        "uint16_t",
        "MacAddress",
        "MacAddress",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *FrameDataStandardDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FrameDataStandardDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataStandard *pp = (FrameDataStandard *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FrameDataStandardDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataStandard *pp = (FrameDataStandard *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDataSequenceNumber());
        case 1: return ulong2string(pp->getSourcePanID());
        case 2: return ulong2string(pp->getDestinationPanID());
        case 3: {std::stringstream out; out << pp->getSourceMacAddressEUI64(); return out.str();}
        case 4: {std::stringstream out; out << pp->getDestinationMacAddressEUI64(); return out.str();}
        case 5: return long2string(pp->getSourceMacAddress());
        case 6: return long2string(pp->getDestinationMacAddress());
        default: return "";
    }
}

bool FrameDataStandardDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataStandard *pp = (FrameDataStandard *)object; (void)pp;
    switch (field) {
        case 0: pp->setDataSequenceNumber(string2long(value)); return true;
        case 1: pp->setSourcePanID(string2ulong(value)); return true;
        case 2: pp->setDestinationPanID(string2ulong(value)); return true;
        case 5: pp->setSourceMacAddress(string2long(value)); return true;
        case 6: pp->setDestinationMacAddress(string2long(value)); return true;
        default: return false;
    }
}

const char *FrameDataStandardDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3: return opp_typename(typeid(MacAddress));
        case 4: return opp_typename(typeid(MacAddress));
        default: return NULL;
    };
}

void *FrameDataStandardDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataStandard *pp = (FrameDataStandard *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getSourceMacAddressEUI64()); break;
        case 4: return (void *)(&pp->getDestinationMacAddressEUI64()); break;
        default: return NULL;
    }
}

Register_Class(FrameDataCompressed);

FrameDataCompressed::FrameDataCompressed(const char *name, int kind) : ::wsn_energy::Frame(name,kind)
{
    this->headerLength_var = 32;
    this->codeBit_var = 0;
    this->isOrignatorCompressed_var = 0;
    this->isFinalDestinationCompressed_var = 0;
    this->hopLeft_var = 0;
    this->hcDispatch_var = 0;
    this->broadcastHeader_var = 0;
    this->fragmentationHeader_var = 0;
    this->dataSequenceNumber_var = 0;
    this->sourcePanID_var = 0;
    this->destinationPanID_var = 0;
    this->orginatorMacAddress_var = 0;
    this->finalDestinationMacAddress_var = 0;
    this->sourceMacAddress_var = 0;
    this->destinationMacAddress_var = 0;
}

FrameDataCompressed::FrameDataCompressed(const FrameDataCompressed& other) : ::wsn_energy::Frame(other)
{
    copy(other);
}

FrameDataCompressed::~FrameDataCompressed()
{
}

FrameDataCompressed& FrameDataCompressed::operator=(const FrameDataCompressed& other)
{
    if (this==&other) return *this;
    ::wsn_energy::Frame::operator=(other);
    copy(other);
    return *this;
}

void FrameDataCompressed::copy(const FrameDataCompressed& other)
{
    this->headerLength_var = other.headerLength_var;
    this->codeBit_var = other.codeBit_var;
    this->isOrignatorCompressed_var = other.isOrignatorCompressed_var;
    this->isFinalDestinationCompressed_var = other.isFinalDestinationCompressed_var;
    this->hopLeft_var = other.hopLeft_var;
    this->hcDispatch_var = other.hcDispatch_var;
    this->broadcastHeader_var = other.broadcastHeader_var;
    this->fragmentationHeader_var = other.fragmentationHeader_var;
    this->orginatorAddressEUI64_var = other.orginatorAddressEUI64_var;
    this->finalDestinationMacAddressEUI64_var = other.finalDestinationMacAddressEUI64_var;
    this->dataSequenceNumber_var = other.dataSequenceNumber_var;
    this->sourcePanID_var = other.sourcePanID_var;
    this->destinationPanID_var = other.destinationPanID_var;
    this->sourceMacAddressEUI64_var = other.sourceMacAddressEUI64_var;
    this->destinationMacAddressEUI64_var = other.destinationMacAddressEUI64_var;
    this->orginatorMacAddress_var = other.orginatorMacAddress_var;
    this->finalDestinationMacAddress_var = other.finalDestinationMacAddress_var;
    this->sourceMacAddress_var = other.sourceMacAddress_var;
    this->destinationMacAddress_var = other.destinationMacAddress_var;
}

void FrameDataCompressed::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimPack(b);
    doPacking(b,this->headerLength_var);
    doPacking(b,this->codeBit_var);
    doPacking(b,this->isOrignatorCompressed_var);
    doPacking(b,this->isFinalDestinationCompressed_var);
    doPacking(b,this->hopLeft_var);
    doPacking(b,this->hcDispatch_var);
    doPacking(b,this->broadcastHeader_var);
    doPacking(b,this->fragmentationHeader_var);
    doPacking(b,this->orginatorAddressEUI64_var);
    doPacking(b,this->finalDestinationMacAddressEUI64_var);
    doPacking(b,this->dataSequenceNumber_var);
    doPacking(b,this->sourcePanID_var);
    doPacking(b,this->destinationPanID_var);
    doPacking(b,this->sourceMacAddressEUI64_var);
    doPacking(b,this->destinationMacAddressEUI64_var);
    doPacking(b,this->orginatorMacAddress_var);
    doPacking(b,this->finalDestinationMacAddress_var);
    doPacking(b,this->sourceMacAddress_var);
    doPacking(b,this->destinationMacAddress_var);
}

void FrameDataCompressed::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimUnpack(b);
    doUnpacking(b,this->headerLength_var);
    doUnpacking(b,this->codeBit_var);
    doUnpacking(b,this->isOrignatorCompressed_var);
    doUnpacking(b,this->isFinalDestinationCompressed_var);
    doUnpacking(b,this->hopLeft_var);
    doUnpacking(b,this->hcDispatch_var);
    doUnpacking(b,this->broadcastHeader_var);
    doUnpacking(b,this->fragmentationHeader_var);
    doUnpacking(b,this->orginatorAddressEUI64_var);
    doUnpacking(b,this->finalDestinationMacAddressEUI64_var);
    doUnpacking(b,this->dataSequenceNumber_var);
    doUnpacking(b,this->sourcePanID_var);
    doUnpacking(b,this->destinationPanID_var);
    doUnpacking(b,this->sourceMacAddressEUI64_var);
    doUnpacking(b,this->destinationMacAddressEUI64_var);
    doUnpacking(b,this->orginatorMacAddress_var);
    doUnpacking(b,this->finalDestinationMacAddress_var);
    doUnpacking(b,this->sourceMacAddress_var);
    doUnpacking(b,this->destinationMacAddress_var);
}

int FrameDataCompressed::getHeaderLength() const
{
    return headerLength_var;
}

void FrameDataCompressed::setHeaderLength(int headerLength)
{
    this->headerLength_var = headerLength;
}

int FrameDataCompressed::getCodeBit() const
{
    return codeBit_var;
}

void FrameDataCompressed::setCodeBit(int codeBit)
{
    this->codeBit_var = codeBit;
}

bool FrameDataCompressed::getIsOrignatorCompressed() const
{
    return isOrignatorCompressed_var;
}

void FrameDataCompressed::setIsOrignatorCompressed(bool isOrignatorCompressed)
{
    this->isOrignatorCompressed_var = isOrignatorCompressed;
}

bool FrameDataCompressed::getIsFinalDestinationCompressed() const
{
    return isFinalDestinationCompressed_var;
}

void FrameDataCompressed::setIsFinalDestinationCompressed(bool isFinalDestinationCompressed)
{
    this->isFinalDestinationCompressed_var = isFinalDestinationCompressed;
}

int FrameDataCompressed::getHopLeft() const
{
    return hopLeft_var;
}

void FrameDataCompressed::setHopLeft(int hopLeft)
{
    this->hopLeft_var = hopLeft;
}

int FrameDataCompressed::getHcDispatch() const
{
    return hcDispatch_var;
}

void FrameDataCompressed::setHcDispatch(int hcDispatch)
{
    this->hcDispatch_var = hcDispatch;
}

int FrameDataCompressed::getBroadcastHeader() const
{
    return broadcastHeader_var;
}

void FrameDataCompressed::setBroadcastHeader(int broadcastHeader)
{
    this->broadcastHeader_var = broadcastHeader;
}

int FrameDataCompressed::getFragmentationHeader() const
{
    return fragmentationHeader_var;
}

void FrameDataCompressed::setFragmentationHeader(int fragmentationHeader)
{
    this->fragmentationHeader_var = fragmentationHeader;
}

MacAddress& FrameDataCompressed::getOrginatorAddressEUI64()
{
    return orginatorAddressEUI64_var;
}

void FrameDataCompressed::setOrginatorAddressEUI64(const MacAddress& orginatorAddressEUI64)
{
    this->orginatorAddressEUI64_var = orginatorAddressEUI64;
}

MacAddress& FrameDataCompressed::getFinalDestinationMacAddressEUI64()
{
    return finalDestinationMacAddressEUI64_var;
}

void FrameDataCompressed::setFinalDestinationMacAddressEUI64(const MacAddress& finalDestinationMacAddressEUI64)
{
    this->finalDestinationMacAddressEUI64_var = finalDestinationMacAddressEUI64;
}

int FrameDataCompressed::getDataSequenceNumber() const
{
    return dataSequenceNumber_var;
}

void FrameDataCompressed::setDataSequenceNumber(int dataSequenceNumber)
{
    this->dataSequenceNumber_var = dataSequenceNumber;
}

int FrameDataCompressed::getSourcePanID() const
{
    return sourcePanID_var;
}

void FrameDataCompressed::setSourcePanID(int sourcePanID)
{
    this->sourcePanID_var = sourcePanID;
}

int FrameDataCompressed::getDestinationPanID() const
{
    return destinationPanID_var;
}

void FrameDataCompressed::setDestinationPanID(int destinationPanID)
{
    this->destinationPanID_var = destinationPanID;
}

MacAddress& FrameDataCompressed::getSourceMacAddressEUI64()
{
    return sourceMacAddressEUI64_var;
}

void FrameDataCompressed::setSourceMacAddressEUI64(const MacAddress& sourceMacAddressEUI64)
{
    this->sourceMacAddressEUI64_var = sourceMacAddressEUI64;
}

MacAddress& FrameDataCompressed::getDestinationMacAddressEUI64()
{
    return destinationMacAddressEUI64_var;
}

void FrameDataCompressed::setDestinationMacAddressEUI64(const MacAddress& destinationMacAddressEUI64)
{
    this->destinationMacAddressEUI64_var = destinationMacAddressEUI64;
}

int FrameDataCompressed::getOrginatorMacAddress() const
{
    return orginatorMacAddress_var;
}

void FrameDataCompressed::setOrginatorMacAddress(int orginatorMacAddress)
{
    this->orginatorMacAddress_var = orginatorMacAddress;
}

int FrameDataCompressed::getFinalDestinationMacAddress() const
{
    return finalDestinationMacAddress_var;
}

void FrameDataCompressed::setFinalDestinationMacAddress(int finalDestinationMacAddress)
{
    this->finalDestinationMacAddress_var = finalDestinationMacAddress;
}

int FrameDataCompressed::getSourceMacAddress() const
{
    return sourceMacAddress_var;
}

void FrameDataCompressed::setSourceMacAddress(int sourceMacAddress)
{
    this->sourceMacAddress_var = sourceMacAddress;
}

int FrameDataCompressed::getDestinationMacAddress() const
{
    return destinationMacAddress_var;
}

void FrameDataCompressed::setDestinationMacAddress(int destinationMacAddress)
{
    this->destinationMacAddress_var = destinationMacAddress;
}

class FrameDataCompressedDescriptor : public cClassDescriptor
{
  public:
    FrameDataCompressedDescriptor();
    virtual ~FrameDataCompressedDescriptor();

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

Register_ClassDescriptor(FrameDataCompressedDescriptor);

FrameDataCompressedDescriptor::FrameDataCompressedDescriptor() : cClassDescriptor("wsn_energy::FrameDataCompressed", "wsn_energy::Frame")
{
}

FrameDataCompressedDescriptor::~FrameDataCompressedDescriptor()
{
}

bool FrameDataCompressedDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FrameDataCompressed *>(obj)!=NULL;
}

const char *FrameDataCompressedDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FrameDataCompressedDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 19+basedesc->getFieldCount(object) : 19;
}

unsigned int FrameDataCompressedDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<19) ? fieldTypeFlags[field] : 0;
}

const char *FrameDataCompressedDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "headerLength",
        "codeBit",
        "isOrignatorCompressed",
        "isFinalDestinationCompressed",
        "hopLeft",
        "hcDispatch",
        "broadcastHeader",
        "fragmentationHeader",
        "orginatorAddressEUI64",
        "finalDestinationMacAddressEUI64",
        "dataSequenceNumber",
        "sourcePanID",
        "destinationPanID",
        "sourceMacAddressEUI64",
        "destinationMacAddressEUI64",
        "orginatorMacAddress",
        "finalDestinationMacAddress",
        "sourceMacAddress",
        "destinationMacAddress",
    };
    return (field>=0 && field<19) ? fieldNames[field] : NULL;
}

int FrameDataCompressedDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "codeBit")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isOrignatorCompressed")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "isFinalDestinationCompressed")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopLeft")==0) return base+4;
    if (fieldName[0]=='h' && strcmp(fieldName, "hcDispatch")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "broadcastHeader")==0) return base+6;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentationHeader")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "orginatorAddressEUI64")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalDestinationMacAddressEUI64")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataSequenceNumber")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePanID")==0) return base+11;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPanID")==0) return base+12;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceMacAddressEUI64")==0) return base+13;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationMacAddressEUI64")==0) return base+14;
    if (fieldName[0]=='o' && strcmp(fieldName, "orginatorMacAddress")==0) return base+15;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalDestinationMacAddress")==0) return base+16;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceMacAddress")==0) return base+17;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationMacAddress")==0) return base+18;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FrameDataCompressedDescriptor::getFieldTypeString(void *object, int field) const
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
        "bool",
        "bool",
        "int",
        "int",
        "int",
        "int",
        "MacAddress",
        "MacAddress",
        "int",
        "int",
        "int",
        "MacAddress",
        "MacAddress",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<19) ? fieldTypeStrings[field] : NULL;
}

const char *FrameDataCompressedDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FrameDataCompressedDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataCompressed *pp = (FrameDataCompressed *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FrameDataCompressedDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataCompressed *pp = (FrameDataCompressed *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getHeaderLength());
        case 1: return long2string(pp->getCodeBit());
        case 2: return bool2string(pp->getIsOrignatorCompressed());
        case 3: return bool2string(pp->getIsFinalDestinationCompressed());
        case 4: return long2string(pp->getHopLeft());
        case 5: return long2string(pp->getHcDispatch());
        case 6: return long2string(pp->getBroadcastHeader());
        case 7: return long2string(pp->getFragmentationHeader());
        case 8: {std::stringstream out; out << pp->getOrginatorAddressEUI64(); return out.str();}
        case 9: {std::stringstream out; out << pp->getFinalDestinationMacAddressEUI64(); return out.str();}
        case 10: return long2string(pp->getDataSequenceNumber());
        case 11: return long2string(pp->getSourcePanID());
        case 12: return long2string(pp->getDestinationPanID());
        case 13: {std::stringstream out; out << pp->getSourceMacAddressEUI64(); return out.str();}
        case 14: {std::stringstream out; out << pp->getDestinationMacAddressEUI64(); return out.str();}
        case 15: return long2string(pp->getOrginatorMacAddress());
        case 16: return long2string(pp->getFinalDestinationMacAddress());
        case 17: return long2string(pp->getSourceMacAddress());
        case 18: return long2string(pp->getDestinationMacAddress());
        default: return "";
    }
}

bool FrameDataCompressedDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataCompressed *pp = (FrameDataCompressed *)object; (void)pp;
    switch (field) {
        case 0: pp->setHeaderLength(string2long(value)); return true;
        case 1: pp->setCodeBit(string2long(value)); return true;
        case 2: pp->setIsOrignatorCompressed(string2bool(value)); return true;
        case 3: pp->setIsFinalDestinationCompressed(string2bool(value)); return true;
        case 4: pp->setHopLeft(string2long(value)); return true;
        case 5: pp->setHcDispatch(string2long(value)); return true;
        case 6: pp->setBroadcastHeader(string2long(value)); return true;
        case 7: pp->setFragmentationHeader(string2long(value)); return true;
        case 10: pp->setDataSequenceNumber(string2long(value)); return true;
        case 11: pp->setSourcePanID(string2long(value)); return true;
        case 12: pp->setDestinationPanID(string2long(value)); return true;
        case 15: pp->setOrginatorMacAddress(string2long(value)); return true;
        case 16: pp->setFinalDestinationMacAddress(string2long(value)); return true;
        case 17: pp->setSourceMacAddress(string2long(value)); return true;
        case 18: pp->setDestinationMacAddress(string2long(value)); return true;
        default: return false;
    }
}

const char *FrameDataCompressedDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 8: return opp_typename(typeid(MacAddress));
        case 9: return opp_typename(typeid(MacAddress));
        case 13: return opp_typename(typeid(MacAddress));
        case 14: return opp_typename(typeid(MacAddress));
        default: return NULL;
    };
}

void *FrameDataCompressedDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FrameDataCompressed *pp = (FrameDataCompressed *)object; (void)pp;
    switch (field) {
        case 8: return (void *)(&pp->getOrginatorAddressEUI64()); break;
        case 9: return (void *)(&pp->getFinalDestinationMacAddressEUI64()); break;
        case 13: return (void *)(&pp->getSourceMacAddressEUI64()); break;
        case 14: return (void *)(&pp->getDestinationMacAddressEUI64()); break;
        default: return NULL;
    }
}

Register_Class(FrameACK);

FrameACK::FrameACK(const char *name, int kind) : ::wsn_energy::Frame(name,kind)
{
    this->setHeaderLength(5);

    this->dataSequenceNumber_var = 0;
}

FrameACK::FrameACK(const FrameACK& other) : ::wsn_energy::Frame(other)
{
    copy(other);
}

FrameACK::~FrameACK()
{
}

FrameACK& FrameACK::operator=(const FrameACK& other)
{
    if (this==&other) return *this;
    ::wsn_energy::Frame::operator=(other);
    copy(other);
    return *this;
}

void FrameACK::copy(const FrameACK& other)
{
    this->dataSequenceNumber_var = other.dataSequenceNumber_var;
}

void FrameACK::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimPack(b);
    doPacking(b,this->dataSequenceNumber_var);
}

void FrameACK::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimUnpack(b);
    doUnpacking(b,this->dataSequenceNumber_var);
}

int FrameACK::getDataSequenceNumber() const
{
    return dataSequenceNumber_var;
}

void FrameACK::setDataSequenceNumber(int dataSequenceNumber)
{
    this->dataSequenceNumber_var = dataSequenceNumber;
}

class FrameACKDescriptor : public cClassDescriptor
{
  public:
    FrameACKDescriptor();
    virtual ~FrameACKDescriptor();

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

Register_ClassDescriptor(FrameACKDescriptor);

FrameACKDescriptor::FrameACKDescriptor() : cClassDescriptor("wsn_energy::FrameACK", "wsn_energy::Frame")
{
}

FrameACKDescriptor::~FrameACKDescriptor()
{
}

bool FrameACKDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FrameACK *>(obj)!=NULL;
}

const char *FrameACKDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FrameACKDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int FrameACKDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *FrameACKDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dataSequenceNumber",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int FrameACKDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataSequenceNumber")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FrameACKDescriptor::getFieldTypeString(void *object, int field) const
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

const char *FrameACKDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FrameACKDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FrameACK *pp = (FrameACK *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FrameACKDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FrameACK *pp = (FrameACK *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDataSequenceNumber());
        default: return "";
    }
}

bool FrameACKDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FrameACK *pp = (FrameACK *)object; (void)pp;
    switch (field) {
        case 0: pp->setDataSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *FrameACKDescriptor::getFieldStructName(void *object, int field) const
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

void *FrameACKDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FrameACK *pp = (FrameACK *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(FrameBeacon);

FrameBeacon::FrameBeacon(const char *name, int kind) : ::wsn_energy::Frame(name,kind)
{
    this->setHeaderLength(26);

    this->beaconSequenceNumber_var = 0;
    this->sourcePanID_var = 0;
    this->destinationPanID_var = 0;
    this->sourceMacAddress_var = 0;
    this->destinationMacAddress_var = 0;
    this->beaconOrder_var = 0;
    this->superFrameOrder_var = 0;
    this->finalCAPslot_var = 0;
    this->batteryLifeExtension_var = 0;
    this->reserved_var = 0;
    this->PANcoordinator_var = 0;
    this->associationPermit_var = 0;
}

FrameBeacon::FrameBeacon(const FrameBeacon& other) : ::wsn_energy::Frame(other)
{
    copy(other);
}

FrameBeacon::~FrameBeacon()
{
}

FrameBeacon& FrameBeacon::operator=(const FrameBeacon& other)
{
    if (this==&other) return *this;
    ::wsn_energy::Frame::operator=(other);
    copy(other);
    return *this;
}

void FrameBeacon::copy(const FrameBeacon& other)
{
    this->beaconSequenceNumber_var = other.beaconSequenceNumber_var;
    this->sourcePanID_var = other.sourcePanID_var;
    this->destinationPanID_var = other.destinationPanID_var;
    this->sourceMacAddress_var = other.sourceMacAddress_var;
    this->destinationMacAddress_var = other.destinationMacAddress_var;
    this->beaconOrder_var = other.beaconOrder_var;
    this->superFrameOrder_var = other.superFrameOrder_var;
    this->finalCAPslot_var = other.finalCAPslot_var;
    this->batteryLifeExtension_var = other.batteryLifeExtension_var;
    this->reserved_var = other.reserved_var;
    this->PANcoordinator_var = other.PANcoordinator_var;
    this->associationPermit_var = other.associationPermit_var;
}

void FrameBeacon::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimPack(b);
    doPacking(b,this->beaconSequenceNumber_var);
    doPacking(b,this->sourcePanID_var);
    doPacking(b,this->destinationPanID_var);
    doPacking(b,this->sourceMacAddress_var);
    doPacking(b,this->destinationMacAddress_var);
    doPacking(b,this->beaconOrder_var);
    doPacking(b,this->superFrameOrder_var);
    doPacking(b,this->finalCAPslot_var);
    doPacking(b,this->batteryLifeExtension_var);
    doPacking(b,this->reserved_var);
    doPacking(b,this->PANcoordinator_var);
    doPacking(b,this->associationPermit_var);
}

void FrameBeacon::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimUnpack(b);
    doUnpacking(b,this->beaconSequenceNumber_var);
    doUnpacking(b,this->sourcePanID_var);
    doUnpacking(b,this->destinationPanID_var);
    doUnpacking(b,this->sourceMacAddress_var);
    doUnpacking(b,this->destinationMacAddress_var);
    doUnpacking(b,this->beaconOrder_var);
    doUnpacking(b,this->superFrameOrder_var);
    doUnpacking(b,this->finalCAPslot_var);
    doUnpacking(b,this->batteryLifeExtension_var);
    doUnpacking(b,this->reserved_var);
    doUnpacking(b,this->PANcoordinator_var);
    doUnpacking(b,this->associationPermit_var);
}

int FrameBeacon::getBeaconSequenceNumber() const
{
    return beaconSequenceNumber_var;
}

void FrameBeacon::setBeaconSequenceNumber(int beaconSequenceNumber)
{
    this->beaconSequenceNumber_var = beaconSequenceNumber;
}

int FrameBeacon::getSourcePanID() const
{
    return sourcePanID_var;
}

void FrameBeacon::setSourcePanID(int sourcePanID)
{
    this->sourcePanID_var = sourcePanID;
}

int FrameBeacon::getDestinationPanID() const
{
    return destinationPanID_var;
}

void FrameBeacon::setDestinationPanID(int destinationPanID)
{
    this->destinationPanID_var = destinationPanID;
}

int FrameBeacon::getSourceMacAddress() const
{
    return sourceMacAddress_var;
}

void FrameBeacon::setSourceMacAddress(int sourceMacAddress)
{
    this->sourceMacAddress_var = sourceMacAddress;
}

int FrameBeacon::getDestinationMacAddress() const
{
    return destinationMacAddress_var;
}

void FrameBeacon::setDestinationMacAddress(int destinationMacAddress)
{
    this->destinationMacAddress_var = destinationMacAddress;
}

int FrameBeacon::getBeaconOrder() const
{
    return beaconOrder_var;
}

void FrameBeacon::setBeaconOrder(int beaconOrder)
{
    this->beaconOrder_var = beaconOrder;
}

int FrameBeacon::getSuperFrameOrder() const
{
    return superFrameOrder_var;
}

void FrameBeacon::setSuperFrameOrder(int superFrameOrder)
{
    this->superFrameOrder_var = superFrameOrder;
}

int FrameBeacon::getFinalCAPslot() const
{
    return finalCAPslot_var;
}

void FrameBeacon::setFinalCAPslot(int finalCAPslot)
{
    this->finalCAPslot_var = finalCAPslot;
}

int FrameBeacon::getBatteryLifeExtension() const
{
    return batteryLifeExtension_var;
}

void FrameBeacon::setBatteryLifeExtension(int batteryLifeExtension)
{
    this->batteryLifeExtension_var = batteryLifeExtension;
}

int FrameBeacon::getReserved() const
{
    return reserved_var;
}

void FrameBeacon::setReserved(int reserved)
{
    this->reserved_var = reserved;
}

int FrameBeacon::getPANcoordinator() const
{
    return PANcoordinator_var;
}

void FrameBeacon::setPANcoordinator(int PANcoordinator)
{
    this->PANcoordinator_var = PANcoordinator;
}

int FrameBeacon::getAssociationPermit() const
{
    return associationPermit_var;
}

void FrameBeacon::setAssociationPermit(int associationPermit)
{
    this->associationPermit_var = associationPermit;
}

class FrameBeaconDescriptor : public cClassDescriptor
{
  public:
    FrameBeaconDescriptor();
    virtual ~FrameBeaconDescriptor();

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

Register_ClassDescriptor(FrameBeaconDescriptor);

FrameBeaconDescriptor::FrameBeaconDescriptor() : cClassDescriptor("wsn_energy::FrameBeacon", "wsn_energy::Frame")
{
}

FrameBeaconDescriptor::~FrameBeaconDescriptor()
{
}

bool FrameBeaconDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FrameBeacon *>(obj)!=NULL;
}

const char *FrameBeaconDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FrameBeaconDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount(object) : 12;
}

unsigned int FrameBeaconDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *FrameBeaconDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "beaconSequenceNumber",
        "sourcePanID",
        "destinationPanID",
        "sourceMacAddress",
        "destinationMacAddress",
        "beaconOrder",
        "superFrameOrder",
        "finalCAPslot",
        "batteryLifeExtension",
        "reserved",
        "PANcoordinator",
        "associationPermit",
    };
    return (field>=0 && field<12) ? fieldNames[field] : NULL;
}

int FrameBeaconDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconSequenceNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePanID")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPanID")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceMacAddress")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationMacAddress")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconOrder")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "superFrameOrder")==0) return base+6;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalCAPslot")==0) return base+7;
    if (fieldName[0]=='b' && strcmp(fieldName, "batteryLifeExtension")==0) return base+8;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+9;
    if (fieldName[0]=='P' && strcmp(fieldName, "PANcoordinator")==0) return base+10;
    if (fieldName[0]=='a' && strcmp(fieldName, "associationPermit")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FrameBeaconDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : NULL;
}

const char *FrameBeaconDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FrameBeaconDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FrameBeacon *pp = (FrameBeacon *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FrameBeaconDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FrameBeacon *pp = (FrameBeacon *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBeaconSequenceNumber());
        case 1: return long2string(pp->getSourcePanID());
        case 2: return long2string(pp->getDestinationPanID());
        case 3: return long2string(pp->getSourceMacAddress());
        case 4: return long2string(pp->getDestinationMacAddress());
        case 5: return long2string(pp->getBeaconOrder());
        case 6: return long2string(pp->getSuperFrameOrder());
        case 7: return long2string(pp->getFinalCAPslot());
        case 8: return long2string(pp->getBatteryLifeExtension());
        case 9: return long2string(pp->getReserved());
        case 10: return long2string(pp->getPANcoordinator());
        case 11: return long2string(pp->getAssociationPermit());
        default: return "";
    }
}

bool FrameBeaconDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FrameBeacon *pp = (FrameBeacon *)object; (void)pp;
    switch (field) {
        case 0: pp->setBeaconSequenceNumber(string2long(value)); return true;
        case 1: pp->setSourcePanID(string2long(value)); return true;
        case 2: pp->setDestinationPanID(string2long(value)); return true;
        case 3: pp->setSourceMacAddress(string2long(value)); return true;
        case 4: pp->setDestinationMacAddress(string2long(value)); return true;
        case 5: pp->setBeaconOrder(string2long(value)); return true;
        case 6: pp->setSuperFrameOrder(string2long(value)); return true;
        case 7: pp->setFinalCAPslot(string2long(value)); return true;
        case 8: pp->setBatteryLifeExtension(string2long(value)); return true;
        case 9: pp->setReserved(string2long(value)); return true;
        case 10: pp->setPANcoordinator(string2long(value)); return true;
        case 11: pp->setAssociationPermit(string2long(value)); return true;
        default: return false;
    }
}

const char *FrameBeaconDescriptor::getFieldStructName(void *object, int field) const
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

void *FrameBeaconDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FrameBeacon *pp = (FrameBeacon *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(FrameCommand);

FrameCommand::FrameCommand(const char *name, int kind) : ::wsn_energy::Frame(name,kind)
{
    this->setHeaderLength(25);

    this->dataSequenceNumber_var = 0;
    this->sourcePanID_var = 0;
    this->destinationPanID_var = 0;
    this->sourceMacAddress_var = 0;
    this->destinationMacAddress_var = 0;
    this->commandType_var = 0;
}

FrameCommand::FrameCommand(const FrameCommand& other) : ::wsn_energy::Frame(other)
{
    copy(other);
}

FrameCommand::~FrameCommand()
{
}

FrameCommand& FrameCommand::operator=(const FrameCommand& other)
{
    if (this==&other) return *this;
    ::wsn_energy::Frame::operator=(other);
    copy(other);
    return *this;
}

void FrameCommand::copy(const FrameCommand& other)
{
    this->dataSequenceNumber_var = other.dataSequenceNumber_var;
    this->sourcePanID_var = other.sourcePanID_var;
    this->destinationPanID_var = other.destinationPanID_var;
    this->sourceMacAddress_var = other.sourceMacAddress_var;
    this->destinationMacAddress_var = other.destinationMacAddress_var;
    this->commandType_var = other.commandType_var;
}

void FrameCommand::parsimPack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimPack(b);
    doPacking(b,this->dataSequenceNumber_var);
    doPacking(b,this->sourcePanID_var);
    doPacking(b,this->destinationPanID_var);
    doPacking(b,this->sourceMacAddress_var);
    doPacking(b,this->destinationMacAddress_var);
    doPacking(b,this->commandType_var);
}

void FrameCommand::parsimUnpack(cCommBuffer *b)
{
    ::wsn_energy::Frame::parsimUnpack(b);
    doUnpacking(b,this->dataSequenceNumber_var);
    doUnpacking(b,this->sourcePanID_var);
    doUnpacking(b,this->destinationPanID_var);
    doUnpacking(b,this->sourceMacAddress_var);
    doUnpacking(b,this->destinationMacAddress_var);
    doUnpacking(b,this->commandType_var);
}

int FrameCommand::getDataSequenceNumber() const
{
    return dataSequenceNumber_var;
}

void FrameCommand::setDataSequenceNumber(int dataSequenceNumber)
{
    this->dataSequenceNumber_var = dataSequenceNumber;
}

int FrameCommand::getSourcePanID() const
{
    return sourcePanID_var;
}

void FrameCommand::setSourcePanID(int sourcePanID)
{
    this->sourcePanID_var = sourcePanID;
}

int FrameCommand::getDestinationPanID() const
{
    return destinationPanID_var;
}

void FrameCommand::setDestinationPanID(int destinationPanID)
{
    this->destinationPanID_var = destinationPanID;
}

int FrameCommand::getSourceMacAddress() const
{
    return sourceMacAddress_var;
}

void FrameCommand::setSourceMacAddress(int sourceMacAddress)
{
    this->sourceMacAddress_var = sourceMacAddress;
}

int FrameCommand::getDestinationMacAddress() const
{
    return destinationMacAddress_var;
}

void FrameCommand::setDestinationMacAddress(int destinationMacAddress)
{
    this->destinationMacAddress_var = destinationMacAddress;
}

int FrameCommand::getCommandType() const
{
    return commandType_var;
}

void FrameCommand::setCommandType(int commandType)
{
    this->commandType_var = commandType;
}

class FrameCommandDescriptor : public cClassDescriptor
{
  public:
    FrameCommandDescriptor();
    virtual ~FrameCommandDescriptor();

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

Register_ClassDescriptor(FrameCommandDescriptor);

FrameCommandDescriptor::FrameCommandDescriptor() : cClassDescriptor("wsn_energy::FrameCommand", "wsn_energy::Frame")
{
}

FrameCommandDescriptor::~FrameCommandDescriptor()
{
}

bool FrameCommandDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FrameCommand *>(obj)!=NULL;
}

const char *FrameCommandDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FrameCommandDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int FrameCommandDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *FrameCommandDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "dataSequenceNumber",
        "sourcePanID",
        "destinationPanID",
        "sourceMacAddress",
        "destinationMacAddress",
        "commandType",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int FrameCommandDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataSequenceNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourcePanID")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPanID")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceMacAddress")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationMacAddress")==0) return base+4;
    if (fieldName[0]=='c' && strcmp(fieldName, "commandType")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FrameCommandDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *FrameCommandDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FrameCommandDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FrameCommand *pp = (FrameCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FrameCommandDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FrameCommand *pp = (FrameCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getDataSequenceNumber());
        case 1: return long2string(pp->getSourcePanID());
        case 2: return long2string(pp->getDestinationPanID());
        case 3: return long2string(pp->getSourceMacAddress());
        case 4: return long2string(pp->getDestinationMacAddress());
        case 5: return long2string(pp->getCommandType());
        default: return "";
    }
}

bool FrameCommandDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FrameCommand *pp = (FrameCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setDataSequenceNumber(string2long(value)); return true;
        case 1: pp->setSourcePanID(string2long(value)); return true;
        case 2: pp->setDestinationPanID(string2long(value)); return true;
        case 3: pp->setSourceMacAddress(string2long(value)); return true;
        case 4: pp->setDestinationMacAddress(string2long(value)); return true;
        case 5: pp->setCommandType(string2long(value)); return true;
        default: return false;
    }
}

const char *FrameCommandDescriptor::getFieldStructName(void *object, int field) const
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

void *FrameCommandDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FrameCommand *pp = (FrameCommand *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

} // namespace wsn_energy

