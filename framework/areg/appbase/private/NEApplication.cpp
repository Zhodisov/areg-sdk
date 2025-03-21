/************************************************************************
 * This file is part of the AREG SDK core engine.
 * AREG SDK is dual-licensed under Free open source (Apache version 2.0
 * License) and Commercial (with various pricing models) licenses, depending
 * on the nature of the project (commercial, research, academic or free).
 * You should have received a copy of the AREG SDK license description in LICENSE.txt.
 * If not, please contact to info[at]aregtech.com
 *
 * \copyright   (c) 2017-2023 Aregtech UG. All rights reserved.
 * \file        areg/appbase/NEApplication.hpp
 * \ingroup     AREG SDK, Automated Real-time Event Grid Software Development Kit
 * \author      Artak Avetyan
 * \brief       AREG Platform, Application global namespace and configurations
 ************************************************************************/
 /************************************************************************
  * Include files.
  ************************************************************************/
#include "areg/appbase/NEApplication.hpp"

/**
 * "AREG TCP/IP connection Message Multicast Router Service"
 **/
AREG_API_IMPL char NEApplication::ROUTER_SERVICE_NAME_ASCII[]    { "AREG TCP/IP connection Message Multicast Router Service" };
// { 'A', 'R', 'E', 'G', ' ', 'T', 'C', 'P', '/', 'I', 'P', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'M', 'e', 's', 's', 'a', 'g', 'e', ' ', 'M', 'u', 'l', 't', 'i', 'c', 'a', 's', 't', ' ', 'R', 'o', 'u', 't', 'e', 'r', ' ', 'S', 'e', 'r', 'v', 'i', 'c', 'e', '\0' };

/**
 * L"AREG TCP/IP connection Message Multicast Router Service"
 **/
AREG_API_IMPL wchar_t NEApplication::ROUTER_SERVICE_NAME_WIDE[]  { L"AREG TCP/IP connection Message Multicast Router Service" };
// { 'A', 'R', 'E', 'G', ' ', 'T', 'C', 'P', '/', 'I', 'P', ' ', 'c', 'o', 'n', 'n', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'M', 'e', 's', 's', 'a', 'g', 'e', ' ', 'M', 'u', 'l', 't', 'i', 'c', 'a', 's', 't', ' ', 'R', 'o', 'u', 't', 'e', 'r', ' ', 'S', 'e', 'r', 'v', 'i', 'c', 'e', '\0' };

/**
 * "AREG TCP/IP Logs collection Service"
 **/
AREG_API_IMPL char NEApplication::LOGGER_SERVICE_NAME_ASCII[]    { "AREG TCP/IP TCP/IP Logs collection Service" };
// { 'A', 'R', 'E', 'G', ' ', 'T', 'C', 'P', '/', 'I', 'P', ' ', 'L', 'o', 'g', 's', ' ', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'S', 'e', 'r', 'v', 'i', 'c', 'e', '\0' };

/**
 * L"AREG TCP/IP Logs collection Service"
 **/
AREG_API_IMPL wchar_t NEApplication::LOGGER_SERVICE_NAME_WIDE[]  { L"AREG TCP/IP TCP/IP Logs collection Service" };
// { 'A', 'R', 'E', 'G', ' ', 'T', 'C', 'P', '/', 'I', 'P', ' ', 'L', 'o', 'g', 's', ' ', 'c', 'o', 'l', 'l', 'e', 'c', 't', 'i', 'o', 'n', ' ', 'S', 'e', 'r', 'v', 'i', 'c', 'e', '\0' };

AREG_API_IMPL const std::vector<Identifier>     NEApplication::LogTypeIdentifiers =
{
      {static_cast<unsigned int>(NETrace::eLogingTypes::LogTypeUndefined)               , NEApplication::DefaultLogTypes[0].ltIdName        }
    , {static_cast<unsigned int>(NETrace::eLogingTypes::LogTypeRemote)                  , NEApplication::DefaultLogTypes[1].ltIdName        }
    , {static_cast<unsigned int>(NETrace::eLogingTypes::LogTypeFile)                    , NEApplication::DefaultLogTypes[2].ltIdName        }
    , {static_cast<unsigned int>(NETrace::eLogingTypes::LogTypeDebug)                   , NEApplication::DefaultLogTypes[3].ltIdName        }
    , {static_cast<unsigned int>(NETrace::eLogingTypes::LogTypeDatabase)                , NEApplication::DefaultLogTypes[4].ltIdName        }
};

AREG_API_IMPL const std::vector<Identifier>   NEApplication::ConnectionIdentifiers
{
      { static_cast<unsigned int>(NERemoteService::eConnectionTypes::ConnectUndefined)  , NEApplication::DefaultConnections[0].ltIdName     }
    , { static_cast<unsigned int>(NERemoteService::eConnectionTypes::ConnectTcpip)      , NEApplication::DefaultConnections[1].ltIdName     }
    , { static_cast<unsigned int>(NERemoteService::eConnectionTypes::ConnectUdp)        , NEApplication::DefaultConnections[2].ltIdName     }
    , { static_cast<unsigned int>(NERemoteService::eConnectionTypes::ConnectWeb)        , NEApplication::DefaultConnections[3].ltIdName     }
    , { static_cast<unsigned int>(NERemoteService::eConnectionTypes::ConnectSM)         , NEApplication::DefaultConnections[4].ltIdName     }
};

AREG_API_IMPL const std::vector<Identifier>   NEApplication::RemoteServiceIdentifiers
{
      { static_cast<unsigned int>(NERemoteService::eRemoteServices::ServiceUnknown)     , NEApplication::DefaultRemotetServices[0].ltIdName }
    , { static_cast<unsigned int>(NERemoteService::eRemoteServices::ServiceRouter)      , NEApplication::DefaultRemotetServices[1].ltIdName }
    , { static_cast<unsigned int>(NERemoteService::eRemoteServices::ServiceLogger)      , NEApplication::DefaultRemotetServices[2].ltIdName }
};

AREG_API_IMPL const std::vector<Identifier>   NEApplication::LogScopePriorityIndentifiers
{
      { static_cast<unsigned int>(NETrace::eLogPriority::PrioInvalid)                   , NETrace::PRIO_NO_PRIO                             }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioNotset)                    , NETrace::PRIO_NOTSET_STR                          }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioScope)                     , NETrace::PRIO_SCOPE_STR                           }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioFatal)                     , NETrace::PRIO_FATAL_STR                           }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioError)                     , NETrace::PRIO_ERROR_STR                           }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioWarning)                   , NETrace::PRIO_WARNING_STR                         }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioInfo)                      , NETrace::PRIO_INFO_STR                            }
    , { static_cast<unsigned int>(NETrace::eLogPriority::PrioDebug)                     , NETrace::PRIO_DEBUG_STR                           }
};
