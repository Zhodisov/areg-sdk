//////////////////////////////////////////////////////////////////////////
// Begin generate generated/src/private/PubSubEvents.hpp file
//////////////////////////////////////////////////////////////////////////

#ifndef  GENERATED_SRC_PRIVATE_PUBSUBEVENTS_HPP
#define  GENERATED_SRC_PRIVATE_PUBSUBEVENTS_HPP

/************************************************************************
 * (c) copyright    2023
 *
 * Generated at     15.11.2023  14:52:18 GMT+01:00
 *                  Create by AREG SDK code generator tool from source PubSub.
 *
 * \file            generated/src/private/PubSubEvents.hpp
 * \ingroup         PubSub Service Interface
 * \brief           This is an automatic generated code of PubSub
 *                  Service Interface event classes declaration.
 ************************************************************************/

/************************************************************************
 * Include files
 ************************************************************************/
#include "areg/base/GEGlobal.h"
#include "generated/src/NEPubSub.hpp"
#include "areg/component/RequestEvents.hpp"
#include "areg/component/ResponseEvents.hpp"
#include "areg/component/NotificationEvent.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/

/************************************************************************
 * Declared classes
 ************************************************************************/
class PubSubRequestEvent;
class PubSubNotifyRequestEvent;
class PubSubResponseEvent;
class PubSubNotificationEvent;

/**
 * \brief   In this file following classes are declared:
 *              1.  PubSubRequestEvent
 *              2.  PubSubNotifyRequestEvent
 *              3.  PubSubResponseEvent
 *              4.  PubSubNotificationEvent
 *          These are PubSub Service Interface event objects.
 *          They are used to send Communication Events to Proxy,
 *          Stub and Client objects.
 *          The PubSubRequestEvent Event is used to send request message to Stub object.
 *          The PubSubNotifyRequestEvent Event is used to assign for Notifications of Attributes or Responses / Broadcasts.
 *          The PubSubResponseEvent Event is used to send response or update message to Proxy object.
 *          The PubSubNotificationEvent Event is used to trigger functions on Client object.
 *          For more details see descriptions bellow.
 **/

//////////////////////////////////////////////////////////////////////////
// PubSubRequestEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   PubSubRequestEvent is used to send request events from Proxy objects to Stub
 *          Every request is generating Request Event and forwarded to Stub for processing.
 **/
class PubSubRequestEvent   : public RemoteRequestEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( PubSubRequestEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Gets message source proxy address, message target address and message request ID.
     *
     * \param   fromSource  The Proxy message source address.
     * \param   toTarget    The Stub message target address to deliver event.
     * \param   reqId       The request message ID.
     **/
    PubSubRequestEvent( const ProxyAddress & fromSource, const StubAddress & toTarget, unsigned int reqId );
    /**
     * \brief   Gets streamable data of arguments, message source proxy address, message target address  and message request ID.
     *
     * \param   args        The streamable object containing message arguments.
     * \param   fromSource  The Proxy message source address.
     * \param   toTarget    The Stub message target address to deliver event.
     * \param   reqId       The request message ID.
     **/
    PubSubRequestEvent( const EventDataStream & args, const ProxyAddress & fromSource, const StubAddress & toTarget, unsigned int reqId );
    /**
     * \brief   Initializes request event from streaming object, where data is serialized. Used in remote messaging.
     *
     * \param   stream      The streaming object, where event data is serialized.
     **/
    PubSubRequestEvent( const IEInStream & stream );
    /**
     * \brief   Destructor.
     **/
    virtual ~PubSubRequestEvent( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    PubSubRequestEvent( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( PubSubRequestEvent );
};

//////////////////////////////////////////////////////////////////////////
// PubSubNotifyRequestEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   PubSubNotifyRequestEvent is used to send notification request events.
 *          Used when Proxy is requesting to start / stop notifications of attribute update, Broadcast, or response.
 **/
class PubSubNotifyRequestEvent : public RemoteNotifyRequestEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( PubSubNotifyRequestEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Used to send start / stop notification request from Prosy to Stub.
     *
     * \param   fromProxy   The source Proxy address, requesting start / stop notifications.
     * \param   toStub      The target Stub address to start / stop sending notifications.
     * \param   msgId       The ID of message. Normally either Attribute ID, Broadcast ID or Response ID. The Request IDs cannot be notified.
     * \param   reqType     The type of request.
     **/
    PubSubNotifyRequestEvent( const ProxyAddress & fromProxy, const StubAddress & toStub, unsigned int msgId, NEService::eRequestType reqType );
    /**
     * \brief   Initializes notification request event from streaming object, where data is serialized. Used in remote messaging.
     *
     * \param   stream      The streaming object, where event data is serialized.
     **/
    PubSubNotifyRequestEvent( const IEInStream & stream );
    /**
     * \brief   Destructor.
     **/
    virtual ~PubSubNotifyRequestEvent( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    PubSubNotifyRequestEvent( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( PubSubNotifyRequestEvent );
};

//////////////////////////////////////////////////////////////////////////
// PubSubResponseEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   PubSubResponseEvent is used to send response events from Stub to Proxy.
 **/
class PubSubResponseEvent  : public RemoteResponseEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( PubSubResponseEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Used to send response messages from Stub to Proxy. The argument list is empty.
     *
     * \param   proxyTarget The target Proxy address to deliver message
     * \param   result      The result code of response message
     * \param   responseId  The response message ID. Normally either attribute, broadcast or response ID.
     * \param   seqNr       The sequence number of response call. By default it is NEService::SEQUENCE_NUMBER_NOTIFY.
     **/
    PubSubResponseEvent( const ProxyAddress & proxyTarget, NEService::eResultType result, unsigned int responseId, const SequenceNumber &  seqNr = NEService::SEQUENCE_NUMBER_NOTIFY );
    /**
     * \brief   Used to send response messages from Stub to Proxy with arguments.
     *
     * \param   args        The streamable object containing message arguments.
     * \param   proxyTarget The target Proxy address to deliver message
     * \param   result      The result code of response message
     * \param   responseId  The response message ID. Normally either attribute, broadcast or response ID.
     * \param   seqNr       The sequence number of response call. By default it is NEService::SEQUENCE_NUMBER_NOTIFY.
     **/
    PubSubResponseEvent( const EventDataStream & args, const ProxyAddress & proxyTarget, NEService::eResultType result, unsigned int responseId, const SequenceNumber &  seqNr = NEService::SEQUENCE_NUMBER_NOTIFY );
    /**
     * \brief   Initialization constructor. Used to clone same message for different Proxy objects.
     * \param   proxyTarget The target Proxy address to deliver message
     * \param   source      The source event object containing message ID, result code and parameters.
     **/
    PubSubResponseEvent( const ProxyAddress & proxyTarget, const RemoteResponseEvent & source );
    /**
     * \brief   Initializes response event from streaming object, where data is serialized. Used in remote messaging.
     *
     * \param   stream      The streaming object, where event data is serialized.
     **/
    PubSubResponseEvent( const IEInStream & stream );
    /**
     * \brief   Destructor.
     **/
    virtual ~PubSubResponseEvent( void ) = default;

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
    virtual ServiceResponseEvent * cloneForTarget( const ProxyAddress & target ) const override;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    PubSubResponseEvent( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( PubSubResponseEvent );
};

//////////////////////////////////////////////////////////////////////////
// PubSubNotificationEvent class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   PubSubNotificationEvent is used by Proxy to send notifications to client objects
 *          and trigger appropriate functions
 **/
class PubSubNotificationEvent  : public NotificationEvent
{
//////////////////////////////////////////////////////////////////////////
// Declare Event Runtime
//////////////////////////////////////////////////////////////////////////
    DECLARE_RUNTIME_EVENT( PubSubNotificationEvent )

//////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Copies notification event data
     * \param   data    The notification event data to copy
     **/
    explicit PubSubNotificationEvent( const NotificationEventData & data );

protected:
    /**
     * \brief   Protected destructor.
     **/
    virtual ~PubSubNotificationEvent( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    PubSubNotificationEvent( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( PubSubNotificationEvent );
};

#endif  // GENERATED_SRC_PRIVATE_PUBSUBEVENTS_HPP

//////////////////////////////////////////////////////////////////////////
// End generate generated/src/private/PubSubEvents.hpp file
//////////////////////////////////////////////////////////////////////////
