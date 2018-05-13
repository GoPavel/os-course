#include <iostream>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <unistd.h>
#include <sstream>
#include <iterator>

int main() {

    for(;;) {
        std::cout << "> ";
        std::string path; // path of application
        std::cin >> path;

        std::vector<std::string> args;
        args.push_back(path);
        std::string buf;
        if(!std::getline(std::cin, buf)) {
            std::cout << std::endl;
            break;
        }
        std::istringstream stream(buf);
        std::copy(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  std::back_inserter(args));

        char *neweviron[] = { nullptr };

        int status;
        const pid_t pid = fork();
        pid_t ret_wait;
        if(pid == -1) {
            perror("fork");
            break;
        }
        if(!pid) {
            // application case
            std::vector<char const*> c_args;
            for(auto const arg : args) {
                c_args.push_back(arg.data());
            }
            c_args.push_back(nullptr);
            execve(path.c_str(), const_cast<char* const*>(c_args.data()), neweviron);
            perror("execve");
            exit(EXIT_FAILURE);
            break;
        }
        if(pid) {
            // shell case
            ret_wait = waitpid(pid, &status, WUNTRACED);
            std::cout << "Precess exit with " << status << std::endl;
            if(ret_wait == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
            continue;
        }
    }

    return 0;
}
