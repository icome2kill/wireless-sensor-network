//
// Generated file, do not edit! Created by nedtool 4.6 from package/strobe/strobe.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "strobe_m.h"

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
    cEnum *e = cEnum::find("wsn_energy::KIND");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::KIND"));
    e->insert(DATA, "DATA");
    e->insert(COMMAND, "COMMAND");
    e->insert(RESULT, "RESULT");
);

Register_Class(Command);

Command::Command(const char *name, int kind) : ::cPacket(name,kind)
{
    this->note_var = 0;
}

Command::Command(const Command& other) : ::cPacket(other)
{
    copy(other);
}

Command::~Command()
{
}

Command& Command::operator=(const Command& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Command::copy(const Command& other)
{
    this->note_var = other.note_var;
}

void Command::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->note_var);
}

void Command::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->note_var);
}

int Command::getNote() const
{
    return note_var;
}

void Command::setNote(int note)
{
    this->note_var = note;
}

class CommandDescriptor : public cClassDescriptor
{
  public:
    CommandDescriptor();
    virtual ~CommandDescriptor();

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

Register_ClassDescriptor(CommandDescriptor);

CommandDescriptor::CommandDescriptor() : cClassDescriptor("wsn_energy::Command", "cPacket")
{
}

CommandDescriptor::~CommandDescriptor()
{
}

bool CommandDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Command *>(obj)!=NULL;
}

const char *CommandDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CommandDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int CommandDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *CommandDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "note",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int CommandDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "note")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CommandDescriptor::getFieldTypeString(void *object, int field) const
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

const char *CommandDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int CommandDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Command *pp = (Command *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CommandDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Command *pp = (Command *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNote());
        default: return "";
    }
}

bool CommandDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Command *pp = (Command *)object; (void)pp;
    switch (field) {
        case 0: pp->setNote(string2long(value)); return true;
        default: return false;
    }
}

const char *CommandDescriptor::getFieldStructName(void *object, int field) const
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

void *CommandDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Command *pp = (Command *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(Result);

Result::Result(const char *name, int kind) : ::cPacket(name,kind)
{
    this->note_var = 0;
}

Result::Result(const Result& other) : ::cPacket(other)
{
    copy(other);
}

Result::~Result()
{
}

Result& Result::operator=(const Result& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Result::copy(const Result& other)
{
    this->note_var = other.note_var;
}

void Result::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->note_var);
}

void Result::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->note_var);
}

int Result::getNote() const
{
    return note_var;
}

void Result::setNote(int note)
{
    this->note_var = note;
}

class ResultDescriptor : public cClassDescriptor
{
  public:
    ResultDescriptor();
    virtual ~ResultDescriptor();

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

Register_ClassDescriptor(ResultDescriptor);

ResultDescriptor::ResultDescriptor() : cClassDescriptor("wsn_energy::Result", "cPacket")
{
}

ResultDescriptor::~ResultDescriptor()
{
}

bool ResultDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Result *>(obj)!=NULL;
}

const char *ResultDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ResultDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int ResultDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *ResultDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "note",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int ResultDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "note")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ResultDescriptor::getFieldTypeString(void *object, int field) const
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

const char *ResultDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ResultDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Result *pp = (Result *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ResultDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Result *pp = (Result *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNote());
        default: return "";
    }
}

bool ResultDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Result *pp = (Result *)object; (void)pp;
    switch (field) {
        case 0: pp->setNote(string2long(value)); return true;
        default: return false;
    }
}

const char *ResultDescriptor::getFieldStructName(void *object, int field) const
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

void *ResultDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Result *pp = (Result *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::MANUAL_EVENT");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::MANUAL_EVENT"));
    e->insert(NODE_STARTUP, "NODE_STARTUP");
    e->insert(OUT_OF_ENERGY, "OUT_OF_ENERGY");
    e->insert(NODE_DESTRUCT, "NODE_DESTRUCT");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::COMMAND_APP");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::COMMAND_APP"));
    e->insert(APP_ENVIRON_FLAG, "APP_ENVIRON_FLAG");
    e->insert(APP_SENSING_FLAG, "APP_SENSING_FLAG");
    e->insert(APP_READY_TO_SEND, "APP_READY_TO_SEND");
    e->insert(RPL_SET_UP_DELAY, "RPL_SET_UP_DELAY");
    e->insert(APP_SEND_LIGHT_DATA, "APP_SEND_LIGHT_DATA");
    e->insert(APP_SEND_HEAT_DATA_HIGH, "APP_SEND_HEAT_DATA_HIGH");
    e->insert(APP_SEND_HEAT_DATA_LOW, "APP_SEND_HEAT_DATA_LOW");
    e->insert(APP_SEND_MOISTURE_DATA, "APP_SEND_MOISTURE_DATA");
    e->insert(APP_SEND_SOIL_DATA_HIGH, "APP_SEND_SOIL_DATA_HIGH");
    e->insert(APP_SEND_SOIL_DATA_LOW, "APP_SEND_SOIL_DATA_LOW");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::COMMAND_NET");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::COMMAND_NET"));
    e->insert(NET_TIMER_DIO, "NET_TIMER_DIO");
    e->insert(NET_TIMER_DIS, "NET_TIMER_DIS");
    e->insert(NET_CHECK_BUFFER, "NET_CHECK_BUFFER");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::COMMAND_MAC");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::COMMAND_MAC"));
    e->insert(MAC_CCA_REQUEST, "MAC_CCA_REQUEST");
    e->insert(MAC_ASK_SEND_FRAME, "MAC_ASK_SEND_FRAME");
    e->insert(MAC_END_SEND_FRAME, "MAC_END_SEND_FRAME");
    e->insert(MAC_IGNITE_RDC, "MAC_IGNITE_RDC");
    e->insert(MAC_EXPIRE_IFS, "MAC_EXPIRE_IFS");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::RESULT_FROM_MAC");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::RESULT_FROM_MAC"));
    e->insert(MAC_FINISH_PHASE, "MAC_FINISH_PHASE");
    e->insert(MAC_SEND_DEAD_NEIGHBOR, "MAC_SEND_DEAD_NEIGHBOR");
    e->insert(MAC_RELIABLE, "MAC_RELIABLE");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::COMMAND_RDC");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::COMMAND_RDC"));
    e->insert(RDC_TRANSMIT, "RDC_TRANSMIT");
    e->insert(RDC_LISTEN, "RDC_LISTEN");
    e->insert(RDC_IDLE, "RDC_IDLE");
    e->insert(RDC_CCA_REQUEST, "RDC_CCA_REQUEST");
    e->insert(RDC_PERIODICAL_MAJOR_CHECK, "RDC_PERIODICAL_MAJOR_CHECK");
    e->insert(RDC_PERIODICAL_MINOR_CHECK, "RDC_PERIODICAL_MINOR_CHECK");
    e->insert(RDC_CCA_RESULT, "RDC_CCA_RESULT");
    e->insert(RDC_CCA_TIME_OUT, "RDC_CCA_TIME_OUT");
    e->insert(RDC_PHASE_TIME_OUT, "RDC_PHASE_TIME_OUT");
    e->insert(RDC_BEGIN_TRANS_TURN, "RDC_BEGIN_TRANS_TURN");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::RESULT_RDC");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::RESULT_RDC"));
    e->insert(RDC_READY_TRANS_PHASE, "RDC_READY_TRANS_PHASE");
    e->insert(RDC_SEND_OK, "RDC_SEND_OK");
    e->insert(RDC_SEND_NO_ACK, "RDC_SEND_NO_ACK");
    e->insert(RDC_SEND_FATAL, "RDC_SEND_FATAL");
    e->insert(RDC_SEND_COL, "RDC_SEND_COL");
    e->insert(CHANNEL_CLEAR, "CHANNEL_CLEAR");
    e->insert(CHANNEL_BUSY, "CHANNEL_BUSY");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::COMMAND_PHY");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::COMMAND_PHY"));
    e->insert(PHY_SWITCH_TRANSMIT, "PHY_SWITCH_TRANSMIT");
    e->insert(PHY_BEGIN_TRANSMIT, "PHY_BEGIN_TRANSMIT");
    e->insert(PHY_END_TRANSMIT, "PHY_END_TRANSMIT");
    e->insert(PHY_SWITCH_LISTEN, "PHY_SWITCH_LISTEN");
    e->insert(PHY_LISTENING, "PHY_LISTENING");
    e->insert(PHY_SWITCH_IDLE, "PHY_SWITCH_IDLE");
    e->insert(PHY_IDLING, "PHY_IDLING");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("wsn_energy::RESULT_PHY");
    if (!e) enums.getInstance()->add(e = new cEnum("wsn_energy::RESULT_PHY"));
    e->insert(PHY_TX_OK, "PHY_TX_OK");
    e->insert(PHY_TX_ERR, "PHY_TX_ERR");
);

} // namespace wsn_energy

