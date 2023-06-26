#ifndef AREG_APPBASE_NEAPPLICATION_HPP
#define AREG_APPBASE_NEAPPLICATION_HPP
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
 * \ingroup     AREG Asynchronous Event-Driven Communication Framework
 * \author      Artak Avetyan
 * \brief       AREG Platform, Application global namespace and configurations
 ************************************************************************/
/************************************************************************
 * Include files.
 ************************************************************************/
#include "areg/base/GEGlobal.h"

#include <string_view>

/**
 * \brief   In this namespace contains application default configuration values.
 **/
namespace NEApplication
{
    /**
     * \brief   The default path of tracing configuration file.
     *          The path is relative to the executable folder.
     **/
    constexpr std::string_view  DEFAULT_TRACING_CONFIG_FILE     { "./config/log.init" };

    /**
     * \brief   The default path of message routing configuration file.
     *          The path is relative to the executable folder.
     **/
    constexpr std::string_view  DEFAULT_ROUTER_CONFIG_FILE      { "./config/router.init" };

    /**
     * \brief   ASCII version of service interface router service name.
     * "AREG TCP/IP connection Message Multicast Router Service"
     **/
    extern AREG_API char        ROUTER_SERVICE_NAME_ASCII[];

    /**
     * \brief   Unicode version of service interface router service name
     * L"AREG TCP/IP connection Message Multicast Router Service"
     **/
    extern AREG_API wchar_t     ROUTER_SERVICE_NAME_WIDE[];

    /**
     * \brief   ASCII version of service interface logger service name.
     * "AREG TCP/IP Logs collection Service"
     **/
    extern AREG_API char        LOGGER_SERVICE_NAME_ASCII[];

    /**
     * \brief   Unicode version of service interface logger service name
     * L"AREG TCP/IP Log collection Service"
     **/
    extern AREG_API wchar_t     LOGGER_SERVICE_NAME_WIDE[];

    /**
     * \brief   The default name of Multicast Router.
     **/
    constexpr std::string_view  DEFAULT_ROUTER_SERVICE_NAME     { "mcrouter" };

    template<class CommandType>
    struct ServiceCommand
    {
        const std::string_view  optLong;    // The long name of the option to process
        const std::string_view  optShort;   // The short name of the option to process
        const std::string_view  optDescr;   // The optional description
        const CommandType       optCommand; // The digital value of the option to process
    };

    template<class CommandType, CommandType defaultValue>
    inline CommandType parseOption(const char* const option, const NEApplication::ServiceCommand<CommandType> cmdList[], uint32_t count);
}

template<class CommandType, CommandType defaultValue>
inline CommandType NEApplication::parseOption(const char* const option, const NEApplication::ServiceCommand<CommandType> cmdList[], uint32_t count)
{
    CommandType result = defaultValue;
    if ((option != nullptr) && (*option != '\0'))
    {
        for (uint32_t i = 0; i < count; ++i)
        {
            const NEApplication::ServiceCommand<CommandType>& cmdOpt = cmdList[i];
            if ((cmdOpt.optLong == option) || (cmdOpt.optShort == option))
            {
                result = cmdOpt.optCommand;
                break;
            }
        }
    }

    return result;
}


#endif // AREG_APPBASE_NEAPPLICATION_HPP
