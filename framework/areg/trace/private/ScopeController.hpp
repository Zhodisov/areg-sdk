#ifndef AREG_TRACE_PRIVATE_SCOPECONTROLLER_HPP
#define AREG_TRACE_PRIVATE_SCOPECONTROLLER_HPP
/************************************************************************
 * This file is part of the AREG SDK core engine.
 * AREG SDK is dual-licensed under Free open source (Apache version 2.0
 * License) and Commercial (with various pricing models) licenses, depending
 * on the nature of the project (commercial, research, academic or free).
 * You should have received a copy of the AREG SDK license description in LICENSE.txt.
 * If not, please contact to info[at]aregtech.com
 *
 * \copyright   (c) 2017-2023 Aregtech UG. All rights reserved.
 * \file        areg/trace/private/ScopeController.hpp
 * \ingroup     AREG SDK, Automated Real-time Event Grid Software Development Kit
 * \author      Artak Avetyan
 * \brief       AREG Platform, Trace controller.
 ************************************************************************/
 /************************************************************************
  * Include files.
  ************************************************************************/
#include "areg/base/GEGlobal.h"
#include "areg/base/TEResourceMap.hpp"

#include "areg/trace/NETrace.hpp"
#include "areg/trace/private/NELogging.hpp"

#include <string_view>

/************************************************************************
 * Dependencies
 ************************************************************************/
class TraceScope;
class Property;

//////////////////////////////////////////////////////////////////////////
// ScopeController::TraceScopeMap class declaration
//////////////////////////////////////////////////////////////////////////
//!< Scope hash map
using MapTraceScope     = NETrace::ScopeList;
//!< Scope resource map helper
using ImplTraceScope    = TEResourceMapImpl<unsigned int, TraceScope *>;
//!< The trace scope key-value pair.
using TraceScopePair    = std::pair<unsigned int, TraceScope *>;
//!< The map of scopes to configure
using ListScopes        = StringToIntegerHashMap;
    
/**
 * \brief   Resource map, container of all logging scopes
 **/
class TraceScopeMap   : public TELockResourceMap<unsigned int, TraceScope *, MapTraceScope, ImplTraceScope>
{
    friend class NetTcpLogger;
    friend class ScopeController;
    friend class TraceManager;

//////////////////////////////////////////////////////////////////////////
// Constructor / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    TraceScopeMap( void ) = default;
    ~TraceScopeMap( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    DECLARE_NOCOPY_NOMOVE( TraceScopeMap );
};

/**
 * \brief   The controller of scopes in the application.
 *          It contains all scopes in the application.
 *          It contains the list of initialized scopes in the configuration file.
 *          It activates and deactivates scopes, and changes the scope priority.
 **/
class ScopeController
{
//////////////////////////////////////////////////////////////////////////
// Constructor / Destructor
//////////////////////////////////////////////////////////////////////////
public:
    ScopeController( void ) = default;
    ~ScopeController( void ) = default;

//////////////////////////////////////////////////////////////////////////
// Attributes
//////////////////////////////////////////////////////////////////////////
public:

    /**
     * \brief   Returns the list of scopes registered in the application.
     **/
    inline const TraceScopeMap & getScopeList( void ) const;

    /**
     * \brief   By given unique scope ID it returns instance of
     *          Trace Scope object. Returns nullptr if there is no
     *          trace scope object with specified ID registered
     *          in the system.
     * \param   scopeId     The unique trace scope ID to lookup in the system
     * \return  Returns valid pointer to Trace Scope object if it is
     *          registered. Otherwise, it returns nullptr.
     **/
    inline const TraceScope * getScope( unsigned int scopeId ) const;

    /**
     * \brief   By given unique scope name it returns instance of
     *          Trace Scope object. Returns nullptr if there is no
     *          trace scope object with specified name registered
     *          in the system.
     * \param   scopeName   The unique trace scope name to lookup in the system
     * \return  Returns valid pointer to Trace Scope object if it is
     *          registered. Otherwise, it returns nullptr.
     **/
    inline const TraceScope * getScope( const char * scopeName ) const;

    /**
     * \brief   Checks whether there is trace scope object registered
     *          in the system with specified unique ID.
     * \param   scopeId     The unique trace scope ID to check in the system.
     * \return  Returns true if there is trace scope with specified unique ID
     *          is registered in the system. Otherwise, it returns false.
     **/
    bool isScopeRegistered( unsigned int scopeId ) const;

    /**
     * \brief   Checks whether there is trace scope object registered
     *          in the system with specified unique name.
     * \param   scopeName   The unique trace scope name to check in the system.
     * \return  Returns true if there is trace scope with specified unique name
     *          is registered in the system. Otherwise, it returns false.
     **/
    bool isScopeRegistered( const char * scopeName ) const;

//////////////////////////////////////////////////////////////////////////
// Operations
//////////////////////////////////////////////////////////////////////////
public:

    /**
     * \brief   Registers instance of trace scope object in trace manager.
     *          The trace scope should have unique ID.
     * \param   scope   The instance trace scope object to register.
     **/
    void registerScope( TraceScope & scope );

    /**
     * \brief   Unregisters instance of trace scope object in trace manager.
     * \param   scope   The instance of trace scope to unregister.
     **/
    void unregisterScope( TraceScope & scope );

    /**
     * \brief   By given unique ID searches trace scope object in the map and if found,
     *          sets the specified scope priority.
     * \param   scopeId     The unique ID of trace scope to search in the system.
     * \param   newPrio     The priority value to set for trace scope.
     **/
    void setScopePriority( unsigned int scopeId, unsigned int newPrio );

    /**
     * \brief   By given unique ID searches trace scope object in the map and if found,
     *          sets the specified scope priority.
     * \param   scopeId     The unique ID of trace scope to search in the system.
     * \param   newPrio     The name of priority value to set for trace scope.
     **/
    inline void setScopePriority( unsigned int scopeId, const String & newPrio );

    /**
     * \brief   By given unique name searches trace scope object in the map and if found,
     *          sets the specified scope priority.
     * \param   scopeName   The unique name of trace scope to search in the system.
     * \param   newPrio     The priority value to set for trace scope.
     **/
    inline void setScopePriority( const String & scopeName, unsigned int newPrio );

    /**
     * \brief   By given unique name searches trace scope object in the map and if found,
     *          sets the specified scope priority.
     * \param   scopeName   The unique name of trace scope to search in the system.
     * \param   newPrio     The name of priority value to set for trace scope.
     **/
    inline void setScopePriority( const String & scopeName, const String & newPrio );

    /**
     * \brief   By given unique ID searches trace scope object in the map and if found,
     *          adds the specified scope priority.
     * \param   scopeId     The unique ID of trace scope to search in the system.
     * \param   addPrio     The priority value to add for trace scope.
     **/
    void addScopePriority( unsigned int scopeId, NETrace::eLogPriority addPrio );

    /**
     * \brief   By given unique ID searches trace scope object in the map and if found,
     *          adds the specified scope priority.
     * \param   scopeId     The unique ID of trace scope to search in the system.
     * \param   addPrio     The name of priority value to add for trace scope.
     **/
    inline void addScopePriority( unsigned int scopeId, const String & addPrio );

    /**
     * \brief   By given unique name searches trace scope object in the map and if found,
     *          adds the specified scope priority.
     * \param   scopeName   The unique name of trace scope to search in the system.
     * \param   addPrio     The priority value to add for trace scope.
     **/
    inline void addScopePriority( const String & scopeName, NETrace::eLogPriority addPrio );

    /**
     * \brief   By given unique name searches trace scope object in the map and if found,
     *          adds the specified scope priority.
     * \param   scopeName   The unique name of trace scope to search in the system.
     * \param   addPrio     The name of priority value to add for trace scope.
     **/
    inline void addScopePriority( const String & scopeName, const String & addPrio );

    /**
     * \brief   By given unique ID searches trace scope object in the map and if found,
     *          removes the specified scope priority.
     * \param   scopeId     The unique ID of trace scope to search in the system.
     * \param   remPrio     The priority value to remove for trace scope.
     **/
    void removeScopePriority( unsigned int scopeId, NETrace::eLogPriority remPrio );

    /**
     * \brief   By given unique ID searches trace scope object in the map and if found,
     *          removes the specified scope priority.
     * \param   scopeId     The unique ID of trace scope to search in the system.
     * \param   remPrio     The name of priority value to remove for trace scope.
     **/
    inline void removeScopePriority( unsigned int scopeId, const String & remPrio );

    /**
     * \brief   By given unique name searches trace scope object in the map and if found,
     *          removes the specified scope priority.
     * \param   scopeName   The unique name of trace scope to search in the system.
     * \param   remPrio     The priority value to remove for trace scope.
     **/
    inline void removeScopePriority( const String & scopeName, NETrace::eLogPriority remPrio );

    /**
     * \brief   By given unique name searches trace scope object in the map and if found,
     *          removes the specified scope priority.
     * \param   scopeName   The unique name of trace scope to search in the system.
     * \param   remPrio     The name of priority value to remove for trace scope.
     **/
    inline void removeScopePriority( const String & scopeName, const String & remPrio );

    /**
     * \brief   By given name of scope group searches trace scope object in the map and for every
     *          found scope object, sets the specified scope priority.
     * \param   scopeGroupName  The name of trace scope group to search in the system.
     * \param   newPrio         The priority value to set for every trace scope.
     * \return  Returns number of trace scope object, which priority has been changed.
     *          Returns zero, if could not find any trace scope within specified group.
     **/
    int setScopeGroupPriority( const String & scopeGroupName, unsigned int newPrio );

    /**
     * \brief   By given name of scope group searches trace scope object in the map and for every
     *          found scope object, sets the specified scope priority.
     * \param   scopeGroupName  The name of trace scope group to search in the system.
     * \param   newPrio         The name of priority value to set for every trace scope.
     * \return  Returns number of trace scope object, which priority has been changed.
     *          Returns zero, if could not find any trace scope within specified group.
     **/
    inline int setScopeGroupPriority( const String & scopeGroupName, const String & newPrio );

    /**
     * \brief   By given name of scope group searches trace scope object in the map and for every
     *          found scope object, adds the specified scope priority.
     * \param   scopeGroupName  The name of trace scope group to search in the system.
     * \param   addPrio         The priority value to add for every trace scope.
     * \return  Returns number of trace scope object, which priority has been changed.
     *          Returns zero, if could not find any trace scope within specified group.
     **/
    int addScopeGroupPriority( const String & scopeGroupName, NETrace::eLogPriority addPrio );

    /**
     * \brief   By given name of scope group searches trace scope object in the map and for every
     *          found scope object, adds the specified scope priority.
     * \param   scopeGroupName  The name of trace scope group to search in the system.
     * \param   addPrio         The name of priority value to add for every trace scope.
     * \return  Returns number of trace scope object, which priority has been changed.
     *          Returns zero, if could not find any trace scope within specified group.
     **/
    inline int addScopeGroupPriority( const String & scopeGroupName, const String & addPrio );

    /**
     * \brief   By given name of scope group searches trace scope object in the map and for every
     *          found scope object, removes the specified scope priority.
     * \param   scopeGroupName  The name of trace scope group to search in the system.
     * \param   remPrio         The priority value to remove for every trace scope.
     * \return  Returns number of trace scope object, which priority has been changed.
     *          Returns zero, if could not find any trace scope within specified group.
     **/
    int removeScopeGroupPriority( const String & scopeGroupName, NETrace::eLogPriority remPrio );

    /**
     * \brief   By given name of scope group searches trace scope object in the map and for every
     *          found scope object, removes the specified scope priority.
     * \param   scopeGroupName  The name of trace scope group to search in the system.
     * \param   remPrio         The name of priority value to remove for every trace scope.
     * \return  Returns number of trace scope object, which priority has been changed.
     *          Returns zero, if could not find any trace scope within specified group.
     **/
    inline int removeScopeGroupPriority( const String & scopeGroupName, const String & remPrio );

    /**
     * \brief   Clears the list of configured scopes.
     *          Call this method if making new configuration.
     **/
    inline void clearConfigScopes( void );

    /**
     * \brief   Call to reset and disable any message priority of scopes.
     **/
    void resetScopes(void);

    /**
     * \brief   Activates default scopes listed in the internally.
     **/
    void activateDefaults( void );

    /**
     * \brief   Configures the scope or scope group defined in the property.
     * \param   prop    The trace property object initialized when read configuration file.
     *                  It contains the scope name and scope priority information.
     **/
    void configureScopes( const Property & prop );

    /**
     * \brief   Configures defined scope or scope group.
     * \param   scopeName   The name of the scope or scope group to configure.
     * \param   scopePrio   The priority to set to scope or scope group.
     **/
    void configureScopes( const String & scopeName, unsigned int scopePrio );

    /**
     * \brief   Picks up the list of configured scopes and log priorities and sets the scope priorties,
     *          so that they are activated or deactivated.
     **/
    void configureScopes(void);

    /**
     * \brief   Activates specified scope. The system cannot log if a scope is inactive.
     *          No property of specified scope is changed, the priority remains unchanged.
     * \param   traceScope  The scope to activate.
     **/
    void activateScope( TraceScope & traceScope );

    /**
     * \brief   Activates specified scope and sets specified logging priority. 
     *          The system cannot log if a scope is inactive. The method as well changes logging priority.
     * \param   traceScope      The scope to activate and update logging priority.
     * \param   defaultPrio     The default priority to set to the scope.
     **/
    void activateScope( TraceScope & traceScope, unsigned int defaultPriority );

    /**
     * \brief   Activates or deactivates the scope based on the log scope priority set in the configuration.
     * \param   makeActive  Flag, indicating whether scopes should be activated or deactivated.
     *                      If true, it lookups in the configuration settings and updates the priority.
     *                      Otherwise, it deactivates all scopes, so that no messages are logged.
     **/
    void changeScopeActivityStatus( bool makeActive );

    /**
     * \brief   Changes the logging priority of the scope.
     * \param   scopeName   The name of a scope or scope group.
     * \param   scopeId     The ID of the scope. Can be zero if it is a scope group.
     * \param   logPrio     The priority of the log to set.
     **/
    void changeScopeActivityStatus( const String & scopeName, unsigned int scopeId, unsigned int logPrio );

//////////////////////////////////////////////////////////////////////////
// Hidden methods
//////////////////////////////////////////////////////////////////////////
private:

    /**
     * \brief   Checks whether the specified scope name indicates the group of scopes or a single scope name.
     *          The group of scopes ends with symbol '*'.
     **/
    static inline bool _isScopeGroup( const String & scopeName );

//////////////////////////////////////////////////////////////////////////
// Hidden members
//////////////////////////////////////////////////////////////////////////
private:
    //!< The list of scopes read out from configuration file.
    ListScopes          mConfigScopeList;
    //!< The list of scope groups read out from configuration file
    ListScopes          mConfigScopeGroup;
    //!< The map of registered trace scope objects.
    TraceScopeMap       mMapTraceScope;

//////////////////////////////////////////////////////////////////////////
// Forbidden calls
//////////////////////////////////////////////////////////////////////////
private:
    DECLARE_NOCOPY_NOMOVE( ScopeController );
};

//////////////////////////////////////////////////////////////////////////
// ScopeController inline methods
//////////////////////////////////////////////////////////////////////////

inline const TraceScopeMap & ScopeController::getScopeList( void ) const
{
    return mMapTraceScope;
}

inline const TraceScope * ScopeController::getScope( unsigned int scopeId ) const
{
    return mMapTraceScope.findResourceObject( scopeId );
}

inline const TraceScope * ScopeController::getScope( const char * scopeName ) const
{
    return getScope( NETrace::makeScopeId(scopeName) );
}

inline bool ScopeController::isScopeRegistered( unsigned int scopeId ) const
{
    return (getScope(scopeId) != nullptr);
}

inline bool ScopeController::isScopeRegistered( const char * scopeName ) const
{
    return (getScope( scopeName ) != nullptr);
}

inline void ScopeController::setScopePriority( unsigned int scopeId, const String & newPrio )
{
    setScopePriority( scopeId, NETrace::stringToLogPrio( newPrio ) );
}

inline void ScopeController::setScopePriority( const String & scopeName, unsigned int newPrio )
{
    setScopePriority( NETrace::makeScopeId( scopeName ), newPrio );
}

inline void ScopeController::setScopePriority( const String & scopeName, const String & newPrio )
{
    setScopePriority( NETrace::makeScopeId( scopeName ), NETrace::stringToLogPrio( newPrio ) );
}

inline void ScopeController::addScopePriority( unsigned int scopeId, const String & addPrio )
{
    addScopePriority( scopeId, NETrace::stringToLogPrio( addPrio ) );
}

inline void ScopeController::addScopePriority( const String & scopeName, NETrace::eLogPriority addPrio )
{
    addScopePriority( NETrace::makeScopeId( scopeName ), addPrio );
}

inline void ScopeController::addScopePriority( const String & scopeName, const String & addPrio )
{
    addScopePriority( NETrace::makeScopeId( scopeName ), NETrace::stringToLogPrio( addPrio ) );
}

inline void ScopeController::removeScopePriority( unsigned int scopeId, const String & remPrio )
{
    removeScopePriority( scopeId, NETrace::stringToLogPrio( remPrio ) );
}

inline void ScopeController::removeScopePriority( const String & scopeName, NETrace::eLogPriority remPrio )
{
    removeScopePriority( NETrace::makeScopeId( scopeName ), remPrio );
}

inline void ScopeController::removeScopePriority( const String & scopeName, const String & remPrio )
{
    removeScopePriority( NETrace::makeScopeId( scopeName ), NETrace::stringToLogPrio( remPrio ) );
}

inline int ScopeController::setScopeGroupPriority( const String & scopeGroupName, const String & newPrio )
{
    return setScopeGroupPriority( scopeGroupName, NETrace::stringToLogPrio( newPrio ) );
}

inline int ScopeController::addScopeGroupPriority( const String & scopeGroupName, const String & addPrio )
{
    return addScopeGroupPriority( scopeGroupName, NETrace::stringToLogPrio( addPrio ) );
}

inline int ScopeController::removeScopeGroupPriority( const String & scopeGroupName, const String & remPrio )
{
    return removeScopeGroupPriority( scopeGroupName, NETrace::stringToLogPrio( remPrio ) );
}

inline void ScopeController::clearConfigScopes( void )
{
    mConfigScopeList.clear( );
    mConfigScopeGroup.clear( );
}

#endif   // AREG_TRACE_PRIVATE_ScopeController_HPP
