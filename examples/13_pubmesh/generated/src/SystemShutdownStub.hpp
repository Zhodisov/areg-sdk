//////////////////////////////////////////////////////////////////////////
// Begin generate generated/src/SystemShutdownStub.hpp file
//////////////////////////////////////////////////////////////////////////
#ifndef  GENERATED_SRC_SYSTEMSHUTDOWNSTUB_HPP
#define  GENERATED_SRC_SYSTEMSHUTDOWNSTUB_HPP

/************************************************************************
 * (c) copyright    2023
 *
 * Generated at     15.11.2023  14:51:47 GMT+01:00
 *                  Create by AREG SDK code generator tool from source SystemShutdown.
 *
 * \file            generated/src/SystemShutdownStub.hpp
 * \ingroup         SystemShutdown Service Interface
 * \brief           This is an automatic generated code of SystemShutdown
 *                  Service Interface Stub class declaration.
 ************************************************************************/

/************************************************************************
 * Include files
 ************************************************************************/
#include "areg/base/GEGlobal.h"
#include "generated/src/NESystemShutdown.hpp"
#include "areg/component/StubBase.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/

//////////////////////////////////////////////////////////////////////////
// SystemShutdownStub class declaration
//////////////////////////////////////////////////////////////////////////
/**
 * \brief       SystemShutdown Service Interface Stub object.
 *              Instantiated per every server component, which differ by
 *              role name of component.
 *
 *              Simple Service Interface to demonstrate working features of AREG SDK.
 *              This service demonstrates the usage of attribute.
 **/
class SystemShutdownStub   : protected  StubBase
{
//////////////////////////////////////////////////////////////////////////
// Constructor / Destructor. Protected
//////////////////////////////////////////////////////////////////////////
protected:
    /**
     * \brief   Initializes Stub by given component object, which should be already instantiated.
     * \param   masterComp  The master component object, which is initializing service Stub.
     * \note    Before constructor is called, the instance of Component must be already initialized.
     **/
    explicit SystemShutdownStub( Component & masterComp );
    /**
     * \brief   Destructor.
     **/
    virtual ~SystemShutdownStub( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Unlocks and cancels all requests, excepts those which were manually unlocked.
     *          This call will send cancel error message (NEService::eResultType::RequestCanceled)
     *          to all clients waiting for response.
     **/
    void unlockAllRequests( void );

//////////////////////////////////////////////////////////////////////////
// Start Service Interface operations / attributes and overrides declaration
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// SystemShutdown Interface Attributes
//////////////////////////////////////////////////////////////////////////
 public:
/************************************************************************
 * Attribute ServiceState functions
 ************************************************************************/

    /**
     * \brief   Returns true if ServiceState attribute is valid
     **/
    inline bool isServiceStateValid( void ) const;
    /**
     * \brief   Invalidates ServiceState attribute and
     *          sends error update notification message to clients.
     **/
    inline void invalidateServiceState( void );
    /**
     * \brief   Force to send ServiceState attribute notification message to all clients.
     *          The method can be called when the attribute is updated not via set-method.
     **/
     inline void notifyServiceStateUpdated( void );
    /**
     * \brief   Set ServiceState attribute value and send notification event to all clients.
     *          The notification is sent only when value is updated or validated.
     * \param   newValue    New value of ServiceState attribute to set.
     *                      The ServiceState attribute description:
     *                      Describes the system availability state
     **/
    virtual void setServiceState( const NESystemShutdown::eServiceState & newValue );
    /**
     * \brief   Returns the value of ServiceState attribute.
     *          The ServiceState attribute description:
     *          Describes the system availability state
     **/
    inline const NESystemShutdown::eServiceState & getServiceState( void ) const;
    inline NESystemShutdown::eServiceState & getServiceState( void );

//////////////////////////////////////////////////////////////////////////
// SystemShutdown Interface Requests
//////////////////////////////////////////////////////////////////////////
public:

    /**
     * \brief   Request call.
     *          The request to shutdown the system.
     * \note    Has no response
     **/
    virtual void requestSystemShutdown( void ) = 0;

//////////////////////////////////////////////////////////////////////////
// SystemShutdown Interface Responses
//////////////////////////////////////////////////////////////////////////
public:

//////////////////////////////////////////////////////////////////////////
// SystemShutdown Interface Broadcasts
//////////////////////////////////////////////////////////////////////////
public:

//////////////////////////////////////////////////////////////////////////
// End Service Interface operations / attributes and overrides declaration
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//  Operations.
//////////////////////////////////////////////////////////////////////////
public:
/************************************************************************/
// StubBase overrides. Public methods.
/************************************************************************/

    /**
     * \brief   Sends update notification message to all clients.
     *          This method can be called manually to send update
     *          notification message after updating attribute value.
     *
     * \param   msgId   The attribute message ID to notify clients.
     **/
    virtual void sendNotification( unsigned int msgId ) override;

    /**
     * \brief   Sends error message to clients.
     *          If message ID is a request, it should send result NEService::eResultType::RequestError
     *          or NEService::eResultType::RequestCanceled, depending on msgCancel flag.
     *          If message ID is a response, it should send result NEService::eResultType::RequestInvalid.
     *          If message ID is an attribute, it should send result NEService::eResultType::DataInvalid
     *          and invalidate attribute data value.
     *
     * \param   msgId       The message ID to send error message
     * \param   msgCancel   Indicates whether the request is canceled or should respond with error.
     *                      This parameter has sense only for request IDs.
     *                      It is ignored for response and attributes IDs.
     **/
    virtual void errorRequest( unsigned int msgId, bool msgCancel ) override;

protected:
/************************************************************************/
// StubBase overrides. Triggered by Component on startup.
/************************************************************************/

    /**
     * \brief   This function is triggered by Component when starts up.
     *          Overwrite this method and set appropriate request and
     *          attribute update notification event listeners here
     * \param   holder  The holder component of service interface of Stub,
     *                  which started up.
     **/
    virtual void startupServiceInterface( Component & holder ) override;

    /**
     * \brief   This function is triggered by Component when shuts down.
     *          Overwrite this method to remove listeners and stub cleanup
     * \param   holder  The holder component of service interface of Stub,
     *                  which shuts down.
     **/
    virtual void shutdownServiceIntrface ( Component & holder ) override;

/************************************************************************/
// StubBase overrides. Protected methods
/************************************************************************/

    /**
     * \brief   Creates Response event object to pass of client.
     * \param   proxy   The address of proxy object to send response event
     * \param   msgId   The message ID to send to client
     * \param   result  The result of message
     * \param   data    The buffer of data to send to client. Can be Invalid buffer.
     * \return  Returns valid pointer to Response event object
     **/
    virtual ResponseEvent * createResponseEvent( const ProxyAddress & proxy, unsigned int msgId, NEService::eResultType result, const EventDataStream & data ) const override;

    /**
     * \brief   Overwrite method to create remote service request event from streaming object for
     *          further dispatching by stub.
     * \param   stream  Streaming object, which contains event data.
     * \return  If operation succeeds, returns valid pointer to Service Request event object.
     *          Otherwise, it returns nullptr.
     **/
    virtual RemoteRequestEvent * createRemoteRequestEvent( const IEInStream & stream ) const override;

    /**
     * \brief   Overwrite method to create remote notify request event from streaming object for
     *          further dispatching by stub.
     * \param   stream  Streaming object, which contains event data.
     * \return  If operation succeeds, returns valid pointer to Service Request event object.
     *          Otherwise, it returns nullptr.
     **/
    virtual RemoteNotifyRequestEvent * createRemoteNotifyRequestEvent( const IEInStream & stream ) const override;

private:
/************************************************************************/
// IEComponentConsumer interface overrides.
/************************************************************************/

    /**
     * \brief   Triggered to process service request event.
     *          Overwrite method to process every service request event.
     * \param   eventElem   Service Request Event object, contains request
     *                      call ID and parameters.
     **/
    virtual void processRequestEvent( ServiceRequestEvent & eventElem ) override;

    /**
     * \brief   Triggered to process attribute update notification event.
     *          Override method to process request to get attribute value and
     *          process notification request of attribute update.
     * \param   eventElem   Service Request Event object, contains attribute ID.
     **/
    virtual void processAttributeEvent( ServiceRequestEvent & eventElem ) override;

//////////////////////////////////////////////////////////////////////////
// Hidden function calls
//////////////////////////////////////////////////////////////////////////
private:
    /**
     * \brief   Returns reference to SystemShutdownStub object
     **/
    inline SystemShutdownStub & self( void );

//////////////////////////////////////////////////////////////////////////
// Member variables
//////////////////////////////////////////////////////////////////////////
private:
/************************************************************************
 * Attributes
 ************************************************************************/

    /**
     * \brief   Attribute ServiceState
     *          Describes the system availability state
     **/
    NESystemShutdown::eServiceState mServiceState;
    /**
     * \brief   Attribute ServiceState data validation state.
     **/
    NEService::eDataStateType       mServiceStateState;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    SystemShutdownStub( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( SystemShutdownStub );
};

//////////////////////////////////////////////////////////////////////////
// SystemShutdownStub class inline functions implementation
//////////////////////////////////////////////////////////////////////////

inline SystemShutdownStub & SystemShutdownStub::self( void )
{
    return (*this);
}

/************************************************************************
 * \brief   ServiceState attribute functions
 ************************************************************************/
 
inline bool SystemShutdownStub::isServiceStateValid( void ) const
{
    return (mServiceStateState  == NEService::eDataStateType::DataIsOK);
}

inline void SystemShutdownStub::invalidateServiceState( void )
{
    errorRequest( static_cast<msg_id>(NESystemShutdown::eMessageIDs::MsgId_ServiceState), false );
}

inline void SystemShutdownStub::notifyServiceStateUpdated( void )
{
    sendNotification( static_cast<msg_id>(NESystemShutdown::eMessageIDs::MsgId_ServiceState) );
}

inline const NESystemShutdown::eServiceState & SystemShutdownStub::getServiceState( void ) const
{
    return mServiceState;
}

inline NESystemShutdown::eServiceState & SystemShutdownStub::getServiceState( void )
{
    return mServiceState;
}

//////////////////////////////////////////////////////////////////////////
// SystemShutdownStub class declaration End
//////////////////////////////////////////////////////////////////////////

#endif   // GENERATED_SRC_SYSTEMSHUTDOWNSTUB_HPP

//////////////////////////////////////////////////////////////////////////
// End generate generated/src/SystemShutdownStub.hpp file
//////////////////////////////////////////////////////////////////////////
