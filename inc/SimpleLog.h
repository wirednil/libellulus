#ifndef __SIMPLE_LOG_H__
#define __SIMPLE_LOG_H__

#define SIMPLE_DEBUG(FMT, ...) do { \
    wrapper_logger(DEBUG, FMT, __FILE__, __LINE__, __func__, ##args); \
} while (false)

#define SIMPLE_INFO(FMT, ...) do { \
    wrapper_logger(INFO, FMT, __FILE__, __LINE__, __func__, ##args); \
} while (false)

#define SIMPLE_ERROR(FMT, ...) do { \
    wrapper_logger(ERROR, FMT, __FILE__, __LINE__, __func__, ##args); \
} while (false)

#define SIMPLE_WARNING(FMT, ...) do { \
    wrapper_logger(WARNING, FMT, __FILE__, __LINE__, __func__, ##args); \
} while (false)

#define SIMPLE_FATAL(FMT, ...) do { \
    wrapper_logger(FATAL, FMT, __FILE__, __LINE__, __func__, ##args); \
} while (false)

#endif //__SIMPLE_LOG_H__