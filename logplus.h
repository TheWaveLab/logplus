#pragma once

#include <string>
#include "log4cplus/logger.h"
#include "log4cplus/fileappender.h"
#include "log4cplus/consoleappender.h"
#include "log4cplus/layout.h"
#include "log4cplus/configurator.h"
#include "log4cplus/loggingmacros.h"
#include "AutoLock.h"

using namespace log4cplus;
using namespace helpers;

#define DEFAULT_LOG_CONFIGFILE "log4cplus.cfg"

#define LOGPLUS_DEBUG(p) LOG4CPLUS_DEBUG(logplus::m_logger, p)
#define LOGPLUS_INFO(p) LOG4CPLUS_INFO(logplus::m_logger, p)
#define LOGPLUS_WARN(p) LOG4CPLUS_WARN(logplus::m_logger, p)
#define LOGPLUS_ERROR(p) LOG4CPLUS_ERROR(logplus::m_logger, p)
#define LOGPLUS_FATAL(p) LOG4CPLUS_FATAL(logplus::m_logger, p)


class logplus
{
public:
	static logplus *getlogger(const std::string strconf);
	static void releaselogger();

public:
	static Logger m_logger;

private:
	logplus(void);
	~logplus(void);
	logplus(const logplus &);
	const logplus &operator =(const logplus &);
	static logplus *m_instance;
	static bool m_binit;
	static std::string m_strConfig;
	//static CMutex m_mutex;
};

