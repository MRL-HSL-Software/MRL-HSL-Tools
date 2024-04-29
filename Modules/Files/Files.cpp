# ifndef MRL_HSL_TOOLS_FILES
    # include "Files.hpp"
    /**
     * @brief Constructor
     */
    Files::Files() {}
    /**
     * @brief Get Files List
     * @param path
     * @return std::vector<std::string>
     */
    std::vector<std::string> Files::open_dir(std::string path) {
        //-- Reset Files
        files.clear();
        //-- Open Directory
        directory = opendir(path.c_str());
        //-- Check Directory
        if (directory == NULL) {
            std::cout << FAILED "Can Not Open Directory " CYAN << path << RESET " from " CYAN << current_dir() << RESET << std::endl;
            return files;
        }
        //-- Read Directory
        while ((entry = readdir(directory))) {
            //-- Check File
            if (entry->d_type == DT_REG) {
                //-- Check if File is PNG or JPG
                std::string file = entry->d_name;
                if (file.find(".png") != std::string::npos || file.find(".jpg") != std::string::npos) {
                    std::cout << TAB SUCCESS "Found File " DARK_CYAN << file << RESET << std::endl;
                    files.push_back(entry->d_name);
                }
            }
        }
        //-- Check Empty Files
        if (files.empty()) {
            std::cout << TAB FAILED "No Files Found in " CYAN << path << RESET << std::endl;
            std::string command = "nautilus " + path + " 2>/dev/null";
            system(command.c_str());
        }
        //-- Close Directory
        closedir(directory);
        //-- Return Files
        return files;
    }
    /**
     * @brief Get Current Directory
     * @return std::string
     */
    std::string Files::current_dir() {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            return std::string(cwd);
        } else {
            return "UNKNOWN";
        }
    }
    /**
     * @brief Rename Files
     * @param path
     * @param mode
     * @return std::vector<std::string>
     */
    std::vector<std::string> Files::rename_files(std::string path, int mode) {
        std::vector<std::string> files = open_dir(path);
        datetime.current = datetime.getCurrentDatetime();
        for (int i = 1; i <= files.size(); i++) {
            std::string file = files[i - 1];
            std::string new_file = "";
            switch (mode) {
                case RENAME_TO_ID_AND_DATE_AND_TIME:
                    new_file = std::to_string(i) + "_" + std::to_string(datetime.current.year) + "_" + std::to_string(datetime.current.month) + "_" + std::to_string(datetime.current.day) + "_" + std::to_string(datetime.current.hour) + "_" + std::to_string(datetime.current.minute) + "_" + std::to_string(datetime.current.second) + "_";
                    break;
                case RENAME_TO_DATE_AND_TIME:
                    new_file = std::to_string(datetime.current.year) + "_" + std::to_string(datetime.current.month) + "_" + std::to_string(datetime.current.day) + "_" + std::to_string(datetime.current.hour) + "_" + std::to_string(datetime.current.minute) + "_" + std::to_string(datetime.current.second) + "_";
                    break;
                case RENAME_TO_ID_AND_TIME:
                    new_file = std::to_string(i) + "_" + std::to_string(datetime.current.hour) + "_" + std::to_string(datetime.current.minute) + "_" + std::to_string(datetime.current.second) + "_";
                    break;
                case RENAME_TO_ID_AND_DATE:
                    new_file = std::to_string(i) + "_" + std::to_string(datetime.current.year) + "_" + std::to_string(datetime.current.month) + "_" + std::to_string(datetime.current.day) + "_";
                    break;
                case RENAME_TO_DATE:
                    new_file = std::to_string(datetime.current.year) + "_" + std::to_string(datetime.current.month) + "_" + std::to_string(datetime.current.day) + "_";
                    break;
                case RENAME_TO_TIME:
                    new_file = std::to_string(datetime.current.hour) + "_" + std::to_string(datetime.current.minute) + "_" + std::to_string(datetime.current.second) + "_";
                    break;
                case RENAME_TO_ID:
                    new_file = std::to_string(i) + "_" + file;
                    break;
            }
            std::string old_path = path + "/" + file;
            std::string new_path = path + "/" + new_file;
            rename(old_path.c_str(), new_path.c_str());
        }
        return open_dir(path);
    }
# endif // MRL_HSL_TOOLS_FILES