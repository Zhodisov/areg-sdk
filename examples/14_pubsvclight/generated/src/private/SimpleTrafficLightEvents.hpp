//////////////////////////////////////////////////////////////////////////
// Begin generate generated/src/private/SimpleTrafficLightEvents.hpp file
//////////////////////////////////////////////////////////////////////////
#ifndef  GENERATED_SRC_PRIVATE_SIMPLETRAFFICLIGHTEVENTS_HPP
#define  GENERATED_SRC_PRIVATE_SIMPLETRAFFICLIGHTEVENTS_HPP
/************************************************************************
 * (c) copyright    2021
 *                  Create by AREG SDK code generator tool from source SimpleTrafficLight.
 * Generated at     11.08.2021  13:18:20 GMT+02:00 
 ************************************************************************/

/************************************************************************
 * \file            generated/src/private/SimpleTrafficLightEvents.hpp
 * \ingroup         SimpleTrafficLight Service Interface
 * \brief           This is an automatic generated code of SimpleTrafficLight Service Interface Event classes declaration.
 ************************************************************************/

/************************************************************************
 * Include files
 ************************************************************************/
#include "areg/base/GEGlobal.h"
#include "generated/src/NESimpleTrafficLight.hpp"
#include "areg/component/RequestEvents.hpp"
#include "areg/component/ResponseEvents.hpp"
#include "areg/component/NotificationEvent.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/

/************************************************************************
 * Declared classes
 ************************************************************************/
class SimpleTrafficLightRequestEvent;
class SimpleTrafficLightNotifyRequestEvent;
class SimpleTrafficLightResponseEvent;
class SimpleTrafficLightNotificationEvent;

/**
 * \brief   In this file following classes are declared:
 *              1.  SimpleTrafficLightRequestEvent
 *              2.  SimpleTrafficLightNotifyRequestEvent
 *              3.  SimpleTrafficLightResponseEvent
 *              4.  SimpleTrafficLightNotificationEvent
 *          These are SimpleTrafficLight Service Interface event objects.
 *          They are used to send Communication Events to Proxy,
 *          Stub and Client objects.
 *          The SimpleTrafficLightRequestEvent Event is used to send request message to Stub object.
 *          The SimpleTrafficLightNotifyRequestEvent Event is used to assign for Notifications of Attributes or Responses / Broadcasts.
 *          The SimpleTrafficLightResponseEvent Event is used to send response or update message to Proxy object.
 *          The SimpleTrafficLightNotificationEvent Event is used to trigger functions on Client object.
 *          For more details see descriptions bellow.
 **/

//////////////////////////////////////////////////////////////////////////
// SimpleTrafficLightRequestEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   SimpleTrafficLightRequestEvent is used to send request events from Proxy objects to Stub
 *          Every request is generating Request Event and forwarded to Stub for processing.
 **/
class SimpleTrafficLightRequestEvent   : public RemoteRequestEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( SimpleTrafficLightRequestEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Initialization constructor. Gets message source proxy address, message target address and message request ID.
     * \param   fromSource  The Proxy message source address.
     * \param   toTarget    The Stub message target address to deliver event.
     * \param   reqId       The request message ID.
     **/
    SimpleTrafficLightRequestEvent( const ProxyAddress & fromSource, const StubAddress & toTarget, unsigned int reqId );
    /**
     * \brief   Initialization constructor. Gets streamable data of arguments, message source proxy address, message target address  and message request ID.
     * \param   args        The streamable object containing message arguments.
     * \param   fromSource  The Proxy message source address.
     * \param   toTarget    The Stub message target address to deliver event.
     * \param   reqId       The request message ID.
     **/
    SimpleTrafficLightRequestEvent( const EventDataStream & args, const ProxyAddress & fromSource, const StubAddress & toTarget, unsigned int reqId );
    /**
     * \brief   Initialization constructor. Initializes request event from streaming object, where data is serialized. Used in remote messaging.
     * \param   stream      The streaming object, where event data is serialized.
     **/
    SimpleTrafficLightRequestEvent( const IEInStream & stream );
    /**
     * \brief   Destructor.
     **/
    virtual ~SimpleTrafficLightRequestEvent( void );

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    SimpleTrafficLightRequestEvent( void );
    SimpleTrafficLightRequestEvent( const SimpleTrafficLightRequestEvent & /* src */ );
    const SimpleTrafficLightRequestEvent & operator = ( const SimpleTrafficLightRequestEvent & /* src */ );
};

//////////////////////////////////////////////////////////////////////////
// SimpleTrafficLightNotifyRequestEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   SimpleTrafficLightNotifyRequestEvent is used to send notification request events.
 *          Used when Proxy is requesting to start / stop notifications of attribute update, Broadcast, or response.
 **/
class SimpleTrafficLightNotifyRequestEvent : public RemoteNotifyRequestEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( SimpleTrafficLightNotifyRequestEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Initialization constructor. Used to send start / stop notification request from Prosy to Stub.
     * \param   fromProxy   The source Proxy address, requesting start / stop notifications.
     * \param   toStub      The target Stub address to start / stop sending notifications.
     * \param   msgId       The ID of message. Normally either Attribute ID, Broadcast ID or Response ID. The Request IDs cannot be notified.
     * \param   reqType     The type of request.
     **/
    SimpleTrafficLightNotifyRequestEvent( const ProxyAddress & fromProxy, const StubAddress & toStub, unsigned int msgId, NEService::eRequestType reqType );
    /**
     * \brief   Initialization constructor. Initializes notification request event from streaming object, where data is serialized. Used in remote messaging.
     * \param   stream      The streaming object, where event data is serialized.
     **/
    SimpleTrafficLightNotifyRequestEvent( const IEInStream & stream );
    /**
     * \brief   Destructor.
     **/
    virtual ~SimpleTrafficLightNotifyRequestEvent( void );

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    SimpleTrafficLightNotifyRequestEvent( void );
    SimpleTrafficLightNotifyRequestEvent( const SimpleTrafficLightNotifyRequestEvent & /* src */ );
    const SimpleTrafficLightNotifyRequestEvent & operator = ( const SimpleTrafficLightNotifyRequestEvent & /* src */ );
};

//////////////////////////////////////////////////////////////////////////
// SimpleTrafficLightResponseEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   SimpleTrafficLightResponseEvent is used to send response events from Stub to Proxy.
 **/
class SimpleTrafficLightResponseEvent  : public RemoteResponseEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( SimpleTrafficLightResponseEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Initialization constructor. Used to send response messages from Stub to Proxy. The argument list is empty.
     * \param   proxyTarget The target Proxy address to deliver message
     * \param   result      The result code of response message
     * \param   responseId  The response message ID. Normally either attribute, broadcast or response ID.
     * \param   seqNr       The sequence number of response call. By default it is NEService::SEQUENCE_NUMBER_NOTIFY.
     **/
    SimpleTrafficLightResponseEvent( const ProxyAddress & proxyTarget, NEService::eResultType result, unsigned int responseId, unsigned int seqNr = NEService::SEQUENCE_NUMBER_NOTIFY );
    /**
     * \brief   Initialization constructor. Used to send response messages from Stub to Proxy with arguments.
     * \param   args        The streamable object containing message arguments.
     * \param   proxyTarget The target Proxy address to deliver message
     * \param   result      The result code of response message
     * \param   responseId  The response message ID. Normally either attribute, broadcast or response ID.
     * \param   seqNr       The sequence number of response call. By default it is NEService::SEQUENCE_NUMBER_NOTIFY.
     **/
    SimpleTrafficLightResponseEvent( const EventDataStream & args, const ProxyAddress & proxyTarget, NEService::eResultType result, unsigned int responseId, unsigned int seqNr = NEService::SEQUENCE_NUMBER_NOTIFY );
    /**
     * \brief   Initialization constructor. Used to clone same message for different Proxy objects.
     * \param   proxyTarget The target Proxy address to deliver message
     * \param   source      The source event object containing message ID, result code and parameters.
     **/
    SimpleTrafficLightResponseEvent( const ProxyAddress & proxyTarget, const RemoteResponseEvent & source );
    /**
     * \brief   Initialization constructor. Initializes response event from streaming object, where data is serialized. Used in remote messaging.
     * \param   stream      The streaming object, where event data is serialized.
     **/
    SimpleTrafficLightResponseEvent( const IEInStream & stream );
    /**
     * \brief   Destructor
     **/
    virtual ~SimpleTrafficLightResponseEvent( void );

//////////////////////////////////////////////////////////////////////////
// Overrides
//////////////////////////////////////////////////////////////////////////
public:
/************************************************************************/
// ServiceResponseEvent override
/************************************************************************/

    /**
     * \brief   Clones existing service event object.
     *          Copies all data and sets specified target proxy address.
     *          Overwrite this method in every service response specific
     *          class to be able to clone events.
     * \param   target  The target proxy address.
     * \return  Cloned service response event object, which contains specified
     *          target proxy address.
     **/
    virtual ServiceResponseEvent * cloneForTarget( const ProxyAddress & target ) const;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    SimpleTrafficLightResponseEvent( void );
    SimpleTrafficLightResponseEvent( const SimpleTrafficLightResponseEvent & /* src */ );
    const SimpleTrafficLightResponseEvent & operator = ( const SimpleTrafficLightResponseEvent & /* src */ );
};

//////////////////////////////////////////////////////////////////////////
// SimpleTrafficLightNotificationEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   SimpleTrafficLightNotificationEvent is used by Proxy to send notifications to client objects
 *          and trigger appropriate functions
 **/
class SimpleTrafficLightNotificationEvent  : public NotificationEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( SimpleTrafficLightNotificationEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Initialization constructor. Copies notification event data
     * \param   data    The notification event data to copy
     **/
    SimpleTrafficLightNotificationEvent( const NotificationEventData & data );

protected:
    /**
     * \brief   Destructor. Protected
     **/
    virtual ~SimpleTrafficLightNotificationEvent( void );
    
//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    SimpleTrafficLightNotificationEvent( void );
    SimpleTrafficLightNotificationEvent( const SimpleTrafficLightNotificationEvent & /* src */ );
    const SimpleTrafficLightNotificationEvent & operator = ( const SimpleTrafficLightNotificationEvent & /* src */ );
};

#endif   // GENERATED_SRC_PRIVATE_SIMPLETRAFFICLIGHTEVENTS_HPP

//////////////////////////////////////////////////////////////////////////
// End generate generated/src/private/SimpleTrafficLightEvents.hpp file
//////////////////////////////////////////////////////////////////////////
 