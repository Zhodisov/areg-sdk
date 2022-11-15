//////////////////////////////////////////////////////////////////////////
// Begin generate generated/src/PatientInformationClientBase.hpp file
//////////////////////////////////////////////////////////////////////////
#ifndef  GENERATED_SRC_PATIENTINFORMATIONCLIENTBASE_HPP
#define  GENERATED_SRC_PATIENTINFORMATIONCLIENTBASE_HPP

/************************************************************************
 * (c) copyright    2022
 *
 * Generated at     13.08.2022  02:46:19 GMT+02:00
 *                  Create by AREG SDK code generator tool from source PatientInformation.
 *
 * \file            generated/src/PatientInformationClientBase.hpp
 * \ingroup         PatientInformation Service Interface
 * \brief           This is an automatic generated code of PatientInformation
 *                  Service Interface Client base class declaration.
 ************************************************************************/

/************************************************************************
 * Include files
 ************************************************************************/
#include "areg/base/GEGlobal.h"
#include "generated/src/NEPatientInformation.hpp"
#include "areg/component/IEProxyListener.hpp"
#include "areg/component/NotificationEvent.hpp"

#include "generated/src/private/PatientInformationProxy.hpp"

/************************************************************************
 * Dependencies
 ************************************************************************/
class Component;
class DispatcherThread;

//////////////////////////////////////////////////////////////////////////
// PatientInformationClientBase class declaration.
//////////////////////////////////////////////////////////////////////////
/**
 * \brief       The interface of PatientInformation Service Interface
 *              Client base object. This object should be inherited
 *              and overrides should be implemented.
 *
 *              This service sends the patient information to apply connected devices.
 **/
class PatientInformationClientBase  : public IEProxyListener
{
//////////////////////////////////////////////////////////////////////////
// Constructor / Destructor. Protected
//////////////////////////////////////////////////////////////////////////
protected:
    /**
     * \brief   Initialize PatientInformation Service Interface client object.
     *          Specifies used service and owner thread.
     * \param   roleName    The role name assigned to PatientInformation servicing component object.
     * \param   ownerThread The name of component owner thread to dispatch messages.
     *                      If nullptr, all messages are dispatched in current component thread.
     **/
    PatientInformationClientBase( const String & roleName, const String & ownerThread = String::EmptyString );

    /**
     * \brief   Initialize PatientInformation Service Interface client object.
     *          Specifies used service and owner thread.
     * \param   roleName    The role name assigned to PatientInformation servicing component object.
     * \param   ownerThread The instance of component owner thread to dispatch messages.
     **/
    PatientInformationClientBase( const String & roleName, DispatcherThread & ownerThread );

    /**
     * \brief   Initialize PatientInformation Service Interface client object.
     *          Specifies used service and owner component.
     * \param   roleName    The role name assigned to PatientInformation servicing component object.
     * \param   owner       The instance of client owner component. The component object should be already initialized.
     * \note    When this constructor is used, it is important that the Component object is already initialized.
     *          and the component thread is set.
     **/
    PatientInformationClientBase( const String & roleName, Component & owner );

    /**
     * \brief   Destructor.
     **/
    virtual ~PatientInformationClientBase( void );

//////////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////////
public:
    /**
     * \brief   Clears all notifications, stops receiving notifications from server
     **/
    inline void clearAllNotifications( void );

    /**
     * \brief   Returns true if the specified certain notification is already assigned.
     *          Otherwise returns false.
     * \param   msgId   The ID of message to check.
     **/
    inline bool isNotificationAssigned( NEPatientInformation::eMessageIDs msgId ) const;

    /**
     * \brief   Returns true if client object has got connection with servicing component
     **/
    inline bool isConnected( void ) const;

    /**
     * \brief   Returns the name of used service.
     **/
    inline const String & getServiceName( void ) const;

    /**
     * \brief   Returns the version of used service.
     **/
    inline const Version & getServiceVersion( void ) const;

//////////////////////////////////////////////////////////////////////////
// Start Service Interface operations / attributes and overrides declaration
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// PatientInformation Interface Attributes
//////////////////////////////////////////////////////////////////////////
public:

/************************************************************************
 * Attribute Patient functions
 ************************************************************************/
    /**
     * \brief   Returns true if value of Patient attribute is valid.
     *          If Update Notification is disabled, this method will return false.
     **/
    inline bool isPatientValid( void ) const;
    /**
     * \brief   Returns the value of Patient attribute.
     *          To get valid value, the Update Notification should be enabled.
     *          Attribute Patient description:
     *          The patient information to apply to hardware.
     * \param   state   On returns, contains the validation flag of attribute data.
     *                  Check validation flag before use attribute value.
     * \see     isPatientValid, notifyPatientUpdate, onPatientUpdate
     **/
    inline const NEPatientInformation::PatientInfo & getPatient( NEService::eDataStateType & state ) const;
    /**
     * \brief   Call to enable or disable receiving notifications on Patient attribute update.
     *          Once notification is enabled and the data is updated,
     *          the getPatient method will return valid data
     *          Attribute Patient description:
     *          The patient information to apply to hardware.
     * \param   notify  If true, notification will be enable. If false, notification is disabled
     * \see     isPatientValid, getPatient, onPatientUpdate
     **/
    inline void notifyOnPatientUpdate( bool notify = true );
    /**
     * \brief   Triggered, when Patient attribute is updated. The function contains
     *          attribute value and validation flag. When notification is enabled,
     *          the method should be overwritten in derived class.
     *          Attributes Patient description:
     *          The patient information to apply to hardware.
     * \param   Patient The value of Patient attribute.
     * \param   state   The data validation flag.
     **/
    virtual void onPatientUpdate( const NEPatientInformation::PatientInfo & Patient, NEService::eDataStateType state );

//////////////////////////////////////////////////////////////////////////
// PatientInformation Interface Requests / Responses / Broadcasts
//////////////////////////////////////////////////////////////////////////
public:

//////////////////////////////////////////////////////////////////////////
// End Service Interface operations / attributes and overrides declaration
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Overrides
//////////////////////////////////////////////////////////////////////////
protected:
/************************************************************************/
// IEProxyListener Overrides
/************************************************************************/
    /**
     * \brief   Triggered by Proxy, when gets service connected event.
     *          Make client initializations in this function. No request
     *          will be processed until this function is not called for
     *          client object. Also set listeners here if client is interested
     *          to receive update notifications.
     * \param   isConnected     The flag, indicating whether service is connected
     *                          or disconnected. Make cleanups and stop sending
     *                          requests or assigning for notification if
     *                          this flag is false. No event to Stub target will
     *                          be sent, until no service connected event is
     *                          received.
     * \param   proxy           The Service Interface Proxy object, which is
     *                          notifying service connection.
     * \return  Return true if this service connect notification was relevant to client object,
     *          i.e. if passed Proxy address is equal to the Proxy object that client has.
     *          If Proxy objects are not equal, it should return false;
     **/
    virtual bool serviceConnected( bool isConnected, ProxyBase & proxy ) override;

/************************************************************************/
// PatientInformationClientBase Error Handling overrides
/************************************************************************/

    /**
     * \brief   Overwrite this method if need to make error handling on invalid request
     * \param   InvalidReqId    The ID of invalid request
     **/
    virtual void invalidRequest( NEPatientInformation::eMessageIDs InvalidReqId );

//////////////////////////////////////////////////////////////////////////
// Attributes
//////////////////////////////////////////////////////////////////////////

    /**
     * \brief   Call to recreate Proxy for the client. This call will remove and unregister all existing notifications
     *          and the client will not receive pending update or response notifications.
     *          The client first will receive disconnect message, then again connect.
     *          Reset update notifications manually in connect if need.
     *          This function call can be used when the client instance should be registered and run in new thread.
     *
     * \return  Returns true if Proxy was created with success.
     **/
    bool recreateProxy( void );

    /**
     * \brief  Returns pointer to client dispatcher thread where the messages are dispatched.
     *         The function can return nullptr if Proxy was not instantiated yet.
     **/
    DispatcherThread * getDispatcherThread( void );

    /**
     * \brief   Returns the current sequence number
     **/
    inline unsigned int getCurrentSequenceNr( void ) const;

    /**
     * \brief  Returns instance of proxy object.
     */
    inline const PatientInformationProxy * getProxy( void ) const;

    /**
     * \brief Returns target service component role name.
     **/
    inline const String & getServiceRole( void ) const;

//////////////////////////////////////////////////////////////////////////
// Member variables
//////////////////////////////////////////////////////////////////////////
private:
    /**
     * \brief   Connection flag. If true, the client object is connected to server
     **/
    bool                mIsConnected;
    /**
     * \brief   The counter of sequence number
     **/
    unsigned int        mCurrSequenceNr;
    /**
     * \brief   Pointer of Proxy object providing communication
     **/
    PatientInformationProxy *   mProxy;

//////////////////////////////////////////////////////////////////////////
// Hidden methods
//////////////////////////////////////////////////////////////////////////
private:
/************************************************************************/
// IENotificationEventConsumer overrides
/************************************************************************/

    /**
     * \brief   Is processing notification event calls.
     * \param   eventElem   Notification Event object to process
     **/
    virtual void processNotificationEvent( NotificationEvent & eventElem ) override;

/************************************************************************/
// PatientInformationClientBase hidden methods
/************************************************************************/

    /**
     * \brief   Enables / Disables notification flags on appropriate message call.
     * \param   msgId   The ID of message to enable / disable notification
     * \param   notify  If true, the notification is enabled.
     *                  If false, the notification is disabled.
     * \param   always  Flag, indicating whether should notify always or not.
     *                  if 'notify' parameter is true and the notification is already
     *                  assigned, then if parameter 'always' is true, it will trigger
     *                  notification immediately after call.
     **/
    void notifyOn( NEPatientInformation::eMessageIDs msgId, bool notify, bool always = false );
    /**
     * \brief   Overwrite this method if need to make error handling on invalid response
     * \param   InvalidRespId   The ID of invalid response
     **/
     void invalidResponse( NEPatientInformation::eMessageIDs InvalidRespId );

    /**
     * \brief   By default, the function calls appropriate request failure function.
     *          Overwrite this method if need to make error handling on request failed.
     * \param   msgId           The ID of either response of request message, which failed. Normally ID of request.
     * \param   FailureReason   The failure reason value of request call.
     **/
    void requestFailed( NEPatientInformation::eMessageIDs FailureMsgId, NEService::eResultType FailureReason );

    /**
     * \brief   Returns reference of PatientInformationClientBase object
     **/
    inline PatientInformationClientBase & self( void );

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    PatientInformationClientBase( void ) = delete;
    DECLARE_NOCOPY_NOMOVE( PatientInformationClientBase );
};

//////////////////////////////////////////////////////////////////////////
// PatientInformationClientBase class inline functions implementation
//////////////////////////////////////////////////////////////////////////

inline PatientInformationClientBase & PatientInformationClientBase::self( void )
{
    return (*this);
}

inline unsigned int PatientInformationClientBase::getCurrentSequenceNr( void ) const
{
    return mCurrSequenceNr;
}

inline void PatientInformationClientBase::clearAllNotifications( void )
{
    ASSERT(mProxy != nullptr);
    mProxy->clearAllNotifications(static_cast<IENotificationEventConsumer &>(self()));
}

inline bool PatientInformationClientBase::isConnected( void ) const
{
    ASSERT(mProxy != nullptr);
    return mIsConnected;
}

inline bool PatientInformationClientBase::isNotificationAssigned( NEPatientInformation::eMessageIDs msgId ) const
{
    ASSERT(mProxy != nullptr);
    return mProxy->hasNotificationListener(static_cast<unsigned int>(msgId));
}

inline const String & PatientInformationClientBase::getServiceName( void ) const
{
    ASSERT(mProxy != nullptr);
    return mProxy->getProxyAddress().getServiceName();
}

inline const Version & PatientInformationClientBase::getServiceVersion( void ) const
{
    ASSERT(mProxy != nullptr);
    return mProxy->getProxyAddress().getServiceVersion();
}

/************************************************************************
 * Attribute inline functions
 ************************************************************************/

inline bool PatientInformationClientBase::isPatientValid( void ) const
{
    ASSERT(mProxy != nullptr);
   return mProxy->isPatientValid( );
}
inline const NEPatientInformation::PatientInfo & PatientInformationClientBase::getPatient( NEService::eDataStateType & state ) const
{
    ASSERT(mProxy != nullptr);
    return mProxy->getPatient( state );
}

inline void PatientInformationClientBase::notifyOnPatientUpdate( bool notify /* = true */ )
{
    PatientInformationClientBase::notifyOn( NEPatientInformation::eMessageIDs::MsgId_Patient, notify, false );
}

inline const PatientInformationProxy * PatientInformationClientBase::getProxy( void ) const
{
    return mProxy;
}

inline const String & PatientInformationClientBase::getServiceRole( void ) const
{
    ASSERT(mProxy != nullptr);
    return mProxy->getProxyAddress().getRoleName();
}

#endif   // GENERATED_SRC_PATIENTINFORMATIONCLIENTBASE_HPP

//////////////////////////////////////////////////////////////////////////
// End generate generated/src/PatientInformationClientBase.hpp file
//////////////////////////////////////////////////////////////////////////
