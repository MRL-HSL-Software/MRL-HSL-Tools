# ifndef MRL_HSL_TOOLS_FILES
    /**
     * @file Files.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief MRL HSL Tools Files Module
     * @version 0.1
     * @date 2024-04-29
     */
    # define MRL_HSL_TOOLS_FILES
    //-- Include Dirent.h
    # ifndef _DIRENT_H
        # include <dirent.h>
    # endif // _DIRENT_H
    //-- Include Unistd.h
    # ifndef _UNISTD_H
        # include <unistd.h>
    # endif // _UNISTD_H
    //-- Include Vectors
    # ifndef _GLIBCXX_VECTOR
        # include <vector>
    # endif // _GLIBCXX_VECTOR
    //-- Include String
    # ifndef _GLIBCXX_STRING
        # include <string>
    # endif // _GLIBCXX_STRING
    //-- Include Iostream
    # ifndef _GLIBCXX_IOSTREAM
        # include <iostream>
    # endif // _GLIBCXX_IOSTREAM
    //-- Include Configurations
    # ifndef MRL_HSL_TOOLS_MODULES_CONFIGS
        # include "../Configs.hpp"
    # endif // MRL_HSL_TOOLS_MODULES_CONFIGS
    //-- Include Datetime Module
    # ifndef MRL_HSL_TOOLS_DATETIME
        # include "../Datetime/Datetime.hpp"
    # endif // MRL_HSL_TOOLS_DATETIME
    enum ENUM_RENAME_FILES_METHODS {
        RENAME_TO_ID_AND_DATE_AND_TIME = 6,
        RENAME_TO_DATE_AND_TIME = 5,
        RENAME_TO_ID_AND_TIME = 4,
        RENAME_TO_ID_AND_DATE = 3,
        RENAME_TO_DATE = 2,
        RENAME_TO_TIME = 1,
        RENAME_TO_ID = 0
    };
    /**
     * @brief Files Class Definition
     */
    class Files {
        public:
            /**
             * @brief Datetime Module
             */
            Datetime datetime;
            /**
             * @brief Directory Object
             */
            DIR *directory;
            /**
             * @brief Files List
             */
            std::vector<std::string> files;
            /**
             * @brief Directory Entry
             */
            struct dirent *entry;
            /**
             * @brief Construct a new Files object
             */
            Files();
            /**
             * @brief Get Files List
             * @param path
             * @return std::vector<std::string>
             */
            std::vector<std::string> open_dir(std::string path);
            /**
             * @brief Get Current Directory
             * @return std::string
             */
            std::string current_dir();
            /**
             * @brief Rename Files
             * @param path
             * @param mode
             * @return std::vector<std::string>
             */
            std::vector<std::string> rename_files(std::string path, int mode);
    };
# endif // MRL_HSL_TOOLS_FILES