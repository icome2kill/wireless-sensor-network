//
// Generated file, do not edit! Created by nedtool 4.6 from package/data/data.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "data_m.h"

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

Register_Class(Data);

Data::Data(const char *name, int kind) : ::cPacket(name,kind)
{
    this->time_var = 0;
    this->destinationPort_var = 0;
    this->destinationIPAddress_var = 0;
    this->value_var = 0;
}

Data::Data(const Data& other) : ::cPacket(other)
{
    copy(other);
}

Data::~Data()
{
}

Data& Data::operator=(const Data& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Data::copy(const Data& other)
{
    this->time_var = other.time_var;
    this->destinationPort_var = other.destinationPort_var;
    this->destinationIPAddress_var = other.destinationIPAddress_var;
    this->destinationIPAddressV6_var = other.destinationIPAddressV6_var;
    this->value_var = other.value_var;
}

void Data::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->time_var);
    doPacking(b,this->destinationPort_var);
    doPacking(b,this->destinationIPAddress_var);
    doPacking(b,this->destinationIPAddressV6_var);
    doPacking(b,this->value_var);
}

void Data::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->time_var);
    doUnpacking(b,this->destinationPort_var);
    doUnpacking(b,this->destinationIPAddress_var);
    doUnpacking(b,this->destinationIPAddressV6_var);
    doUnpacking(b,this->value_var);
}

double Data::getTime() const
{
    return time_var;
}

void Data::setTime(double time)
{
    this->time_var = time;
}

int Data::getDestinationPort() const
{
    return destinationPort_var;
}

void Data::setDestinationPort(int destinationPort)
{
    this->destinationPort_var = destinationPort;
}

int Data::getDestinationIPAddress() const
{
    return destinationIPAddress_var;
}

void Data::setDestinationIPAddress(int destinationIPAddress)
{
    this->destinationIPAddress_var = destinationIPAddress;
}

IpAddress& Data::getDestinationIPAddressV6()
{
    return destinationIPAddressV6_var;
}

void Data::setDestinationIPAddressV6(const IpAddress& destinationIPAddressV6)
{
    this->destinationIPAddressV6_var = destinationIPAddressV6;
}

const char * Data::getValue() const
{
    return value_var.c_str();
}

void Data::setValue(const char * value)
{
    this->value_var = value;
}

class DataDescriptor : public cClassDescriptor
{
  public:
    DataDescriptor();
    virtual ~DataDescriptor();

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

Register_ClassDescriptor(DataDescriptor);

DataDescriptor::DataDescriptor() : cClassDescriptor("wsn_energy::Data", "cPacket")
{
}

DataDescriptor::~DataDescriptor()
{
}

bool DataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Data *>(obj)!=NULL;
}

const char *DataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int DataDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *DataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "time",
        "destinationPort",
        "destinationIPAddress",
        "destinationIPAddressV6",
        "value",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int DataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "time")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationPort")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationIPAddress")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationIPAddressV6")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DataDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "IpAddress",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *DataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int DataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Data *pp = (Data *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Data *pp = (Data *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getTime());
        case 1: return long2string(pp->getDestinationPort());
        case 2: return long2string(pp->getDestinationIPAddress());
        case 3: {std::stringstream out; out << pp->getDestinationIPAddressV6(); return out.str();}
        case 4: return oppstring2string(pp->getValue());
        default: return "";
    }
}

bool DataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Data *pp = (Data *)object; (void)pp;
    switch (field) {
        case 0: pp->setTime(string2double(value)); return true;
        case 1: pp->setDestinationPort(string2long(value)); return true;
        case 2: pp->setDestinationIPAddress(string2long(value)); return true;
        case 4: pp->setValue((value)); return true;
        default: return false;
    }
}

const char *DataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 3: return opp_typename(typeid(IpAddress));
        default: return NULL;
    };
}

void *DataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Data *pp = (Data *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getDestinationIPAddressV6()); break;
        default: return NULL;
    }
}

} // namespace wsn_energy

