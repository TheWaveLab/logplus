#include "logplus.h"

logplus *logplus::m_instance = new logplus;
bool logplus::m_binit = false;
std::string logplus::m_strConfig = DEFAULT_LOG_CONFIGFILE;
Logger logplus::m_logger;
//CMutex logplus::m_mutex;

logplus::logplus(void)
{
	
}


logplus::~logplus(void)
{
}

logplus *logplus::getlogger(const std::string strconf)
{
	m_strConfig = strconf;
	PropertyConfigurator::doConfigure(m_strConfig);
	m_logger = Logger::getInstance("WARN_MSGS");

	return m_instance;
}

void logplus::releaselogger()
{
	m_logger.shutdown();
	delete m_instance;
	m_instance = NULL;
}
