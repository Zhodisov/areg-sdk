#ifndef  AREG_EXAMPLES_15_PUBSVCWORKER_IPCSVCPATIENT_SRC_PATIENTSERVICE_HPP
#define  AREG_EXAMPLES_15_PUBSVCWORKER_IPCSVCPATIENT_SRC_PATIENTSERVICE_HPP
/************************************************************************
 * \file        ipcsvcpatient/src/PatientService.hpp
 * \ingroup     AREG Asynchronous Event-Driven Communication Framework examples
 * \author      Artak Avetyan (mailto:artak@aregtech.com)
 * \brief       Collection of AREG SDK examples.
 *              This is a patient info service.
 ************************************************************************/
/************************************************************************
 * Include files.
 ************************************************************************/

#include "areg/base/GEGlobal.h"
#include "areg/component/Component.hpp"
#include "generated/src/PatientInformationStub.hpp"
#include "ipcsvcpatient/src/PatientServiceWorkerConsumer.hpp"

/**
 * \brief   The servicing object.
 **/
class PatientService    : public    Component
                        , private   PatientInformationStub
{
//////////////////////////////////////////////////////////////////////////
// Statics and constants.
//////////////////////////////////////////////////////////////////////////
public:

    /**
     * \brief   The name of worker thread consumer
     **/
    static const char * const   PatienServiceConsumerName       /*= "PatienServiceConsumer"*/;

    /**
     * \brief   The name or worker thread.
     **/
    static const char * const   PatientServiceWorkerThread      /*= "PatientServiceWorkerThread"*/;

    /**
     * \brief   Called by system to instantiate the component.
     * \param   entry   The entry of registry, which describes the component.
     * \param   owner   The component owning thread.
     * \return  Returns instantiated component to run in the system
     **/
    static Component * CreateComponent( const NERegistry::ComponentEntry & entry, ComponentThread & owner );

    /**
     * \brief   Called by system to delete component and free resources.
     * \param   compObject  The instance of component previously created by CreateComponent method.
     * \param   entry   The entry of registry, which describes the component.
     **/
    static void DeleteComponent( Component & compObject, const NERegistry::ComponentEntry & entry );

protected:

    /**
     * \brief   Returns pointer to Worker Thread Consumer object identified
     *          by consumer name and if needed, by worker thread name.
     *          This function is triggered, when component is initialized and
     *          worker threads should be created.
     * \param   consumerName        The name of worker thread consumer object to identify
     * \param   workerThreadName    The name of worker thread, which consumer should return
     * \return  Return valid pointer if worker thread has assigned consumer.
     **/
    virtual IEWorkerThreadConsumer * workerThreadConsumer( const char* consumerName, const char* workerThreadName );

//////////////////////////////////////////////////////////////////////////
// Hidden members.
//////////////////////////////////////////////////////////////////////////
private:
    /**
     * \brief   Initializes component and the implemented services.
     **/
    PatientService( const NERegistry::ComponentEntry & entry, ComponentThread & owner );
    /**
     * \brief   Destructor.
     **/
    virtual ~PatientService(void);

    /**
     * \brief   Wrapper of this pointer.
     **/
    inline PatientService & self( void );

//////////////////////////////////////////////////////////////////////////
// Member variables.
//////////////////////////////////////////////////////////////////////////
private:
    /**
     * \brief   The worker thread consumer object.
     **/
    PatientServiceWorkerConsumer    mWorkerConsumer;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls.
//////////////////////////////////////////////////////////////////////////
private:
    PatientService( void );
    PatientService( const PatientService & /*src*/ );
    const PatientService & operator = ( const PatientService & /*src*/ );
};

#endif  // AREG_EXAMPLES_15_PUBSVCWORKER_IPCSVCPATIENT_SRC_PATIENTSERVICE_HPP
