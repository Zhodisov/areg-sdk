//////////////////////////////////////////////////////////////////////////
// Begin generate generated/src/private/HelloUnblockProxy.hpp file
//////////////////////////////////////////////////////////////////////////
#ifndef  GENERATED_SRC_PRIVATE_HELLOUNBLOCKPROXY_HPP
#define  GENERATED_SRC_PRIVATE_HELLOUNBLOCKPROXY_HPP

/************************************************************************
 * (c) copyright    2023
 *
 * Generated at     15.11.2023  14:52:16 GMT+01:00
 *                  Create by AREG SDK code generator tool from source HelloUnblock.
 *
 * \file            generated/src/private/HelloUnblockProxy.hpp
 * \ingroup         HelloUnblock Service Interface
 * \brief           This is an automatic generated code of HelloUnblock
 *                  Service Interface Proxy class declaration.
 ************************************************************************/

/************************************************************************
 * Include files
 ************************************************************************/
#include "areg/base/GEGlobal.h"
#include "generated/src/NEHelloUnblock.hpp"
#include "areg/component/ProxyBase.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/
class HelloUnblockResponseEvent;

//////////////////////////////////////////////////////////////////////////
// HelloUnblockProxy class declaration Begin
//////////////////////////////////////////////////////////////////////////
/**
 * \brief       HelloUnblock Service Interface proxy class.
 *              Automatically instantiated per thread at client startup.
 *              Used to communicate with stub object and sending notifications
 *              to each client running in the thread instance.
 *
 *              Simple Service Interface to demonstrate working features of AREG SDK.
 *              In this example the client sends a request each 200 ms and the service replies each 500,
 *              so that when the client sends next request, there is always a pending request on the service.
 *              To process the request and make correct reply, the service manually unblocks the request
 *              and when timeout is expired, sends the response.
 *              The service is stopped and the application is shutdown when there is no more pending request.
 **/
class HelloUnblockProxy   : public ProxyBase
{
    friend class HelloUnblockClientBase;

private:
    //////////////////////////////////////////////////////////////////////////
    // HelloUnblockProxy::HelloUnblockServiceAvailableEvent class declaration
    //////////////////////////////////////////////////////////////////////////
    /**
     * \brief   The event is used immediately to notify new client about service
     *          availability and escape duplicating notification for other,
     *          already connected clients.
     **/
    class HelloUnblockServiceAvailableEvent : public ProxyBase::ServiceAvailableEvent
    {
    //////////////////////////////////////////////////////////////////////////
    // Runtime internals
    //////////////////////////////////////////////////////////////////////////
        DECLARE_RUNTIME_EVENT(HelloUnblockProxy::HelloUnblockServiceAvailableEvent)

    //////////////////////////////////////////////////////////////////////////
    // Constructor/ Destructor
    //////////////////////////////////////////////////////////////////////////
    public:
        /**
         * \brief   Sets event consumer object to deliver notification.
         **/
        explicit HelloUnblockServiceAvailableEvent( IENotificationEventConsumer & consumer );
        /**
         * \brief   Destructor.
         **/
        virtual ~HelloUnblockServiceAvailableEvent( void ) = default;
    //////////////////////////////////////////////////////////////////////////
    // Forbidden calls
    //////////////////////////////////////////////////////////////////////////
    private:
        HelloUnblockServiceAvailableEvent( void ) = delete;
        DECLARE_NOCOPY_NOMOVE( HelloUnblockServiceAvailableEvent );
    };
//////////////////////////////////////////////////////////////////////////
// HelloUnblockProxy predefined constants and static members.
//////////////////////////////////////////////////////////////////////////
protected:
    /**
     * \brief   Returns existing or creates new proxy object if it is not existing
     *          in the current thread scope.
     * \param   roleName        The role name of stub component object.
     * \param   connectListener The reference to connection listener
     * \param   ownerThread     The instance of thread to dispatch messages.
     * \return  Returns pointer to instantiated proxy object.
     **/
    static HelloUnblockProxy * createProxy( const String & roleName, IEProxyListener & connectListener, DispatcherThread & ownerThread );

    /**
     * \brief   Returns existing or creates new proxy object if it is not existing
     *          in the current thread scope.
     * \param   roleName        The role name of stub component object.
     * \param   connectListener The reference to connection listener
     * \param   ownerThread     The name of thread instance to dispatch messages.
     *                          If nullptr, current dispatching thread is used to dispatch messages.
     * \return  Returns pointer to instantiated proxy object.
     **/
    static HelloUnblockProxy * createProxy( const String & roleName, IEProxyListener & connectListener, const String & ownerThread = String::EmptyString );

//////////////////////////////////////////////////////////////////////////
// Constructor / Destructor. Protected
//////////////////////////////////////////////////////////////////////////
protected:
    /**
     * \brief   Creates Proxy object by given role name.
     *          Do not create proxy object directly, instead use CreateProxy function.
     * \param   roleName    The role name of proxy, i.e. role name of server component object.
     * \param   ownerThread The instance of thread to dispatch messages.
     *                      If nullptr, current dispatching thread is used to dispatch messages.
     **/
    explicit HelloUnblockProxy( const String & roleName, DispatcherThread * ownerThread = nullptr );
    /**
     * \brief   Destructor
     **/
    virtual ~HelloUnblockProxy( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Attributes and operations.
//////////////////////////////////////////////////////////////////////////
public:
/************************************************************************
 * Attributes
 ************************************************************************/
    /**
     * \brief   Returns true if value of HelloServiceState attribute is valid.
     *          If Update Notification is disabled, this method will return false.
     **/
    inline bool isHelloServiceStateValid( void ) const;
    /**
     * \brief   Returns the value of HelloServiceState attribute.
     *          To get valid value, the Update Notification should be enabled. 
     *          Attribute HelloServiceState description:
     *          The state of the service.
     * \param   state   On returns, contains the validation flag of attribute data.
     *                  Check validation flag before use attribute value.
     **/
    inline NEHelloUnblock::eServiceState getHelloServiceState( NEService::eDataStateType & state ) const;

/************************************************************************
 * Parameters
 ************************************************************************/
    /**
     * \brief   Returns value of clientId of response call function.
     *          The parameter is validated and set when Proxy is getting response call.
     *          Parameter clientId description:
     *          Generated ID for the client used when send request to unblock.
     **/
    inline unsigned int getParamclientId( void ) const;

    /**
     * \brief   Returns value of seqNr of response call function.
     *          The parameter is validated and set when Proxy is getting response call.
     *          Parameter seqNr description:
     *          The sequence number created by the client. On reply the service sends the sequence number so that
     *          the client can check that all sequences exist.
     **/
    inline unsigned int getParamseqNr( void ) const;

/************************************************************************
 * Requests.
 ************************************************************************/
    /**
     * \brief   Request call.
     *          Request to assign an ID to the client used to call unblock request.
     * \param   caller  The reference of caller object to get response.
     * \return  The sequence count number of call
     * \see     responseIdentifier
     **/
    const SequenceNumber &  requestIdentifier( IENotificationEventConsumer & caller );

    /**
     * \brief   Request call.
     *          Request to print hello world
     * \param   caller      The reference of caller object to get response.
     * \param   clientId    The given ID of the client. Should be 0 if unknown
     * \param   seqNr       The sequence number generated by the client. On each request the client increase the sequence number
     *          and stops sending request when reach the maximum.
     * \return  The sequence count number of call
     * \see     responseHelloUnblock
     **/
    const SequenceNumber &  requestHelloUblock( IENotificationEventConsumer & caller, unsigned int clientId, unsigned int seqNr );

//////////////////////////////////////////////////////////////////////////
// Operations.
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Checks whether there is already listener of Notification Event
     *          exists. If does not exit, adds new listener entry in the listener
     *          list. If need, send appropriate message to Stub to start
     *          sending attribute update messages. If already listener
     *          exists in listener list and notifyAlways flag is true,
     *          sends immediate update notification based on existing update data status.
     * \param   msgId           The Notification Message ID
     * \param   consumer        The pointer of Notification Event consumer
     * \param   notifyAlways    The flag, indicating whether the notification event
     *                          should be send to client immediately if the notification
     *                          already exists. By default it is false.
     **/
    inline void setNotification( NEHelloUnblock::eMessageIDs notifyId, IENotificationEventConsumer & listener, bool notifyAlways = false );
    /**
     * \brief   Clears listener entries of specified Notification Event consumer
     * \param   msgId       The Notification Message ID
     * \param   consumer    The pointer of Notification Event Consumer.
     **/
    inline void clearNotification( NEHelloUnblock::eMessageIDs notifyId, IENotificationEventConsumer & listener );
    /**
     * \brief   Clears all notification for specified listener and unregisters it
     * \param   listener    The notification consumer object, which should be unregistered.
     **/
    inline void clearAllNotifications( IENotificationEventConsumer & listener );

//////////////////////////////////////////////////////////////////////////
// Overrides
//////////////////////////////////////////////////////////////////////////
protected:
/************************************************************************/
// IEProxyEventConsumer interface overrides.
/************************************************************************/
    /**
     * \brief   Method derived from IEProxyEventConsumer interface.
     *          Triggered when on the request to execute function
     *          on server side, Proxy have got response message.
     * \param   eventElem   The Service Response event object.
     *                      Contains response message and information
     *                      sent by Stub
     **/
    virtual void processResponseEvent( ServiceResponseEvent & eventElem ) override;
    /**
     * \brief   Method derived from IEProxyEventConsumer interface.
     *          Triggered when on server side a certain Attribute
     *          value has been updated.
     * \param   eventElem   The Service Response event object.
     *                      Contains new updated value of Attribute
     *                      and validation flag.
     **/
    virtual void processAttributeEvent( ServiceResponseEvent & eventElem ) override;

/************************************************************************/
// ProxyBase interface overrides.
/************************************************************************/

    /**
     * \brief   Creates notification event to send to client objects.
     *          All Notification Events should be internal events and
     *          should be instances of NotificationEvent class.
     * \param   data    The Notification Event data object containing
     *                  notification information.
     * \return  Returns new created notification event object.
     **/
    virtual NotificationEvent * createNotificationEvent( const NotificationEventData & data ) const override;

    /**
     * \brief   Create Request event to send to Stub object.
     *          Request events are triggering request calls on Stub side.
     * \param   args    The buffer containing serialized arguments of request call.
     * \param   reqId   The ID of request call.
     * \return  Return pointer of valid Request event.
     **/
    virtual ServiceRequestEvent * createRequestEvent( const EventDataStream & args, unsigned int reqId ) override;

    /**
     * \brief   Creates event requesting to receive update notification events.
     *          The caller should be address of current proxy and the target
     *          should address of appropriate sub address.
     * \param   msgId       The message ID to send. Should be either attribute or response (info)
     * \param   reqType     The type of request.
     * \return  Returns valid pointer of created service request event object.
     **/
    virtual ServiceRequestEvent * createNotificationRequestEvent( unsigned int msgId, NEService::eRequestType reqType ) override;

    /**
     * \brief   Overwrite method to create response event from streaming object for
     *          further dispatching by proxy.
     * \param   stream  Streaming object, which contains event data.
     * \return  If operation succeeds, returns valid pointer to Service Response event object.
     *          Otherwise, it returns nullptr.
     **/
    virtual RemoteResponseEvent * createRemoteResponseEvent( const IEInStream & stream ) const override;

    /**
     * \brief   Overwrite method to create error remote response event.
     *          Function is triggered when remote request sent by proxy failed and did not reach target.
     * \param   addrProxy   Address of Proxy object, which sent request event
     * \param   msgId       Message ID, which was requested to process
     * \param   reason      Failure reason set by system
     * \param   seqNr       The sequence number of processing message.
     **/
    virtual RemoteResponseEvent * createRemoteRequestFailedEvent( const ProxyAddress & addrProxy, unsigned int msgId, NEService::eResultType reason, const SequenceNumber &  seqNr ) const override;

    /**
     * \brief   Overwrite this method to create service available event to new instantiated clients.
     * \param   consumer    The instance of consumer, which receives service available event.
     * \return  If succeeds, returns valid pointer to service available event object.
     **/
    virtual ProxyBase::ServiceAvailableEvent * createServiceAvailableEvent( IENotificationEventConsumer & consumer ) override;

    /**
     * \brief   Called to register all servicing listeners. It is called when proxy is instantiated.
     *          Overwrite method to add service event listeners.
     **/
    virtual void registerServiceListeners( void ) override;

    /**
     * \brief   Called to unregister all servicing listeners. It is called when proxy is freed.
     *          Overwrite method to remove service event listeners.
     **/
    virtual void unregisterServiceListeners( void ) override;

//////////////////////////////////////////////////////////////////////////
// Member variables
//////////////////////////////////////////////////////////////////////////
private:
/************************************************************************
 * Attribute members
 ************************************************************************/
    /**
     * \brief   HelloServiceState attribute value.
     *          The state of the service.
     **/
    NEHelloUnblock::eServiceState   mHelloServiceState;

/************************************************************************
 * Parameter members
 ************************************************************************/
    /**
     * \brief   clientId parameter value.
     *          Generated ID for the client used when send request to unblock.
     **/
    unsigned int                    mParamclientId;

    /**
     * \brief   seqNr parameter value.
     *          The sequence number created by the client. On reply the service sends the sequence number so that
     *          the client can check that all sequences exist.
     **/
    unsigned int                    mParamseqNr;

//////////////////////////////////////////////////////////////////////////
// Hidden methods
//////////////////////////////////////////////////////////////////////////
private:
/************************************************************************
 * Hidden operations
 ************************************************************************/
    /**
     * \brief   Updates attribute and response call variable data received from Stub
     * \param   eventElem   The event object containing buffer with serialized data
     * \param   respId      The response message ID, which received.
     *                      It is either attribute or response message ID
     **/
    void updateData( HelloUnblockResponseEvent & eventElem, NEHelloUnblock::eMessageIDs respId );
    /**
     * \brief   Starts processing response message. The received event contains
     *          ID of appropriate message to update and contains result flag.
     *          If request calls failed (busy), the ID in event is a request call ID.
     *          In all other cases, the ID is either response call, info call,
     *          or attribute update notification call.
     *          It will also update parameters and states.
     * \param   evenElem    The response object containing message ID, result and data.
     **/
    void processResponse( HelloUnblockResponseEvent & evenElem );

    /**
     * \brief   returns reference HelloUnblockProxy object
     **/
    inline HelloUnblockProxy & self( void );

/************************************************************************
 * Hidden static operations
 ************************************************************************/
private:
    /**
     * \brief   Create proxy object.
     * \param   roleName    The server component role name
     * \param   ownerThread The instance of thread to dispatch messages.
     *                      If nullptr, current dispatching thread is used to dispatch messages.
     * \return  Pointer to instantiated proxy object.
     **/
    static ProxyBase * _createProxy( const String & roleName, DispatcherThread * ownerThread = nullptr );

//////////////////////////////////////////////////////////////////////////
// Forbidden calls.
//////////////////////////////////////////////////////////////////////////
private:
    HelloUnblockProxy( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( HelloUnblockProxy );
};

//////////////////////////////////////////////////////////////////////////
// HelloUnblockProxy class declaration End
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// HelloUnblockProxy class inline functions implementation
//////////////////////////////////////////////////////////////////////////

/************************************************************************
 * Inline operations
 ************************************************************************/

inline void HelloUnblockProxy::setNotification( NEHelloUnblock::eMessageIDs notifyId, IENotificationEventConsumer & listener, bool notifyAlways /* = false */ )
{
    ProxyBase::setNotification(static_cast<unsigned int>(notifyId), &listener, notifyAlways);
}

inline void HelloUnblockProxy::clearNotification( NEHelloUnblock::eMessageIDs notifyId, IENotificationEventConsumer & listener )
{
    ProxyBase::clearNotification(static_cast<unsigned int>(notifyId), &listener);
}

inline void HelloUnblockProxy::clearAllNotifications( IENotificationEventConsumer & listener )
{
    ProxyBase::unregisterListener( &listener );
}

inline HelloUnblockProxy & HelloUnblockProxy::self( void )
{
    return (*this);
}

/************************************************************************
 * Inline attributes
 ************************************************************************/

inline bool HelloUnblockProxy::isHelloServiceStateValid( void ) const
{
    return (getProxyData().getAttributeState( static_cast<msg_id>(NEHelloUnblock::eMessageIDs::MsgId_HelloServiceState) ) == NEService::eDataStateType::DataIsOK);
}

inline NEHelloUnblock::eServiceState HelloUnblockProxy::getHelloServiceState( NEService::eDataStateType & state ) const
{
    state = getProxyData().getAttributeState( static_cast<msg_id>(NEHelloUnblock::eMessageIDs::MsgId_HelloServiceState) );
    return mHelloServiceState;
}

/************************************************************************
 * Inline parameters
 ************************************************************************/

inline unsigned int HelloUnblockProxy::getParamclientId( void ) const
{
    return mParamclientId;
}

inline unsigned int HelloUnblockProxy::getParamseqNr( void ) const
{
    return mParamseqNr;
}

#endif   // GENERATED_SRC_PRIVATE_HELLOUNBLOCKPROXY_HPP

//////////////////////////////////////////////////////////////////////////
// End generate generated/src/private/HelloUnblockProxy.hpp file
//////////////////////////////////////////////////////////////////////////
