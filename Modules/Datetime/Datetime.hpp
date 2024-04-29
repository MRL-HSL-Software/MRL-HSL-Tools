# ifndef MRL_HSL_TOOLS_DATETIME
    /**
     * @file Datetime.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Datetime Tools
     * @version 0.1
     * @date 2024-04-29
     * 
     * @copyright Copyright (c) 2024
     * 
     */
    # define MRL_HSL_TOOLS_DATETIME
    //-- Include Configurations
    # ifndef MRL_HSL_TOOLS_MODULES_CONFIGS
        # include "../Configs.hpp"
    # endif // MRL_HSL_TOOLS_MODULES_CONFIGS
    # ifndef _GLIBCXX_CTIME
        # include <ctime>
    # endif // _GLIBCXX_CTIME
    //-- Include String
    # ifndef _GLIBCXX_STRING
        # include <string>
    # endif // _GLIBCXX_STRING
    //-- Include Iostream
    # ifndef _GLIBCXX_IOSTREAM
        # include <iostream>
    # endif // _GLIBCXX_IOSTREAM
    /**
     * @brief Datetime Class
     */
    class Datetime {
        public:
            /**
             * @brief Date
             */
            std::time_t now;
            /**
             * @brief Date Time
             */
            std::tm *local;
            /**
             * @brief Current Date and Time Struct
             * @param day Day
             * @param gmt GMT
             * @param year Year
             * @param hour Hour
             * @param month Month
             * @param minute Minute
             * @param second Second
             * @param weekDay Week Day
             * @param yearDay Year Day
             * @param daylightSavingTime Daylight Saving Time
             */
            struct Current {
                int day;
                long gmt;
                int year;
                int hour;
                int month;
                int minute;
                int second;
                int weekDay;
                int yearDay;
                int daylightSavingTime;
            };
            /**
             * @brief Current
             * @param day Day
             * @param gmt GMT
             * @param year Year
             * @param hour Hour
             * @param month Month
             * @param minute Minute
             * @param second Second
             * @param weekDay Week Day
             * @param yearDay Year Day
             * @param daylightSavingTime Daylight Saving Time
             * @return Current
             */
            Current current;
            /**
             * @brief Construct a new Datetime object
             */
            Datetime();
            /**
             * @brief Get Current Date Method
             * @return Current
             */
            Current getCurrentDatetime();
    };
# endif // MRL_HSL_TOOLS_DATETIME