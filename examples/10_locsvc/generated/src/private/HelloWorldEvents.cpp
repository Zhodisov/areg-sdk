//////////////////////////////////////////////////////////////////////////
// Begin generate generated/src/private/HelloWorldEvents.cpp file
//////////////////////////////////////////////////////////////////////////

/************************************************************************
 * (c) copyright    2023
 *
 * Generated at     15.11.2023  14:51:36 GMT+01:00
 *                  Create by AREG SDK code generator tool from source HelloWorld.
 *
 * \file            generated/src/private/HelloWorldEvents.hpp
 * \ingroup         HelloWorld Service Interface
 * \brief           This is an automatic generated code of HelloWorld
 *                  Service Interface event classes implementation.
 ************************************************************************/

/************************************************************************
 * Include files
 ************************************************************************/
#include "generated/src/private/HelloWorldEvents.hpp"

//////////////////////////////////////////////////////////////////////////
// HelloWorldRequestEvent class implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// HelloWorldRequestEvent class, Runtime implementation
//////////////////////////////////////////////////////////////////////////
/**
 * \brief   HelloWorldRequestEvent Event runtime implementation
 **/
IMPLEMENT_RUNTIME_EVENT( HelloWorldRequestEvent, LocalRequestEvent )

//////////////////////////////////////////////////////////////////////////
// HelloWorldRequestEvent class, Constructors / Destructor
//////////////////////////////////////////////////////////////////////////

HelloWorldRequestEvent::HelloWorldRequestEvent( const ProxyAddress & fromSource, const StubAddress & toTarget, unsigned int reqId )
    : LocalRequestEvent( fromSource, toTarget, reqId )
{
}

HelloWorldRequestEvent::HelloWorldRequestEvent( const EventDataStream & args, const ProxyAddress & fromSource, const StubAddress & toTarget, unsigned int reqId )
    : LocalRequestEvent( args, fromSource, toTarget, reqId, NEHelloWorld::getString( static_cast<NEHelloWorld::eMessageIDs>(reqId) ) )
{
}


//////////////////////////////////////////////////////////////////////////
// HelloWorldNotifyRequestEvent class implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// HelloWorldNotifyRequestEvent class, Runtime implementation
//////////////////////////////////////////////////////////////////////////

IMPLEMENT_RUNTIME_EVENT( HelloWorldNotifyRequestEvent, LocalNotifyRequestEvent )

//////////////////////////////////////////////////////////////////////////
// HelloWorldNotifyRequestEvent class, Constructors / Destructor
//////////////////////////////////////////////////////////////////////////

HelloWorldNotifyRequestEvent::HelloWorldNotifyRequestEvent( const ProxyAddress & fromProxy, const StubAddress & toStub, unsigned int msgId, NEService::eRequestType reqType )
    : LocalNotifyRequestEvent( fromProxy, toStub, msgId, reqType )
{
}


//////////////////////////////////////////////////////////////////////////
// HelloWorldResponseEvent class implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// HelloWorldResponseEvent class, Runtime implementation
//////////////////////////////////////////////////////////////////////////

IMPLEMENT_RUNTIME_EVENT( HelloWorldResponseEvent, LocalResponseEvent )

//////////////////////////////////////////////////////////////////////////
// HelloWorldResponseEvent class, Constructors / Destructor
//////////////////////////////////////////////////////////////////////////

HelloWorldResponseEvent::HelloWorldResponseEvent( const ProxyAddress & proxyTarget, NEService::eResultType result, unsigned int responseId, const SequenceNumber &  seqNr /* = NEService::SEQUENCE_NUMBER_NOTIFY */ )
    : LocalResponseEvent( proxyTarget, result, responseId, seqNr )
{
}

HelloWorldResponseEvent::HelloWorldResponseEvent( const EventDataStream & args, const ProxyAddress & proxyTarget, NEService::eResultType result, unsigned int responseId, const SequenceNumber &  seqNr /* = NEService::SEQUENCE_NUMBER_NOTIFY */ )
    : LocalResponseEvent( args, proxyTarget, result, responseId, seqNr, NEHelloWorld::getString(static_cast<NEHelloWorld::eMessageIDs>(responseId)) )
{
}

HelloWorldResponseEvent::HelloWorldResponseEvent( const ProxyAddress & proxyTarget, const LocalResponseEvent & source )
    : LocalResponseEvent( proxyTarget, source )
{
}


//////////////////////////////////////////////////////////////////////////
// HelloWorldResponseEvent class, Methods
//////////////////////////////////////////////////////////////////////////

ServiceResponseEvent* HelloWorldResponseEvent::cloneForTarget( const ProxyAddress & target ) const
{
    return static_cast<ServiceResponseEvent *>( DEBUG_NEW HelloWorldResponseEvent(target, static_cast<const LocalResponseEvent &>(*this)) );
}

//////////////////////////////////////////////////////////////////////////
// HelloWorldNotificationEvent class implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// HelloWorldNotificationEvent class, Runtime implementation
//////////////////////////////////////////////////////////////////////////

IMPLEMENT_RUNTIME_EVENT( HelloWorldNotificationEvent, NotificationEvent )

//////////////////////////////////////////////////////////////////////////
// HelloWorldNotificationEvent class, Constructors / Destructor
//////////////////////////////////////////////////////////////////////////

HelloWorldNotificationEvent::HelloWorldNotificationEvent( const NotificationEventData & data )
    : NotificationEvent   ( data )
{
}

//////////////////////////////////////////////////////////////////////////
// End generate generated/src/private/HelloWorldEvents.cpp file
//////////////////////////////////////////////////////////////////////////
