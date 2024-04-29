# ifndef MRL_HSL_TOOLS_DATETIME
    # include "Datetime.hpp"
    /**
     * @brief Constructor
     */
    Datetime::Datetime() {}
    /**
     * @brief Get Current Date Method
     * @return Current
     */
    Datetime::Current Datetime::getCurrentDatetime() {
        now = std::time(0);
        local = std::localtime(&now);
        current.day = local->tm_mday;
        current.gmt = local->tm_gmtoff;
        current.year = local->tm_year + 1900;
        current.hour = local->tm_hour;
        current.month = local->tm_mon + 1;
        current.minute = local->tm_min;
        current.second = local->tm_sec;
        current.weekDay = local->tm_wday;
        current.yearDay = local->tm_yday;
        current.daylightSavingTime = local->tm_isdst;
        return current;
    }
# endif // MRL_HSL_TOOLS_DATETIME