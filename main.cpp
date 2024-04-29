# ifndef MRL_HSL_SOFTWARE_TOOLS
    # include "Tools.hpp"
    # include <iostream>
    //-- Main Function
    int main() {
        Tools tools;
        std::cout << "\033[2J\x1b[H" << std::endl;
        std::cout << CYAN "Select Tool :" << std::endl;
        std::cout << CYAN "1. " RESET "Labeling" << std::endl;
        std::cout << CYAN "2. " RESET "Logger" << std::endl;
        int choice;
        std::cout << CYAN "Choice : " RESET; std::cin >> choice;
        switch (choice) {
            //-- Labeling
            case 1: {
                std::cout << "\033[2J\x1b[H" << std::endl;
                std::cout << CYAN "Select Labeling Option :" << std::endl;
                std::cout << CYAN "1. " RESET "Rect Box" << std::endl;
                std::cout << CYAN "2. " RESET "Semantic" << std::endl;
                int sub_choice;
                std::cout << CYAN "Choice : " RESET; std::cin >> sub_choice;
                switch (sub_choice) {
                    //-- Rect Box
                    case 1: {
                        std::cout << LOG "Rect Box Tool Selected" << std::endl;
                        break;
                    }
                    //-- Semantic
                    case 2: {
                        std::cout << LOG "Semantic Tool Selected" << std::endl;
                        //-- Load Input Data
                        std::cout << LOG "Searching Input Files ..." << std::endl;
                        std::vector<std::string> files = tools.modules.files.open_dir(
                            TOOLS_LABELING_SOURCE_IMAGES_PATH
                        );
                        std::cout << TAB LOG "Found " CYAN << files.size() << RESET " Files" << std::endl;
                        std::cout << TAB CYAN "Do You Want to Rename Found Files ?" << std::endl;
                        std::cout << TAB CYAN "1. " RESET "Yes" << std::endl;
                        std::cout << TAB CYAN "2. " RESET "No" << std::endl;
                        int rename_choice;
                        std::cout << TAB CYAN "Choice : " RESET; std::cin >> rename_choice;
                        if (rename_choice == 1) {
                            std::cout << TAB LOG "Renaming Files ..." << std::endl;
                            tools.modules.files.rename_files(
                                TOOLS_LABELING_SOURCE_IMAGES_PATH,
                                RENAME_TO_ID_AND_DATE_AND_TIME
                            );
                            std::cout << TAB LOG "Files Renamed Successfully" << std::endl;
                            std::vector<std::string> files = tools.modules.files.open_dir(
                                TOOLS_LABELING_SOURCE_IMAGES_PATH
                            );
                            std::cout << TAB LOG "Found " CYAN << files.size() << RESET " Files" << std::endl;
                        }
                        //-- Open Labeling Tool
                        tools.visionTools.labeling.semantic(
                            TOOLS_LABELING_SOURCE_IMAGES_PATH,
                            TOOLS_LABELING_LABELED_IMAGES_PATH,
                            files
                        );
                        break;
                    }
                }
                break;
            };
            //-- Logger
            case 2: {
                std::cout << LOG "Logger Tool Selected" << std::endl;
                break;
            }
        }
        return 0;
    
    }
# endif // MRL_HSL_SOFTWARE_TOOLS